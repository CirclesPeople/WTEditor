#include "pageicon.h"

#include <QMargins>
#include <QPalette>

void PageIcon::init(){

    mVBLayout = new QVBoxLayout();
    mGridLayout = new QGridLayout();
    mScrollArea = new QScrollArea();

    mPhoneIcon = new BaseIconWidget(QObject::tr(ICON_PHONE),FLAG_HIDE, ICON_PHONE_FLAG);
    mPhoneIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_phone.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mPhoneIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *phoneWindow= new WindowIcon(mPhoneIcon);
        phoneWindow->showIconWindow();
    });

    mEmailIcon = new BaseIconWidget(QObject::tr(ICON_EMAIL),FLAG_HIDE, ICON_EMAIL_FLAG);
    mEmailIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_email.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mEmailIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *emailWindow= new WindowIcon(mEmailIcon);
        emailWindow->showIconWindow();
    });

    mMessagingIcon = new BaseIconWidget(QObject::tr(ICON_MESSAGING),FLAG_HIDE, ICON_MESSAGING_FLAG);
    mMessagingIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_messaging.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mMessagingIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *messagingWindow= new WindowIcon(mMessagingIcon);
        messagingWindow->showIconWindow();
    });

    mBrowserIcon = new BaseIconWidget(QObject::tr(ICON_BROWSER),FLAG_HIDE, ICON_BROWSER_FLAG);
    mBrowserIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_browser.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mBrowserIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *browserWindow= new WindowIcon(mBrowserIcon);
        browserWindow->showIconWindow();
    });

    mSettingsIcon = new BaseIconWidget(QObject::tr(ICON_SETTINGS),FLAG_HIDE, ICON_SETTINGS_FLAG);
    mSettingsIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_settings.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mSettingsIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *settingsWindow= new WindowIcon(mSettingsIcon);
        settingsWindow->showIconWindow();
    });

    mCameraIcon = new BaseIconWidget(QObject::tr(ICON_CAMERA),FLAG_HIDE, ICON_CAMERA_FLAG);
    mCameraIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_camera.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mCameraIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *cameraWindow= new WindowIcon(mCameraIcon);
        cameraWindow->showIconWindow();
    });

    mGalleryIcon = new BaseIconWidget(QObject::tr(ICON_GALLERY),FLAG_HIDE, ICON_GALLERY_FLAG);
    mGalleryIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_gallery.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mGalleryIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *galleryWindow= new WindowIcon(mGalleryIcon);
        galleryWindow->showIconWindow();
    });

    mMusicIcon = new BaseIconWidget(QObject::tr(ICON_MUSIC),FLAG_HIDE, ICON_MUSIC_FLAG);
    mMusicIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    connect(mMusicIcon,&BaseIconWidget::onClicked,[=](){
        WindowIcon *musicWindow= new WindowIcon(mMusicIcon);
        musicWindow->showIconWindow();
    });

    mCalendarIcon = new BaseIconWidget(QObject::tr(ICON_CALENDAR),FLAG_HIDE, ICON_CALENDAR_FLAG);
    mCalendarIcon->setPixmap(QPixmap(":/qsrc/theme_default/launcher_icons/drawable-dpi/com_wt_music.png").scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
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
