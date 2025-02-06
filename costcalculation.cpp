#include "costcalculation.h"


CostCalculation::CostCalculation(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}
    , ui(tmpUI)
{
}


void CostCalculation::manheimAuctionFees() {
    mUSAuction = ui->CB_Auction->currentText();
    mUSPort = ui->CB_USPortLoading->currentText();
    mDestinationCountry = ui->CB_DestinationCountry->currentText();
    mAgeOfCar = ui->LE_AgeOfCar->text().toInt();
    mEngineCapacity = ui->LE_EngineCapacity->text().toInt();
    mEngineType = ui->CB_EngineType->currentText();
    mCarDealerFee = ui->LE_CarDealerFees->text().toInt();
    mIsPersonalUse = ui->RB_PersUse_Yes->isChecked();


    if(mUSAuction == "Manheim Auction") {
        AUCTION_FEE = 0.035;
    } else {
        AUCTION_FEE = 0.;
    }

    if(mUSPort == "Houston") {
        TRANSPORT_AUCTION_PORT = 600;
    } else {
        TRANSPORT_AUCTION_PORT = 800;
    }

    if(mDestinationCountry == "Georgia" || mDestinationCountry == "Russia") {
        TRANSPORT_DESTINATION_PORT = 1300;
    } else if(mDestinationCountry == "Ukraine") {
        TRANSPORT_DESTINATION_PORT = 800;
    } else {
        TRANSPORT_DESTINATION_PORT = 1200;
    }

}

void CostCalculation::setEurToUsdCoeff(double usdCoeff)
{
    mEurToUsdCoeff = usdCoeff;
}

void CostCalculation::serPersonalUse(const bool data)
{
    mIsPersonalUse = data;
}

void CostCalculation::calculation()
{

    // update vars
    manheimAuctionFees();

    int totalCost = 0;
    // Auction Purchased price
    totalCost += mAuctionCarBuyPrice;
    QString tmpAuctionPrice = mUSAuction + " purchase price: " + "$" + QString::number(mAuctionCarBuyPrice);
    ui->TE_Calculation->append(tmpAuctionPrice);

    // Auction Fee
    totalCost += int(mAuctionCarBuyPrice * AUCTION_FEE);
    QString tmpAuctionFee = QString::number(int(mAuctionCarBuyPrice * AUCTION_FEE));
    ui->TE_Calculation->append("Auction Fee for " + mUSAuction + " is: $" + tmpAuctionFee);

    // Delivery Fee
    totalCost += TRANSPORT_AUCTION_PORT;
    QString tmpDeliveryFee = QString::number(TRANSPORT_AUCTION_PORT);
    ui->TE_Calculation->append("Delivery to " + mUSPort + ": $" + tmpDeliveryFee);

    //Sending of documents
    totalCost += 250;
    QString tmpDocumentSending = "Sending of documents: $" + QString::number(250);
    ui->TE_Calculation->append(tmpDocumentSending);

    // Delivery to destination port and country
    if(mDestinationCountry == "Russia") {
        totalCost += TRANSPORT_DESTINATION_PORT;
        QString tmpDeliveryToPort = "Delivery to the Georgia: $" + QString::number(TRANSPORT_DESTINATION_PORT);
        ui->TE_Calculation->append(tmpDeliveryToPort);

        totalCost += 400;
        QString tmpUnloading = "Unloading the container and papework: $400";
        ui->TE_Calculation->append(tmpUnloading);

        totalCost += 600;
        QString tmpDeliveryToMoskow = "Delivery from the port to Moscow: $600";
        ui->TE_Calculation->append(tmpDeliveryToMoskow);
    } else if(mDestinationCountry == "Ukraine") {
        totalCost += TRANSPORT_DESTINATION_PORT;
        QString tmpDeliveryToPort = "Delivery to the Klaipeda: $" + QString::number(TRANSPORT_DESTINATION_PORT);
        ui->TE_Calculation->append(tmpDeliveryToPort);

        totalCost += 50;
        QString tmpSublot = "Sublot: $50 ??";
        ui->TE_Calculation->append(tmpSublot);

        totalCost += 350;
        QString tmpExpedition = "Expedition: $350 ??";
        ui->TE_Calculation->append(tmpExpedition);

        totalCost += 800;
        QString tmpDeliveryToKyiv = "Delivery from the port to Kyiv: $800";
        ui->TE_Calculation->append(tmpDeliveryToKyiv);
    }

    // Customs clearance

    if(mDestinationCountry == "Russia") {
        double customsFee = 165.33;
        double tax = 0.;
        double recyclingFee = 0.;

        taxCalculationRussia(tax);
        recyclingFeeCalculationRussia(recyclingFee);

        ui->TE_Calculation->append("Customs Fee: $" + QString::number(int(customsFee)));
        ui->TE_Calculation->append("Tax: $" + QString::number(int(tax)));
        ui->TE_Calculation->append("Recycling Fee: $" + QString::number(int(recyclingFee)));

        totalCost += tax;
        totalCost += recyclingFee;
        totalCost += customsFee;

        ui->TE_Calculation->append("ЭПТС + СБКТС: $" + QString::number(400));
        totalCost += 400;

    } else if(mDestinationCountry == "Ukraine") {
        int tax = 0;
        double exciseTax = 0.;
        int capacityCoeff = 50;
        int VAT = 0;

        taxCalculationUkraine(tax, capacityCoeff, exciseTax, VAT);

        ui->TE_Calculation->append("Tax: $" + QString::number(tax));
        ui->TE_Calculation->append("Exise Tax: $" + QString::number(int(exciseTax)));
        ui->TE_Calculation->append("VAT: $" + QString::number(int(VAT)));

        totalCost += tax;
        totalCost += exciseTax;
        totalCost += VAT;
    }

    totalCost += mCarDealerFee;
    ui->TE_Calculation->append("Dealer Fee: $" + QString::number(mCarDealerFee));

    ui->TE_Calculation->append("-------------------");
    ui->TE_Calculation->append("Total: " + QString::number(int(totalCost)));
}

void CostCalculation::recyclingFeeCalculationRussia(double& recyclingFee) {
    double tmpVal = 0.;
    if(mIsPersonalUse == true) {
        if(mAgeOfCar <= 3 ) {
            tmpVal = (mEngineCapacity * 0.17);
        } else {
            tmpVal = (mEngineCapacity * 0.26);
        }
        recyclingFee = tmpVal;

        return ;
    }

    if(ui->CB_EngineType->currentText() == "Electric") {
        if(mAgeOfCar <= 3 ){
            tmpVal = (mEngineCapacity * 1.63);
        } else {
            tmpVal = (mEngineCapacity * 6.1);
        }
    } else {
        if(mAgeOfCar <= 3 ) {
            if(mEngineCapacity <= 1000) {
                tmpVal = 2.41 * mEngineCapacity;
            } else if(mEngineCapacity > 1000 && mEngineCapacity <= 2000) {
                tmpVal = 8.92 * mEngineCapacity;
            } else if(mEngineCapacity > 2000 && mEngineCapacity <= 3000) {
                tmpVal = 12,98 * mEngineCapacity;
            } else if(mEngineCapacity > 3000 && mEngineCapacity <= 3500) {
                tmpVal = 14.08 * mEngineCapacity;
            } else if(mEngineCapacity > 3500) {
                tmpVal = 22,25 * mEngineCapacity;
            }
        } else {
            if(mEngineCapacity <= 1000) {
                tmpVal = 6.15 * mEngineCapacity;
            } else if(mEngineCapacity > 1000 && mEngineCapacity <= 2000) {
                tmpVal = 15.69 * mEngineCapacity;
            } else if(mEngineCapacity > 2000 && mEngineCapacity <= 3000) {
                tmpVal = 24.01 * mEngineCapacity;
            } else if(mEngineCapacity > 3000 && mEngineCapacity <= 3500) {
                tmpVal = 28.5 * mEngineCapacity;
            } else if(mEngineCapacity > 3500) {
                tmpVal = 35.01 * mEngineCapacity;
            }

        }
    }

    recyclingFee = tmpVal;
}

void CostCalculation::taxCalculationRussia(double& tax)
{
    double percentPrice{0.};
    double engineCCPrice{0.};
    if(mAgeOfCar <= 3 ){
        if(mAuctionCarBuyPrice <= (8500 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.54; //(54%)
            engineCCPrice = mEngineCapacity * (2.5 * mEurToUsdCoeff); // 2.5 Euro per cc
        } else if(mAuctionCarBuyPrice > (8'500 * mEurToUsdCoeff) && mAuctionCarBuyPrice <= (16'700 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.48; //(48%)
            engineCCPrice = mEngineCapacity * (3.5 * mEurToUsdCoeff); // 3.5 Euro per cc
        } else if(mAuctionCarBuyPrice > (16'700 * mEurToUsdCoeff) && mAuctionCarBuyPrice <= (42'300 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.48; //(48%)
            engineCCPrice = mEngineCapacity * (5.5 * mEurToUsdCoeff); // 5.5 Euro per cc
        } else if(mAuctionCarBuyPrice > (42'300 * mEurToUsdCoeff) && mAuctionCarBuyPrice <= (84'500 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.48; //(48%)
            engineCCPrice = mEngineCapacity * (7.5 * mEurToUsdCoeff); // 7.5 Euro per cc
        } else if(mAuctionCarBuyPrice > (84'500 * mEurToUsdCoeff) && mAuctionCarBuyPrice <= (169'000 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.48; //(48%)
            engineCCPrice = mEngineCapacity * (15.0 * mEurToUsdCoeff); // 15.0 Euro per cc
        } else if(mAuctionCarBuyPrice > (169'000 * mEurToUsdCoeff)) {
            percentPrice = mAuctionCarBuyPrice * 0.48; //(48%)
            engineCCPrice = mEngineCapacity * (20.0 * mEurToUsdCoeff); // 20.0 Euro per cc
        }
    } else if(mAgeOfCar > 3 && mAgeOfCar <=5) {
        if(mEngineCapacity <= 1000) {
            engineCCPrice = mEngineCapacity * (1.5 * mEurToUsdCoeff); // 1.5 Euro per cc
        } else if(mEngineCapacity > 1000 && mEngineCapacity <= 1500) {
            engineCCPrice = mEngineCapacity * (1.7 * mEurToUsdCoeff); // 1.7 Euro per cc
        } else if(mEngineCapacity > 1500 && mEngineCapacity <= 1800) {
            engineCCPrice = mEngineCapacity * (2.5 * mEurToUsdCoeff); // 2.5 Euro per cc
        } else if(mEngineCapacity > 1800 && mEngineCapacity <= 2300) {
            engineCCPrice = mEngineCapacity * (2.7 * mEurToUsdCoeff); // 2.7 Euro per cc
        } else if(mEngineCapacity > 2300 && mEngineCapacity <= 3000) {
            engineCCPrice = mEngineCapacity * (3.0 * mEurToUsdCoeff); // 3.0 Euro per cc
        } else if(mEngineCapacity > 3000) {
            engineCCPrice = mEngineCapacity * (3.6 * mEurToUsdCoeff); // 3.6 Euro per cc
        }
    } else if(mAgeOfCar > 5) {
        if(mEngineCapacity <= 1000) {
            engineCCPrice = mEngineCapacity * (3.0 * mEurToUsdCoeff); // 3.0 Euro per cc
        } else if(mEngineCapacity > 1000 && mEngineCapacity <= 1500) {
            engineCCPrice = mEngineCapacity * (3.2 * mEurToUsdCoeff); // 3.2 Euro per cc
        } else if(mEngineCapacity > 1500 && mEngineCapacity <= 1800) {
            engineCCPrice = mEngineCapacity * (3.5 * mEurToUsdCoeff); // 3.5 Euro per cc
        } else if(mEngineCapacity > 1800 && mEngineCapacity <= 2300) {
            engineCCPrice = mEngineCapacity * (4.8 * mEurToUsdCoeff); // 4.8 Euro per cc
        } else if(mEngineCapacity > 2300 && mEngineCapacity <= 3000) {
            engineCCPrice = mEngineCapacity * (5.0 * mEurToUsdCoeff); // 5.0 Euro per cc
        } else if(mEngineCapacity > 3000) {
            engineCCPrice = mEngineCapacity * (5.7 * mEurToUsdCoeff); // 3.6 Euro per cc
        }
    }

    tax = std::max(percentPrice, engineCCPrice);

    qDebug() << "tax: " << tax;
}


void CostCalculation::taxCalculationUkraine(int32_t& tax, int32_t& capacityCoeff, double& exciseTax, int32_t& VAT)
{
    tax = 0.1 * (mAuctionCarBuyPrice + int(mAuctionCarBuyPrice * AUCTION_FEE));

    if(mEngineCapacity > 3000 && mEngineType == "Gasoline") {
        capacityCoeff = 100;
    } else if(mEngineType == "Diesel") {
        capacityCoeff = 75;
    }
    exciseTax = mAgeOfCar * capacityCoeff * (mEngineCapacity / 1000);

    VAT = 0.2 * (mAuctionCarBuyPrice + int(mAuctionCarBuyPrice * AUCTION_FEE));
}

void CostCalculation::setDestinationCountry(const QString& data)
{
    mDestinationCountry = data;
}

void CostCalculation::setUSPort(const QString& data)
{
    mUSPort = data;
}

void CostCalculation::setUSAuction(const QString& data)
{
    mUSAuction = data;
}

void CostCalculation::setEngineType(const QString& data)
{
    mEngineType = data;
}

void CostCalculation::setOwnerType(const QString& data)
{
    mOwnerType = data;
}


void CostCalculation::setAuctionCarBuyPrice(const uint16_t data)
{
    mAuctionCarBuyPrice = data;
}

void CostCalculation::setPortCharges(const uint16_t data)
{
    mPortCharges = data;
}

void CostCalculation::setCarDealerFee(const uint16_t data)
{
    mCarDealerFee = data;
}

void CostCalculation::setEngineCapacity(const uint16_t data)
{
    mEngineCapacity = data;
}

void CostCalculation::setEnginePower(const uint16_t data)
{
    mEnginePower = data;
}

void CostCalculation::setVehicleWeight(const uint16_t data)
{
    mVehicleWeight = data;
}

void CostCalculation::setYearOfProduct(const uint16_t data)
{
    mAgeOfCar = data;
}

void CostCalculation::setCarInsurance(const bool data)
{
    mCarInsurance = data;
}
