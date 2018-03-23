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

protected:

};

#endif // BASEICONWIDGET_H
