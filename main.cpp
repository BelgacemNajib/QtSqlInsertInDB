#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QEventLoop>
#include <QDirIterator>
#include <QDir>
#include <QtSql/QtSql>
#include "fieldfileloader.h"

int main(int argc, char *argv[])
{

    if(argc < 4){
        qDebug() << "wrong number of paramter \n Expected "
                    "<file name > <log directory> < log directory> < load type >";
        return -1;
    }
    QString fileName = QString(argv[1]);
    QString extend = fileName.split('.')[1];

    if(extend == "field") {
        FieldFileLoader* fieldLoad = new FieldFileLoader(fileName);
        fieldLoad->loadFile();
    } else if (extend == "die") {
        // TODO
    } else if (extend == "img") {
        // TODO
    } else if (extend == "sti") {
        // TODO
    } else if (extend == "spm") {
        // TODO
    } else if (extend == "hdr") {
        // TODO
    }



    return 0;
}

