/********************************************************************************
** Form generated from reading UI file 'creategamescene.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGAMESCENE_H
#define UI_CREATEGAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateGameScene
{
public:
    QLineEdit *nameLineEdit;
    QLabel *label;
    QComboBox *timeLimitCombo;
    QLabel *label_2;
    QCheckBox *viewersCheckBox;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CreateGameScene)
    {
        if (CreateGameScene->objectName().isEmpty())
            CreateGameScene->setObjectName(QStringLiteral("CreateGameScene"));
        CreateGameScene->resize(500, 250);
        nameLineEdit = new QLineEdit(CreateGameScene);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(160, 50, 171, 31));
        QFont font;
        font.setPointSize(12);
        nameLineEdit->setFont(font);
        label = new QLabel(CreateGameScene);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 81, 31));
        label->setFont(font);
        timeLimitCombo = new QComboBox(CreateGameScene);
        timeLimitCombo->setObjectName(QStringLiteral("timeLimitCombo"));
        timeLimitCombo->setGeometry(QRect(160, 90, 171, 31));
        label_2 = new QLabel(CreateGameScene);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 121, 31));
        label_2->setFont(font);
        viewersCheckBox = new QCheckBox(CreateGameScene);
        viewersCheckBox->setObjectName(QStringLiteral("viewersCheckBox"));
        viewersCheckBox->setGeometry(QRect(160, 140, 171, 31));
        viewersCheckBox->setFont(font);
        okButton = new QPushButton(CreateGameScene);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(380, 80, 93, 28));
        cancelButton = new QPushButton(CreateGameScene);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(380, 120, 93, 28));

        retranslateUi(CreateGameScene);

        QMetaObject::connectSlotsByName(CreateGameScene);
    } // setupUi

    void retranslateUi(QDialog *CreateGameScene)
    {
        CreateGameScene->setWindowTitle(QApplication::translate("CreateGameScene", "Dialog", nullptr));
        label->setText(QApplication::translate("CreateGameScene", "Name", nullptr));
        label_2->setText(QApplication::translate("CreateGameScene", "Limit of time", nullptr));
        viewersCheckBox->setText(QApplication::translate("CreateGameScene", "Allow viewers", nullptr));
        okButton->setText(QApplication::translate("CreateGameScene", "OK", nullptr));
        cancelButton->setText(QApplication::translate("CreateGameScene", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGameScene: public Ui_CreateGameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGAMESCENE_H
