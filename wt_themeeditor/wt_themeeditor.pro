#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T15:30:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wt_themeeditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    base/baseiconwidget.cpp \
    configs/config.cpp \
    data/sqlmodule.cpp \
    network/networkmodule.cpp \
    pages/pagegreet.cpp \
    pages/pageicon.cpp \
    pages/pageothers.cpp \
    pages/pagetheme.cpp \
    test/testmainwindow.cpp \
    utils/utiladb.cpp \
    main.cpp \
    mainmenubar.cpp \
    mainstatusbar.cpp \
    maintoolsbar.cpp \
    mainwindow.cpp \
    pagemodule.cpp \
    tabmodule.cpp \
    window/windowicon.cpp \
    window/windowsettings.cpp \
    utils/utilstyle.cpp \
    window/windowemulator.cpp

HEADERS += \
    base/baseiconwidget.h \
    data/sqlmodule.h \
    network/networkmodule.h \
    pages/pagegreet.h \
    pages/pageicon.h \
    pages/pageothers.h \
    pages/pagetheme.h \
    test/testmainwindow.h \
    utils/utiladb.h \
    mainmenubar.h \
    mainstatusbar.h \
    maintoolsbar.h \
    mainwindow.h \
    pagemodule.h \
    tabmodule.h \
    window/windowicon.h \
    window/windowsettings.h \
    window/windowemulator.h

FORMS += \
    testmainwindow.ui

RESOURCES += \
    qsrc/qss.qrc \
    qsrc/main.qrc \
    qsrc/wt_editor_style.qrc

DISTFILES += \
    qsrc/main.rc \
    qsrc/theme_default/fonts/Roboto-Italic.ttf \
    qsrc/theme_default/lockscreens/lockscreen.jpg \
    qsrc/theme_default/wallpapers/launcher.jpg \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_1.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_10.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_11.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_12.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_13.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_14.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_15.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_16.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_17.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_18.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_19.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_2.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_20.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_21.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_22.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_23.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_24.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_25.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_26.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_27.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_28.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_29.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_3.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_30.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_31.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_4.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_5.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_6.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_7.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_8.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_9.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/calendar_bg.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/cmccwm_mobilemusic.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/cn_cj_pe.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/cn_wps_moffice_eng.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_andreader_prein.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_backup.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_browser.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_calculator2.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_calendar.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_camera3.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_contacts_activities_peopleactivity.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_deskclock.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_dialer_dialtactsactivity.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_documentsui.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_email.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_firewall.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_mms.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_mplayer.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_profile.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_quicksearchbox.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_settings_settings.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_settings_settings_tethersettingsactivity.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_android_stk.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_aspire_mm.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_autonavi_cmccmap.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_autonavi_minimap.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_baidu_searchbox.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_caf_fmradio.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_chinamobile_mcloud.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_cmcc_wallet.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_dean_areasearch.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_dianping_v1.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_eg_android_alipaygphone.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_happyelements_androidanimal.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_hmct_filemanager_activity.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_iflytek_cmcc.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_iflytek_inputmethod.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_immomo_momo.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_letv_android_client.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_levect_lockscreen_mobile.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_meitu_meiyancamera.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_moji_mjweather.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_mt_mtxx_mtxx.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_netease_newsreader_activity.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_qiyi_video.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_redstone_ota_ui.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_sdu_didi_psnger.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_sina_weibo.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_ss_android_article_news.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_taobao_taobao.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_tencent_mm.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_tencent_mobileqq.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_tencent_news.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_tencent_qqlive.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_tencent_qqmusic..png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_whty_wicity_china.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_wingtech_compass.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_wingtech_note.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_wingui_safemgr.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_wt_soundrecorder.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_xxx_userservice.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/com_youku_phone.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/ctrip_android_view.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/folder_icon_preview_inner.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/ic_launcher.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/icon_bg.png \
    qsrc/theme_default/launcher_icons/drawable-xxhdpi-v4/org_codeaurora_gallery.png

 CONFIG += c++11
