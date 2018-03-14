#ifndef CONFIG_H
#define CONFIG_H
#define CONFIG_PATH "config.ini"

#include <QSettings>

class Config
{
public:
    Config();

    QSettings *mSettings;

    void init();
};

#endif // CONFIG_H
