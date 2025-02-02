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
{
    ui->setupUi(this);

    mAuction->auctionComboBox();
    mAuction->auctionLabel();
    mAuction->auctionLineEdit();
    mCarDealer->dealerLineEdit();


    mPortLoading->portLoadingComboBox();
    mPortLoading->portChargeLineEdit();

    mInsurance->insuranceComboBox();
    mDestinationCountry->destiantionCountryComboBox();



    connect(ui->CB_Auction, &QComboBox::currentTextChanged,
            this, &MainWindow::handleComboBoxChange);

    connect(ui->lEditCarDealerFees, &QLineEdit::textChanged,
            this, &MainWindow::handleComboBoxChange);

    connect(ui->lEditBrokerFees, &QLineEdit::textChanged, this, &MainWindow::handleLineEditChange);

    connect(ui->CB_USPortLoading, &QComboBox::currentTextChanged,
            this, &MainWindow::handleComboBoxChange);

    connect(ui->lEditPortCharges, &QLineEdit::textChanged, this, &MainWindow::handleLineEditChange);


    connect(ui->CB_CarInsurance, &QComboBox::currentTextChanged,
            this, &MainWindow::handleComboBoxChange);
    connect(ui->mCBDestinationCountry, &QComboBox::currentTextChanged,
            this, &MainWindow::handleComboBoxChange);
    connect(ui->pushButtonQuit, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);



}



void MainWindow::handleComboBoxChange(const QString& text)
{
    if(text == "Ukraine") {
        connect(mCarData, &CarData::engineTypeChanged, this, &MainWindow::onEngineTypeChanged);
        mCarData->carDataActivate(text);

        qDebug() << "carData activated" << text;
    } else {
        if(mCarData->getCarDataEngineType() != nullptr) {
            mCarData->carDataDeactivate();

            qDebug() << "carData cleared" << text;
        }
    }
}

void MainWindow::handleLineEditChange(const QString &text)
{
    qDebug() << "Line Edit Value: " << text;
}

void MainWindow::onEngineTypeChanged(const QString &text)
{
    qDebug() << "Selected Engine Type: " << text;
}




MainWindow::~MainWindow()
{
    delete ui;
}



