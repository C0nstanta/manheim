#include "destinationcountry.h"

DestinationCountry::DestinationCountry(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBDestinationCountry(new QComboBox(this))
{

}

void DestinationCountry::destiantionCountryComboBox() {

    ui->CB_DestinationCountry->addItem("Armenia");
    ui->CB_DestinationCountry->addItem("Georgia");
    ui->CB_DestinationCountry->addItem("Kazakhstan");
    ui->CB_DestinationCountry->addItem("Kyrgyzstan");
    ui->CB_DestinationCountry->addItem("Poland");
    ui->CB_DestinationCountry->addItem("Russia");
    ui->CB_DestinationCountry->addItem("Ukraine");
    ui->CB_DestinationCountry->addItem("USA");

}
