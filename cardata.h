#ifndef CARDATA_H
#define CARDATA_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>

class CarData : public QMainWindow
{
    Q_OBJECT
public:
    CarData(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

private:
    Ui::MainWindow* ui;
};

#endif // CARDATA_H
