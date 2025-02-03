#include "costcalculation.h"

CostCalculation::CostCalculation(QWidget *parent)
    : QMainWindow{parent}
{}


void CostCalculation::manheimAuctionFees() {
    if(mUSAuction == "Manheim Auction") {
        AUCTION_FEE = 0.035;
    }

    if(mUSPort == "Houston") {
        TRANSPORT_AUCTION_PORT = 600;
    }


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
    mYearOfProduct = data;
}

void CostCalculation::setCarInsurance(const bool data)
{
    mCarInsurance = data;
}
