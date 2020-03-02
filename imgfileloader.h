#ifndef ImgFileLoader_H
#define ImgFileLoader_H
#include "fileloader.h"

/**
 * @brief ImgFileLoader: read img file with some check
 * if all check are ok content of file is inserted in db
 */
class ImgFileLoader:public FileLoader
{
public:
    ImgFileLoader() = delete;// dont needed
    ImgFileLoader(QString &fileName);
    ~ImgFileLoader();
    void loadFile()override;

};

#endif // ImgFileLoader_H
