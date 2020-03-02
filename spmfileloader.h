#ifndef SpmFileLoader_H
#define SpmFileLoader_H
#include "fileloader.h"

/**
 * @brief SpmFileLoader: read spm file with some check
 * if all check are ok content of file is inserted in db
 */
class SpmFileLoader:public FileLoader
{
public:
    SpmFileLoader() = delete;// dont needed
    SpmFileLoader(QString &fileName);
    ~SpmFileLoader();
    void loadFile()override;
};

#endif // SpmFileLoader_H
