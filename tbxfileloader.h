#ifndef fieldFileLoader_H
#define fieldFileLoader_H
#include "fileloader.h"

/**
 * @brief TbxFileLoader: read tbx file with some check
 * if all check are ok content of file is inserted in db (stc_tbox)
 */
class TbxFileLoader:public FileLoader
{
public:
    TbxFileLoader() = delete;// dont needed
    TbxFileLoader(QString &fileName);
    ~TbxFileLoader();
    void loadFile()override;
};

#endif // fieldFileLoader_H
