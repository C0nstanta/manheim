#include "cardata.h"

CarData::CarData(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}
    , ui(tmpUI)
    , mCarDataFrame(nullptr)
    , mCBEngineType(nullptr)
    , mLabelEngineType(nullptr)
    , mLineEditEngineCapacity(nullptr)
    , mLabelEngineCapacity(nullptr)
    , mLineEditYearProduct(nullptr)
    , mLabelYearProduct(nullptr)
{

}

void CarData::carDataActivate()
{
    engineTypeComboBox();
    ownerTypeComboBox();
    ageOfCarLineEdit();
    enginePowerLineEdit();
    vehicleWeightLineEdit();
    engineCapacityLineEdit();
}

void CarData::carDataDeactivate() {

    // mLabelEngineType->clear();
    // delete mLabelEngineType;
    // mLabelEngineType = nullptr;

    // mCBEngineType->clear();
    // delete mCBEngineType;
    // mCBEngineType = nullptr;

    // mLabelEngineCapacity->clear();
    // delete mLabelEngineCapacity;
    // mLabelEngineCapacity = nullptr;

    // mLineEditEngineCapacity->clear();
    // delete mLineEditEngineCapacity;
    // mLineEditEngineCapacity = nullptr;

    // mCarDataFrame->clearMask();
    // delete mCarDataFrame;
    // mCarDataFrame = nullptr;
}

void CarData::engineTypeComboBox()
{
    ui->CB_EngineType->addItem("Gasoline");
    ui->CB_EngineType->addItem("Diesel");
    ui->CB_EngineType->addItem("Electric");
    ui->CB_EngineType->addItem("Hybrid");
}

void CarData::ownerTypeComboBox()
{
    ui->CB_OwnerType->addItem("Individual");
    ui->CB_OwnerType->addItem("Legal entity");

}

void CarData::engineCapacityLineEdit()
{
    auto validator = new QIntValidator(0, 999999, this);
    ui->LE_EngineCapacity->setValidator(validator);
    ui->LE_EngineCapacity->setText("0");
}

void CarData::ageOfCarLineEdit()
{
    auto validator = new QIntValidator(0, 999, this);
    ui->LE_AgeOfCar->setValidator(validator);
    ui->LE_AgeOfCar->setText("0");
}

void CarData::enginePowerLineEdit()
{
    auto validator = new QIntValidator(0, 9999, this);
    ui->LE_EnginePower->setValidator(validator);
    ui->LE_EnginePower->setText("0");
}

void CarData::vehicleWeightLineEdit()
{
    auto validator = new QIntValidator(0, 9999, this);
    ui->LE_VehicleWeight->setValidator(validator);
    ui->LE_VehicleWeight->setText("0");
}





QComboBox* CarData::getCarDataEngineType()
{
    return mCBEngineType;
}

QLabel* CarData::getLabelEngineType()
{
    return mLabelEngineType;
}

QLineEdit* CarData::getLineEditEngineCapacity()
{
    return mLineEditEngineCapacity;
}

QLabel* CarData::getLabelEngineCapacity()
{
    return mLabelEngineCapacity;
}

QLineEdit* CarData::getLineEditYearProduct()
{
    return mLineEditYearProduct;
}

QLabel* CarData::getLabelYearProduct()
{
    return mLabelYearProduct;
}




