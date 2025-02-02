#ifndef CARDATA_H
#define CARDATA_H

#include "./ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QFrame>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>

class CarData : public QMainWindow
{
    Q_OBJECT
public:
    CarData(QWidget *parent = nullptr, Ui::MainWindow* tmpUI = nullptr);

    void carDataActivate();
    void carDataDeactivate();
    void engineTypeComboBox();
    void engineCapacityLineEdit();
    void yearOfProductionLineEdit();
    void ownerTypeComboBox();

    // void carDataFrame(const int x, const int y);

    // QFrame* getCarDataFrame();
    QComboBox* getCarDataEngineType();
    QLabel* getLabelEngineType();
    QLineEdit* getLineEditEngineCapacity();
    QLabel* getLabelEngineCapacity();
    QLineEdit* getLineEditYearProduct();
    QLabel* getLabelYearProduct();


signals:
    void engineTypeChanged(const QString &text);

private:
    Ui::MainWindow* ui;

private:
    QFrame* mCarDataFrame;
    QComboBox* mCBEngineType;  // Pointer to the dynamic combo box
    QLabel* mLabelEngineType;
    QLineEdit* mLineEditEngineCapacity;
    QLabel* mLabelEngineCapacity;
    QLineEdit* mLineEditYearProduct;
    QLabel* mLabelYearProduct;


};

#endif // CARDATA_H
