/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION1_H
#define UI_QTGUIAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication1Class
{
public:
    QAction *viewConstellation;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *starList;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *nameLine;
    QLabel *label_2;
    QLineEdit *RALine;
    QLabel *label3;
    QLineEdit *declinationLine;
    QLabel *label_3;
    QLineEdit *diameterLine;
    QLabel *label_4;
    QLineEdit *imageLine;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QPushButton *viewButton;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLine;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuMain_Page;
    QMenu *menuConstellations;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication1Class)
    {
        if (QtGuiApplication1Class->objectName().isEmpty())
            QtGuiApplication1Class->setObjectName(QString::fromUtf8("QtGuiApplication1Class"));
        QtGuiApplication1Class->resize(783, 496);
        viewConstellation = new QAction(QtGuiApplication1Class);
        viewConstellation->setObjectName(QString::fromUtf8("viewConstellation"));
        actionExit = new QAction(QtGuiApplication1Class);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(QtGuiApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        starList = new QListWidget(centralWidget);
        starList->setObjectName(QString::fromUtf8("starList"));

        horizontalLayout->addWidget(starList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        nameLine = new QLineEdit(centralWidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));

        verticalLayout_2->addWidget(nameLine);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        RALine = new QLineEdit(centralWidget);
        RALine->setObjectName(QString::fromUtf8("RALine"));

        verticalLayout_2->addWidget(RALine);

        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));

        verticalLayout_2->addWidget(label3);

        declinationLine = new QLineEdit(centralWidget);
        declinationLine->setObjectName(QString::fromUtf8("declinationLine"));

        verticalLayout_2->addWidget(declinationLine);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        diameterLine = new QLineEdit(centralWidget);
        diameterLine->setObjectName(QString::fromUtf8("diameterLine"));

        verticalLayout_2->addWidget(diameterLine);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        imageLine = new QLineEdit(centralWidget);
        imageLine->setObjectName(QString::fromUtf8("imageLine"));

        verticalLayout_2->addWidget(imageLine);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QString::fromUtf8("viewButton"));

        verticalLayout_2->addWidget(viewButton);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchLine = new QLineEdit(centralWidget);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setLayoutDirection(Qt::LeftToRight);
        searchLine->setClearButtonEnabled(false);

        verticalLayout->addWidget(searchLine);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout_3->addLayout(verticalLayout);

        QtGuiApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 783, 21));
        menuMain_Page = new QMenu(menuBar);
        menuMain_Page->setObjectName(QString::fromUtf8("menuMain_Page"));
        menuConstellations = new QMenu(menuBar);
        menuConstellations->setObjectName(QString::fromUtf8("menuConstellations"));
        QtGuiApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplication1Class->setStatusBar(statusBar);

        menuBar->addAction(menuMain_Page->menuAction());
        menuBar->addAction(menuConstellations->menuAction());
        menuMain_Page->addAction(actionExit);
        menuConstellations->addAction(viewConstellation);

        retranslateUi(QtGuiApplication1Class);

        QMetaObject::connectSlotsByName(QtGuiApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication1Class)
    {
        QtGuiApplication1Class->setWindowTitle(QApplication::translate("QtGuiApplication1Class", "QtGuiApplication1", nullptr));
        viewConstellation->setText(QApplication::translate("QtGuiApplication1Class", "View constellations", nullptr));
        actionExit->setText(QApplication::translate("QtGuiApplication1Class", "Exit", nullptr));
        label->setText(QApplication::translate("QtGuiApplication1Class", "Name", nullptr));
        label_2->setText(QApplication::translate("QtGuiApplication1Class", "Right Ascension", nullptr));
        label3->setText(QApplication::translate("QtGuiApplication1Class", "Declination", nullptr));
        label_3->setText(QApplication::translate("QtGuiApplication1Class", "Diameter", nullptr));
        label_4->setText(QApplication::translate("QtGuiApplication1Class", "Image location", nullptr));
        pushButton->setText(QApplication::translate("QtGuiApplication1Class", "Add Star", nullptr));
        checkBox->setText(QApplication::translate("QtGuiApplication1Class", "Show from my constellations only", nullptr));
        viewButton->setText(QApplication::translate("QtGuiApplication1Class", "View Star", nullptr));
        menuMain_Page->setTitle(QApplication::translate("QtGuiApplication1Class", "Options", nullptr));
        menuConstellations->setTitle(QApplication::translate("QtGuiApplication1Class", "Constellations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication1Class: public Ui_QtGuiApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION1_H
