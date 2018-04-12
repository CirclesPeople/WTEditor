#ifndef PAGEICON_H
#define PAGEICON_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include "base/baseiconwidget.h"
#include "window/windowicon.h"

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

class PageIcon:public QWidget
{
public:
    PageIcon(QWidget *parent = 0);
    ~PageIcon();

private:
    WindowIcon *mWindowIcon;

    QVBoxLayout *mVBLayout;
    QGridLayout *mGridLayout;
    QScrollArea *mScrollArea;

    BaseIconWidget *mPhoneIcon;
    BaseIconWidget *mContactsIcon;
    BaseIconWidget *mMessagingIcon;
    BaseIconWidget *mBrowserIcon;
    BaseIconWidget *mSettingsIcon;
    BaseIconWidget *mCameraIcon;
    BaseIconWidget *mGalleryIcon;
    BaseIconWidget *mMusicIcon;
    BaseIconWidget *mCalendarIcon;

    void init();
};

#endif // PAGEICON_H
