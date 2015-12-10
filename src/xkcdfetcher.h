#ifndef XKCDFETCHER_H
#define XKCDFETCHER_H

#include <QtCore/QObject>

class QNetworkAccessManager;
class QNetworkReply;

class XKCDComic;

class XKCDFetcher : public QObject
{
    Q_OBJECT
public:
    XKCDFetcher();

    Q_INVOKABLE void getLatest();
    Q_INVOKABLE void getForId(const int id);

    Q_INVOKABLE XKCDComic *lastFetchedComic() const { return comic_; }

private slots:
    void replyFinished(QNetworkReply *reply);

signals:
    void comicReady();

private:
    QNetworkAccessManager *networkManager_;
    XKCDComic *comic_;
};

#endif // XKCDFETCHER_H
