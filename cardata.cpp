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

void CarData::carDataActivate(const QString& country)
{
    qDebug() << "engineTypeComboBox" << country;


    int x = 440;
    int y = 190;

    carDataFrame(x, y);
    engineTypeComboBox(x, y, country);
    engineCapacityLineEdit(x, y, country);
}

void CarData::carDataDeactivate() {

    mLabelEngineType->clear();
    delete mLabelEngineType;
    mLabelEngineType = nullptr;

    mCBEngineType->clear();
    delete mCBEngineType;
    mCBEngineType = nullptr;

    mLabelEngineCapacity->clear();
    delete mLabelEngineCapacity;
    mLabelEngineCapacity = nullptr;

    mLineEditEngineCapacity->clear();
    delete mLineEditEngineCapacity;
    mLineEditEngineCapacity = nullptr;

    mCarDataFrame->clearMask();
    delete mCarDataFrame;
    mCarDataFrame = nullptr;
}

void CarData::carDataFrame(const int x, const int y)
{

    mCarDataFrame = new QFrame(ui->widget);
    mCarDataFrame->setGeometry(x, y, 330, 250);
    mCarDataFrame->setLineWidth(3);
    mCarDataFrame->setFrameShadow(QFrame::Raised);
    mCarDataFrame->setFrameShape(QFrame::StyledPanel);
    mCarDataFrame->show();

}


void CarData::engineTypeComboBox(const int x, const int y, const QString& country)
{
    qDebug() << "engineTypeComboBox 1 " << country;

    mLabelEngineType = new QLabel(ui->widget);
    mLabelEngineType->setGeometry(x + 10, y + 10, 130, 16);
    mLabelEngineType->setText("Engine Type");
    mLabelEngineType->show();


    mCBEngineType = new QComboBox(ui->widget);
    mCBEngineType->setGeometry(x + 2, y + 27, 151, 32);

    mCBEngineType->addItem("Gasoline");
    mCBEngineType->addItem("Diesel");
    mCBEngineType->addItem("Electric");
    mCBEngineType->addItem("Hybrid");
    mCBEngineType->show();

    connect(mCBEngineType, &QComboBox::currentTextChanged, this, &CarData::engineTypeChanged);

    qDebug() << "engineTypeComboBox 2 " << country;
}

void CarData::engineCapacityLineEdit(const int x, const int y, const QString& country)
{
    mLabelEngineCapacity = new QLabel(ui->widget);
    mLabelEngineCapacity->setGeometry(x + 130 + 30, y + 10, 140, 16);
    mLabelEngineCapacity->setText("Engine capacity(cc/cm)");
    mLabelEngineCapacity->show();

    mLineEditEngineCapacity = new QLineEdit(ui->widget);
    mLineEditEngineCapacity->setGeometry(x + 130 + 30, y + 30, 115, 20);
    mLineEditEngineCapacity->setText("0");
    mLineEditEngineCapacity->show();


}

void CarData::yearOfProductionLineEdit(const int x, const int y, const QString& country)
{
    // mLineEditYearProduct = new QLineEdit(ui->widget);
}

// getters bunch
QFrame* CarData::getCarDataFrame()
{
    return mCarDataFrame;
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




