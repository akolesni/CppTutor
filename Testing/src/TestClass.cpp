#include "TestClass.h"
#include "stdio.h"

std::unique_ptr<ITestClass> TestClassFactory::s_testClass;

int get2()
{
    return 2;
}

int add2(int value)
{
    return value + get2();
}


long getFileSize(const char* _fileName)
{
    FILE* pFile{};
    long fileSize = -1L;
    pFile = ::fopen(_fileName, "r");
    if(nullptr != pFile)
    {
        fileSize = ::ftell(pFile);
        ::fclose(pFile);
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

std::string TestClass::getName()
{
    return "TestClass";
}
