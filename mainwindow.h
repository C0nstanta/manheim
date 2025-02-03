#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "auction.h"
#include "cardata.h"
#include "cardealer.h"
#include "insurance.h"
#include "portloading.h"
#include "destinationcountry.h"
#include "costcalculation.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void exit();





public slots:
    void handleComboBoxChange(const QString &text);
    void handleLineEditChange(const QString &text);

private slots:
    void onEngineTypeChanged(const QString &text);  // Slot to handle dynamic combobox

private:
    // Calculation
    void calculation();


    // Combo Box updates
    void auctionPlaceUpd(const QString& data);
    void portLoadingPlaceUpd(const QString& data);
    void carInsuranceUpd(const QString& data);
    void destinationCountryUpd(const QString& data);
    void engineTypeUpd(const QString& data);
    void ownerTypeUpd(const QString& data);


    // Line Edit updates
    void carDealerFeesUpd(const QString& data);
    void portChargesUpd(const QString& data);
    void auctionCarBuyPriceUpd(const QString& data);
    void engineCapacityUpd(const QString& data);
    void enginePowerUpd(const QString& data);
    void yearProductUpd(const QString& data);
    void vehicleWeightUpd(const QString& data);

    // Combo Box Reset Fields
    void allComboBoxReset();
    void auctionPlaceReset();
    void destinationCountryReset();
    void ownerTypeReset();
    void portLoadingPlaceReset();
    void carInsuranceReset();
    void engineTypeReset();

    // Line Edit clear fields
    void carDataClear();
    void carDealerFeesClear();
    void portChargesClear();
    void auctionCarBuyPriceClear();
    void engineCapacityClear();
    void enginePowerClear();
    void yearProductClear();
    void vehicleWeightClear();


    Ui::MainWindow *ui;
    Auction* mAuction;
    CarData* mCarData;
    CarDealer* mCarDealer;
    Insurance* mInsurance;
    PortLoading* mPortLoading;
    DestinationCountry* mDestinationCountry;
    CostCalculation* mCostCalculation;



};
#endif // MAINWINDOW_H
