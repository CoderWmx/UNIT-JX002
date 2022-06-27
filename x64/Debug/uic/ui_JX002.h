/********************************************************************************
** Form generated from reading UI file 'JX002.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JX002_H
#define UI_JX002_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_JX002Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *BtnCleanTxt;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *BtnOpenDev;
    QPushButton *BtnStop;
    QPushButton *BtnGetPix;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QPushButton *BtnShutter;
    QPushButton *BtnResponseRate;
    QPushButton *BtnSaveDate;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *BtnMax;
    QPushButton *BtnMin;
    QPushButton *BtnCenter;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_8;
    QPushButton *BtnAddL;
    QTableWidget *LtableWidget;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *BtnAddH;
    QTableWidget *HtableWidget;
    QGridLayout *gridLayout_6;
    QLineEdit *HlineEdit;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *BtnDefault;
    QPushButton *BtnRestLList;
    QLineEdit *HHlineEdit;
    QLineEdit *HLlineEdit;
    QLabel *label_7;
    QLineEdit *LLlineEdit;
    QLineEdit *LHlineEdit;
    QLineEdit *LlineEdit;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *BtnRestHList;
    QPushButton *BtnRestAll;
    QPushButton *BtnSave;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Original;
    QGridLayout *gridLayout_5;
    QLabel *LabelEquilibriumState;
    QLabel *LabelLast;
    QLabel *LabelPowerOn;
    QLineEdit *EditINT;
    QLabel *label_15;
    QLineEdit *EditGFID;
    QLabel *label_16;
    QLineEdit *EditGAIN;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *LabelHeatingMachineTime;
    QLabel *label_23;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnGetDate;
    QPushButton *BtnDefault_2;
    QPushButton *BtnParameter;
    QSpacerItem *verticalSpacer_3;
    QCustomPlot *PlotWidget;
    QWidget *tab_4;

    void setupUi(QMainWindow *JX002Class)
    {
        if (JX002Class->objectName().isEmpty())
            JX002Class->setObjectName(QStringLiteral("JX002Class"));
        JX002Class->resize(1718, 1035);
        QIcon icon;
        icon.addFile(QStringLiteral(":/JX002/UNIT.ico"), QSize(), QIcon::Normal, QIcon::Off);
        JX002Class->setWindowIcon(icon);
        JX002Class->setStyleSheet(QLatin1String("/* === Shared === */\n"
"QStackedWidget, QLabel, QPushButton, QRadioButton, QCheckBox,\n"
"QGroupBox,QScrollArea, QStatusBar, QToolButton, QComboBox, QDialog {\n"
"    background-color: #222222;\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"}\n"
"\n"
"/* === QWidget === */\n"
"QWidget:window {\n"
"    background: #222222;\n"
"    color: #BBBBBB;\n"
"    font-family: \"Segoe UI\";\n"
"}\n"
"\n"
"/* === QToolTip === */\n"
"QToolTip {\n"
"    background-color: #000000;\n"
"    border: 2px solid #333333;\n"
"    color: yellow;\n"
"}\n"
"\n"
"/* === QPushButton === */\n"
"QPushButton {\n"
"    border: 1px solid #333333;\n"
"    padding: 4px;\n"
"    min-width: 65px;\n"
"    min-height: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #333333;\n"
"    border-color: #444444;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #111111;\n"
"    border-color: #333333;\n"
"    color: yellow;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* === C"
                        "heckable items === */\n"
"QCheckBox::indicator, QRadioButton::indicator, QTreeView::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    background-color: #111111;\n"
"    border: 1px solid #333333;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QCheckBox::indicator::checked, QRadioButton::indicator::checked, QTreeView::indicator::checked {\n"
"    background-color: qradialgradient(cx:0.5, cy:0.5, fx:0.25, fy:0.15, radius:0.3, stop:0 #BBBBBB, stop:1 #111111);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled, QTreeView::indicator:disabled {\n"
"    background-color: #444444;\n"
"}\n"
"\n"
"QCheckBox::indicator::checked:disabled, QRadioButton::indicator::checked:disabled, QTreeView::indicator::checked:disabled {\n"
"    background-color: qradialgradient(cx:0.5, cy:0.5, fx:0.25, fy:0.15, radius:0.3, stop:0 #BBBBBB, stop:1 #444444);\n"
"}\n"
"\n"
"/* === QComboBox === */\n"
"QComboBox {\n"
"    background-color: black;\n"
"    border: 1px"
                        " solid #333333;\n"
"    color: white;\n"
"    padding:1px 2em 1px 3px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    border-left: 1px solid #333333;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    border: 2px solid #333333;\n"
"    width: 6px;\n"
"    height: 6px;\n"
"    background: #5f5f5f;\n"
"}\n"
"\n"
"/* === QGroupBox === */\n"
"QGroupBox {\n"
"    border: 2px solid #333333;\n"
"    margin-top: 2ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    color: yellow;\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    margin-left: 5px;\n"
"}\n"
"\n"
"/* === QTabWidget === */\n"
"QTabWidget::pane {\n"
"    background: #222222;\n"
"    border: 2px solid #333333;\n"
"}\n"
"\n"
"/* === QTabBar === */\n"
"QTabBar::tab {\n"
"    background: transparent;\n"
"    border: 1px solid #333333;\n"
"    border-bottom: none;\n"
"    color: #BBBBBB;\n"
"    padding-left: 5px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px"
                        ";\n"
"    padding-bottom: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #333333;\n"
"    border: 1px solid #444444;\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #111111;\n"
"    border: 1px solid #333333;\n"
"    border-top: 1px solid yellow;\n"
"    border-bottom: none;\n"
"    color: yellow\n"
"}\n"
"\n"
"/* === QToolBar === */\n"
"QToolBar {\n"
"    background-color: #222222;\n"
"    border: none;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QToolBar:handle {\n"
"    background: #222222;\n"
"    border-left: 1px dotted yellow;\n"
"    color: #BBBBBB;\n"
"}\n"
"\n"
"QToolBar::separator {\n"
"    width: 6px;\n"
"    background-color: #222222;\n"
"}\n"
"\n"
"/* === QToolButton === */\n"
"QToolButton {\n"
"    border: 1px solid #333333;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #333333;\n"
"    border: 1px solid #444444;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] { /* only for MenuButtonPopup */\n"
"    paddin"
                        "g-right: 20px; /* make way for the popup button */\n"
"}\n"
"\n"
"QToolButton::menu-button {\n"
"    border-left: 1px solid #333333;\n"
"    background: transparent;\n"
"    width: 16px;\n"
"}\n"
"\n"
"QToolButton::menu-button:hover {\n"
"    border-left: 1px solid #444444;\n"
"    background: transparent;\n"
"    width: 16px;\n"
"}\n"
"\n"
"QToolButton:checked, QToolButton:pressed {\n"
"    background-color: #111111;\n"
"    color: yellow;\n"
"}\n"
"\n"
"/* === QMenu === */\n"
"QMenu {\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"    color: white;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 2px 25px 2px 20px;\n"
"    border: 1px solid transparent;\n"
"}\n"
"\n"
"QMenu::item:disabled {\n"
"    color: #666666;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    border-color: gray;\n"
"    background: #222222;\n"
"}\n"
"\n"
"QMenu::icon:checked {\n"
"\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background: #222222;\n"
"    margin-left: 10px;\n"
"    ma"
                        "rgin-right: 10px;\n"
"    margin-top: 1px;\n"
"    margin-bottom: 1px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}\n"
"\n"
"/* === QMenuBar === */\n"
"QMenuBar {\n"
"    background-color: black;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:disabled {\n"
"    color: gray;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: #222222;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background: #444444;\n"
"}\n"
" \n"
"/* === QScrollBar:vertical === */\n"
"QScrollBar:vertical {\n"
"    background: #111111;\n"
"    width: 16px;\n"
"    margin: 16px 0 16px 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #555555;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: #444444;\n"
"    height: 16px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: #444444;\n"
""
                        "    height: 16px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:up-arrow:vertical, QScrollBar:down-arrow:vertical {\n"
"    border: 2px solid #333333;\n"
"    width: 6px;\n"
"    height: 6px;\n"
"    background: #5f5f5f;\n"
"}\n"
"\n"
"/* === QScrollBar:horizontal === */\n"
"QScrollBar:horizontal {\n"
"    background: #111111;\n"
"    height: 16px;\n"
"    margin: 0 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #555555;\n"
"    min-width: 16px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    background: #444444;\n"
"    width: 16px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    background: #444444;\n"
"    width: 16px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QS"
                        "crollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar:left-arrow:horizontal, QScrollBar:right-arrow:horizontal {\n"
"    border: 2px solid #333333;\n"
"    width: 6px;\n"
"    height: 6px;\n"
"    background: #5f5f5f;\n"
"}\n"
"\n"
"/* =================== */\n"
"QLineEdit, QListView, QTreeView, QTableView, QAbstractSpinBox {\n"
"    background-color: black;\n"
"    color: #BBBBBB;\n"
"    border: 1px solid #333333;\n"
"}\n"
"\n"
"QAbstractScrollArea, QLineEdit, QTextEdit, QAbstractSpinBox, QComboBox {\n"
"    border-color: #333333;\n"
"    border: 1px solid #333333;\n"
"\n"
"}\n"
"\n"
"/* === QHeaderView === */\n"
"QHeaderView::section {\n"
"    background: #222222;\n"
"    border: 0;\n"
"    color: #BBBBBB;\n"
"    padding: 3px 0 3px 4px;\n"
"}\n"
"\n"
"/* === QListView === */\n"
"QListView::item:hover {\n"
"    background: #333333;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    background: #111111;\n"
"    color: yellow;\n"
"}\n"
"\n"
"/* === QTableView === */\n"
"QTableView:"
                        ":item:hover {\n"
"    background: #333333;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background: #111111;\n"
"    color: yellow;\n"
"}\n"
"\n"
"/* === QTreeView === */\n"
"QTreeView::item {\n"
"    background: black;\n"
"}\n"
"\n"
"QTreeView::item:hover {\n"
"    background: #333333;\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"    background: #111111;\n"
"    color: yellow;\n"
"}\n"
"\n"
"QTreeView::branch {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings {\n"
"\n"
"}\n"
"\n"
"/* === Customizations === */\n"
"QFrame#infoLabel {\n"
"    border: 1px inset #33"
                        "3333;\n"
"}\n"
"\n"
"2.\n"
".QWidget {\n"
"   background-color: beige;\n"
"}\n"
"\n"
"QToolBar {\n"
"    background-color: beige;\n"
"}\n"
"\n"
"QDialog, QFileDialog {\n"
"    background-color: beige;\n"
"}\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"QTabBar, QTabWidget {\n"
"    background-color: beige;\n"
"}\n"
"QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 1px solid darkkhaki;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0,"
                        " y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"/* Nice Windows-XP-style password character. */\n"
"QLineEdit[echoMode=\"2\"] {\n"
"    lineedit-password-character: 9679;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"     background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                       stop:0 #616161, stop: 0.5 #505050,\n"
"                                       stop: 0.6 #434343, stop:1 #656565);\n"
"     color: white;\n"
"     padding-left: 4px;\n"
"     border: 1px solid #6c6c6c;\n"
" }\n"
"\n"
" QHeaderView::section:checked\n"
" {\n"
"     background-color: red;\n"
" }\n"
"\n"
"\n"
"/* We provide a min-wid"
                        "th and min-height for push buttons\n"
"   so that they look elegant regardless of the width of the text. */\n"
"QPushButton {\n"
"    background-color: palegoldenrod;\n"
"    border-width: 2px;\n"
"    border-color: darkkhaki;\n"
"    border-style: solid;\n"
"    border-radius: 5;\n"
"    padding: 3px;\n"
"    min-width: 9ex;\n"
"    min-height: 2.5ex;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: khaki;\n"
"}\n"
"\n"
"/* Increase the padding, so the text is shifted when the button is\n"
"   pressed. */\n"
"QPushButton:pressed {\n"
"    padding-left: 5px;\n"
"    padding-top: 5px;\n"
"    background-color: #d0d67c;\n"
"}\n"
"\n"
"QLabel, QAbstractButton {\n"
"    font: bold;\n"
"}\n"
"\n"
"/* Mark mandatory fields with a brownish color. */\n"
".mandatory {\n"
"    color: brown;\n"
"}\n"
"\n"
"/* Bold text on status bar looks awful. */\n"
"QStatusBar QLabel {\n"
"   font: normal;\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border-width: 1;\n"
"    border-color: darkkhaki;\n"
"    border-style: solid"
                        ";\n"
"    border-radius: 2;\n"
"}\n"
"\n"
"QStackedWidget, QComboBox, QLineEdit, QSpinBox, QTextEdit, QListView, QWebView, QTreeView, QHeaderView {\n"
"    background-color: cornsilk;\n"
"    selection-color: #0a214c;\n"
"    selection-background-color: #C19A6B;\n"
"}\n"
"\n"
"QListView {\n"
"    show-decoration-selected: 1;\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background-color: wheat;\n"
"}\n"
"\n"
"/* We reserve 1 pixel space in padding. When we get the focus,\n"
"   we kill the padding and enlarge the border. This makes the items\n"
"   glow. */\n"
"QLineEdit, QFrame {\n"
"    border-width: 1px;\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border-color: darkkhaki;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* As mentioned above, eliminate the padding and increase the border. */\n"
"QLineEdit:focus, QFrame:focus {\n"
"    border-width: 3px;\n"
"    padding: 0px;\n"
"}\n"
"\n"
"/* A QLabel is a QFrame  */\n"
"QLabel {\n"
"    border: none;\n"
"    padding: 0;\n"
"    background: none;\n"
""
                        "}\n"
"\n"
"/* A QToolTip is a QLabel  */\n"
"QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"    opacity: 200;\n"
"}\n"
"\n"
"/* Nice to have the background color change when hovered. */\n"
"QRadioButton:hover, QCheckBox:hover {\n"
"    background-color: wheat;\n"
"}\n"
"\n"
"/* Force the dialog's buttons to follow the Windows guidelines. */\n"
"QDialogButtonBox {\n"
"    button-layout: 0;\n"
"}\n"
"\n"
"\n"
"3.\n"
"/*\n"
"    Style by evilworks, 2012-2013. pollux@lavabit.com\n"
"    This file is Public Domain.\n"
"*/\n"
"\n"
"/* === Shared === */\n"
"QStackedWidget, QLabel, QPushButton, QRadioButton, QCheckBox,\n"
"QGroupBox, QStatusBar, QToolButton, QComboBox, QDialog, QTabBar {\n"
"    font-family: \"Segoe UI\";\n"
"    background-color: #888;\n"
"    color: #000;\n"
"}\n"
"\n"
"/* === QWidget === */\n"
"QWidget:window {\n"
"    font-family: 'Segoe UI';\n"
"    background-color: #888;\n"
"}\n"
"\n"
"/* === QPushButton === */\n"
"QPushButton {\n"
"    bor"
                        "der: 1px solid #555;\n"
"    padding: 4px;\n"
"    min-width: 65px;\n"
"    min-height: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #999;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #333;\n"
"    border-color: #555;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* === QComboBox === */\n"
"QComboBox {\n"
"    background-color: #AAA;\n"
"    border: 1px solid #555;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    border-left: 1px solid #333333;\n"
"}\n"
"\n"
"/* === QGroupBox === */\n"
"QGroupBox {\n"
"    border: 1px solid #555;\n"
"    margin-top: 2ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    color: black;\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;    \n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"/* === QTabBar === */\n"
"QTabBar::tab {\n"
"    border-bottom: none;\n"
"    color: #000;\n"
" "
                        "   padding: 4px;\n"
"    background-color: #888;\n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #AAA;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #000;\n"
"    color: white;\n"
"}\n"
"\n"
"\n"
"/* === QTabWidget === */\n"
"QTabWidget::pane {\n"
"    background: #888;\n"
"    border: 1px solid #555;\n"
"}\n"
"QTabWidget::tab-bar { \n"
"	alignment: center; \n"
"} \n"
"\n"
"/* === QToolBar === */\n"
"QToolBar {\n"
"    background: #949494;\n"
"    border: none;\n"
"    padding-left: 0px;\n"
"    padding-right: 0px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QToolBar::separator {\n"
"    width: 1px;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"    background-color: #555;\n"
"}\n"
"\n"
"/* === QToolButton === */\n"
"QToolButton {\n"
"    border: 1px solid #666;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #AAA;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] { /* only for MenuButtonPopup */\n"
"    padding-righ"
                        "t: 20px; /* make way for the popup button */\n"
"}\n"
"\n"
"QToolButton::menu-button {\n"
"    border-left: 1px solid #666;\n"
"    background: transparent;\n"
"    width: 16px;\n"
"}\n"
"\n"
"QToolButton::menu-button:hover {\n"
"    border-left: 1px solid #666;\n"
"    background: transparent;\n"
"    width: 16px;\n"
"}\n"
"\n"
"QToolButton:checked, QToolButton:pressed {\n"
"    background-color: #000;\n"
"    border: 1px solid #555;\n"
"    color: white;\n"
"}\n"
"\n"
"/* === QScrollBar:vertical === */\n"
"QScrollBar:vertical {\n"
"    width: 16px;\n"
"    margin: 16px 0 16px 0;\n"
"    background: #333;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #888;\n"
"    min-height: 16px;\n"
"    border-top: 1px solid #666;\n"
"    border-bottom: 1px solid #666;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: #888;\n"
"    height: 16px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: #888;"
                        "\n"
"    height: 16px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"/* === QScrollBar:horizontal === */\n"
"QScrollBar:horizontal {\n"
"    height: 16px;\n"
"    margin: 0 16px 0 16px;\n"
"    background: #333;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #888;\n"
"    min-width: 16px;\n"
"    border-left: 1px solid #666;\n"
"    border-right: 1px solid #666;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    background: #888;\n"
"    width: 16px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    background: #888;\n"
"    width: 16px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"/* === QMenu === */\n"
"QMenu {\n"
"    ba"
                        "ckground-color: black;\n"
"    border: 1px solid gray;\n"
"    color: white;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 2px 25px 2px 20px;\n"
"    border: 1px solid transparent;\n"
"}\n"
"\n"
"QMenu::item:disabled {\n"
"    color: #666666;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    border-color: gray;\n"
"    background: #222222;\n"
"}\n"
"\n"
"QMenu::icon:checked {\n"
"\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background: #222222;\n"
"    margin-left: 10px;\n"
"    margin-right: 10px;\n"
"    margin-top: 1px;\n"
"    margin-bottom: 1px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}\n"
"\n"
"/* === QMenuBar === */\n"
"QMenuBar {\n"
"    background-color: black;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:disabled {\n"
"    color: gray;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: #222222;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    b"
                        "ackground: #444444;\n"
"}\n"
"/* =================== */\n"
"QLineEdit, QListView, QTreeView, QTableView, QAbstractSpinBox {\n"
"    background-color: #AAA;\n"
"    color: #000;\n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"QAbstractScrollArea, QLineEdit, QTextEdit, QAbstractSpinBox, QComboBox {\n"
"    border: 1px solid #555;\n"
"}\n"
"\n"
"/* === QHeaderView === */\n"
"QHeaderView::section {\n"
"    height: 20px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: #666;\n"
"    border: 0;\n"
"    color: #000;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"/* === QListView === */\n"
"QListView::item:hover {\n"
"    background: #AAA;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    background: #333;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"/* === QTableView === */\n"
"QTableView::item:hover {\n"
"    background: #333333;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background: #111111;\n"
"    color: yellow;\n"
"}\n"
"\n"
"/* === QTreeView === */\n"
"QTreeView::item {\n"
"    background: #AAA;\n"
"}\n"
"\n"
"Q"
                        "TreeView::item:hover {\n"
"    background: #CCC;\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"    background: #333;\n"
"    color: #AAA;\n"
"}\n"
"\n"
"QTreeView::branch {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings {\n"
"\n"
"}\n"
"\n"
"QCustomPlot{\n"
"	background: #222222;\n"
"    color: #BBBBBB;\n"
"}\n"
""));
        centralWidget = new QWidget(JX002Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(centralWidget);
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 25, 1, 1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(800, 600));
        label->setMaximumSize(QSize(800, 600));
        label->setStyleSheet(QLatin1String("image: url(:/JX002/UNIT.ico);\n"
"\n"
"border: 1px solid #333333;"));

        verticalLayout_6->addWidget(label);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(800, 16777215));
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(34, 34, 34);\n"
"color: rgb(164, 164, 164);"));

        verticalLayout_6->addWidget(textEdit);

        BtnCleanTxt = new QPushButton(tab);
        BtnCleanTxt->setObjectName(QStringLiteral("BtnCleanTxt"));
        BtnCleanTxt->setMinimumSize(QSize(75, 22));
        BtnCleanTxt->setMaximumSize(QSize(800, 16777215));

        verticalLayout_6->addWidget(BtnCleanTxt);


        horizontalLayout_2->addLayout(verticalLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 25, 10, 10);
        BtnOpenDev = new QPushButton(groupBox);
        BtnOpenDev->setObjectName(QStringLiteral("BtnOpenDev"));

        gridLayout->addWidget(BtnOpenDev, 0, 0, 1, 1);

        BtnStop = new QPushButton(groupBox);
        BtnStop->setObjectName(QStringLiteral("BtnStop"));

        gridLayout->addWidget(BtnStop, 2, 0, 1, 1);

        BtnGetPix = new QPushButton(groupBox);
        BtnGetPix->setObjectName(QStringLiteral("BtnGetPix"));

        gridLayout->addWidget(BtnGetPix, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(10);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(10, 25, 10, 10);
        BtnShutter = new QPushButton(groupBox_3);
        BtnShutter->setObjectName(QStringLiteral("BtnShutter"));

        gridLayout_4->addWidget(BtnShutter, 0, 0, 1, 1);

        BtnResponseRate = new QPushButton(groupBox_3);
        BtnResponseRate->setObjectName(QStringLiteral("BtnResponseRate"));

        gridLayout_4->addWidget(BtnResponseRate, 1, 0, 1, 1);

        BtnSaveDate = new QPushButton(groupBox_3);
        BtnSaveDate->setObjectName(QStringLiteral("BtnSaveDate"));

        gridLayout_4->addWidget(BtnSaveDate, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(10, 25, 10, 10);
        BtnMax = new QPushButton(groupBox_2);
        BtnMax->setObjectName(QStringLiteral("BtnMax"));

        gridLayout_2->addWidget(BtnMax, 0, 0, 1, 1);

        BtnMin = new QPushButton(groupBox_2);
        BtnMin->setObjectName(QStringLiteral("BtnMin"));

        gridLayout_2->addWidget(BtnMin, 1, 0, 1, 1);

        BtnCenter = new QPushButton(groupBox_2);
        BtnCenter->setObjectName(QStringLiteral("BtnCenter"));

        gridLayout_2->addWidget(BtnCenter, 2, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        gridLayout_3->addLayout(verticalLayout_5, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        horizontalLayout_2->setStretch(1, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 20, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, -1, -1);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_10);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_8);

        BtnAddL = new QPushButton(groupBox_4);
        BtnAddL->setObjectName(QStringLiteral("BtnAddL"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/JX002/Res/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnAddL->setIcon(icon1);

        horizontalLayout_3->addWidget(BtnAddL);


        verticalLayout_2->addLayout(horizontalLayout_3);

        LtableWidget = new QTableWidget(groupBox_4);
        if (LtableWidget->columnCount() < 4)
            LtableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        LtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        LtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        LtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        LtableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        LtableWidget->setObjectName(QStringLiteral("LtableWidget"));
        LtableWidget->setMinimumSize(QSize(0, 400));

        verticalLayout_2->addWidget(LtableWidget);


        horizontalLayout_6->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 20, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, -1, -1);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_11);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_12);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_13);

        BtnAddH = new QPushButton(groupBox_5);
        BtnAddH->setObjectName(QStringLiteral("BtnAddH"));
        BtnAddH->setIcon(icon1);

        horizontalLayout_4->addWidget(BtnAddH);


        verticalLayout_3->addLayout(horizontalLayout_4);

        HtableWidget = new QTableWidget(groupBox_5);
        if (HtableWidget->columnCount() < 4)
            HtableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        HtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        HtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        HtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        HtableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        HtableWidget->setObjectName(QStringLiteral("HtableWidget"));
        HtableWidget->setMinimumSize(QSize(0, 400));

        verticalLayout_3->addWidget(HtableWidget);


        horizontalLayout_6->addWidget(groupBox_5);


        gridLayout_7->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        HlineEdit = new QLineEdit(tab_2);
        HlineEdit->setObjectName(QStringLiteral("HlineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HlineEdit->sizePolicy().hasHeightForWidth());
        HlineEdit->setSizePolicy(sizePolicy);
        HlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(HlineEdit, 2, 5, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_6->addWidget(label_6, 2, 0, 1, 2);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_6->addWidget(label_4, 1, 0, 1, 2);

        BtnDefault = new QPushButton(tab_2);
        BtnDefault->setObjectName(QStringLiteral("BtnDefault"));
        BtnDefault->setMinimumSize(QSize(75, 22));

        gridLayout_6->addWidget(BtnDefault, 5, 0, 1, 3);

        BtnRestLList = new QPushButton(tab_2);
        BtnRestLList->setObjectName(QStringLiteral("BtnRestLList"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BtnRestLList->sizePolicy().hasHeightForWidth());
        BtnRestLList->setSizePolicy(sizePolicy1);
        BtnRestLList->setMinimumSize(QSize(75, 22));

        gridLayout_6->addWidget(BtnRestLList, 4, 0, 1, 3);

        HHlineEdit = new QLineEdit(tab_2);
        HHlineEdit->setObjectName(QStringLiteral("HHlineEdit"));
        sizePolicy.setHeightForWidth(HHlineEdit->sizePolicy().hasHeightForWidth());
        HHlineEdit->setSizePolicy(sizePolicy);
        HHlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(HHlineEdit, 1, 5, 1, 1);

        HLlineEdit = new QLineEdit(tab_2);
        HLlineEdit->setObjectName(QStringLiteral("HLlineEdit"));
        sizePolicy.setHeightForWidth(HLlineEdit->sizePolicy().hasHeightForWidth());
        HLlineEdit->setSizePolicy(sizePolicy);
        HLlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(HLlineEdit, 1, 2, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 2, 3, 1, 2);

        LLlineEdit = new QLineEdit(tab_2);
        LLlineEdit->setObjectName(QStringLiteral("LLlineEdit"));
        sizePolicy.setHeightForWidth(LLlineEdit->sizePolicy().hasHeightForWidth());
        LLlineEdit->setSizePolicy(sizePolicy);
        LLlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(LLlineEdit, 0, 2, 1, 1);

        LHlineEdit = new QLineEdit(tab_2);
        LHlineEdit->setObjectName(QStringLiteral("LHlineEdit"));
        sizePolicy.setHeightForWidth(LHlineEdit->sizePolicy().hasHeightForWidth());
        LHlineEdit->setSizePolicy(sizePolicy);
        LHlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(LHlineEdit, 0, 5, 1, 1);

        LlineEdit = new QLineEdit(tab_2);
        LlineEdit->setObjectName(QStringLiteral("LlineEdit"));
        sizePolicy.setHeightForWidth(LlineEdit->sizePolicy().hasHeightForWidth());
        LlineEdit->setSizePolicy(sizePolicy);
        LlineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_6->addWidget(LlineEdit, 2, 2, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_6->addWidget(label_5, 1, 3, 1, 2);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 0, 0, 1, 2);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 0, 3, 1, 2);

        BtnRestHList = new QPushButton(tab_2);
        BtnRestHList->setObjectName(QStringLiteral("BtnRestHList"));
        BtnRestHList->setMinimumSize(QSize(75, 22));

        gridLayout_6->addWidget(BtnRestHList, 4, 3, 1, 3);

        BtnRestAll = new QPushButton(tab_2);
        BtnRestAll->setObjectName(QStringLiteral("BtnRestAll"));
        BtnRestAll->setMinimumSize(QSize(75, 22));

        gridLayout_6->addWidget(BtnRestAll, 5, 3, 1, 3);

        BtnSave = new QPushButton(tab_2);
        BtnSave->setObjectName(QStringLiteral("BtnSave"));
        BtnSave->setMinimumSize(QSize(75, 22));

        gridLayout_6->addWidget(BtnSave, 6, 3, 1, 3);


        gridLayout_7->addLayout(gridLayout_6, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_7 = new QHBoxLayout(tab_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Original = new QLabel(tab_3);
        label_Original->setObjectName(QStringLiteral("label_Original"));
        label_Original->setMinimumSize(QSize(400, 300));
        label_Original->setMaximumSize(QSize(400, 300));
        label_Original->setLayoutDirection(Qt::LeftToRight);
        label_Original->setStyleSheet(QLatin1String("\n"
"border: 1px solid #333333;\n"
"image: url(:/JX002/UNIT.ico);\n"
""));

        horizontalLayout_5->addWidget(label_Original);


        verticalLayout_7->addLayout(horizontalLayout_5);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(2);
        gridLayout_5->setVerticalSpacing(10);
        gridLayout_5->setContentsMargins(10, 10, 10, 10);
        LabelEquilibriumState = new QLabel(tab_3);
        LabelEquilibriumState->setObjectName(QStringLiteral("LabelEquilibriumState"));
        LabelEquilibriumState->setMinimumSize(QSize(0, 22));

        gridLayout_5->addWidget(LabelEquilibriumState, 5, 1, 1, 1);

        LabelLast = new QLabel(tab_3);
        LabelLast->setObjectName(QStringLiteral("LabelLast"));

        gridLayout_5->addWidget(LabelLast, 6, 1, 1, 1);

        LabelPowerOn = new QLabel(tab_3);
        LabelPowerOn->setObjectName(QStringLiteral("LabelPowerOn"));

        gridLayout_5->addWidget(LabelPowerOn, 3, 1, 1, 1);

        EditINT = new QLineEdit(tab_3);
        EditINT->setObjectName(QStringLiteral("EditINT"));
        EditINT->setMinimumSize(QSize(0, 22));

        gridLayout_5->addWidget(EditINT, 0, 1, 1, 1);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);

        EditGFID = new QLineEdit(tab_3);
        EditGFID->setObjectName(QStringLiteral("EditGFID"));
        EditGFID->setMinimumSize(QSize(0, 22));

        gridLayout_5->addWidget(EditGFID, 1, 1, 1, 1);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_5->addWidget(label_16, 2, 0, 1, 1);

        EditGAIN = new QLineEdit(tab_3);
        EditGAIN->setObjectName(QStringLiteral("EditGAIN"));
        EditGAIN->setMinimumSize(QSize(0, 22));

        gridLayout_5->addWidget(EditGAIN, 2, 1, 1, 1);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_5->addWidget(label_19, 4, 0, 1, 1);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_5->addWidget(label_17, 3, 0, 1, 1);

        LabelHeatingMachineTime = new QLabel(tab_3);
        LabelHeatingMachineTime->setObjectName(QStringLiteral("LabelHeatingMachineTime"));

        gridLayout_5->addWidget(LabelHeatingMachineTime, 4, 1, 1, 1);

        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_5->addWidget(label_23, 6, 0, 1, 1);

        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(0, 22));

        gridLayout_5->addWidget(label_21, 5, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BtnGetDate = new QPushButton(tab_3);
        BtnGetDate->setObjectName(QStringLiteral("BtnGetDate"));

        horizontalLayout->addWidget(BtnGetDate);

        BtnDefault_2 = new QPushButton(tab_3);
        BtnDefault_2->setObjectName(QStringLiteral("BtnDefault_2"));

        horizontalLayout->addWidget(BtnDefault_2);

        BtnParameter = new QPushButton(tab_3);
        BtnParameter->setObjectName(QStringLiteral("BtnParameter"));

        horizontalLayout->addWidget(BtnParameter);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        horizontalLayout_7->addLayout(verticalLayout_7);

        PlotWidget = new QCustomPlot(tab_3);
        PlotWidget->setObjectName(QStringLiteral("PlotWidget"));

        horizontalLayout_7->addWidget(PlotWidget);

        horizontalLayout_7->setStretch(1, 1);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_9->addWidget(tabWidget);

        JX002Class->setCentralWidget(centralWidget);
        QWidget::setTabOrder(BtnOpenDev, BtnGetPix);
        QWidget::setTabOrder(BtnGetPix, BtnStop);
        QWidget::setTabOrder(BtnStop, BtnMax);
        QWidget::setTabOrder(BtnMax, BtnMin);
        QWidget::setTabOrder(BtnMin, BtnCenter);
        QWidget::setTabOrder(BtnCenter, BtnShutter);
        QWidget::setTabOrder(BtnShutter, LtableWidget);
        QWidget::setTabOrder(LtableWidget, HtableWidget);

        retranslateUi(JX002Class);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(JX002Class);
    } // setupUi

    void retranslateUi(QMainWindow *JX002Class)
    {
        JX002Class->setWindowTitle(QApplication::translate("JX002Class", "JX002", Q_NULLPTR));
        label->setText(QString());
        BtnCleanTxt->setText(QApplication::translate("JX002Class", "\346\270\205\347\251\272\350\276\223\345\207\272\346\240\217", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("JX002Class", "\346\221\204\345\203\217\345\244\264\345\274\200\345\205\263", Q_NULLPTR));
        BtnOpenDev->setText(QApplication::translate("JX002Class", "\346\211\223\345\274\200\350\256\276\345\244\207", Q_NULLPTR));
        BtnStop->setText(QApplication::translate("JX002Class", "\345\201\234\346\255\242\350\216\267\345\217\226", Q_NULLPTR));
        BtnGetPix->setText(QApplication::translate("JX002Class", "\350\216\267\345\217\226\345\233\276\345\203\217", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("JX002Class", "\350\256\276\345\244\207\346\216\247\345\210\266", Q_NULLPTR));
        BtnShutter->setText(QApplication::translate("JX002Class", "\345\210\207\346\215\242\345\277\253\351\227\250", Q_NULLPTR));
        BtnResponseRate->setText(QApplication::translate("JX002Class", "\350\260\203\350\212\202\345\223\215\345\272\224\347\216\207", Q_NULLPTR));
        BtnSaveDate->setText(QApplication::translate("JX002Class", "\346\225\260\346\215\256\344\277\235\345\255\230\346\210\220\346\226\207\344\273\266", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("JX002Class", "\347\202\271\346\270\251\345\272\246", Q_NULLPTR));
        BtnMax->setText(QApplication::translate("JX002Class", "\346\234\200\351\253\230\346\270\251\345\272\246", Q_NULLPTR));
        BtnMin->setText(QApplication::translate("JX002Class", "\346\234\200\344\275\216\346\270\251\345\272\246", Q_NULLPTR));
        BtnCenter->setText(QApplication::translate("JX002Class", "\344\270\255\345\277\203\346\270\251\345\272\246", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("JX002Class", "\345\233\276\345\203\217\346\216\247\345\210\266", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("JX002Class", "\344\275\216\346\270\251\346\241\243", Q_NULLPTR));
        label_9->setText(QApplication::translate("JX002Class", "\345\272\217\345\217\267", Q_NULLPTR));
        label_10->setText(QApplication::translate("JX002Class", "\346\270\251\345\272\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("JX002Class", "\345\267\256\345\200\274", Q_NULLPTR));
        BtnAddL->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = LtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = LtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = LtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = LtableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("JX002Class", "\351\253\230\346\270\251\346\241\243", Q_NULLPTR));
        label_11->setText(QApplication::translate("JX002Class", "\345\272\217\345\217\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("JX002Class", "\346\270\251\345\272\246", Q_NULLPTR));
        label_13->setText(QApplication::translate("JX002Class", "\345\267\256\345\200\274", Q_NULLPTR));
        BtnAddH->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = HtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = HtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = HtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = HtableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("JX002Class", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        HlineEdit->setText(QString());
        label_6->setText(QApplication::translate("JX002Class", "\344\275\216\346\270\251\346\241\243\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("JX002Class", "\351\253\230\346\270\251\346\241\243\344\275\216\346\270\251\346\256\265TEC\350\241\245\345\201\277\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        BtnDefault->setText(QApplication::translate("JX002Class", "\346\201\242\345\244\215\351\273\230\350\256\244\347\263\273\346\225\260\345\200\274", Q_NULLPTR));
        BtnRestLList->setText(QApplication::translate("JX002Class", "\346\201\242\345\244\215\351\273\230\350\256\244\344\275\216\346\270\251\346\241\243\345\210\227\350\241\250\345\200\274", Q_NULLPTR));
        HHlineEdit->setText(QString());
        HLlineEdit->setText(QString());
        label_7->setText(QApplication::translate("JX002Class", "\351\253\230\346\270\251\346\241\243\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        LlineEdit->setText(QString());
        label_5->setText(QApplication::translate("JX002Class", "\351\253\230\346\270\251\346\241\243\351\253\230\346\270\251\346\256\265TEC\350\241\245\345\201\277\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("JX002Class", "\344\275\216\346\270\251\346\241\243\344\275\216\346\270\251\347\216\257\345\242\203TEC\350\241\245\345\201\277\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("JX002Class", "\344\275\216\346\270\251\346\241\243\351\253\230\346\270\251\347\216\257\345\242\203TEC\350\241\245\345\201\277\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        BtnRestHList->setText(QApplication::translate("JX002Class", "\346\201\242\345\244\215\351\273\230\350\256\244\351\253\230\346\270\251\346\241\243\345\210\227\350\241\250\345\200\274", Q_NULLPTR));
        BtnRestAll->setText(QApplication::translate("JX002Class", "\345\205\250\351\203\250\346\201\242\345\244\215\351\273\230\350\256\244", Q_NULLPTR));
        BtnSave->setText(QApplication::translate("JX002Class", "\344\277\235\345\255\230", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("JX002Class", "\347\201\260\345\272\246\350\275\254\346\270\251\345\272\246", Q_NULLPTR));
        label_Original->setText(QString());
        LabelEquilibriumState->setText(QApplication::translate("JX002Class", "0", Q_NULLPTR));
        LabelLast->setText(QApplication::translate("JX002Class", "0", Q_NULLPTR));
        LabelPowerOn->setText(QApplication::translate("JX002Class", "00\357\274\23200", Q_NULLPTR));
        label_15->setText(QApplication::translate("JX002Class", "GFID", Q_NULLPTR));
        label_16->setText(QApplication::translate("JX002Class", "GAIN", Q_NULLPTR));
        label_14->setText(QApplication::translate("JX002Class", "INT", Q_NULLPTR));
        label_19->setText(QApplication::translate("JX002Class", "\345\267\262\347\203\255\346\234\272\346\227\266\351\227\264", Q_NULLPTR));
        label_17->setText(QApplication::translate("JX002Class", "\346\234\272\350\212\257\345\274\200\346\234\272\346\227\266\351\227\264", Q_NULLPTR));
        LabelHeatingMachineTime->setText(QApplication::translate("JX002Class", "0", Q_NULLPTR));
        label_23->setText(QApplication::translate("JX002Class", "\344\270\212\346\254\241\345\217\202\346\225\260\344\277\235\347\225\231\346\227\266\351\227\264", Q_NULLPTR));
        label_21->setText(QApplication::translate("JX002Class", "\345\271\263\350\241\241\347\212\266\346\200\201", Q_NULLPTR));
        BtnGetDate->setText(QApplication::translate("JX002Class", "\350\216\267\345\217\226\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        BtnDefault_2->setText(QApplication::translate("JX002Class", "\351\273\230\350\256\244\345\217\202\346\225\260", Q_NULLPTR));
        BtnParameter->setText(QApplication::translate("JX002Class", "\344\277\235\345\255\230\345\217\202\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("JX002Class", "\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("JX002Class", "\351\235\236\345\235\207\345\214\200\346\200\247\347\237\253\346\255\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JX002Class: public Ui_JX002Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JX002_H
