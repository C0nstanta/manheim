#include "destinationcountry.h"

DestinationCountry::DestinationCountry(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBDestinationCountry(new QComboBox(this))
{

}

void DestinationCountry::destiantionCountryComboBox() {

    ui->mCBDestinationCountry->addItem("Ukraine");
    ui->mCBDestinationCountry->addItem("Armenia");
    ui->mCBDestinationCountry->addItem("Georgia");
    ui->mCBDestinationCountry->addItem("Kazakhstan");
    ui->mCBDestinationCountry->addItem("Kyrgyzstan");
    ui->mCBDestinationCountry->addItem("Poland");
    ui->mCBDestinationCountry->addItem("Russia");
    ui->mCBDestinationCountry->addItem("USA");

}
