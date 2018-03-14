#ifndef MAINSTATUSBAR_H
#define MAINSTATUSBAR_H

#include <QWidget>
#include <QStatusBar>
#include <QLabel>

class MainStatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit MainStatusBar(QWidget *parent = nullptr);
    void init();

    QLabel *statusLabel;

signals:

public slots:
};

#endif // MAINSTATUSBAR_H
