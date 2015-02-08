#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QtWebView/QtWebView>
#include <QtWebKit/QtWebKit>
#include <QtWebKitWidgets/QWebView>
#include <QTabWidget>
#include <QLineEdit>
#include <QPushButton>

QLineEdit * ed;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QRect a(20,30,250,24);
    QLabel * lbl = new QLabel(this);
    lbl->setGeometry(a);
    lbl->setParent(this);
    lbl->setText("Добро пожаловать в браузерную оболочку!");
    ed = new QLineEdit(this);
    ed->setGeometry(a.x()+240, a.y()+5, 125, 20);
    ed->setObjectName("edit1");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{
    //static int t(0);
    QPoint p1(10, 10), p2(80, 25);
    QWebView * web = new QWebView;
    web->setGeometry(p1.x(), p1.y()+p2.y(), 250, 400);
    web->load(QUrl("http://www."+ed->text()));
    web->loadStarted();
    ui->tabWidget->addTab(web,"Вкладка: "+ed->text());
    ed->setFocus();
}
