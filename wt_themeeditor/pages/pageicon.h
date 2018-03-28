#ifndef PAGEICON_H
#define PAGEICON_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include "base/baseiconwidget.h"
#include "icon/windowicon.h"

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
