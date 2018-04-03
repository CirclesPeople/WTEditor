#include <QString>
#include <QSettings>
#include <QCoreApplication>

#define CONFIG_PATH "config.ini"

class Config{
public:
    static void initSettings(){
        QSettings settings(CONFIG_PATH,QSettings::IniFormat);
        settings.beginGroup("devinfo");
        if(!settings.contains("author"))
            settings.setValue("author", "Bill Huang");
        if(!settings.contains("organization"))
            settings.setValue("organization", "Wingtech");
        if(!settings.contains("org_domain"))
            settings.setValue("org_domain", "com.wingtech");
        if(!settings.contains("app_name"))
            settings.setValue("app_name", "WT ThemeEditor");
    }

};
