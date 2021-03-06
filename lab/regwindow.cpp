#include "regwindow.h"
#include "ui_regwindow.h"
#include "startwindow.h"
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include "crypto.h"

RegWindow::RegWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
        socket->connectToHost("127.0.0.1", 33333);
        connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
        connect(socket, SIGNAL(readyRead()), SLOT(slot_ready_read()));
}

void RegWindow::slot_connected()
{
    QMessageBox msgBox;
    msgBox.setText("You are on the server");
    msgBox.exec();
}
void RegWindow::slot_send_to_server(QString message){
    QByteArray array,array_d;
    array.append(message);
    crypto c;
    array_d = c.encrypt(array);
    socket->write(array_d);
}
void RegWindow::slot_ready_read(){
    QByteArray arr,arr_d;
    int mess;
    QMessageBox msgBox;
    while (socket->bytesAvailable() > 0)
    {
        arr = socket->readAll();

    }
    crypto c;
    arr_d = c.decrypt(arr);
    mess = arr_d.toInt();
    if(mess==0){
        msgBox.setText("Registred");
        msgBox.exec();
    } else if (mess==1){
        msgBox.setText("This username already used");
        msgBox.exec();
    }
}
void RegWindow::slot_disconected(){

}
RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_actionBack_triggered()
{
    StartWindow *wnd = new StartWindow();
    this->close();
    wnd->show();
}

void RegWindow::on_pushButtonLog_clicked()
{
    QMessageBox msgBox;
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL,"
               "level VARCHAR(20) NOT NULL"
               ")");
*/
    QString login = ui->lineEdit_log_2->text();
    QString password = ui->lineEdit_pass_2->text();
    /*query.bindValue(":login","admin");
    query.bindValue(":password","123");
    query.bindValue(":level","1");
    query.exec();
    query.bindValue(":login","manager1");
    query.bindValue(":password","111");
    query.bindValue(":level","2");
    query.exec();
    query.bindValue(":login","user1");
    query.bindValue(":password","1");
    query.bindValue(":level","3");
    query.exec();*/
    /*int temp=0;
    query.exec("SELECT * FROM User");
        while(query.next())
            if(query.value(0).toString()==login.toLocal8Bit().constData()){
                temp=1;
                msgBox.setText("Login already used");
                msgBox.exec();
            }     
    if(temp==0){
        query.prepare("INSERT INTO User(login, password, level) "
                          "VALUES (:login, :password, :level)");
        query.bindValue(":login",login);
        query.bindValue(":password",password);
        query.bindValue(":level","3");
        query.exec();
        msgBox.setText("Succesful");
        msgBox.exec();
    }
    db.close();*/
    if(login == NULL || password == NULL){
        msgBox.setText("Fill empty areas");
        msgBox.exec();
    }else{
    QString message;
        message = "registration " + login + " " + password;
        slot_send_to_server(message);
    }
}
