#include "insurance.h"


Insurance::Insurance(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}, ui(tmpUI), mCBInsurance(new QComboBox(this))
{

}

void Insurance::insuranceComboBox() {

    ui->CB_CarInsurance->addItem("No");
    ui->CB_CarInsurance->addItem("Yes");

}
