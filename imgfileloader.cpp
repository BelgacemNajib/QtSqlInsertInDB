#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "imgfileloader.h"

ImgFileLoader::ImgFileLoader(QString &fileName) {
    setReceivedFile(fileName);
}

ImgFileLoader::~ImgFileLoader(){delete getReceivedFile();}

void ImgFileLoader::loadFile() {


}
