#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QEventLoop>
#include <QDirIterator>
#include <QDir>
#include <QtSql/QtSql>
#include "fieldfileloader.h"
#include "diefileloader.h"
#include "stifileloader.h"
#include "spmfileloader.h"
#include "tbxfileloader.h"
#include "hdrfileloader.h"
#include "imgfileloader.h"

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
        // TODO: incomplet
        DieFileLoader* dieLoad = new DieFileLoader(fileName);
        dieLoad->loadFile();
    } else if (extend == "img") {
        // TODO: incomplet
        ImgFileLoader* imgLoad = new ImgFileLoader(fileName);
        imgLoad->loadFile();
    } else if (extend == "sti") {
        // TODO: incomplet
        StiFileLoader* stiLoad = new StiFileLoader(fileName);
        stiLoad->loadFile();
    } else if (extend == "spm") {
        // TODO: incomplet
        SpmFileLoader* spmLoad = new SpmFileLoader(fileName);
        spmLoad->loadFile();
    } else if (extend == "hdr") {
        // TODO: incomplet
        HdrFileLoader* hdrLoad = new HdrFileLoader(fileName);
        hdrLoad->loadFile();
    }

    return 0;
}

