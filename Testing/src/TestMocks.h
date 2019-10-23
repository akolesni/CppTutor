#include "gmock/gmock.h"
#include "TestClass.h"

#ifndef TESTING_TESTMOCKS_H
#define TESTING_TESTMOCKS_H

using namespace testing;

class MockTestClass : public ITestClass
{
public:
    MOCK_METHOD2(getMax, int(int, int));
    MOCK_METHOD2(getMin, int(int, int));
    MOCK_METHOD0(getName, std::string());
};
#endif //TESTING_TESTMOCKS_H
