#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "app/xylotoyrc.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QObject * xylotoyrc=new XylotoyRc();

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("app", xylotoyrc);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    int returnCode = app.exec();
    return returnCode;
}
