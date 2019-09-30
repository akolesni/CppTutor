#ifndef UNTITLED1_TESTCLASS_H
#define UNTITLED1_TESTCLASS_H


int get2();
int add2(int value);


long getFileSize(const char* filename);


class ITestClass
{
    virtual int getMax(int a1, int a2) = 0;

    virtual int getMin(int a1, int a2) = 0;
};

class TestClass : public ITestClass
{
public:
    int getMax(int a1, int a2) override;
    int getMin(int a1, int a2) override;
};

#endif //UNTITLED1_TESTCLASS_H
