#ifndef PAGEICON_H
#define PAGEICON_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

#include "window/windowicon.h"
#include "base/baseiconwidget.h"

class PageIcon:public QWidget
{
public:
    PageIcon(QWidget *parent = 0);
    ~PageIcon();

private:
    QVBoxLayout *mVBLayout;
    QGridLayout *mGridLayout;
    QScrollArea *mScrollArea;

    BaseIconWidget *mPhoneIcon;
    BaseIconWidget *mEmailIcon;
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
