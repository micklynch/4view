/********************************************************************************
** Form generated from reading UI file 'mprviewer.ui'
**
** Created: Fri Nov 23 18:33:15 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPRVIEWER_H
#define UI_MPRVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MPRviewer
{
public:
    QAction *actionOpen_Files;
    QAction *actionOpen_Series;
    QAction *actionGaussian_Blur;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFiles;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MPRviewer)
    {
        if (MPRviewer->objectName().isEmpty())
            MPRviewer->setObjectName(QString::fromUtf8("MPRviewer"));
        MPRviewer->resize(600, 400);
        actionOpen_Files = new QAction(MPRviewer);
        actionOpen_Files->setObjectName(QString::fromUtf8("actionOpen_Files"));
        actionOpen_Series = new QAction(MPRviewer);
        actionOpen_Series->setObjectName(QString::fromUtf8("actionOpen_Series"));
        actionGaussian_Blur = new QAction(MPRviewer);
        actionGaussian_Blur->setObjectName(QString::fromUtf8("actionGaussian_Blur"));
        centralWidget = new QWidget(MPRviewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MPRviewer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MPRviewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MPRviewer->setMenuBar(menuBar);
        statusBar = new QStatusBar(MPRviewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MPRviewer->setStatusBar(statusBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFiles->addAction(actionOpen_Files);
        menuFiles->addAction(actionOpen_Series);
        menuEdit->addAction(actionGaussian_Blur);

        retranslateUi(MPRviewer);

        QMetaObject::connectSlotsByName(MPRviewer);
    } // setupUi

    void retranslateUi(QMainWindow *MPRviewer)
    {
        MPRviewer->setWindowTitle(QApplication::translate("MPRviewer", "MPRviewer", 0, QApplication::UnicodeUTF8));
        actionOpen_Files->setText(QApplication::translate("MPRviewer", "Open File", 0, QApplication::UnicodeUTF8));
        actionOpen_Series->setText(QApplication::translate("MPRviewer", "Open Series", 0, QApplication::UnicodeUTF8));
        actionGaussian_Blur->setText(QApplication::translate("MPRviewer", "Gaussian Blur", 0, QApplication::UnicodeUTF8));
        menuFiles->setTitle(QApplication::translate("MPRviewer", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MPRviewer", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MPRviewer: public Ui_MPRviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPRVIEWER_H
