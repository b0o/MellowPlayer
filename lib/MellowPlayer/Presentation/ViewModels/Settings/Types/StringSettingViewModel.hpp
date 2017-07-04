#pragma once

#include <MellowPlayer/Application/Settings/Setting.hpp>
#include "SettingViewModel.hpp"

BEGIN_MELLOWPLAYER_NAMESPACE(Presentation)

class StringSettingViewModel: public SettingViewModel {
    Q_OBJECT
    Q_PROPERTY(QString value READ getValue WRITE setValue NOTIFY valueChanged)
public:
    StringSettingViewModel(Application::Setting& setting, QObject* parent=nullptr);

    QString getValue() const;
    QString getQmlComponent() override;

public slots:
    void setValue(QString value);

signals:
    void valueChanged();

protected slots:
    void onValueChanged() override;

};

END_MELLOWPLAYER_NAMESPACE