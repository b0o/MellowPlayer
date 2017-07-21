#pragma once

#include "MellowPlayer/Application/Theme/Theme.hpp"
#include "StreamingServiceMetadata.hpp"
#include <MellowPlayer/Application/Logging/LoggingManager.hpp>
#include <QtCore/QString>
#include <QtGui/QImage>
#include <memory>

namespace MellowPlayer::Application
{
    class StreamingServiceScript;

    class StreamingService : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString author READ getAuthor CONSTANT)
        Q_PROPERTY(QString authorWebsite READ getAuthorWebsite CONSTANT)
        Q_PROPERTY(QString logo READ getLogo CONSTANT)
        Q_PROPERTY(QString name READ getName CONSTANT)
        Q_PROPERTY(QString url READ getUrl CONSTANT)
        Q_PROPERTY(QString version READ getVersion CONSTANT)
        Q_PROPERTY(StreamingServiceScript *script READ getScript CONSTANT)
    public:
        StreamingService(const StreamingServiceMetadata &metadata, const Theme &theme = Theme());
        ~StreamingService();

        bool isValid() const;
        const QString &getAuthor() const;
        const QString &getAuthorWebsite() const;
        QString getLogo() const;
        const QString &getName() const;
        QString getUrl() const;
        const QString &getVersion() const;
        StreamingServiceScript *getScript() const;
        const Theme &getTheme() const;

        QString getPluginDirectory() const;

        void updateTheme(Theme &newTheme);
        void updateScript(const QString &script);

        bool operator==(const StreamingService &rhs) const;
        bool operator!=(const StreamingService &rhs) const;

    signals:
        void scriptChanged();
        void themeChanged();

    private:
        StreamingServiceMetadata metadata;
        Theme theme;
        std::unique_ptr<StreamingServiceScript> script;
    };
}
