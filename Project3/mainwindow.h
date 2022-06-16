#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "curvemanager.h"

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
    //void on_plot_customContextMenuRequested(const QPoint &pos);

    void on_btn_add_clicked();

    void on_btn_clear_clicked();

    void on_btn_reset_clicked();


private:
    Ui::MainWindow *ui;
    CurveManager *manager;
};

#endif // MAINWINDOW_H
