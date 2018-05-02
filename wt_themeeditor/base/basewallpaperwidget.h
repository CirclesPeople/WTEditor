#ifndef BASEWALLPAPERWIDGET_H
#define BASEWALLPAPERWIDGET_H

#include <QLabel>


//flags for icons
#define ICON_SETTING "keyguard"
#define ICON_SETTINGS_NAME "com_wt_keyguard"
#define ICON_SETTINGS_FLAG 1

#define ICON_CAMERA "wallpaper"
#define ICON_CAMERA_NAME "com_wt_wallpaper"
#define ICON_CAMERA_FLAG 2

//images res path
#define IMG_WALLPAPER ":/qsrc/theme_default/wallpapers/com_wt_wallpaper.jpg"
#define IMG_KEYGUARD ":/qsrc/theme_default/keyguards/com_wt_keyguard.jpg"

class BaseWallpaperWidget : public QLabel
{
    Q_OBJECT
public:
    BaseWallpaperWidget();

    QString mImagePath;
    QString *mTag;

signals:
    void signalSave(BaseWallpaperWidget *baseWallpaperWidget);
    void signalApply(BaseWallpaperWidget *baseWallpaperWidget);
    void signalDel(BaseWallpaperWidget *bBaseWallpaperWidget);

protected:
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // BASEWALLPAPERWIDGET_H
