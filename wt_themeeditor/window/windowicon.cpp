#include "windowicon.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QUrl>
#include <QList>
#include <QImage>
#include <QPixmap>
#include <QMimeData>

/* 时间过滤 */
bool WindowIcon::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == newIcon) {
        if (event->type() == QEvent::DragEnter) {
            //[1]当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            // [2]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            pathLittle = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathLittle); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                image = image.scaled(newIcon->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
                newIcon->setPixmap(QPixmap::fromImage(image));
            }

            return true;
        }
    }else if (watched == newIconM) {
        if (event->type() == QEvent::DragEnter) {
            //[1]当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            // [2]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            pathMiddle = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathMiddle); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                image = image.scaled(newIconM->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
                newIconM->setPixmap(QPixmap::fromImage(image));
            }

            return true;
        }
    }else if (watched == newIconH) {
        if (event->type() == QEvent::DragEnter) {
            //[1]当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            // [2]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            pathHigh = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathHigh); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                image = image.scaled(newIconH->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
                newIconH->setPixmap(QPixmap::fromImage(image));
            }

            return true;
        }
    }

    return false;
}

/* 显示窗口 */
void WindowIcon::showIconWindow(){
    show();
}

/* 初始化 */
void WindowIcon::init(){
    setFixedSize(600,400);

    mGridLayout = new QGridLayout();

    //默认图标
    defaultIcon = new BaseIconWidget(QObject::tr("default"), FLAG_HIDE);
    defaultIconM = new BaseIconWidget(QObject::tr("defaultM"), FLAG_HIDE);
    defaultIconH = new BaseIconWidget(QObject::tr("defaultH"), FLAG_HIDE);
    newIcon = new BaseIconWidget(QObject::tr("new"), FLAG_SHOW);
    newIconM = new BaseIconWidget(QObject::tr("newM"), FLAG_SHOW);
    newIconH = new BaseIconWidget(QObject::tr("newH"), FLAG_SHOW);

    //新图标
    newIcon->installEventFilter(this);
    newIcon->setAcceptDrops(true);

    newIconM->installEventFilter(this);
    newIconM->setAcceptDrops(true);

    newIconH->installEventFilter(this);
    newIconH->setAcceptDrops(true);

    //箭头
    arrow =new QLabel();
    arrow->setPixmap(QPixmap(":/qsrc/image/arrow.ico"));
    arrowM =new QLabel();
    arrowM->setPixmap(QPixmap(":/qsrc/image/arrow.ico"));
    arrowH =new QLabel();
    arrowH->setPixmap(QPixmap(":/qsrc/image/arrow.ico"));
    QFont ft;
    ft.setPointSize(16);
    ft.setBold(true);

    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(Qt::black));

    label = new QLabel("480P");
    label->setFont(ft);
    label->setPalette(pa);
    labelM = new QLabel("720P");
    labelM->setFont(ft);
    labelM->setPalette(pa);
    labelH = new QLabel("1080P");
    labelH->setFont(ft);
    labelH->setPalette(pa);

    newIcon->installEventFilter(this);
    newIcon->setAcceptDrops(true);
    newIconM->installEventFilter(this);
    newIconM->setAcceptDrops(true);
    newIconH->installEventFilter(this);
    newIconH->setAcceptDrops(true);

    //初始化
    mGridLayout->addWidget(label,0,0,Qt::AlignCenter);
    mGridLayout->addWidget(labelM,1,0,Qt::AlignCenter);
    mGridLayout->addWidget(labelH,2,0,Qt::AlignCenter);

    mGridLayout->addWidget(defaultIcon,0,1,Qt::AlignCenter);
    mGridLayout->addWidget(defaultIconM,1,1,Qt::AlignCenter);
    mGridLayout->addWidget(defaultIconH,2,1,Qt::AlignCenter);

    mGridLayout->addWidget(arrow,0,2,Qt::AlignCenter);
    mGridLayout->addWidget(arrowM,1,2,Qt::AlignCenter);
    mGridLayout->addWidget(arrowH,2,2,Qt::AlignCenter);

    mGridLayout->addWidget(newIcon,0,3,Qt::AlignCenter);
    mGridLayout->addWidget(newIconM,1,3,Qt::AlignCenter);
    mGridLayout->addWidget(newIconH,2,3,Qt::AlignCenter);

    setLayout(mGridLayout);


}

WindowIcon::WindowIcon(QWidget *parent):QWidget(parent)
{
    init();
}
