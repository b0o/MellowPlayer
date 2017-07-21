#pragma once

#include "SettingViewModel.hpp"
#include <MellowPlayer/Application/Settings/Setting.hpp>
#include <MellowPlayer/Application/TimeLimits.hpp>

namespace MellowPlayer::Presentation
{
    class TimeLimitSettingViewModel : public SettingViewModel
    {
        Q_OBJECT
        Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
        Q_PROPERTY(QStringList values READ getValues CONSTANT)
    public:
        TimeLimitSettingViewModel(Application::Setting &setting, QObject *parent = nullptr);

        QString getValue() const;
        QStringList getValues() const;
        QString getQmlComponent() override;

    signals:
        void valueChanged();

    public slots:
        void setValue(QString value);

    protected slots:
        void onValueChanged() override;

    private:
        void registerEnumTranslation(Application::TimeLimits value, const QString &translation);

        QMap<QString, Application::TimeLimits> stringToEnum;
        QMap<Application::TimeLimits, QString> enumToString;
    };
}
