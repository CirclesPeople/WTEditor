#include "windowicon.h"
#include "utils/utiladb.h"

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
            pathD = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathD); // QImage对I/O优化过, QPixmap对显示优化
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
            pathM = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathM); // QImage对I/O优化过, QPixmap对显示优化
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
            pathH = urls.first().toLocalFile();

            // [3]: 在label上显示拖放的图片
            QImage image(pathH); // QImage对I/O优化过, QPixmap对显示优化
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

void WindowIcon::setIconImg(BaseIconWidget *baseIconWidget, const int iconflag){
    switch(iconflag){
    case ICON_PHONE_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_PHONE).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_EMAIL_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_EMAIL).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_MESSAGING_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_MESSAGING).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_BROWSER_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_BROWSER).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_SETTINGS_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_SETTINGS).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_CAMERA_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_CAMERA).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_GALLERY_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_GALLERY).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    case ICON_CALENDAR_FLAG:
        baseIconWidget->setPixmap(QPixmap(IMG_CALENDAR).scaled(ICON_SIZE,ICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        break;
    }
}

/* delete icons */
void WindowIcon::delImage(BaseIconWidget *baseIconWidget){
    //do nothing;
}

/* apply icons */
void WindowIcon::applyImage(BaseIconWidget *baseIconWidget)
{
    int flag=baseIconWidget->mTypeFlag;
    QString iconname=baseIconWidget->mIconName.append(".png");
    switch(flag)
    {
    case NEW_FLAG:
    {
        QString adbPush_D(ADB_PUSH);
        QString dirIcon_D(ICON_VALUE_ADDR);
        mUtilADB->mkdir(THEME_VALUE_ADDR);
        mUtilADB->mkdir(ICON_VALUE_ADDR);
        mUtilADB->mkdir(dirIcon_D.append(baseIconWidget->mIcon).append(SEPARATOR));
        mUtilADB->mkdir(dirIcon_D.append(NEW_DIR_DEFAULT).append(SEPARATOR));

        QString cmdDefault=adbPush_D.append(pathD).append(" ").append(dirIcon_D).append(iconname);

        mUtilADB->adbPush(cmdDefault);
        mUtilADB->sendBroadcast(ADB_BROADCAST);
        break;
    }
    case NEW_M_FLAG:
    {
        QString adbPush_M(ADB_PUSH);
        QString dirIcon_M(ICON_VALUE_ADDR);
        mUtilADB->mkdir(THEME_VALUE_ADDR);
        mUtilADB->mkdir(ICON_VALUE_ADDR);
        mUtilADB->mkdir(dirIcon_M.append(baseIconWidget->mIcon).append(SEPARATOR));
        mUtilADB->mkdir(dirIcon_M.append(NEW_DIR_MIDDLE).append(SEPARATOR));

        QString cmdMiddle=adbPush_M.append(pathD).append(" ").append(dirIcon_M).append(iconname);

        mUtilADB->adbPush(cmdMiddle);
        mUtilADB->sendBroadcast(ADB_BROADCAST);
        break;
    }
    case NEW_H_FLAG:
    {
        QString adbPush_H(ADB_PUSH);
        QString dirIcon_H(ICON_VALUE_ADDR);
        mUtilADB->mkdir(THEME_VALUE_ADDR);
        mUtilADB->mkdir(ICON_VALUE_ADDR);
        mUtilADB->mkdir(dirIcon_H.append(baseIconWidget->mIcon).append(SEPARATOR));
        mUtilADB->mkdir(dirIcon_H.append(NEW_DIR_HIGH).append(SEPARATOR));

        QString cmdHigh=adbPush_H.append(pathD).append(" ").append(dirIcon_H).append(iconname);

        mUtilADB->adbPush(cmdHigh);
        mUtilADB->sendBroadcast(ADB_BROADCAST);
        break;
    }
    }
}

/* save icons */
void WindowIcon::saveImage(BaseIconWidget *baseIconWidget){
    QSettings settings(CONFIG_PATH,QSettings::IniFormat);
    int res;
    int flag=baseIconWidget->mTypeFlag;
    QString iconname=baseIconWidget->mIconName.append(".png");
    switch(flag){
    case NEW_FLAG:
        qDebug() << "pathD is " << pathD;
        res = copyFile(pathD, settings.value("/dir/current").toString().append("/icon/").append(baseIconWidget->mIcon).append("/default/").append(iconname), true);
        break;

    case NEW_M_FLAG:
        res = copyFile(pathM, settings.value("/dir/current").toString().append("/icon/").append(baseIconWidget->mIcon).append("/middle/").append(iconname), true);
        break;

    case NEW_H_FLAG:
        res = copyFile(pathH, settings.value("/dir/current").toString().append("/icon/").append(baseIconWidget->mIcon).append("/high/").append(iconname), true);
        break;
    }
    qDebug() << "flag is " << flag << "copyFile result is " << res;
}

/* copy files */
int WindowIcon::copyFile(QString fromPath ,QString toPath, bool isCover)
{
    if (fromPath == toPath){
        return REPEATED;
    }
    if (!QFile::exists(fromPath)){
        return NOT_EXIST;
    }

    QDir *createfile = new QDir;
    bool exist = createfile->exists(toPath);
    if (exist){
        if(isCover){
            createfile->remove(toPath);
        }
    }

    qDebug() << fromPath << toPath;
    if(!QFile::copy(fromPath, toPath))
    {
        return SUCCESSFUL;
    }
    return FAILED;
}

int WindowIcon::deleteFile(BaseIconWidget *baseIconWidget)
{
    return 0;
}

int WindowIcon::applyFile(QString filePath){
    return 0;
}

/* 初始化 */
void WindowIcon::init(){

    setFixedSize(600,400);

    mGridLayout = new QGridLayout();

    //默认图标
    defaultIcon = new BaseIconWidget(mBaseIconWidget->mIconName, FLAG_HIDE, mBaseIconWidget->mIconFlag, DEFAULT_FLAG);
    setIconImg(defaultIcon,mBaseIconWidget->mIconFlag);

    defaultIconM = new BaseIconWidget(mBaseIconWidget->mIconName, FLAG_HIDE, mBaseIconWidget->mIconFlag, DEFAULT_M_FLAG);
    setIconImg(defaultIconM,mBaseIconWidget->mIconFlag);

    defaultIconH = new BaseIconWidget(mBaseIconWidget->mIconName, FLAG_HIDE, mBaseIconWidget->mIconFlag, DEFAULT_H_FLAG);
    setIconImg(defaultIconH,mBaseIconWidget->mIconFlag);

    newIcon = new BaseIconWidget(mBaseIconWidget->mIcon, mBaseIconWidget->mIconName, FLAG_SHOW, mBaseIconWidget->mIconFlag, NEW_FLAG);
    connect(newIcon, &BaseIconWidget::signalApply, this, &WindowIcon::applyImage);
    connect(newIcon, &BaseIconWidget::signalSave, this, &WindowIcon::saveImage);
    connect(newIcon, &BaseIconWidget::signalDel, this, &WindowIcon::delImage);

    newIconM = new BaseIconWidget(mBaseIconWidget->mIcon, mBaseIconWidget->mIconName, FLAG_SHOW, mBaseIconWidget->mIconFlag, NEW_M_FLAG);
    connect(newIconM, &BaseIconWidget::signalApply, this, &WindowIcon::applyImage);
    connect(newIconM, &BaseIconWidget::signalSave, this, &WindowIcon::saveImage);
    connect(newIconM, &BaseIconWidget::signalDel, this, &WindowIcon::delImage);

    newIconH = new BaseIconWidget(mBaseIconWidget->mIcon, mBaseIconWidget->mIconName, FLAG_SHOW, mBaseIconWidget->mIconFlag, NEW_H_FLAG);
    connect(newIconH, &BaseIconWidget::signalApply, this, &WindowIcon::applyImage);
    connect(newIconH, &BaseIconWidget::signalSave, this, &WindowIcon::saveImage);
    connect(newIconH, &BaseIconWidget::signalDel, this, &WindowIcon::delImage);

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

WindowIcon::WindowIcon(BaseIconWidget *baseIconWidget, UtilADB *utilADB)
{
    mBaseIconWidget = baseIconWidget;
    mUtilADB = utilADB;
    init();
}
