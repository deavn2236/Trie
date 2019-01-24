#include "fileform.h"
#include "ui_fileform.h"
#include "trie.h"
#include<QFileDialog>
#include<QDebug>
extern QString lines;
QString path;
string s;
QString word;
bool ischeck;
FileForm::FileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileForm)
{
    ui->setupUi(this);
}

FileForm::~FileForm()
{
    delete ui;
}

void FileForm::on_backbtn_clicked()
{
    //parentWidget()->show();
    this->close();
}

void FileForm::on_find_clicked()
{
    ischeck=ui->checkBox->isChecked();
    qDebug()<<ischeck;
    ui->postext->setText("");
    word=ui->wordtext->text();

    char*ch;
    QByteArray ba = word.toLatin1(); // must
    ch=ba.data();

    findword(s,ch);

    ui->postext->setText(lines);
    lines="";
}

void FileForm::on_selectfilebtn_clicked()
{
    path=QFileDialog::getOpenFileName(this,tr("file"),".",tr("Text Files(*.txt)"));
    ui->filepathtext->setText(path);
    s=path.toStdString();
}
