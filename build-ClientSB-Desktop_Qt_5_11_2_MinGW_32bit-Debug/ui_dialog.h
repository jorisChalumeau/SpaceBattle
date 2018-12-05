/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *hostCombo;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *getFortuneButton;
    QLineEdit *message;
    QLineEdit *pseudo;
    QPushButton *boutonEnvoyer;
    QTextEdit *listeMessages;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *buttonGame;
    QPushButton *decoButton;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QStringLiteral("dialog"));
        dialog->resize(782, 743);
        buttonBox = new QDialogButtonBox(dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(480, 10, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        hostCombo = new QComboBox(dialog);
        hostCombo->setObjectName(QStringLiteral("hostCombo"));
        hostCombo->setGeometry(QRect(160, 20, 271, 31));
        label = new QLabel(dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(22, 20, 91, 20));
        label_2 = new QLabel(dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 111, 31));
        portLineEdit = new QLineEdit(dialog);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(160, 80, 271, 31));
        statusLabel = new QLabel(dialog);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 140, 621, 20));
        getFortuneButton = new QPushButton(dialog);
        getFortuneButton->setObjectName(QStringLiteral("getFortuneButton"));
        getFortuneButton->setGeometry(QRect(500, 140, 131, 28));
        message = new QLineEdit(dialog);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(240, 700, 351, 28));
        pseudo = new QLineEdit(dialog);
        pseudo->setObjectName(QStringLiteral("pseudo"));
        pseudo->setGeometry(QRect(10, 700, 151, 28));
        boutonEnvoyer = new QPushButton(dialog);
        boutonEnvoyer->setObjectName(QStringLiteral("boutonEnvoyer"));
        boutonEnvoyer->setGeometry(QRect(620, 700, 141, 28));
        listeMessages = new QTextEdit(dialog);
        listeMessages->setObjectName(QStringLiteral("listeMessages"));
        listeMessages->setGeometry(QRect(20, 180, 501, 421));
        label_3 = new QLabel(dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(12, 670, 91, 20));
        label_4 = new QLabel(dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 670, 91, 20));
        buttonGame = new QPushButton(dialog);
        buttonGame->setObjectName(QStringLiteral("buttonGame"));
        buttonGame->setGeometry(QRect(630, 630, 131, 28));
        decoButton = new QPushButton(dialog);
        decoButton->setObjectName(QStringLiteral("decoButton"));
        decoButton->setGeometry(QRect(653, 140, 101, 28));

        retranslateUi(dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QApplication::translate("dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("dialog", "Server Name", nullptr));
        label_2->setText(QApplication::translate("dialog", "Server host", nullptr));
        statusLabel->setText(QApplication::translate("dialog", "TextLabel", nullptr));
        getFortuneButton->setText(QApplication::translate("dialog", "Connection", nullptr));
        boutonEnvoyer->setText(QApplication::translate("dialog", "Send Message", nullptr));
        label_3->setText(QApplication::translate("dialog", "Pseudo", nullptr));
        label_4->setText(QApplication::translate("dialog", "Message", nullptr));
        buttonGame->setText(QApplication::translate("dialog", "Acces game", nullptr));
        decoButton->setText(QApplication::translate("dialog", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
