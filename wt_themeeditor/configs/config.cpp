#include <QString>
#include <QSettings>
#include <QCoreApplication>

#define CONFIG_PATH "config.ini"

class Config{
public:
    static void initSettings(){
        QSettings settings(CONFIG_PATH,QSettings::IniFormat);
        if(!settings.contains("/devinfo/author"))
            settings.setValue("/devinfo/author", "Bill Huang");
        if(!settings.contains("/devinfo/organization"))
            settings.setValue("/devinfo/organization", "Wingtech");
        if(!settings.contains("/devinfo/org_domain"))
            settings.setValue("/devinfo/org_domain", "com.wingtech");
        if(!settings.contains("/devinfo/app_name"))
            settings.setValue("/devinfo/app_name", "WT ThemeEditor");
    }

};
