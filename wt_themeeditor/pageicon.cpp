#include "pageicon.h"

#include <QMargins>
#include <QLabel>
#include <QPalette>
#include <QScrollArea>

PageIcon::PageIcon(QWidget *parent):QWidget(parent)
{
    init();
}

void PageIcon::init(){

    mGridLayout = new QGridLayout();

    mPhoneIcon = new BaseIconWidget(QObject::tr("Phone"));
    mContactsIcon = new BaseIconWidget(QObject::tr("Contacts"));
    mMessagingIcon = new BaseIconWidget(QObject::tr("Messaging"));
    mBrowserIcon = new BaseIconWidget(QObject::tr("Browser"));
    mSettingsIcon = new BaseIconWidget(QObject::tr("Settings"));
    mCameraIcon = new BaseIconWidget(QObject::tr("Cmamera"));
    mGalleryIcon = new BaseIconWidget(QObject::tr("Gallery"));
    mMusicIcon = new BaseIconWidget(QObject::tr("Music"));

    mGridLayout->addWidget(mPhoneIcon,0,0,Qt::AlignCenter);
    mGridLayout->addWidget(mContactsIcon,0,1,Qt::AlignCenter);
    mGridLayout->addWidget(mMessagingIcon,0,2,Qt::AlignCenter);
    mGridLayout->addWidget(mBrowserIcon,0,3,Qt::AlignCenter);

    mGridLayout->addWidget(mSettingsIcon,1,0,Qt::AlignCenter);
    mGridLayout->addWidget(mCameraIcon,1,1,Qt::AlignCenter);
    mGridLayout->addWidget(mGalleryIcon,1,2,Qt::AlignCenter);
    mGridLayout->addWidget(mMusicIcon,1,3,Qt::AlignCenter);

    setLayout(mGridLayout);

}

PageIcon::~PageIcon(){

}
