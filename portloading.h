#ifndef PORTLOADING_H
#define PORTLOADING_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>

class PortLoading : public QMainWindow
{
    Q_OBJECT
public:
    PortLoading(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

    void portLoadingComboBox();
    void portChargeLineEdit();

private:
    Ui::MainWindow* ui;
    QComboBox* mCBPortLoading;

};

#endif // PORTLOADING_H
