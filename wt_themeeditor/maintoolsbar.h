#ifndef MAINTOOLSBAR_H
#define MAINTOOLSBAR_H

#include <QWidget>
#include <QToolBar>

class MainToolsBar : public QToolBar
{
    Q_OBJECT
public:
    explicit MainToolsBar(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINTOOLSBAR_H
