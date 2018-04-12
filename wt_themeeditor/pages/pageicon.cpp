#include "pageicon.h"

#include <QMargins>
#include <QLabel>
#include <QPalette>

void PageIcon::init(){



    mWindowIcon = new WindowIcon();
    mVBLayout = new QVBoxLayout();
    mGridLayout = new QGridLayout();
    mScrollArea = new QScrollArea();

    mPhoneIcon = new BaseIconWidget(QObject::tr("Phone"),FLAG_HIDE);
    connect(mPhoneIcon,&BaseIconWidget::onClicked,mWindowIcon,&WindowIcon::showIconWindow);

    mContactsIcon = new BaseIconWidget(QObject::tr("Contacts"), FLAG_HIDE);
    mMessagingIcon = new BaseIconWidget(QObject::tr("Messaging"), FLAG_HIDE);
    mBrowserIcon = new BaseIconWidget(QObject::tr("Browser"), FLAG_HIDE);
    mSettingsIcon = new BaseIconWidget(QObject::tr("Settings"), FLAG_HIDE);
    mCameraIcon = new BaseIconWidget(QObject::tr("Cmamera"), FLAG_HIDE);
    mGalleryIcon = new BaseIconWidget(QObject::tr("Gallery"), FLAG_HIDE);
    mMusicIcon = new BaseIconWidget(QObject::tr("Music"), FLAG_HIDE);
    mCalendarIcon = new BaseIconWidget(QObject::tr("Calendar"), FLAG_HIDE);

    mGridLayout->addWidget(mPhoneIcon,0,0,Qt::AlignCenter);
    mGridLayout->addWidget(mContactsIcon,0,1,Qt::AlignCenter);
    mGridLayout->addWidget(mMessagingIcon,0,2,Qt::AlignCenter);
    mGridLayout->addWidget(mBrowserIcon,0,3,Qt::AlignCenter);

    mGridLayout->addWidget(mSettingsIcon,1,0,Qt::AlignCenter);
    mGridLayout->addWidget(mCameraIcon,1,1,Qt::AlignCenter);
    mGridLayout->addWidget(mGalleryIcon,1,2,Qt::AlignCenter);
    mGridLayout->addWidget(mMusicIcon,1,3,Qt::AlignCenter);

    mGridLayout->addWidget(mCalendarIcon,2,3,Qt::AlignCenter);

    mScrollArea->setLayout(mGridLayout);
    mVBLayout->addWidget(mScrollArea);
    setLayout(mVBLayout);

}

PageIcon::PageIcon(QWidget *parent):QWidget(parent)
{
    init();
}

PageIcon::~PageIcon(){

}
