#include "costcalculation.h"

CostCalculation::CostCalculation(QWidget *parent, Ui::MainWindow* tmpUI)
    : QMainWindow{parent}
    , ui(tmpUI)
{}


void CostCalculation::manheimAuctionFees() {
    mUSAuction = ui->CB_Auction->currentText();
    mUSPort = ui->CB_USPortLoading->currentText();
    mDestinationCountry = ui->CB_DestinationCountry->currentText();
    mAgeOfCar = ui->LE_AgeOfCar->text().toInt();
    mEngineCapacity = ui->LE_EngineCapacity->text().toInt();
    mEngineType = ui->CB_EngineType->currentText();
    mCarDealerFee = ui->LE_CarDealerFees->text().toInt();


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

void CostCalculation::taxCalculationRussia()
{

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
