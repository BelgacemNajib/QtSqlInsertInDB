#include "fileloader.h"
#include "QDebug"


FileLoader::FileLoader()
{
 qDebug() << "principal object";
}

FileLoader::~FileLoader(){}

bool FileLoader::checkFileNameFormat() {
    QString mask = receivedFile->fileName().split("_")[0];
    mask = mask.toUpper();

    if (mask.size() > 5) {
        qDebug() << " file name is not in right format ";
        return false;
    }
    setMaName(mask);
    return true;
}

bool FileLoader::checkExistenceMasket() {
 return true;
}

void FileLoader::loadFile() {
    qDebug() << "load file as function of thier extention";
}

void FileLoader::setReceivedFile(const QString &fileName) {
    receivedFile = new QFile(fileName);
}

QFile *FileLoader::getReceivedFile() {
    return receivedFile;
}

const QString &FileLoader::getMaName() {
    return maName;
}

void FileLoader::setMaName(const QString &m) {
    maName = m ;
}

bool FileLoader::commonChecksOk() {
    if(!checkExistenceMasket()) {
        qDebug() << "maskset is not in the DB \n";
        return false;
    }
    if (!checkFileNameFormat()) {
        qDebug() << "file name is not in the right format \n";
        return false;
    }
    return true;
 }

