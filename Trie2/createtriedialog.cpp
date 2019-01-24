#include "createtriedialog.h"
#include "ui_createtriedialog.h"
#include "trie.h"
#include <QMessageBox>
#include <QDebug>
 int N0 ;
extern bool ifword;
extern bool ifer;
extern QString lines;
extern bool ischeck;
Trie *t;
CreateTrieDialog::CreateTrieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTrieDialog)
{
    ui->setupUi(this);
}

CreateTrieDialog::~CreateTrieDialog()
{
    delete ui;
}

void CreateTrieDialog::on_phonebtn_clicked()
{
    N0=10;
    ui->cue->setText("请输入电话号码");
}

void CreateTrieDialog::on_wordbtn_clicked()
{
    N0=26;
    ui->cue->setText("请输入单词");
}

void CreateTrieDialog::on_findbtn1_clicked()
{
    ischeck=ui->checkBox->isChecked();
    QString s=ui->lineEdit->text();
    char*ch;
    QByteArray ba = s.toLatin1(); // must
    ch=ba.data();
qDebug()<<ch;
    QString st=ui->context->toPlainText();
    string ss=st.toStdString();
qDebug()<<st;
    bool b0=haveword(ss,ch);

    if(ifer){QMessageBox::warning(this,tr("warding"),tr("请正确输入类型"),QMessageBox::Yes); return;}
    if(b0){ui->result->setText("TRUE");qDebug()<<b0;}
    else ui->result->setText("FALSE");

}

