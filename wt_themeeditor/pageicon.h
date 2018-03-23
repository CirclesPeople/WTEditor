#ifndef PAGEICON_H
#define PAGEICON_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>

#include "baseiconwidget.h"

class PageIcon:public QWidget
{
public:
    PageIcon(QWidget *parent = 0);
    ~PageIcon();

private:
    QGridLayout *mGridLayout;

    BaseIconWidget *mPhoneIcon;
    BaseIconWidget *mContactsIcon;
    BaseIconWidget *mMessagingIcon;
    BaseIconWidget *mBrowserIcon;
    BaseIconWidget *mSettingsIcon;
    BaseIconWidget *mCameraIcon;
    BaseIconWidget *mGalleryIcon;
    BaseIconWidget *mMusicIcon;

    void init();
};

#endif // PAGEICON_H
