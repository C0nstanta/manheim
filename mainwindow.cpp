#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mAuction(new Auction(nullptr, ui))
    , mCarData(new CarData(nullptr, ui))
    , mCarDealer(new CarDealer(nullptr, ui))
    , mInsurance(new Insurance(nullptr, ui))
    , mPortLoading(new PortLoading(nullptr, ui))
    , mDestinationCountry(new DestinationCountry(nullptr, ui))
    , mCostCalculation(new CostCalculation(nullptr, ui))
    , mNetManager(new NetworkManager(this))
{

    ui->setupUi(this);

    connect(mNetManager, &NetworkManager::dataReceived, this, &MainWindow::handleUSDResponse);
    mNetManager->fetchData();

    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->RB_PersUse_Yes);
    buttonGroup->addButton(ui->RB_PersUse_No);

    mAuction->auctionInUsaComboBox();
    mAuction->auctionLabel();
    mAuction->auctionCarDealerFeesLineEdit();
    mAuction->auctionCarBuyPriceLineEdit();

    mCarDealer->dealerLineEdit();


    mPortLoading->portLoadingComboBox();
    mPortLoading->portChargeLineEdit();

    mInsurance->insuranceComboBox();
    mDestinationCountry->destiantionCountryComboBox();
    mCarData->carDataActivate();


    connect(ui->CB_Auction, &QComboBox::currentTextChanged, this, &MainWindow::auctionPlaceUpd);
    connect(ui->CB_USPortLoading, &QComboBox::currentTextChanged, this, &MainWindow::portLoadingPlaceUpd);
    connect(ui->CB_CarInsurance, &QComboBox::currentTextChanged, this, &MainWindow::carInsuranceUpd);
    connect(ui->CB_DestinationCountry, &QComboBox::currentTextChanged, this, &MainWindow::destinationCountryUpd);

    connect(ui->CB_OwnerType, &QComboBox::currentTextChanged, this, &MainWindow::ownerTypeUpd);
    connect(ui->CB_EngineType, &QComboBox::currentTextChanged, this, &MainWindow::engineTypeUpd);

    connect(ui->LE_CarDealerFees, &QLineEdit::textChanged, this, &MainWindow::carDealerFeesUpd);

    connect(ui->RB_PersUse_Yes, &QRadioButton::clicked, this, &MainWindow::personalUseYes);
    connect(ui->RB_PersUse_No, &QRadioButton::clicked, this, &MainWindow::personalUseNo);

    // connect(ui->LE_PortCharges, &QLineEdit::textChanged, this, &MainWindow::portChargesUpd);

    connect(ui->LE_AuctionCarBuyPrice, &QLineEdit::textChanged, this, &MainWindow::auctionCarBuyPriceUpd);
    connect(ui->LE_EngineCapacity, &QLineEdit::textChanged, this, &MainWindow::engineCapacityUpd);
    connect(ui->LE_EnginePower, &QLineEdit::textChanged, this, &MainWindow::enginePowerUpd);
    connect(ui->LE_AgeOfCar, &QLineEdit::textChanged, this, &MainWindow::yearProductUpd);
    connect(ui->LE_VehicleWeight, &QLineEdit:: textChanged, this, &MainWindow::vehicleWeightUpd);

    // quit
    connect(ui->PB_Quit, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);

    // clear Line Edit Fields
    connect(ui->PB_Clear, &QPushButton::clicked, this, &MainWindow::carDataClear);

    // calculation
    connect(ui->PB_Calculate, &QPushButton::clicked, this, &MainWindow::calculation);


}

void MainWindow::handleUSDResponse(const double usd)
{
    mCostCalculation->setEurToUsdCoeff(usd);

    qDebug() << "USD response: " << usd;
}

void MainWindow::handleComboBoxChange(const QString& text)
{
    qDebug() << "Combo Box Value: " << text;
}

void MainWindow::handleLineEditChange(const QString &text)
{
    qDebug() << "Line Edit Value: " << text;
}

void MainWindow::onEngineTypeChanged(const QString &text)
{
    qDebug() << "Selected Engine Type: " << text;
}


// calculation
void MainWindow::calculation()
{
    ui->TE_Calculation->clear();

    mCostCalculation->calculation();
}

// personal use checked
void MainWindow::personalUseYes(bool checked)
{
    ui->RB_PersUse_Yes->setChecked(checked);
    qDebug() << "ui->RB_PersUse_Yes: " << checked;
    qDebug() << "ui->RB_PersUse_No->isChecked(): " << ui->RB_PersUse_No->isChecked();
    qDebug() << "ui->RB_PersUse_Yes->isChecked(): " << ui->RB_PersUse_Yes->isChecked();

}

void MainWindow::personalUseNo(bool checked)
{
    ui->RB_PersUse_No->setChecked(checked);
    qDebug() << "ui->RB_PersUse_No: " << checked;
    qDebug() << "ui->RB_PersUse_No->isChecked(): " << ui->RB_PersUse_No->isChecked();
    qDebug() << "ui->RB_PersUse_Yes->isChecked(): " << ui->RB_PersUse_Yes->isChecked();
}

// update all calculated data
void MainWindow::auctionPlaceUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setUSAuction(data);
}

void MainWindow::portLoadingPlaceUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setUSPort(data);
}

void MainWindow::carInsuranceUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    bool tmpVal = data == "Yes" ? true : false;
    mCostCalculation->setCarInsurance(tmpVal);
}

void MainWindow::destinationCountryUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setDestinationCountry(data);
}

void MainWindow::engineTypeUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setEngineType(data);
}

void MainWindow::ownerTypeUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setOwnerType(data);
}


void MainWindow::carDealerFeesUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setCarDealerFee(data.toUInt());
}

void MainWindow::portChargesUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;

    mCostCalculation->setPortCharges(data.toUInt());

}

void MainWindow::auctionCarBuyPriceUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;
    mCostCalculation->setAuctionCarBuyPrice(data.toUInt());

}

void MainWindow::engineCapacityUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;
    mCostCalculation->setEngineCapacity(data.toUInt());

}

void MainWindow::enginePowerUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;
    mCostCalculation->setEnginePower(data.toUInt());

}

void MainWindow::yearProductUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;
    mCostCalculation->setYearOfProduct(data.toUInt());

}

void MainWindow::vehicleWeightUpd(const QString& data)
{
    qDebug() << Q_FUNC_INFO << " : " << data;
    mCostCalculation->setVehicleWeight(data.toUInt());

}

// Combo Box Reset Fields
void MainWindow::allComboBoxReset()
{
    auctionPlaceReset();
    destinationCountryReset();
    ownerTypeReset();
    portLoadingPlaceReset();
    carInsuranceReset();
    engineTypeReset();
}

void MainWindow::auctionPlaceReset()
{
    ui->CB_Auction->setCurrentText("Manheim Auction");
}
void MainWindow::destinationCountryReset()
{
    ui->CB_DestinationCountry->setCurrentText("Armenia");
}
void MainWindow::ownerTypeReset()
{
    ui->CB_OwnerType->setCurrentText("Individual");
}
void MainWindow::portLoadingPlaceReset()
{
    ui->CB_USPortLoading->setCurrentText("Houston");
}
void MainWindow::carInsuranceReset()
{
    ui->CB_CarInsurance->setCurrentText("No");
}
void MainWindow::engineTypeReset()
{
    ui->CB_EngineType->addItem("Gasoline");
}


// clear LineEdit fields block
void MainWindow::carDataClear()
{
    ui->TE_Calculation->clear();

    allComboBoxReset();

    carDealerFeesClear();
    portChargesClear();
    auctionCarBuyPriceClear();
    engineCapacityClear();
    enginePowerClear();
    yearProductClear();
    vehicleWeightClear();
}

void MainWindow::carDealerFeesClear()
{
    ui->LE_CarDealerFees->setText("0");
}
void MainWindow::portChargesClear()
{
//     ui->LE_PortCharges->setText("0");
}
void MainWindow::auctionCarBuyPriceClear()
{
    ui->LE_AuctionCarBuyPrice->setText("0");
}
void MainWindow::engineCapacityClear()
{
    ui->LE_EngineCapacity->setText("0");
}
void MainWindow::enginePowerClear()
{
    ui->LE_EnginePower->setText("0");
}
void MainWindow::yearProductClear()
{
    ui->LE_AgeOfCar->setText("0");
}
void MainWindow::vehicleWeightClear()
{
    ui->LE_VehicleWeight->setText("0");
}




void engineTypeUpd(const QString& data);
void ownerTypeUpd(const QString& data);

MainWindow::~MainWindow()
{
    delete ui;
    delete mAuction;
    delete mCarData;
    delete mCarDealer;
    delete mInsurance;
    delete mPortLoading;
    delete mDestinationCountry;
    delete mCostCalculation;
    delete mNetManager;
}



