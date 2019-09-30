#include "TestClass.h"
#include "stdio.h"

int get2()
{
    return 2;
}

int add2(int value)
{
    return value + get2();
}


long getFileSize(const char* filename)
{
    FILE* pFile{};
    long fileSize = -1L;
    pFile = fopen(filename, "r");
    if(NULL != pFile)
    {
        fileSize = ftell(pFile);
        fclose(pFile);
    }

    return fileSize;
}


int TestClass::getMax(int a1, int a2)
{
    return a1;
}

int TestClass::getMin(int a1, int a2)
{
    return a1;
}
