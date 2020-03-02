#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "tbxfileloader.h"

TbxFileLoader::TbxFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

TbxFileLoader::~TbxFileLoader(){delete getReceivedFile();}

void TbxFileLoader::loadFile() {


}

