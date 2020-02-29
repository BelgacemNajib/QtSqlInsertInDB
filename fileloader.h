#pragma once
#include <QFile>
/**
 * @brief The FileLoader class
 *
 * base class, it contains common checks like :
 *          - file name fomat
 *          - existing maskset in db
 *
 * childs can be: hdrFileLoader
 *                dieFileLoader
 *                FieldFileLoader
 *                imgFileLoader
 *                spmFileLoader
 *                tbxFileLoader
 *                stiFileLoader
 */

class FileLoader
{

    // file to be traited
    QFile *receivedFile;
    QString maName;
public:
    FileLoader();
    FileLoader(QFile& file) = delete;
    virtual ~FileLoader();

    // common checks funtions
    bool checkFileNameFormat();
    bool checkExistenceMasket();
    bool commonChecksOk();

    // each child has to define his
    virtual void loadFile();

    // getter and setter of the file to be treted
    void setReceivedFile(const QString &fileName);
    QFile *getReceivedFile();

    // getter and setter of the maskset name
    // this maskset name is common to all files
    const QString& getMaName();
    void setMaName(const QString &m);

};

