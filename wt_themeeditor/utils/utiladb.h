#ifndef UTILADB_H
#define UTILADB_H

#include <QProcess>
#include <QObject>

#define ADB_DEVICES "adb devices"
#define ADB_DEVICES_FLAG 1
#define ADB_SHELL "adb shell"
#define ADB_SHELL_FLAG 2
#define ADB_LOGCAT "adb logcat"
#define ADB_LOGCAT_FLAG 3
#define ADB_PUSH "adb push"
#define ADB_PUSH_FLAG 4
#define ADB_PULL "adb pull"
#define ADB_PULL_FLAG 5
#define ADB_INSTALL "adb install"
#define ADB_INSTALL_FLAG 6
#define ADB_UNINSTALL "adb uninstall"
#define ADB_UNINSTALL_FLAG 7
#define ADB_REBOOT_RECOVERY "adb reboot recovery"
#define ADB_REBOOT_RECOVERY_FLAG 8
#define ADB_REBOOT_FASTBOOT "adb reboot fastboot"
#define ADB_REBOOT_FASTBOOT_FLAG 9
#define ADB_REBOOT_RESET "adb reboot reset"
#define ADB_REBOOT_RESET_FLAG 10
#define ADB_KILL "adb kill-server"
#define ADB_KILL_FLAG 11
#define ADB_SCREENCAP "adb shell screencap -p /sdcard/tmp.png"
#define ADB_SCREENCAP_FLAG 12
#define ADB_BROADCAST "adb shell am broadcast -a com.theme.ACTION_REPLACE_THEME "
#define ADB_BROADCAST_FLAG 13
#define THEME_ADDR "--es theme_addr \"\/sdcard\/wt_themes\""
#define ICON_ADDR "--es theme_addr \"\/sdcard\/wt_themes\/icons\""
#define WALLPAPER_ADDR "--es theme_addr \"\/sdcard\/wt_themes\/wallpapers\""
#define FONT_ADDR "--es theme_addr \"\/sdcard\/wt_themes\/fonts\""


class UtilADB:public QObject
{
    Q_OBJECT
public:
    UtilADB();

    QStringList outputList;

    void initConnects();

public slots:
    void adbDevice();
    void adbKill();
    void adbPush(QString *pathFrom,QString *pathTo);
    void adbPull();
    void adbInstall();
    void adbShell();
    void getADBProcessInfo();
    void enterRecoveryMode();
    void enterFastbootMode();
    void enterFactoryMode();
    void screenShot();

signals:
    void adbProcInfo(const QStringList outputList);

private:
    void readFromProcess(const int flag);
    bool isAdbConnect();

    QProcess *adbProcess;
};

#endif // UTILADB_H
