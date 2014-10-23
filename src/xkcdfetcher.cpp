#include "xkcdfetcher.h"

#include <QtCore/QDebug>
#include <QtCore/QJsonDocument>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

static const QUrl latestUrl_{"http://xkcd.com/info.0.json"};
static const QString idAddress_{"http://xkcd.com/%1/info.0.json"};

XKCDFetcher::XKCDFetcher()
    : networkManager_{new QNetworkAccessManager(this)}
{
    connect(networkManager_, &QNetworkAccessManager::finished,
            this, &XKCDFetcher::replyFinished);
}

void XKCDFetcher::getLatest()
{
    networkManager_->get(QNetworkRequest(latestUrl_));
}

void XKCDFetcher::getForId(const int id)
{
    networkManager_->get(QNetworkRequest(QUrl(idAddress_.arg(id))));
}

void XKCDFetcher::replyFinished(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Error in reply" << reply->error();
        return;
    }
    auto jsonDoc = QJsonDocument::fromJson(reply->readAll());
    if (jsonDoc.isObject()) {
        qDebug() << "isObject";
    }
}
