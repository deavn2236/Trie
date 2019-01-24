#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include "QMovie"

WelcomeDialog::WelcomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeDialog)
{
    ui->setupUi(this);
    QMovie* movie=new QMovie("q.gif");
    ui->picture->setMovie(movie);
    movie->start();

}

WelcomeDialog::~WelcomeDialog()
{
    delete ui;
}
