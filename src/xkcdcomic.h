#ifndef XKCDCOMIC_H
#define XKCDCOMIC_H

#include <QtCore/QObject>
#include <QtCore/QDate>

class XKCDComic : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title)
    Q_PROPERTY(QString imgSource READ imgSource)
    Q_PROPERTY(QString alt READ alt)
    Q_PROPERTY(QString transcript READ transcript)
    Q_PROPERTY(QDate date READ date)
    Q_PROPERTY(unsigned int num READ num)
public:
    XKCDComic() {} // for qml
    XKCDComic(const QString &title, const QString &img, const QString &alt,
              const QString &transcript, const QDate &date, unsigned int num);
    static XKCDComic *fromJson(const QJsonObject &json);

    QString title() const { return title_; }
    QString imgSource() const { return imgSource_; }
    QString alt() const { return alt_; }
    QString transcript() const { return transcript_; }
    QDate date() const { return date_; }
    unsigned int num() const { return num_; }

private:
    QString title_;
    QString imgSource_;
    QString alt_;
    QString transcript_;
    QDate date_;
    unsigned int num_;
};

#endif // XKCDCOMIC_H
