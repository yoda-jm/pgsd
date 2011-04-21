#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(on_treeWidget_customContextMenuRequested(const QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_customContextMenuRequested(QPoint pos)
{
    QTreeWidgetItem * item = NULL ;
    item = ui->treeWidget->itemAt(pos);
    QMenu menu(NULL);
    if ( item == NULL ) {
        // nothing selected
        // add("Refresh All")
        // add("Add Group...")
        menu.addSeparator();
        menu.exec(ui->treeWidget->mapToGlobal(pos));
    } else {
        // something selected
        // if (group) {
        //  add("Rename...");
        //  if (dynamic) {
        //      add("Change URI...");
        //      add("Refresh");
        //  } else {
        //  }
        // } else if (feed) {
        //  add("Refresh");
        //  add("Download all items");
        //  if(!parent.dynamic) {
        //      add("Change URI...");
        //  }
        // } else { // it's an item
        //  add("Download");
        // }
    }
    menu.clear();
}
