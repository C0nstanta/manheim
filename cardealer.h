#ifndef CARDEALER_H
#define CARDEALER_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>


class CarDealer : public QMainWindow
{
    Q_OBJECT
public:
    CarDealer(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

    void dealerLineEdit();

private:
    Ui::MainWindow* ui;
};

#endif // CARDEALER_H
