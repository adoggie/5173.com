/********************************************************************************
** Form generated from reading UI file 'upx.ui'
**
** Created: Thu Mar 25 10:58:50 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPX_H
#define UI_UPX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_upxClass
{
public:
    QAction *action;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listHostGroup;
    QListWidget *listHosts;
    QPushButton *btnAddHostGroup;
    QPushButton *btnAddHost;
    QPushButton *btnUpdateHostGroup;
    QLabel *label_2;
    QLineEdit *edtHostAddr1;
    QLineEdit *edtHostAddr2;
    QLabel *label_3;
    QPushButton *btnDelHost;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *edtHostGrpName;
    QLabel *label_6;
    QPushButton *btnDelHostGroup;
    QPushButton *btnRebootHost;
    QWidget *tab_3;
    QPushButton *btnCalcDigest;
    QLabel *label_7;
    QLineEdit *edtGameName;
    QLabel *label_8;
    QLineEdit *edtLocalPath;
    QPushButton *btnAddGame;
    QPushButton *btnUpdateGame;
    QPushButton *btnDelGame;
    QPushButton *btnSelectPath;
    QLabel *label_9;
    QLineEdit *edtRemotePath;
    QTableWidget *listGames;
    QWidget *tab_2;
    QLabel *label_10;
    QPushButton *btnRefresh;
    QPushButton *btnGameAddHost;
    QPushButton *btnGameDelHost;
    QPushButton *btnStopGame;
    QPushButton *btnStartGame;
    QPushButton *btnFileDiffer;
    QPushButton *btnFileSync;
    QCheckBox *cbxCheck;
    QTreeWidget *treeGames;
    QWidget *tab_4;
    QLabel *label;
    QLineEdit *edtCommPort;
    QPushButton *btnSettingsSave;
    QWidget *widget;
    QTextEdit *txtLogMessage;
    QPushButton *btnSaveToFile;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *upxClass)
    {
        if (upxClass->objectName().isEmpty())
            upxClass->setObjectName(QString::fromUtf8("upxClass"));
        upxClass->resize(566, 362);
        action = new QAction(upxClass);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(upxClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 4, 565, 317));
        tabWidget->setSizeIncrement(QSize(23, 23));
        QFont font;
        font.setPointSize(9);
        tabWidget->setFont(font);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listHostGroup = new QListWidget(tab);
        listHostGroup->setObjectName(QString::fromUtf8("listHostGroup"));
        listHostGroup->setGeometry(QRect(10, 32, 185, 191));
        listHosts = new QListWidget(tab);
        listHosts->setObjectName(QString::fromUtf8("listHosts"));
        listHosts->setGeometry(QRect(208, 32, 325, 192));
        listHosts->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listHosts->setSelectionBehavior(QAbstractItemView::SelectRows);
        listHosts->setModelColumn(0);
        btnAddHostGroup = new QPushButton(tab);
        btnAddHostGroup->setObjectName(QString::fromUtf8("btnAddHostGroup"));
        btnAddHostGroup->setGeometry(QRect(12, 260, 60, 23));
        btnAddHostGroup->setFlat(false);
        btnAddHost = new QPushButton(tab);
        btnAddHost->setObjectName(QString::fromUtf8("btnAddHost"));
        btnAddHost->setGeometry(QRect(408, 260, 60, 23));
        btnUpdateHostGroup = new QPushButton(tab);
        btnUpdateHostGroup->setObjectName(QString::fromUtf8("btnUpdateHostGroup"));
        btnUpdateHostGroup->setGeometry(QRect(76, 260, 60, 23));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(224, 236, 54, 12));
        edtHostAddr1 = new QLineEdit(tab);
        edtHostAddr1->setObjectName(QString::fromUtf8("edtHostAddr1"));
        edtHostAddr1->setGeometry(QRect(260, 230, 113, 20));
        edtHostAddr2 = new QLineEdit(tab);
        edtHostAddr2->setObjectName(QString::fromUtf8("edtHostAddr2"));
        edtHostAddr2->setGeometry(QRect(420, 230, 113, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(384, 236, 54, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Narrow"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        btnDelHost = new QPushButton(tab);
        btnDelHost->setObjectName(QString::fromUtf8("btnDelHost"));
        btnDelHost->setGeometry(QRect(472, 260, 60, 23));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 16, 54, 12));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 255);"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(204, 16, 54, 12));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        edtHostGrpName = new QLineEdit(tab);
        edtHostGrpName->setObjectName(QString::fromUtf8("edtHostGrpName"));
        edtHostGrpName->setGeometry(QRect(44, 232, 145, 20));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(12, 236, 54, 12));
        btnDelHostGroup = new QPushButton(tab);
        btnDelHostGroup->setObjectName(QString::fromUtf8("btnDelHostGroup"));
        btnDelHostGroup->setGeometry(QRect(140, 260, 60, 23));
        btnRebootHost = new QPushButton(tab);
        btnRebootHost->setObjectName(QString::fromUtf8("btnRebootHost"));
        btnRebootHost->setGeometry(QRect(470, 8, 65, 23));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        btnCalcDigest = new QPushButton(tab_3);
        btnCalcDigest->setObjectName(QString::fromUtf8("btnCalcDigest"));
        btnCalcDigest->setGeometry(QRect(280, 260, 75, 23));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(4, 208, 54, 12));
        edtGameName = new QLineEdit(tab_3);
        edtGameName->setObjectName(QString::fromUtf8("edtGameName"));
        edtGameName->setGeometry(QRect(68, 204, 113, 20));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 208, 73, 16));
        label_8->setScaledContents(false);
        edtLocalPath = new QLineEdit(tab_3);
        edtLocalPath->setObjectName(QString::fromUtf8("edtLocalPath"));
        edtLocalPath->setGeometry(QRect(280, 204, 233, 20));
        btnAddGame = new QPushButton(tab_3);
        btnAddGame->setObjectName(QString::fromUtf8("btnAddGame"));
        btnAddGame->setGeometry(QRect(8, 260, 75, 23));
        btnUpdateGame = new QPushButton(tab_3);
        btnUpdateGame->setObjectName(QString::fromUtf8("btnUpdateGame"));
        btnUpdateGame->setGeometry(QRect(88, 260, 75, 23));
        btnDelGame = new QPushButton(tab_3);
        btnDelGame->setObjectName(QString::fromUtf8("btnDelGame"));
        btnDelGame->setGeometry(QRect(172, 260, 75, 23));
        btnSelectPath = new QPushButton(tab_3);
        btnSelectPath->setObjectName(QString::fromUtf8("btnSelectPath"));
        btnSelectPath->setGeometry(QRect(516, 200, 25, 23));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 236, 73, 16));
        label_9->setScaledContents(false);
        edtRemotePath = new QLineEdit(tab_3);
        edtRemotePath->setObjectName(QString::fromUtf8("edtRemotePath"));
        edtRemotePath->setGeometry(QRect(280, 232, 233, 20));
        listGames = new QTableWidget(tab_3);
        if (listGames->columnCount() < 4)
            listGames->setColumnCount(4);
        listGames->setObjectName(QString::fromUtf8("listGames"));
        listGames->setGeometry(QRect(8, 4, 545, 192));
        listGames->setStyleSheet(QString::fromUtf8(""));
        listGames->setSelectionBehavior(QAbstractItemView::SelectRows);
        listGames->setShowGrid(true);
        listGames->setCornerButtonEnabled(true);
        listGames->setRowCount(0);
        listGames->setColumnCount(4);
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(12, 4, 54, 12));
        btnRefresh = new QPushButton(tab_2);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setGeometry(QRect(288, 16, 269, 69));
        btnGameAddHost = new QPushButton(tab_2);
        btnGameAddHost->setObjectName(QString::fromUtf8("btnGameAddHost"));
        btnGameAddHost->setGeometry(QRect(284, 92, 145, 41));
        btnGameDelHost = new QPushButton(tab_2);
        btnGameDelHost->setObjectName(QString::fromUtf8("btnGameDelHost"));
        btnGameDelHost->setGeometry(QRect(436, 92, 117, 41));
        btnStopGame = new QPushButton(tab_2);
        btnStopGame->setObjectName(QString::fromUtf8("btnStopGame"));
        btnStopGame->setGeometry(QRect(284, 136, 145, 37));
        btnStartGame = new QPushButton(tab_2);
        btnStartGame->setObjectName(QString::fromUtf8("btnStartGame"));
        btnStartGame->setGeometry(QRect(436, 136, 117, 37));
        btnFileDiffer = new QPushButton(tab_2);
        btnFileDiffer->setObjectName(QString::fromUtf8("btnFileDiffer"));
        btnFileDiffer->setGeometry(QRect(284, 176, 145, 41));
        btnFileSync = new QPushButton(tab_2);
        btnFileSync->setObjectName(QString::fromUtf8("btnFileSync"));
        btnFileSync->setGeometry(QRect(284, 220, 145, 57));
        cbxCheck = new QCheckBox(tab_2);
        cbxCheck->setObjectName(QString::fromUtf8("cbxCheck"));
        cbxCheck->setGeometry(QRect(432, 260, 117, 17));
        treeGames = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeGames->setHeaderItem(__qtreewidgetitem);
        treeGames->setObjectName(QString::fromUtf8("treeGames"));
        treeGames->setGeometry(QRect(8, 20, 269, 261));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(28, 40, 54, 12));
        edtCommPort = new QLineEdit(tab_4);
        edtCommPort->setObjectName(QString::fromUtf8("edtCommPort"));
        edtCommPort->setGeometry(QRect(96, 36, 113, 20));
        btnSettingsSave = new QPushButton(tab_4);
        btnSettingsSave->setObjectName(QString::fromUtf8("btnSettingsSave"));
        btnSettingsSave->setGeometry(QRect(28, 84, 75, 23));
        tabWidget->addTab(tab_4, QString());
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        txtLogMessage = new QTextEdit(widget);
        txtLogMessage->setObjectName(QString::fromUtf8("txtLogMessage"));
        txtLogMessage->setGeometry(QRect(8, 8, 541, 237));
        btnSaveToFile = new QPushButton(widget);
        btnSaveToFile->setObjectName(QString::fromUtf8("btnSaveToFile"));
        btnSaveToFile->setGeometry(QRect(12, 252, 75, 23));
        tabWidget->addTab(widget, QString());
        upxClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(upxClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 566, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        upxClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(upxClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        upxClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(upxClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(upxClass);
    } // setupUi

    void retranslateUi(QMainWindow *upxClass)
    {
        upxClass->setWindowTitle(QApplication::translate("upxClass", "upx", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("upxClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        btnAddHostGroup->setText(QApplication::translate("upxClass", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        btnAddHost->setText(QApplication::translate("upxClass", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btnUpdateHostGroup->setText(QApplication::translate("upxClass", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("upxClass", "\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        edtHostAddr1->setInputMask(QApplication::translate("upxClass", "000.000.000.000;_", 0, QApplication::UnicodeUTF8));
        edtHostAddr2->setInputMask(QApplication::translate("upxClass", "000.000.000.000;_", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("upxClass", "<->", 0, QApplication::UnicodeUTF8));
        btnDelHost->setText(QApplication::translate("upxClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("upxClass", "\347\273\204\345\220\215", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("upxClass", "\344\270\273\346\234\272\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("upxClass", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        btnDelHostGroup->setText(QApplication::translate("upxClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btnRebootHost->setText(QApplication::translate("upxClass", "\351\207\215\345\220\257\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("upxClass", "\344\270\273\346\234\272\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        btnCalcDigest->setText(QApplication::translate("upxClass", "\350\256\241\347\256\227MD5\346\221\230\350\246\201", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("upxClass", "\346\270\270\346\210\217\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("upxClass", "\346\270\270\346\210\217\346\226\207\344\273\266\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        btnAddGame->setText(QApplication::translate("upxClass", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        btnUpdateGame->setText(QApplication::translate("upxClass", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        btnDelGame->setText(QApplication::translate("upxClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        btnSelectPath->setText(QApplication::translate("upxClass", "?", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("upxClass", "\346\270\270\346\210\217\350\277\234\347\250\213\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("upxClass", "\346\270\270\346\210\217\350\265\204\346\272\220", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("upxClass", "\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("upxClass", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        btnGameAddHost->setText(QApplication::translate("upxClass", "\346\267\273\345\212\240\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        btnGameDelHost->setText(QApplication::translate("upxClass", "\345\210\240\351\231\244\344\270\273\346\234\272", 0, QApplication::UnicodeUTF8));
        btnStopGame->setText(QApplication::translate("upxClass", "\345\201\234\346\255\242\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        btnStartGame->setText(QApplication::translate("upxClass", "\345\274\200\345\220\257\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        btnFileDiffer->setText(QApplication::translate("upxClass", "\350\277\234\347\250\213\346\226\207\344\273\266\346\257\224\345\257\271", 0, QApplication::UnicodeUTF8));
        btnFileSync->setText(QApplication::translate("upxClass", "\346\270\270\346\210\217\346\226\207\344\273\266\345\220\214\346\255\245", 0, QApplication::UnicodeUTF8));
        cbxCheck->setText(QApplication::translate("upxClass", "\345\220\214\346\255\245\344\271\213\350\277\233\350\241\214\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("upxClass", "\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("upxClass", "\351\200\232\344\277\241\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        edtCommPort->setText(QApplication::translate("upxClass", "5000", 0, QApplication::UnicodeUTF8));
        btnSettingsSave->setText(QApplication::translate("upxClass", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("upxClass", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btnSaveToFile->setText(QApplication::translate("upxClass", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("upxClass", "\350\277\220\350\241\214\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("upxClass", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class upxClass: public Ui_upxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPX_H
