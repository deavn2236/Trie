#ifndef FILEFORM_H
#define FILEFORM_H

#include <QWidget>

namespace Ui {
class FileForm;
}

class FileForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileForm(QWidget *parent = 0);
    ~FileForm();

private slots:
    void on_backbtn_clicked();

    void on_find_clicked();

    void on_selectfilebtn_clicked();

private:
    Ui::FileForm *ui;
};

#endif // FILEFORM_H
