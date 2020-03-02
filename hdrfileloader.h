#ifndef HdrFileLoader_H
#define HdrFileLoader_H
#include "fileloader.h"

/**
 * @brief HdrFileLoader: read hdr file with some check
 * if all check are ok content of file is inserted in db
 */
class HdrFileLoader:public FileLoader
{
public:
    HdrFileLoader() = delete;// dont needed
    HdrFileLoader(QString &fileName);
    ~HdrFileLoader();
    void loadFile()override;

};

#endif // HdrFileLoader_H
