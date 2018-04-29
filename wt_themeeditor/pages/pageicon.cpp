#include "pageicon.h"

#include <QMargins>
#include <QPalette>

void PageIcon::init(){

    mVBLayout = new QVBoxLayout();
    mGridLayout = new QGridLayout();
    mScrollArea = new QScrollArea();

    mPhoneIcon = new BaseIconWidget(ICON_PHONE, ICON_PHONE_NAME, FLAG_HIDE, ICON_PHONE_FLAG);
    mPhoneIcon->setPixmap(QPixmap(IMG_PHONE).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mPhoneIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *phoneWindow= new WindowIcon(mPhoneIcon);
        phoneWindow->showIconWindow();
    });

    mEmailIcon = new BaseIconWidget(ICON_EMAIL, ICON_EMAIL_NAME, FLAG_HIDE, ICON_EMAIL_FLAG);
    mEmailIcon->setPixmap(QPixmap(IMG_EMAIL).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mEmailIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *emailWindow= new WindowIcon(mEmailIcon);
        emailWindow->showIconWindow();
    });

    mMessagingIcon = new BaseIconWidget(ICON_MESSAGING, ICON_MESSAGING_NAME, FLAG_HIDE, ICON_MESSAGING_FLAG);
    mMessagingIcon->setPixmap(QPixmap(IMG_MESSAGING).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mMessagingIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *messagingWindow= new WindowIcon(mMessagingIcon);
        messagingWindow->showIconWindow();
    });

    mBrowserIcon = new BaseIconWidget(ICON_BROWSER, ICON_BROWSER_NAME,FLAG_HIDE, ICON_BROWSER_FLAG);
    mBrowserIcon->setPixmap(QPixmap(IMG_BROWSER).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mBrowserIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *browserWindow= new WindowIcon(mBrowserIcon);
        browserWindow->showIconWindow();
    });

    mSettingsIcon = new BaseIconWidget(ICON_SETTING, ICON_SETTINGS_NAME, FLAG_HIDE, ICON_SETTINGS_FLAG);
    mSettingsIcon->setPixmap(QPixmap(IMG_SETTINGS).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mSettingsIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *settingsWindow= new WindowIcon(mSettingsIcon);
        settingsWindow->showIconWindow();
    });

    mCameraIcon = new BaseIconWidget(ICON_CAMERA, ICON_CAMERA_NAME, FLAG_HIDE, ICON_CAMERA_FLAG);
    mCameraIcon->setPixmap(QPixmap(IMG_CAMERA).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mCameraIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *cameraWindow= new WindowIcon(mCameraIcon);
        cameraWindow->showIconWindow();
    });

    mGalleryIcon = new BaseIconWidget(ICON_GALLERY, ICON_GALLERY_NAME, FLAG_HIDE, ICON_GALLERY_FLAG);
    mGalleryIcon->setPixmap(QPixmap(IMG_GALLERY).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mGalleryIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *galleryWindow= new WindowIcon(mGalleryIcon);
        galleryWindow->showIconWindow();
    });

    mMusicIcon = new BaseIconWidget(ICON_MUSIC, ICON_MUSIC_NAME, FLAG_HIDE, ICON_MUSIC_FLAG);
    mMusicIcon->setPixmap(QPixmap(IMG_MUSIC).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mMusicIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *musicWindow= new WindowIcon(mMusicIcon);
        musicWindow->showIconWindow();
    });

    mCalendarIcon = new BaseIconWidget(ICON_CALENDAR, ICON_CALENDAR_NAME, FLAG_HIDE, ICON_CALENDAR_FLAG);
    mCalendarIcon->setPixmap(QPixmap(IMG_CALENDAR).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mCalendarIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *calendarWindow= new WindowIcon(mCalendarIcon);
        calendarWindow->showIconWindow();
    });

    mGridLayout->addWidget(mPhoneIcon,0,0,Qt::AlignCenter);
    mGridLayout->addWidget(mEmailIcon,0,1,Qt::AlignCenter);
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
