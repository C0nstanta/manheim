#include "cardealer.h"

CarDealer::CarDealer(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}
    , ui(tmpUI)
{

}

void CarDealer::dealerLineEdit()
{
    QIntValidator *validator = new QIntValidator(0, 99999999, this);
    ui->LE_CarDealerFees->setValidator(validator);
    ui->LE_CarDealerFees->textEdited(0);
}

