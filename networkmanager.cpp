#include "networkmanager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

NetworkManager::NetworkManager(QWidget *parent)
    : QMainWindow{parent}
{
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkManager::onReplyFinished);
}

void NetworkManager::fetchData()
{
    QUrl url("https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/eur.json");
    QNetworkRequest request(url);

    // Optional: Set custom headers
    request.setRawHeader("User-Agent", "Qt HTTP Client");

    manager->get(request);  // Send HTTP GET request
}

void NetworkManager::onReplyFinished(QNetworkReply *reply)
{
    double usd = 1.04;

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Request failed:" << reply->errorString();
    } else {
        QByteArray responseData = reply->readAll();
        // qDebug() << "Response:" << responseData;

        // Parse JSON
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        if(jsonObject.contains("eur") && jsonObject["eur"].isObject()) {
            QJsonObject eurObj = jsonObject["eur"].toObject();
            usd = eurObj["usd"].toDouble();
        }
    }
    // qDebug() << "usd: " << usd;

    emit dataReceived(usd);

    reply->deleteLater();  // Clean up
}
