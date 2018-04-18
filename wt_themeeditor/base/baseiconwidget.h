#ifndef BASEICONWIDGET_H
#define BASEICONWIDGET_H

#include <QObject>
#include <QLabel>
#include <QWidget>

#define FLAG_SHOW 1
#define FLAG_HIDE 0

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


class BaseIconWidget : public QLabel
{
    Q_OBJECT

public:
    BaseIconWidget(const QString iconName, const int showflag, const int iconflag);
    BaseIconWidget(const QString iconName, const int showflag, BaseIconWidget *baseIconWidget);

    BaseIconWidget *mBaseIconWidget;

private:
    QString mIconName;
    int isShow;
    int mIconFlag;

    void init();

signals:
    void onClicked();
    void signalSave();
    void signalApply();
    void signalDel();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // BASEICONWIDGET_H
