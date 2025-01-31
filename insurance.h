#ifndef INSURANCE_H
#define INSURANCE_H


#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>

class Insurance : public QMainWindow
{
    Q_OBJECT
public:
    Insurance(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

    void insuranceComboBox();


private:
    Ui::MainWindow* ui;
    QComboBox* mCBInsurance;
};

#endif // INSURANCE_H
