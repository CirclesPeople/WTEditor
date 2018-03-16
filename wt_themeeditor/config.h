#ifndef CONFIG_H
#define CONFIG_H
#define CONFIG_PATH "config.ini"

#include <QSettings>
#include <QObject>

class Config : public QObject
{
public:
    Config();

    QSettings *mSettings;

    void init();
};

#endif // CONFIG_H
