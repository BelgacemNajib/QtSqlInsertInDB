#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QEventLoop>
#include <QDirIterator>
#include <QDir>
#include <QtSql/QtSql>
#include "fieldfileloader.h"
/*class myApp:public QCoreApplication{
private :
    QFileSystemWatcher fileSystemWatcher;
    QFile * fieldFile;
public :
    using QCoreApplication::QCoreApplication;
    int manageDB() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../testDB.db");
        if(!db.open())
           return 42;

        QSqlQuery result = db.exec ("select * from stc_field");
        while (result.next()) {
                QString ma_name = result.value(0).toString();
                QString position = result.value(1).toString();
                float x = result.value(2).toFloat();
                float y = result.value(3).toFloat();
                QString comment = result.value(4).toString();
                qDebug() << ma_name << position << x << y << comment ;
            }
        qDebug()<<result.lastError().text();

        db.close();
        return 0;
    }

    void newFielFile(){
        QFileSystemWatcher watcher;
        watcher.addPath( "." );

        // connect to db
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../testDB.db");
        if(!db.open())
           return ;


        QEventLoop loop;

        QObject::connect( &watcher, &QFileSystemWatcher::directoryChanged,
                          [&db]( const QString& path )
        {
            QDirIterator it( path,
                            { "*.field.flg" },        // Filter: *.txt
                            QDir::AllEntries);   // Files only

            while ( it.hasNext() )              // List all txt files
            {                                   // on console
                qDebug() << "flg file name "  << it.next();
                QStringList flgFileName = it.fileName().split(".");
                QString filename  = flgFileName[0] + "." + flgFileName[1];
                QFile inputFile(filename);
                qDebug() << "field file name  = " << filename ;

                QString maName = flgFileName[0].split("_")[0];
                maName = maName.toUpper();

                // check on maName
                if (maName.size() > 5) {
                    qDebug() << " file name is not in right format ";
                    break;
                }

                if (inputFile.open(QIODevice::ReadOnly))
                {
                   QTextStream in(&inputFile);
                   int lineIndex = 0;
                   int nbrToken = 0;

                   QTime time;
                   time.start();
                   // read line by line
                   while (!in.atEnd())
                   {
                      QString line = in.readLine();

                      // skip commented lines
                      if (line.contains("#")) continue;

                      QStringList lineContent = line.split(",");

                      if (lineContent.size() != nbrToken && lineIndex) {
                          qDebug() << "wrong number of token";
                          break;
                      }

                      // check on maName in each line
                      if(lineContent[0] != maName) {
                          qDebug() << "line "<< lineIndex << " not in the right";
                          break;
                      }

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
                      qDebug()<<query.lastError().text();

                      nbrToken = lineContent.size();
                      lineIndex++;
                   }

                   qDebug() << "insert in db finished in (s)" << time.elapsed()/1000;
                   inputFile.close();
                   db.commit();
                   db.close();
                }
                // end reading
                inputFile.remove(); // remove field file
                QFile::remove(it.fileName());// remove flg file
            }
        });
        loop.exec();
    }
};*/

int main(int argc, char *argv[])
{

    if(argc < 4){
        qDebug() << "wrong number of paramter \n Expected "
                    "<file name > <log directory> < log directory> < load type >";
        return -1;
    }
    QString fileName = QString(argv[1]);
    FieldFileLoader* fieldLoad = new FieldFileLoader(fileName);
    fieldLoad->loadFile();

    return 0;
}

