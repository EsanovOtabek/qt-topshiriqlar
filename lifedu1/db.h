#ifndef DB
#define DB
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QString>
#include <QDateTime>
#include <QtSql/QSqlDriver>
class DBHelper{

    QSqlDatabase db;

public:
    DBHelper(const QString& path){
        this->db = QSqlDatabase::addDatabase("QSLITE");
        this->db.setDatabaseName(path);
        if(db.open()){
            this->echo="DB connect!";
        }
        else{
            this->echo="DB connection error!";
        }
    }
    QString echo;
};

class Session
{
    QSqlDatabase db;
    QString id;
    QString fio;
    QString email;
    bool insert(){
        QSqlQuery query;
        QString sql="INSERT INTO session (userid,fio,email,utime)VALUES(:userid,:fio,:email,:utime)";
        query.prepare(sql);
        query.bindValue(':userid',this->id);
        query.bindValue(':fio',this->fio);
        query.bindValue(':email',this->email);
        query.bindValue(':utime',QDateTime::currentDateTimeUtc().toString("d.MM.yyyy hh:mm:ss"));
        return query.exec();
    }
    bool delet(){
        QSqlQuery query;
        QString sql="DELETE FROM session WHERE id="+this->id;
        query.prepare(sql);
        return query.exec();
    }
    int count(){
        QSqlQuery query;
        QString sql="SELECT *FROM session";
        query.prepare(sql);
        query.exec();
        return query.size();
    }

public:
    QString echo;
    Session(){
        this->db = QSqlDatabase::addDatabase("QSLITE");
        this->db.setDatabaseName("C:/Users/User/Desktop/baza/user.db");
        if(db.open()){
            this->echo="DB connect!";
        }
        else{
            this->echo="DB connection error!";
        }
    }

    bool login(QString id,QString fio,QString email){
        this->id = id;
        this->fio = fio;
        this->email = email;
        return this->insert();
    }

    bool isActive(){
        return this->count()>0;
    }
    bool logout(){
        return delet();
    }
};







#endif // DB

