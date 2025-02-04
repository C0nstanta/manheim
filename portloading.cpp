#include "portloading.h"


PortLoading::PortLoading(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBPortLoading(new QComboBox(this))
{

}

void PortLoading::portLoadingComboBox() {

    ui->CB_USPortLoading->addItem("Houston");
    ui->CB_USPortLoading->addItem("New York");
    ui->CB_USPortLoading->addItem("Miami");
    ui->CB_USPortLoading->addItem("Los Angeles");
    ui->CB_USPortLoading->addItem("Oakland");

}

void PortLoading::portChargeLineEdit()
{
    // QIntValidator *validator = new QIntValidator(0, 99999999, this);
    // ui->LE_PortCharges->setValidator(validator);
    // ui->LE_PortCharges->textEdited(0);
}
