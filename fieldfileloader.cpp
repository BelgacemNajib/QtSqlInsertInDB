#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "fieldfileloader.h"

FieldFileLoader::FieldFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

FieldFileLoader::~FieldFileLoader(){delete getReceivedFile();}

void FieldFileLoader::loadFile() {

    QVector<int> linexIndex;

    if (getReceivedFile()->open(QIODevice::ReadOnly) && commonChecksOk())
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../testDB.db");
        if(!db.open())
           return;
       QTextStream in(getReceivedFile());
       int lineIndex = 0;
       int nbrToken = 0;

       QTime time;
       time.start();
       // read line by line
       while (!in.atEnd())
       {
          QString line = in.readLine();

          // skip commented lines
          if (line[0] == '#') continue;

          QStringList lineContent = line.split(",");

          // check on the number of token
          if (lineContent.size() != nbrToken && lineIndex) {
              qDebug() << "wrong number of token";
              break;
          }

          // check on maName in each line
          if(lineContent[0] != getMaName()) {
              qDebug() << "line "<< lineIndex << " not in the right \n"
                       << lineContent[0] << "!= " << getMaName();
              break;
          }

          // check doublon
          int tmpIndex = lineContent.size();
          int currentIndex = computeUniqueIndexLine(line,&tmpIndex);
          if(!linexIndex.contains(currentIndex))
            linexIndex.push_back(currentIndex);
          // insert in db
          QSqlQuery query;
          query.prepare("INSERT INTO stc_field (ma_name, position, x,y,comment) "
                        "VALUES (?, ?, ?, ?, ?)");
          int floatIndex = 0;
          for (QString& item : lineContent) {
              if(floatIndex==2 || floatIndex ==3)
                query.addBindValue(item.toFloat());
              else
                  query.addBindValue(item);

              floatIndex++;
          }

          query.exec();
          // check sql error
          query.lastError().text();
          if (query.lastError().text() != " ") {
            qDebug()<<query.lastError().text();
            break;
          }

          nbrToken = lineContent.size();
          lineIndex++;
       }

       qDebug() << "insert in db finished in (s)" << time.elapsed()/1000;
       getReceivedFile()->close();
       db.commit();
       db.close();
    }
    else
        qDebug() << "Error in readind " << getReceivedFile();
}

int FieldFileLoader::computeUniqueIndexLine(QString &str, int *index) {

    if(*index >= 2) {
        (*index)--;
        return computeUniqueIndexLine( str,index);
    }
    else {
        return (int)(0.5*((str[*index] + str[*index-1])*(str[*index] + str[*index-1])
                +  str[*index] + 3*str[*index-1]));
    }
}

