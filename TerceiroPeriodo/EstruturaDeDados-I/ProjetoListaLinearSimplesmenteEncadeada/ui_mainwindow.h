/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonIncluirInicio;
    QLabel *label_5;
    QPushButton *pushButtonAcessarFinal;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButtonIncluirFinal;
    QPushButton *pushButtonRetirarInicio;
    QTextEdit *textEditSaida;
    QPushButton *pushButtonAcessarInicio;
    QLabel *labelFoto;
    QPushButton *pushButtonRetirarFinal;
    QLineEdit *lineEditValor;
    QLabel *label;
    QLabel *label_7;
    QLabel *labelFundo;
    QTextEdit *textEditQuantidadeElementos;
    QPushButton *pushButtonAcessarPosicao;
    QLineEdit *lineEditPosicao;
    QLabel *label_8;
    QPushButton *pushButtonInserirPosicao;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonIncluirInicio = new QPushButton(centralwidget);
        pushButtonIncluirInicio->setObjectName("pushButtonIncluirInicio");
        pushButtonIncluirInicio->setGeometry(QRect(189, 90, 91, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagens/Arquivos/inserir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonIncluirInicio->setIcon(icon);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 220, 47, 39));
        pushButtonAcessarFinal = new QPushButton(centralwidget);
        pushButtonAcessarFinal->setObjectName("pushButtonAcessarFinal");
        pushButtonAcessarFinal->setGeometry(QRect(337, 120, 101, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagens/Arquivos/acessar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAcessarFinal->setIcon(icon1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 60, 61, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(490, 60, 61, 26));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 310, 121, 26));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 60, 71, 26));
        pushButtonIncluirFinal = new QPushButton(centralwidget);
        pushButtonIncluirFinal->setObjectName("pushButtonIncluirFinal");
        pushButtonIncluirFinal->setGeometry(QRect(189, 120, 91, 24));
        pushButtonIncluirFinal->setIcon(icon);
        pushButtonRetirarInicio = new QPushButton(centralwidget);
        pushButtonRetirarInicio->setObjectName("pushButtonRetirarInicio");
        pushButtonRetirarInicio->setGeometry(QRect(480, 90, 101, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagens/Arquivos/retirar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRetirarInicio->setIcon(icon2);
        textEditSaida = new QTextEdit(centralwidget);
        textEditSaida->setObjectName("textEditSaida");
        textEditSaida->setGeometry(QRect(30, 340, 569, 159));
        pushButtonAcessarInicio = new QPushButton(centralwidget);
        pushButtonAcessarInicio->setObjectName("pushButtonAcessarInicio");
        pushButtonAcessarInicio->setGeometry(QRect(337, 90, 101, 24));
        pushButtonAcessarInicio->setIcon(icon1);
        labelFoto = new QLabel(centralwidget);
        labelFoto->setObjectName("labelFoto");
        labelFoto->setGeometry(QRect(60, 70, 81, 111));
        labelFoto->setPixmap(QPixmap(QString::fromUtf8(":/Imagens/Arquivos/jhone.jpeg")));
        labelFoto->setScaledContents(true);
        pushButtonRetirarFinal = new QPushButton(centralwidget);
        pushButtonRetirarFinal->setObjectName("pushButtonRetirarFinal");
        pushButtonRetirarFinal->setGeometry(QRect(480, 120, 101, 24));
        pushButtonRetirarFinal->setIcon(icon2);
        lineEditValor = new QLineEdit(centralwidget);
        lineEditValor->setObjectName("lineEditValor");
        lineEditValor->setGeometry(QRect(280, 230, 169, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 0, 221, 61));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 280, 231, 21));
        labelFundo = new QLabel(centralwidget);
        labelFundo->setObjectName("labelFundo");
        labelFundo->setGeometry(QRect(-2, -25, 811, 611));
        labelFundo->setPixmap(QPixmap(QString::fromUtf8(":/Imagens/Arquivos/windows.jpg")));
        labelFundo->setScaledContents(true);
        textEditQuantidadeElementos = new QTextEdit(centralwidget);
        textEditQuantidadeElementos->setObjectName("textEditQuantidadeElementos");
        textEditQuantidadeElementos->setGeometry(QRect(270, 280, 51, 31));
        pushButtonAcessarPosicao = new QPushButton(centralwidget);
        pushButtonAcessarPosicao->setObjectName("pushButtonAcessarPosicao");
        pushButtonAcessarPosicao->setGeometry(QRect(330, 150, 121, 23));
        pushButtonAcessarPosicao->setIcon(icon1);
        lineEditPosicao = new QLineEdit(centralwidget);
        lineEditPosicao->setObjectName("lineEditPosicao");
        lineEditPosicao->setGeometry(QRect(280, 200, 171, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(200, 200, 71, 21));
        pushButtonInserirPosicao = new QPushButton(centralwidget);
        pushButtonInserirPosicao->setObjectName("pushButtonInserirPosicao");
        pushButtonInserirPosicao->setGeometry(QRect(180, 150, 111, 23));
        pushButtonInserirPosicao->setIcon(icon);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 150, 121, 24));
        pushButton->setIcon(icon2);
        MainWindow->setCentralWidget(centralwidget);
        labelFundo->raise();
        pushButtonIncluirInicio->raise();
        label_5->raise();
        pushButtonAcessarFinal->raise();
        label_2->raise();
        label_4->raise();
        label_6->raise();
        label_3->raise();
        pushButtonIncluirFinal->raise();
        pushButtonRetirarInicio->raise();
        textEditSaida->raise();
        pushButtonAcessarInicio->raise();
        pushButtonRetirarFinal->raise();
        lineEditValor->raise();
        label->raise();
        label_7->raise();
        textEditQuantidadeElementos->raise();
        labelFoto->raise();
        pushButtonAcessarPosicao->raise();
        lineEditPosicao->raise();
        label_8->raise();
        pushButtonInserirPosicao->raise();
        pushButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonIncluirInicio->setText(QCoreApplication::translate("MainWindow", "Incluir Inicio", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Valor</span></p></body></html>", nullptr));
        pushButtonAcessarFinal->setText(QCoreApplication::translate("MainWindow", "Acessar Final", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Incluir</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Retirar</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Mostrar Lista</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Acessar</span></p></body></html>", nullptr));
        pushButtonIncluirFinal->setText(QCoreApplication::translate("MainWindow", "Incluir Final", nullptr));
        pushButtonRetirarInicio->setText(QCoreApplication::translate("MainWindow", "Retirar In\303\255cio", nullptr));
        pushButtonAcessarInicio->setText(QCoreApplication::translate("MainWindow", "Acessar In\303\255cio", nullptr));
        labelFoto->setText(QString());
        pushButtonRetirarFinal->setText(QCoreApplication::translate("MainWindow", "Retirar Final", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#000000;\">Sistema Teste Lista</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Quantidade de Elementos </span></p></body></html>", nullptr));
        labelFundo->setText(QString());
        pushButtonAcessarPosicao->setText(QCoreApplication::translate("MainWindow", "Acessar Posi\303\247\303\243o", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">Posi\303\247\303\243o</span></p></body></html>", nullptr));
        pushButtonInserirPosicao->setText(QCoreApplication::translate("MainWindow", "Inserir Posi\303\247\303\243o", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Retirar Posi\303\247\303\243o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
