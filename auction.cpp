#include "auction.h"

Auction::Auction(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBAuction(new QComboBox(this))
{

}

void Auction::auctionInUsaComboBox()
{

    ui->CB_Auction->addItem("Manheim Auction");
    ui->CB_Auction->addItem("Copart Auction");
    ui->CB_Auction->addItem("Adesa Auction");

}

void Auction::auctionLabel()
{
    ui->lAuctionPrice->setText("Buy price");

}

void Auction::auctionCarDealerFeesLineEdit()
{
    auto validator = new QIntValidator(0, 99999999, this);
    ui->LE_CarDealerFees->setValidator(validator);
    ui->LE_CarDealerFees->textEdited(0);
}

void Auction::auctionCarBuyPriceLineEdit()
{
    auto validator = new QIntValidator(0, 99999999, this);
    ui->LE_AuctionCarBuyPrice->setValidator(validator);
    ui->LE_AuctionCarBuyPrice->textEdited(0);
}
