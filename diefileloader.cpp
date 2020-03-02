#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "diefileloader.h"

DieFileLoader::DieFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

DieFileLoader::~DieFileLoader(){delete getReceivedFile();}

void DieFileLoader::loadFile() {

}


