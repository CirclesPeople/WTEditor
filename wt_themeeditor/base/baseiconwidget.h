#ifndef BASEICONWIDGET_H
#define BASEICONWIDGET_H

#include <QObject>
#include <QLabel>
#include <QWidget>

//is show context menu
#define FLAG_SHOW 1
#define FLAG_HIDE 0

//flags for icons
#define ICON_SETTING "settings"
#define ICON_SETTINGS_NAME "com_wt_settings"
#define ICON_SETTINGS_FLAG 1

#define ICON_CAMERA "camera"
#define ICON_CAMERA_NAME "com_wt_camera"
#define ICON_CAMERA_FLAG 2

#define ICON_GALLERY "gallery"
#define ICON_GALLERY_NAME "com_wt_gallery"
#define ICON_GALLERY_FLAG 3

#define ICON_CALENDAR "calendar"
#define ICON_CALENDAR_NAME "com_wt_calendar"
#define ICON_CALENDAR_FLAG 4

#define ICON_PHONE "phone"
#define ICON_PHONE_NAME "com_wt_phone"
#define ICON_PHONE_FLAG 5

#define ICON_CONTACTS "contacts"
#define ICON_CONTACTS_NAME "com_wt_contacts"
#define ICON_CONTACTS_FLAG 6

#define ICON_MESSAGING "messaging"
#define ICON_MESSAGING_NAME "com_wt_messaging"
#define ICON_MESSAGING_FLAG 7

#define ICON_BROWSER "browser"
#define ICON_BROWSER_NAME "com_wt_browser"
#define ICON_BROWSER_FLAG 8

#define ICON_VIDEOS "videos"
#define ICON_VIDEOS_NAME "com_wt_videos"
#define ICON_VIDEOS_FLAG 9

#define ICON_MUSIC "music"
#define ICON_MUSIC_NAME "com_wt_music"
#define ICON_MUSIC_FLAG 10

#define ICON_CLOCK "clock"
#define ICON_CLOCK_NAME "com_wt_clock"
#define ICON_CLOCK_FLAG 11

#define ICON_EMAIL "email"
#define ICON_EMAIL_NAME "com_wt_email"
#define ICON_EMAIL_FLAG 12

//flags for default
#define DEFAULT_FLAG 1
#define DEFAULT_M_FLAG 2
#define DEFAULT_H_FLAG 3

//flags for new
#define NEW_FLAG 1
#define NEW_M_FLAG 2
#define NEW_H_FLAG 3

//icon default
#define ICON_SIZE 120

//images res path
#define IMG_SETTINGS ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_settings.png"
#define IMG_CAMERA ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_camera.png"
#define IMG_GALLERY ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_gallery.png"
#define IMG_CALENDAR ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png"
#define IMG_PHONE ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_phone.png"
//#define IMG_CONTACTS ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_contacts.png"
#define IMG_MESSAGING ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_messaging.png"
#define IMG_BROWSER ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_browser.png"
//#define IMG_VIDEOS ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_videos.png"
#define IMG_MUSIC ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png"
//#define IMG_CLOCK ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_clock.png"
#define IMG_EMAIL ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_email.png"

class BaseIconWidget : public QLabel
{
    Q_OBJECT

public:
    BaseIconWidget(const QString icon, const QString iconName, const int showflag, const int iconflag);
    BaseIconWidget(const QString icon, const QString iconName, const int showflag, const int iconflag, const int typeflag);

    BaseIconWidget *mBaseIconWidget;

    QStringList icons;
    QString mIconName;
    QString mIcon;
    int isShow;
    int mIconFlag;
    int saveFlag;
    int mTypeFlag;

    void init();

signals:
    void onClicked();
    void signalSave(BaseIconWidget *baseIconWidget);
    void signalApply(BaseIconWidget *baseIconWidget);
    void signalDel(BaseIconWidget *baseIconWidget);

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // BASEICONWIDGET_H
