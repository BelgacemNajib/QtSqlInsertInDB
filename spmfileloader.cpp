#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "spmfileloader.h"

SpmFileLoader::SpmFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

SpmFileLoader::~SpmFileLoader(){delete getReceivedFile();}

void SpmFileLoader::loadFile() {


}
