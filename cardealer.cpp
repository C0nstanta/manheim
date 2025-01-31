#include "cardealer.h"

CarDealer::CarDealer(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}
    , ui(tmpUI)
{

}

void CarDealer::dealerLineEdit()
{
    ui->lEditCarDealerFees->textEdited(0);
}

