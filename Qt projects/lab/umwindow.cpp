    #include "umwindow.h"
#include "ui_umwindow.h"
#include "startwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "loginwindow.h"
#include "database.h"
#include "dialogdelete.h"
#include <QMessageBox>

void UMWindow::SetTemp(int temp){
    t = temp;
}

void UMWindow::slot_ready_read(){
    QByteArray arr;
    std::string mess;
    while (socket->bytesAvailable() > 0)
    {
        arr = socket->readAll();
        mess = arr.toStdString();
    }
    base.transformStr2BD("Tour", mess);
    QStandardItem *item;
    qmodel = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(qmodel);
    qmodel->setHeaderData(0, Qt::Horizontal, "tour");
    qmodel->setHeaderData(1, Qt::Horizontal, "fio");
    qmodel->setHeaderData(2, Qt::Horizontal, "country");
    qmodel->setHeaderData(3, Qt::Horizontal, "magazine");
        for (int i = 0; i < base.db.size() ; i++)
        {
            item = new QStandardItem(QString::fromStdString(base.db[i].tour));
            qmodel->setItem(i, 0, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].fio));
            qmodel->setItem(i, 1, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].coun));
            qmodel->setItem(i, 2, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].mag));
            qmodel->setItem(i, 3, item);
        }

    }
void UMWindow::slot_send_to_server(QString message){
    QByteArray array;
    array.append(message);
    socket->write(array);
}

void UMWindow::slot_disconected(){
}
UMWindow::UMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UMWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
    connect(socket, SIGNAL(readyRead()), SLOT(slot_ready_read()));
    slot_send_to_server("show Tour");
}

UMWindow::~UMWindow()
{
    delete ui;
}

void UMWindow::on_actionLogOut_triggered()
{
   StartWindow *w = new StartWindow();
   this->close();
   w->show();
}

void UMWindow::on_actionRefresh_triggered()
{
    /*if(t==2){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Tour");
    if(!db.open())
        qDebug()<<db.lastError().text();
    model = new QSqlTableModel(this, db);
    model->setTable("User");
    model->select();
    ui->tableView->setModel(model);
    }else if(t==3){
        QStandardItem *item;

        qmodel = new QStandardItemModel(0,4,this);
        ui->tableView->setModel(qmodel);
        qmodel->setHeaderData(0, Qt::Horizontal, "tour");
        qmodel->setHeaderData(1, Qt::Horizontal, "fio");
        qmodel->setHeaderData(2, Qt::Horizontal, "country");
        qmodel->setHeaderData(3, Qt::Horizontal, "magazine");

        DataBase base;
        base.download("Tour");
            for (int i = 0; i < base.db.size() ; i++)
            {
                item = new QStandardItem(QString::fromStdString(base.db[i].tour));
                qmodel->setItem(i, 0, item);

                item = new QStandardItem(QString::fromStdString(base.db[i].fio));
                qmodel->setItem(i, 1, item);

                item = new QStandardItem(QString::fromStdString(base.db[i].coun));
                qmodel->setItem(i, 2, item);

                item = new QStandardItem(QString::fromStdString(base.db[i].mag));
                qmodel->setItem(i, 3, item);
            }

    }*/
    slot_send_to_server("show Tour");
}


void UMWindow::on_actionAdd_triggered()
{
    if(t==2){
        DialogDelete *w = new DialogDelete();
        w->SetTemp(1);
        w->show();
    } else{
        QMessageBox m;
        m.setText("Don't have permission");
        m.exec();
    }
}

void UMWindow::on_actionDelete_triggered()
{
    if(t==2){
        DialogDelete *w = new DialogDelete();
        w->SetTemp(2);
        w->show();
    } else{
        QMessageBox m;
        m.setText("Don't have permission");
        m.exec();
    }
}

void UMWindow::on_BTNFind_clicked()
{
    QStandardItem *item;

    qmodel = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(qmodel);
    qmodel->setHeaderData(0, Qt::Horizontal, "tour");
    qmodel->setHeaderData(1, Qt::Horizontal, "fio");
    qmodel->setHeaderData(2, Qt::Horizontal, "country");
    qmodel->setHeaderData(3, Qt::Horizontal, "magazine");

    QString temp = ui->lineFIND->text();
    base.finding("Tour",temp.toStdString());
        for (int i = 0; i < base.db.size() ; i++)
        {
            item = new QStandardItem(QString::fromStdString(base.db[i].tour));
            qmodel->setItem(i, 0, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].fio));
            qmodel->setItem(i, 1, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].coun));
            qmodel->setItem(i, 2, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].mag));
            qmodel->setItem(i, 3, item);
        }
}