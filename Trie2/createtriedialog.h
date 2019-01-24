#ifndef CREATETRIEDIALOG_H
#define CREATETRIEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateTrieDialog;
}

class CreateTrieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTrieDialog(QWidget *parent = 0);
    ~CreateTrieDialog();

private slots:
    void on_phonebtn_clicked();

    void on_wordbtn_clicked();

    void on_findbtn1_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateTrieDialog *ui;
};

#endif // CREATETRIEDIALOG_H
