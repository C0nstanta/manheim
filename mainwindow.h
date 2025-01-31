#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "auction.h"
#include "cardealer.h"
#include "insurance.h"
#include "portloading.h"
#include "destinationcountry.h"

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


private:

    Ui::MainWindow *ui;
    Auction* mAuction;
    CarDealer* mCarDealer;
    Insurance* mInsurance;
    PortLoading* mPortLoading;
    DestinationCountry* mDestinationCountry;



};
#endif // MAINWINDOW_H
