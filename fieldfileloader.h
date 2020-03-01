#ifndef fieldFileLoader_H
#define fieldFileLoader_H
#include "fileloader.h"

/**
 * @brief FieldFileLoader: read field file with some check
 * if all check are ok content of file is inserted in db (stc_field)
 */
class FieldFileLoader:public FileLoader
{
public:
    FieldFileLoader() = delete;// dont needed
    FieldFileLoader(QString &fileName);
    ~FieldFileLoader();
    void loadFile()override;

    /**
     * @brief computeUniqueIndexLine make unique index for the line (str)
     * it use Cantor Polynomes to make bijection from N^k to N
     * @param str iput string = line content
     * @return the unique index
     */
    int computeUniqueIndexLine(QString& str, int *index);
private:
    int cantor(int a, int b);
};

#endif // fieldFileLoader_H
