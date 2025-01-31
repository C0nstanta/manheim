#include "auction.h"

Auction::Auction(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBAuction(new QComboBox(this))
{

}

void Auction::auctionComboBox()
{

    ui->CB_Auction->addItem("Manheim Auction");
    ui->CB_Auction->addItem("Copart Auction");
    ui->CB_Auction->addItem("Adesa Auction");

}

void Auction::auctionLabel()
{
    ui->lAuctionPrice->setText("Buy price");

}

void Auction::auctionLineEdit()
{
    ui->lEditBrokerFees->textEdited(0);
}
