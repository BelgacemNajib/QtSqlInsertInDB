#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "stifileloader.h"

StiFileLoader::StiFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

StiFileLoader::~StiFileLoader(){delete getReceivedFile();}

void StiFileLoader::loadFile() {


}



