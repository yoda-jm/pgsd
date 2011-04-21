#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_treeWidget_customContextMenuRequested(QPoint pos)
{
    QTreeWidgetItem * item = NULL ;
    item = ui->treeWidget->itemAt(pos);
    QMenu menu(NULL);
    if ( item == NULL ) {
        // nothing selected
	menu.addAction("Refresh all");
	menu.addAction("Add group...");
    } else {
        // something selected
        // if (item.isGroup()) {
		menu.addAction("Rename");
        //	if (item.isDynamicGroup()) {
			menu.addAction("Change URI...");
			menu.addAction("Refresh");
        //	} else {
        //	}
        // } else if (item.isFeed()) {
		menu.addAction("Refresh");
		menu.addAction("Download all items");
        //	if (!item.parent().isDynamicGroup()) {
			menu.addAction("Change URI...");
        //	}
        // } else { // it's an item
		menu.addAction("Download");
        // }
    }
    menu.exec(ui->treeWidget->mapToGlobal(pos));
    menu.clear();
}
