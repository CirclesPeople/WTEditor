#ifndef BASEICONWIDGET_H
#define BASEICONWIDGET_H

#include <QObject>
#include <QLabel>
#include <QWidget>

#define FLAG_SHOW 1
#define FLAG_HIDE 0


class BaseIconWidget : public QLabel
{
    Q_OBJECT

public:
    BaseIconWidget(const QString iconName, const int flag);


private:
    QString mIconName;
    int mFlag;

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
