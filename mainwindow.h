#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "settingsdialog.h"
#include "probes.h"
#include  "protocolGeneric.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef enum
{
    MM1000 = 0,
    MM1200 = 1,
    MM1500 = 2,
    MM2000 = 3
}length_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_prodSlider_valueChanged(int value);
    void on_waterSlider_valueChanged(int value);
    void on_tempSlider_valueChanged(int value);

    void on_length_currentIndexChanged(int index);

    void on_error_currentIndexChanged(int index);

    void on_typeMaster_clicked();
    void on_typeSlave_clicked();

    void on_id_currentIndexChanged(int index);

    void on_ConnectButton_clicked();
    void on_DisconnectButton_clicked();
    void on_ConfigureButton_clicked();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    Ui::MainWindow  *ui;
    SettingsDialog  *m_settings       = nullptr;
    QSerialPort     *m_serial         = nullptr;
    probes          *probe            = nullptr;
    protocolGeneric *protocolGeneric1 = nullptr;

};
#endif // MAINWINDOW_H
