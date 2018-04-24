#ifndef BASEICONWIDGET_H
#define BASEICONWIDGET_H

#include <QObject>
#include <QLabel>
#include <QWidget>

#define FLAG_SHOW 1
#define FLAG_HIDE 0

#define ICON_SETTINGS "Settings"
#define ICON_SETTINGS_FLAG 1
#define ICON_CAMERA "Camera"
#define ICON_CAMERA_FLAG 2
#define ICON_GALLERY "Gallery"
#define ICON_GALLERY_FLAG 3
#define ICON_CALENDAR "Calendar"
#define ICON_CALENDAR_FLAG 4
#define ICON_PHONE "Phone"
#define ICON_PHONE_FLAG 5
#define ICON_CONTACTS "Contacts"
#define ICON_CONTACTS_FLAG 6
#define ICON_MESSAGING "Messaging"
#define ICON_MESSAGING_FLAG 7
#define ICON_BROWSER "Browser"
#define ICON_BROWSER_FLAG 8
#define ICON_VIDEOS "Videos"
#define ICON_VIDEOS_FLAG 9
#define ICON_MUSIC "Music"
#define ICON_MUSIC_FLAG 10
#define ICON_CLOCK "Clock"
#define ICON_CLOCK_FLAG 11
#define ICON_EMAIL "Email"
#define ICON_EMAIL_FLAG 11

#define DEFAULT_FLAG 1
#define DEFAULT_M_FLAG 2
#define DEFAULT_H_FLAG 3

#define NEW_FLAG 1
#define NEW_M_FLAG 2
#define NEW_H_FLAG 3

#define ICON_SIZE 120

#define IMG_PHONE ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_phone.png"
#define IMG_EMAIL ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_email.png"
#define IMG_MESSAGING ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_messaging.png"
#define IMG_BROWSER ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_browser.png"
#define IMG_SETTINGS ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_settings.png"
#define IMG_CAMERA ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_camera.png"
#define IMG_GALLERY ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_gallery.png"
#define IMG_MUSIC ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png"
#define IMG_CALENDAR ":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png"

#define icon_d_path "/icon/default"
#define icon_m_path "/icon/middle"
#define icon_h_path "/icon/high"

class BaseIconWidget : public QLabel
{
    Q_OBJECT

public:
    BaseIconWidget(const QString iconName, const int showflag, const int iconflag);
    BaseIconWidget(const QString iconName, const int showflag, const int iconflag, const int typeflag);

    BaseIconWidget *mBaseIconWidget;

    QString mIconName;
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
