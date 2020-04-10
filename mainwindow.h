#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "probes.h"

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

private:
    Ui::MainWindow *ui;
    probes *probe;
};
#endif // MAINWINDOW_H
