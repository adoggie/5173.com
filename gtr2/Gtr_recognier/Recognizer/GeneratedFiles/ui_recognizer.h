/********************************************************************************
** Form generated from reading UI file 'recognizer.ui'
**
** Created: Thu May 13 16:12:58 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNIZER_H
#define UI_RECOGNIZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecognizerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *m_count;
    QLabel *label_2;
    QLineEdit *m_password;
    QPushButton *m_login;
    QPushButton *m_logout;
    QTabWidget *tabWidget;
    QWidget *tabAnswer;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *positionLabel;
    QLineEdit *answerLineEdit;
    QPushButton *submitPushButton;
    QTreeWidget *treeWidget;
    QWidget *tabLog;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *logTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *m_saveYZMPix;
    QCheckBox *m_saveMBKPositionPix;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *m_leave;
    QRadioButton *m_online;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RecognizerClass)
    {
        if (RecognizerClass->objectName().isEmpty())
            RecognizerClass->setObjectName(QString::fromUtf8("RecognizerClass"));
        RecognizerClass->resize(918, 680);
        centralWidget = new QWidget(RecognizerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        m_count = new QComboBox(centralWidget);
        m_count->setObjectName(QString::fromUtf8("m_count"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_count->sizePolicy().hasHeightForWidth());
        m_count->setSizePolicy(sizePolicy);
        m_count->setEditable(true);

        horizontalLayout_2->addWidget(m_count);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        m_password = new QLineEdit(centralWidget);
        m_password->setObjectName(QString::fromUtf8("m_password"));
        sizePolicy.setHeightForWidth(m_password->sizePolicy().hasHeightForWidth());
        m_password->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(m_password);

        m_login = new QPushButton(centralWidget);
        m_login->setObjectName(QString::fromUtf8("m_login"));

        horizontalLayout_2->addWidget(m_login);

        m_logout = new QPushButton(centralWidget);
        m_logout->setObjectName(QString::fromUtf8("m_logout"));

        horizontalLayout_2->addWidget(m_logout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabAnswer = new QWidget();
        tabAnswer->setObjectName(QString::fromUtf8("tabAnswer"));
        horizontalLayout_7 = new QHBoxLayout(tabAnswer);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox = new QGroupBox(tabAnswer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(251, 381));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        imageLabel = new QLabel(groupBox);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setMinimumSize(QSize(210, 280));
        imageLabel->setFrameShape(QFrame::Panel);
        imageLabel->setFrameShadow(QFrame::Sunken);
        imageLabel->setScaledContents(true);

        verticalLayout->addWidget(imageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        positionLabel = new QLabel(groupBox);
        positionLabel->setObjectName(QString::fromUtf8("positionLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(positionLabel->sizePolicy().hasHeightForWidth());
        positionLabel->setSizePolicy(sizePolicy2);
        positionLabel->setMinimumSize(QSize(200, 80));
        positionLabel->setMaximumSize(QSize(200, 80));
        positionLabel->setFrameShape(QFrame::Panel);
        positionLabel->setFrameShadow(QFrame::Sunken);
        positionLabel->setScaledContents(true);

        horizontalLayout->addWidget(positionLabel);

        answerLineEdit = new QLineEdit(groupBox);
        answerLineEdit->setObjectName(QString::fromUtf8("answerLineEdit"));
        answerLineEdit->setMinimumSize(QSize(15, 50));
        answerLineEdit->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        answerLineEdit->setFont(font);
        answerLineEdit->setMaxLength(10);

        horizontalLayout->addWidget(answerLineEdit);

        submitPushButton = new QPushButton(groupBox);
        submitPushButton->setObjectName(QString::fromUtf8("submitPushButton"));
        submitPushButton->setEnabled(false);
        sizePolicy2.setHeightForWidth(submitPushButton->sizePolicy().hasHeightForWidth());
        submitPushButton->setSizePolicy(sizePolicy2);
        submitPushButton->setMinimumSize(QSize(75, 50));
        submitPushButton->setMaximumSize(QSize(75, 50));

        horizontalLayout->addWidget(submitPushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addWidget(groupBox);

        treeWidget = new QTreeWidget(tabAnswer);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy3);
        treeWidget->setMinimumSize(QSize(380, 0));

        horizontalLayout_7->addWidget(treeWidget);

        tabWidget->addTab(tabAnswer, QString());
        tabLog = new QWidget();
        tabLog->setObjectName(QString::fromUtf8("tabLog"));
        horizontalLayout_3 = new QHBoxLayout(tabLog);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        logTextEdit = new QTextEdit(tabLog);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(logTextEdit);

        tabWidget->addTab(tabLog, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_saveYZMPix = new QCheckBox(groupBox_2);
        m_saveYZMPix->setObjectName(QString::fromUtf8("m_saveYZMPix"));

        horizontalLayout_4->addWidget(m_saveYZMPix);

        m_saveMBKPositionPix = new QCheckBox(groupBox_2);
        m_saveMBKPositionPix->setObjectName(QString::fromUtf8("m_saveMBKPositionPix"));

        horizontalLayout_4->addWidget(m_saveMBKPositionPix);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        m_leave = new QRadioButton(groupBox_3);
        m_leave->setObjectName(QString::fromUtf8("m_leave"));

        horizontalLayout_6->addWidget(m_leave);

        m_online = new QRadioButton(groupBox_3);
        m_online->setObjectName(QString::fromUtf8("m_online"));

        horizontalLayout_6->addWidget(m_online);


        horizontalLayout_5->addWidget(groupBox_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        RecognizerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RecognizerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RecognizerClass->setStatusBar(statusBar);

        retranslateUi(RecognizerClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RecognizerClass);
    } // setupUi

    void retranslateUi(QMainWindow *RecognizerClass)
    {
        RecognizerClass->setWindowTitle(QApplication::translate("RecognizerClass", "GTR\347\255\224\351\242\230\345\231\2501.4.1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecognizerClass", "\345\267\245\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RecognizerClass", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        m_login->setText(QApplication::translate("RecognizerClass", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        m_logout->setText(QApplication::translate("RecognizerClass", "\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RecognizerClass", "\350\257\206\345\210\253\345\214\272", 0, QApplication::UnicodeUTF8));
        submitPushButton->setText(QApplication::translate("RecognizerClass", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("RecognizerClass", "\345\210\233\345\273\272\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("RecognizerClass", "\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("RecognizerClass", "\345\215\225\345\217\267", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabAnswer), QApplication::translate("RecognizerClass", "\347\255\224\351\242\230", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabLog), QApplication::translate("RecognizerClass", "\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("RecognizerClass", "\344\277\235\345\255\230\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        m_saveYZMPix->setText(QApplication::translate("RecognizerClass", "\344\277\235\345\255\230\351\252\214\350\257\201\347\240\201", 0, QApplication::UnicodeUTF8));
        m_saveMBKPositionPix->setText(QApplication::translate("RecognizerClass", "\344\277\235\345\255\230\345\257\206\346\212\245\345\235\220\346\240\207", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("RecognizerClass", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        m_leave->setText(QApplication::translate("RecognizerClass", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
        m_online->setText(QApplication::translate("RecognizerClass", "\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecognizerClass: public Ui_RecognizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNIZER_H
