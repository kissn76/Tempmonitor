#include "tempcontroller.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //https://www.qtcentre.org/threads/67271-Question-on-proper-use-of-QCommandLineOption
    QCommandLineOption i_opt({"i", "intervall"}, "Refresh intervall", "intervall");
    QCommandLineOption l_opt({"l", "logfile"}, "Logfile path", "logfile");
    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(i_opt);
    parser.process(QCoreApplication::arguments());

    int intervall = parser.value("intervall").toInt();

    if (parser.isSet(i_opt) && intervall <= 0)
    {
        qDebug() << "Intervall must be higher then 0!";
        parser.showHelp();
    }

    TempController tc(intervall * 1000);

    return a.exec();
}
