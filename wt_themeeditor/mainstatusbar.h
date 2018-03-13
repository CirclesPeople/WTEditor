#ifndef MAINSTATUSBAR_H
#define MAINSTATUSBAR_H

#include <QWidget>
#include <QStatusBar>

class MainStatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit MainStatusBar(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINSTATUSBAR_H
