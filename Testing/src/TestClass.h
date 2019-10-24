#include <memory>

#ifndef UNTITLED1_TESTCLASS_H
#define UNTITLED1_TESTCLASS_H

int get2();
int add2(int value);


long getFileSize(const char* _fileName);


class ITestClass
{
public:
    virtual ~ITestClass() = default;
    virtual int getMax(int a1, int a2) = 0;

    virtual int getMin(int a1, int a2) = 0;

    virtual std::string getName() = 0;
};

class TestClass : public ITestClass
{
public:
    int getMax(int a1, int a2) override;
    int getMin(int a1, int a2) override;
    std::string getName() override;
};


class TestClassFactory
{
public:
    static std::unique_ptr<ITestClass> createTestClass()
    {
        if (nullptr == s_testClass)
        {
            s_testClass = std::make_unique<TestClass>();
        }

        return std::move(s_testClass);
    }

    static void setTestClass(std::unique_ptr<ITestClass>&& testClass)
    {
        s_testClass = std::move(testClass);
    }
private:
    static std::unique_ptr<ITestClass> s_testClass;
};
#endif //UNTITLED1_TESTCLASS_H
