#include <QtCore/QCoreApplication>
#include <sailfishapp.h>

#include "xkcdfetcher.h"
#include "xkcdcomic.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("SailXKCD");
    QCoreApplication::setOrganizationDomain("com.sailxkcd.sailxkcd");
    QCoreApplication::setApplicationName("SailXKCD");

    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickWindow::setDefaultAlphaBuffer(true);
    QQuickView *view = SailfishApp::createView();

    view->rootContext()->setContextProperty("xkcdFetcher", new XKCDFetcher);

    qmlRegisterType<XKCDComic>("SailXKCD", 1, 0, "XKCDComic");

    view->setSource(SailfishApp::pathTo("qml/main.qml"));
    view->show();

    return app->exec();
}

