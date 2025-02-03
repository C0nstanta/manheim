#ifndef COSTCALCULATION_H
#define COSTCALCULATION_H

#include <QMainWindow>

class CostCalculation : public QMainWindow
{
    Q_OBJECT
public:
    explicit CostCalculation(QWidget *parent = nullptr);

// signals:

    void manheimAuctionFees();


    void setDestinationCountry(const QString& data);
    void setUSPort(const QString& data);
    void setUSAuction(const QString& data);
    void setEngineType(const QString& data);
    void setOwnerType(const QString& data);

    void setAuctionCarBuyPrice(const uint16_t data);
    void setPortCharges(const uint16_t data);
    void setCarDealerFee(const uint16_t data);
    void setEngineCapacity(const uint16_t data);
    void setEnginePower(const uint16_t data);
    void setVehicleWeight(const uint16_t data);
    void setYearOfProduct(const uint16_t data);

    void setCarInsurance(const bool data);

private:
    QString mDestinationCountry{};
    QString mUSPort{};
    QString mUSAuction{};
    QString mEngineType{};
    QString mOwnerType{};


    double AUCTION_FEE{0.};
    uint16_t TRANSPORT_AUCTION_PORT{0};
    uint16_t SENDING_OF_DOCUMENTS{250};

    uint16_t mAuctionCarBuyPrice{0};
    uint16_t mPortCharges{0};
    uint16_t mCarDealerFee{0};
    uint16_t mEngineCapacity{0};
    uint16_t mEnginePower{0};
    uint16_t mVehicleWeight{0};
    uint16_t mYearOfProduct{0};

    bool mCarInsurance{false};
};

#endif // COSTCALCULATION_H
