#include "config.h"

Config::Config()
{
    init();
}

void Config::init(){
    mSettings=new QSettings(CONFIG_PATH,QSettings::IniFormat);
    mSettings->setValue("Author","HuangYabin");
}
