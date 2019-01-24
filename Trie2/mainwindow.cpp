#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createtriedialog.h"
#include "fileform.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createbtn_clicked()
{
    this->hide();
    CreateTrieDialog *cdlg=new CreateTrieDialog();
    cdlg->show();
    cdlg->exec();
    this->show();
}

void MainWindow::on_filebtn_clicked()
{

    FileForm *fileform=new FileForm();
    fileform->show();


}
