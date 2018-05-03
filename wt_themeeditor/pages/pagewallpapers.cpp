#include "pagewallpapers.h"

bool PageWallPapers::eventFilter(QObject *watched, QEvent *event){
    qDebug() << mTag << "eventFilter";
    if (watched == mWallpapper) {
        qDebug() << mTag << "test1";
        if (event->type() == QEvent::DragEnter) {
            qDebug() << mTag << "test2";
            //[1]当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            qDebug() << mTag << "test3";
            // [2]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            mImagePathWallpaper = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(mImagePathWallpaper); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                image = image.scaled(this->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
                mWallpapper->setPixmap(QPixmap::fromImage(image));
            }

            return true;
        }else{
            qDebug() << mTag << "test4";
        }
    }else if (watched == mKeyguard) {
        qDebug() << mTag << "test1";
        if (event->type() == QEvent::DragEnter) {
            qDebug() << mTag << "test2";
            //[1]当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            qDebug() << mTag << "test3";
            // [2]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            mImagePathKeyguard = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(mImagePathKeyguard); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                image = image.scaled(this->size(),
                                     Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation);
                mKeyguard->setPixmap(QPixmap::fromImage(image));
            }

            return true;
        }else{
            qDebug() << mTag << "test4";
        }
    }

    return false;
}


void PageWallPapers::init(){
    mTag = new QString("PageWallpapers: ");
    mHLayout = new QHBoxLayout();

    mWallpapper = new BaseWallpaperWidget();
    mWallpapper->setFixedSize(280,500);
    mWallpapper->setPixmap(QPixmap(IMG_WALLPAPER));
    mWallpapper->installEventFilter(this);
    mWallpapper->setAcceptDrops(true);

    mKeyguard = new BaseWallpaperWidget();
    mKeyguard->setFixedSize(280,500);
    mKeyguard->setPixmap(QPixmap(IMG_KEYGUARD));
    mKeyguard->installEventFilter(this);
    mKeyguard->setAcceptDrops(true);


    mHLayout->addWidget(mKeyguard);
    mHLayout->addWidget(mWallpapper);
    setLayout(mHLayout);
}


PageWallPapers::PageWallPapers()
{
    init();
}



PageWallPapers::~PageWallPapers(){

}
