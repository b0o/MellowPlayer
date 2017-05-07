#include <MellowPlayer/UseCases/Logging/LoggingManager.hpp>
#include <MellowPlayer/UseCases/Interfaces/IMainWindow.hpp>
#include <MellowPlayer/UseCases/Interfaces/IQtApplication.hpp>
#include "Mpris2Root.hpp"

USE_MELLOWPLAYER_NAMESPACE(UseCases)
USE_MELLOWPLAYER_NAMESPACE(Infrastructure)

Mpris2Root::Mpris2Root(IMainWindow& window, IQtApplication& qtApp, QObject* parent) :
        QDBusAbstractAdaptor(parent),
        logger(LoggingManager::instance().getLogger("Mpris2Root")),
        window(window),
        qtApp(qtApp) {

}

void Mpris2Root::Raise() {
    window.show();
}

void Mpris2Root::Quit() {
    qtApp.quit();
}

bool Mpris2Root::canRaise() {
    return true;
}

bool Mpris2Root::canQuit() {
    return true;
}

bool Mpris2Root::hasTrackList() {
    return false;
}

bool Mpris2Root::canSetFullscreen() {
    return false;
}

bool Mpris2Root::fullscreen() {
    return false;
}

void Mpris2Root::setFullscreen(bool value) {
    Q_UNUSED(value);
}

QString Mpris2Root::identity() {
    return "MellowPlayer";
}

QString Mpris2Root::desktopEntry() {
    return "mellowplayer";
}

QStringList Mpris2Root::supportedUriSchemes() {
    return QStringList();
}

QStringList Mpris2Root::supportedMimeTypes() {
    return QStringList();
}