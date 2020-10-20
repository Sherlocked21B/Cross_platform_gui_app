#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void digitpressed();
    void operatorpressed();
   void equaltopressed();
   void on_pushButton_AC_clicked();


   void on_change_sign_clicked();

   void on_Delete_clicked();

   void on_pushButton_equalsto_2_clicked();


   void on_pushButton_AC_2_clicked();

private:
    Ui::MainWindow *ui;
    converter *con;
};

#endif // MAINWINDOW_H
