#ifndef DieFileLoader_H
#define DieFileLoader_H
#include "fileloader.h"

/**
 * @brief DieFileLoader: read die file with some check
 * if all check are ok content of file is inserted in db
 */
class DieFileLoader:public FileLoader
{
public:
    DieFileLoader() = delete;// dont needed
    DieFileLoader(QString &fileName);
    ~DieFileLoader();
    void loadFile()override;

};

#endif // DieFileLoader_H
