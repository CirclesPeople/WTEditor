#ifndef BASEICONWIDGET_H
#define BASEICONWIDGET_H

#include <QObject>
#include <QLabel>
#include <QWidget>

class BaseIconWidget : public QLabel
{
    Q_OBJECT

public:
    BaseIconWidget(const QString iconName);

private:
    QString mIconName;

    void init();

signals:
    void onClicked();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // BASEICONWIDGET_H
