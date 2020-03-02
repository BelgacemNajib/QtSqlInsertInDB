#ifndef StiFileLoader_H
#define StiFileLoader_H
#include "fileloader.h"

/**
 * @brief StiFileLoader: read sti file with some check
 * if all check are ok content of file is inserted in db
 */
class StiFileLoader:public FileLoader
{
public:
    StiFileLoader() = delete;// dont needed
    StiFileLoader(QString &fileName);
    ~StiFileLoader();
    void loadFile()override;
};

#endif // StiFileLoader_H
