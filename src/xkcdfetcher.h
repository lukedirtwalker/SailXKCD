#ifndef XKCDFETCHER_H
#define XKCDFETCHER_H

#include <QtCore/QObject>

class QNetworkAccessManager;
class QNetworkReply;

class XKCDFetcher : public QObject
{
    Q_OBJECT
public:
    XKCDFetcher();

    Q_INVOKABLE void getLatest();
    Q_INVOKABLE void getForId(const int id);

private slots:
    void replyFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager* networkManager_;
};

#endif // XKCDFETCHER_H
