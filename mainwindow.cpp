#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"

#include <QString>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_settings(new SettingsDialog),
      m_serial(new QSerialPort(this)),
      probe(new probes(0,0,0,NO_ERROR,1000,WIRED,1,GENERIC)),
      protocolGeneric1(new protocolGeneric(PARSE_P, 1))
{
    ui->setupUi(this);

    m_settings->setModal(true);

    ui->ConnectButton->setEnabled(true);
    ui->DisconnectButton->setEnabled(false);
    ui->ConfigureButton->setEnabled(true);

    // Inicializo configurador de nivel de producto de sonda
    ui->prodShowLabel->setText(QString("= %1%2").arg("0").arg(" mm"));
    ui->prodSlider->setRange(0, 1000);

    // Inicializo configurador de nivel de agua de sonda
    ui->waterShowLabel->setText(QString("= %1%2").arg("0").arg(" mm"));
    ui->waterSlider->setRange(0, 1000);

    // Inicializo configurador de temperatura de sonda
    ui->tempShowLabel->setText(QString("= %1%2").arg("15").arg(" °C"));
    ui->tempSlider->setRange(-30, 70);

    // Inicializo configurador de longitud de la sonda
    ui->length->addItem(QString("1000 mm"));
    ui->length->addItem(QString("1200 mm"));
    ui->length->addItem(QString("1500 mm"));
    ui->length->addItem(QString("2000 mm"));

    // Inicializo configurador de error de sonda
    ui->error->addItem("No Error");
    ui->error->addItem("Internal Error");
    ui->error->addItem("Comm Error");

    // Inicializo el checkbox del tipo de sonda como MASTER
    ui->typeMaster->setChecked(true);
    ui->typeSlave->setChecked(false);

    // Inicializo configurador de id de sonda
    for (int i = 0; i < ID_MAX; i++)
    {
        ui->id->addItem(QString::number(i + 1));
    }

    ui->portStatusShowLablel->setText("<font color='red'>Disconnected</font>");

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    //connect(m_console, &Console::getData, this, &MainWindow::writeData);

}

MainWindow::~MainWindow()
{
    delete m_settings;
    delete ui;
}

void MainWindow::on_prodSlider_valueChanged(int value)
{
    probe->setProductLevel(float(value));
    QString string_aux = QString("= %1%2").arg(value).arg(" mm");
    ui->prodShowLabel->setText(string_aux);
}

void MainWindow::on_waterSlider_valueChanged(int value)
{
    probe->setWaterLevel(float(value));
    QString string_aux = QString("= %1%2").arg(value).arg(" mm");
    ui->waterShowLabel->setText(string_aux);
}

void MainWindow::on_tempSlider_valueChanged(int value)
{
    probe->setTemperature(float(value));
    QString string_aux = QString("= %1%2").arg(value).arg(" °C");
    ui->tempShowLabel->setText(string_aux);
}

void MainWindow::on_length_currentIndexChanged(int index)
{
    int lengthValue = 0;
    switch ((length_t)index)
    {
    case MM1000:
        lengthValue = 1000;
        break;
    case MM1200:
        lengthValue = 1200;
        break;
    case MM1500:
        lengthValue = 1500;
        break;
    case MM2000:
        lengthValue = 2000;
        break;
    default:
        lengthValue = 1000;
        break;
    }
    probe->setProbeLength(lengthValue);
    ui->prodSlider->setRange(0, lengthValue);
    ui->waterSlider->setRange(0, lengthValue);
}

void MainWindow::on_error_currentIndexChanged(int index)
{
    probe->setErrorStatus((probeError_t)index);

    switch((probeError_t)index)
    {
    case NO_ERROR:
        ui->errorStatusShowLabel->setText("<font color='green'>No Error</font>");
        break;
    case INTERNAL_ERROR:
        ui->errorStatusShowLabel->setText("<font color='red'>Internal Error</font>");
        break;
    case COMM_ERROR:
        ui->errorStatusShowLabel->setText("<font color='red'>Comm Error</font>");
        break;
    default:
        ui->errorStatusShowLabel->setText("<font color='green'>No Error</font>");
        break;
    }
}

void MainWindow::on_typeMaster_clicked()
{
    if((ui->typeSlave->isChecked()) && (ui->typeMaster->isChecked()))
    {
        ui->typeSlave->setChecked(false);
        probe->setProbeType(WIRED);
    }
    else if((!ui->typeSlave->isChecked()) && (ui->typeMaster->isChecked()))
    {
        probe->setProbeType(WIRED);
    }
}

void MainWindow::on_typeSlave_clicked()
{
    if((ui->typeSlave->isChecked()) && (ui->typeMaster->isChecked()))
    {
        ui->typeMaster->setChecked(false);
        probe->setProbeType(WIRELESS);
    }
    else if((ui->typeSlave->isChecked()) && (!ui->typeMaster->isChecked()))
    {
        probe->setProbeType(WIRELESS);
    }
}

void MainWindow::on_id_currentIndexChanged(int index)
{
    probe->setProbeId(index+1);
    protocolGeneric1->setActiveId(index+1);
}

void MainWindow::on_ConnectButton_clicked()
{
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite))
    {
        ui->ConnectButton->setEnabled(false);
        ui->DisconnectButton->setEnabled(true);
        ui->ConfigureButton->setEnabled(false);
        ui->portStatusShowLablel->setText("<font color='green'>Connected</font>");
        ui->portNumberShowLablel->setText(p.name);
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
    }
}

void MainWindow::on_DisconnectButton_clicked()
{
    if (m_serial->isOpen())
    {
        m_serial->close();
    }
    ui->portStatusShowLablel->setText("<font color='red'>Disconnected</font>");
    ui->ConnectButton->setEnabled(true);
    ui->DisconnectButton->setEnabled(false);
    ui->ConfigureButton->setEnabled(true);
    ui->portNumberShowLablel->setText("");
}

void MainWindow::on_ConfigureButton_clicked()
{
    m_settings->show();
}

void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{
   int parseStatus = 0;
   QMessageBox msgBox;


   const QByteArray dataReceived = m_serial->readAll();

   qDebug() << dataReceived;

   parseStatus = protocolGeneric1->parseReceivedData(dataReceived);
   if(parseStatus == PARSE_CORRECT)
   {
       m_serial->write("PARSEO CORRECTO, FUCNIONA LA COMUNICACION!!!");
   }
   else if(parseStatus == PARSE_INCOMPLETE)
   {
       msgBox.setWindowTitle("Warning");
       msgBox.setFixedSize(500,500);
       msgBox.setText("Parse Error");
       msgBox.exec();
   }
   else if(parseStatus == PROBE_ID_INCORRECT)
   {
       msgBox.setWindowTitle("Warning");
       msgBox.setFixedSize(200,200);
       msgBox.setText("Probe Id Incorrect");
       msgBox.exec();
   }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        on_DisconnectButton_clicked();
    }
}
