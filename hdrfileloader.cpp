#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "hdrfileloader.h"

HdrFileLoader::HdrFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

HdrFileLoader::~HdrFileLoader(){delete getReceivedFile();}

void HdrFileLoader::loadFile() {


}



