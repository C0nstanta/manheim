#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QMainWindow>

#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>


class NetworkManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit NetworkManager(QWidget *parent = nullptr);

    void fetchData();

private slots:
    void onReplyFinished(QNetworkReply *reply);

signals:
    void dataReceived(const double usd);

private:
    QNetworkAccessManager *manager;
};

#endif // NETWORKMANAGER_H
