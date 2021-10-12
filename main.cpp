#include <QCoreApplication>
#include <iostream>
#include <locale.h>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QList>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "Turkish");

    QSqlDatabase    db;

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ptnisec");
    db.setUserName("postgres");
    db.setPassword("123456789");
    if(db.open()){
        cout<< "Veri Tabani Bahlantisi Basarili\n";
    }

    QSqlQuery query;
    query.exec("SELECT * FROM users WHERE user_id='1' ");
    query.first();
    QString user_id=query.value(0).toString();
    QString user_name=query.value(1).toString();
    QString user_surname=query.value(2).toString();
    QString user_username=query.value(3).toString();
    QString user_password=query.value(4).toString();


    //qDebug() << user_id << endl << user_name << endl << user_surname << endl << user_username << endl <<user_password ;

    QStringList liste;

    QSqlQuery qry;
    qry.exec("SELECT * FROM users");
    while (qry.next()) {
        liste << (qry.value(1).toString());
    }
    qDebug() << liste.at(1).toLocal8Bit().constData();


    return a.exec();
}
