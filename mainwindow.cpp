#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializo configurador de nivel de producto de sonda
    ui->prodShowLabel->setText(QString("= %1%2").arg("0").arg(" mm"));
    ui->prodSlider->setRange(0, 1000);
    // Inicializo nivel de producto de sonda
    probe->setProductLevel(0);

    // Inicializo configurador de nivel de agua de sonda
    ui->waterShowLabel->setText(QString("= %1%2").arg("0").arg(" mm"));
    ui->waterSlider->setRange(0, 1000);
    // Inicializo nivel de agua de sonda
    probe->setWaterLevel(0);

    // Inicializo configurador de temperatura de sonda
    ui->tempShowLabel->setText(QString("= %1%2").arg("15").arg(" °C"));
    ui->tempSlider->setRange(-30, 70);
    // Inicializo temperatura de sonda
    probe->setTemperature(15);

    // Inicializo configurador de longitud de la sonda
    ui->length->addItem(QString("1000 mm"));
    ui->length->addItem(QString("1200 mm"));
    ui->length->addItem(QString("1500 mm"));
    ui->length->addItem(QString("2000 mm"));
    // Inicializo longitud de sonda
    probe->setProbeLength(1000);

    // Inicializo configurador de error de sonda
    ui->error->addItem("No Error");
    ui->error->addItem("Internal Error");
    ui->error->addItem("Comm Error");
    // Inicializo estado de error de sonda
    probe->setErrorStatus(NO_ERROR);
}

MainWindow::~MainWindow()
{
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
    probe->setErrorStatus(index);

    switch(index)
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
