#pragma once

#include <QFile>
#include <QIcon>
#include <MellowPlayer/Macros.hpp>

PREDECLARE_MELLOWPLAYER_CLASS(UseCases, IApplicationSettings)

BEGIN_MELLOWPLAYER_NAMESPACE(Presentation)

class IconProvider {
public:
    IconProvider(UseCases::IApplicationSettings& applicationSettings);
    QIcon trayIcon();

    static QIcon windowIcon();
    static QIcon restoreWindow();
    static QIcon play();
    static QIcon pause();
    static QIcon next();
    static QIcon previous();
    static QIcon quit();

private:
    UseCases::IApplicationSettings& applicationSettings;
};

END_MELLOWPLAYER_NAMESPACE