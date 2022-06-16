#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_X 1001
#define PIXEL MAX_X - 1 / 10

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new CurveManager(ui->plot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_add_clicked()
{

    manager->addCurve(Curve{});
    manager->plotCurve();
}

void MainWindow::on_btn_clear_clicked()
{
    manager->clearCurve();
}

void MainWindow::on_btn_reset_clicked()
{
    manager->resetView();
}
