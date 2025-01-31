#ifndef DESTINATIONCOUNTRY_H
#define DESTINATIONCOUNTRY_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>


class DestinationCountry : public QMainWindow
{
    Q_OBJECT
public:
    DestinationCountry(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);


    void destiantionCountryComboBox();


private:
    Ui::MainWindow* ui;
    QComboBox* mCBDestinationCountry;

};

#endif // DESTINATIONCOUNTRY_H
