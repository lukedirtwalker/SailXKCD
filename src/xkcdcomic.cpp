#include "xkcdcomic.h"

#include <QtCore/QJsonObject>
#include <QtCore/QVariant>

static const QString titleKey_{"title"};
static const QString imgKey_{"img"};
static const QString altKey_{"alt"};
static const QString transcriptKey_{"transcript"};
static const QString dayKey_{"day"};
static const QString monthKey_{"month"};
static const QString yearKey_{"year"};
static const QString numKey_{"num"};

XKCDComic::XKCDComic(const QString &title, const QString &img,
                     const QString &alt, const QString &transcript,
                     const QDate &date, unsigned int num)
    : title_{title},
      imgSource_{img},
      alt_{alt},
      transcript_{transcript},
      date_{date},
      num_{num}
{}

XKCDComic *XKCDComic::fromJson(const QJsonObject &json)
{
    QString title = json.value(titleKey_).toString();
    QString img = json.value(imgKey_).toString();
    QString alt = json.value(altKey_).toString();
    QString transcript = json.value(transcriptKey_).toString();
    int day = json.value(dayKey_).toString().toInt();
    int month = json.value(monthKey_).toString().toInt();
    int year = json.value(yearKey_).toString().toInt();
    int num = json.value(numKey_).toVariant().toInt();
    return new XKCDComic(title, img, alt, transcript, QDate(year, month, day), num);
}
