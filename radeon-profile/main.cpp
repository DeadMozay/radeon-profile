#include "radeon_profile.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    qDebug() << "Creating application object";

    QApplication a(argc, argv);
    QTranslator translator;
    QLocale locale;

    if (locale.language() != QLocale::Language::English) {
        if (translator.load(locale, "radeon-profile", ".")
                || translator.load(locale, "radeon-profile", ".", QApplication::applicationDirPath())
                || translator.load(locale, "radeon-profile", ".", "/usr/share/radeon-profile"))

            a.installTranslator(&translator);
        else
            qWarning() << "Translation not found.";
    }

    qDebug() << "Creating radeon_profile";
    radeon_profile w;

    return a.exec();
}
