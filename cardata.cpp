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
    // qDebug() << "engineTypeComboBox" << country;


    int x = 440;
    int y = 190;

    // carDataFrame(x, y);
    engineTypeComboBox();
    ownerTypeComboBox();
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

// void CarData::carDataFrame(const int x, const int y)
// {

    // mCarDataFrame = new QFrame(ui->centrawidget);
    // mCarDataFrame->setGeometry(x, y, 330, 250);
    // mCarDataFrame->setLineWidth(3);
    // mCarDataFrame->setFrameShadow(QFrame::Raised);
    // mCarDataFrame->setFrameShape(QFrame::StyledPanel);
    // mCarDataFrame->show();

// }


void CarData::engineTypeComboBox()
{
    // qDebug() << "engineTypeComboBox 1 " << country;

    // mLabelEngineType = new QLabel(ui->centrawidget);
    // mLabelEngineType->setGeometry(x + 10, y + 10, 130, 16);
    // mLabelEngineType->setText("Engine Type");
    // mLabelEngineType->show();


    // mCBEngineType = new QComboBox(ui->centrawidget);
    // mCBEngineType->setGeometry(x + 2, y + 27, 151, 32);

    ui->CB_EngineType->addItem("Gasoline");
    ui->CB_EngineType->addItem("Diesel");
    ui->CB_EngineType->addItem("Electric");
    ui->CB_EngineType->addItem("Hybrid");
    // ui->CB_EngineType->show();

    // connect(mCBEngineType, &QComboBox::currentTextChanged, this, &CarData::engineTypeChanged);

    // qDebug() << "engineTypeComboBox 2 " << country;
}

void CarData::ownerTypeComboBox()
{
    ui->CB_OwnerType->addItem("Individual");
    ui->CB_OwnerType->addItem("Legal entity");

}

void CarData::engineCapacityLineEdit()
{
    // mLabelEngineCapacity = new QLabel(ui->centrawidget);
    // mLabelEngineCapacity->setGeometry(x + 130 + 30, y + 10, 140, 16);
    // mLabelEngineCapacity->setText("Engine capacity(cc/cm)");
    // mLabelEngineCapacity->show();

    // mLineEditEngineCapacity = new QLineEdit(ui->centrawidget);
    // mLineEditEngineCapacity->setGeometry(x + 130 + 30, y + 30, 115, 20);
    // mLineEditEngineCapacity->setText("0");
    // mLineEditEngineCapacity->show();


}

void CarData::yearOfProductionLineEdit()
{
    // mLineEditYearProduct = new QLineEdit(ui->widget);
}

// getters bunch
// QFrame* CarData::getCarDataFrame()
// {
//     return mCarDataFrame;
// }

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




