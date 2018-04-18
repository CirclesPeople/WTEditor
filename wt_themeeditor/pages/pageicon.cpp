#include "pageicon.h"

#include <QMargins>
#include <QPalette>

void PageIcon::init(){

    mVBLayout = new QVBoxLayout();
    mGridLayout = new QGridLayout();
    mScrollArea = new QScrollArea();

    mPhoneIcon = new BaseIconWidget(QObject::tr(ICON_PHONE),FLAG_HIDE, ICON_PHONE_FLAG);
    connect(mPhoneIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *phoneWindow= new WindowIcon(mPhoneIcon);
        phoneWindow->showIconWindow();
    });

    mContactsIcon = new BaseIconWidget(QObject::tr(ICON_CONTACTS),FLAG_HIDE, ICON_CONTACTS_FLAG);
    connect(mContactsIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *contactsWindow= new WindowIcon(mContactsIcon);
        contactsWindow->showIconWindow();
    });

    mMessagingIcon = new BaseIconWidget(QObject::tr(ICON_MESSAGING),FLAG_HIDE, ICON_MESSAGING_FLAG);
    connect(mMessagingIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *messagingWindow= new WindowIcon(mMessagingIcon);
        messagingWindow->showIconWindow();
    });

    mBrowserIcon = new BaseIconWidget(QObject::tr(ICON_BROWSER),FLAG_HIDE, ICON_BROWSER_FLAG);
    connect(mBrowserIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *browserWindow= new WindowIcon(mBrowserIcon);
        browserWindow->showIconWindow();
    });

    mSettingsIcon = new BaseIconWidget(QObject::tr(ICON_SETTINGS),FLAG_HIDE, ICON_SETTINGS_FLAG);
    connect(mSettingsIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *settingsWindow= new WindowIcon(mSettingsIcon);
        settingsWindow->showIconWindow();
    });

    mCameraIcon = new BaseIconWidget(QObject::tr(ICON_CAMERA),FLAG_HIDE, ICON_CAMERA_FLAG);
    connect(mCameraIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *cameraWindow= new WindowIcon(mCameraIcon);
        cameraWindow->showIconWindow();
    });

    mGalleryIcon = new BaseIconWidget(QObject::tr(ICON_GALLERY),FLAG_HIDE, ICON_GALLERY_FLAG);
    connect(mGalleryIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *galleryWindow= new WindowIcon(mGalleryIcon);
        galleryWindow->showIconWindow();
    });

    mMusicIcon = new BaseIconWidget(QObject::tr(ICON_MUSIC),FLAG_HIDE, ICON_MUSIC_FLAG);
    connect(mMusicIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *musicWindow= new WindowIcon(mMusicIcon);
        musicWindow->showIconWindow();
    });

    mCalendarIcon = new BaseIconWidget(QObject::tr(ICON_CALENDAR),FLAG_HIDE, ICON_CALENDAR_FLAG);
    connect(mCalendarIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *calendarWindow= new WindowIcon(mCalendarIcon);
        calendarWindow->showIconWindow();
    });

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
