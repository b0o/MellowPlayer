#include "StreamingServiceWatcher.hpp"
#include "StreamingServiceLoader.hpp"
#include <QtCore/QDir>

using namespace std;
using namespace MellowPlayer::Application;
using namespace MellowPlayer::Infrastructure;

StreamingServiceWatcher::StreamingServiceWatcher()
        : logger(LoggingManager::instance().getLogger("StreamingServiceWatcher"))
{
    connect(&fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &StreamingServiceWatcher::onFileChanged);
}

void StreamingServiceWatcher::watch(StreamingService &serviceToWatch)
{
    const QString pluginDirectory = serviceToWatch.getPluginDirectory();
    const QString themePath = QDir::cleanPath(pluginDirectory + "/" + "theme.json");
    const QString scriptPath = QDir::cleanPath(pluginDirectory + "/" + "integration.js");

    pluginInfos.insert(pluginDirectory, new PluginInfo(serviceToWatch, scriptPath, themePath, this));

    watchPath(themePath);
    watchPath(scriptPath);
}

void StreamingServiceWatcher::watchPath(const QString &path)
{
    LOG_DEBUG(logger, "Watching path: " + path);
    fileSystemWatcher.addPath(path);
}

void StreamingServiceWatcher::onFileChanged(const QString &path)
{
    LOG_DEBUG(logger, "Plugin file changed: " + path);
    QFileInfo fileInfo(path);
    const QString pluginDir = fileInfo.dir().absolutePath();
    const QString name = fileInfo.baseName();
    StreamingService &service = pluginInfos[pluginDir]->service;

    if (name == "integration") {
        service.updateScript(StreamingServiceLoader::readFileContent(path));
    } else {
        Theme theme = StreamingServiceLoader::readTheme(path);
        service.updateTheme(theme);
    }

    fileSystemWatcher.removePath(path);
    fileSystemWatcher.addPath(path);
}
