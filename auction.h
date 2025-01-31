#ifndef AUCTION_H
#define AUCTION_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>

class Auction : public QMainWindow
{
    Q_OBJECT
public:
    Auction(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

    void auctionComboBox();
    void auctionLabel();
    void auctionLineEdit();


private:
    Ui::MainWindow* ui;
    QComboBox* mCBAuction;
};

#endif // AUCTION_H
