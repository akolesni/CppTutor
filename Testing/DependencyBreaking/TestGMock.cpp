#include "gmock/gmock.h"
#include "TestClass.h"

using namespace testing;

class MockTestClass : public ITestClass
{
public:
    MOCK_METHOD2(getMax, int(int, int));
    MOCK_METHOD2(getMin, int(int, int));
};


TEST(Test1, case01)
{
    MockTestClass mockTestClass;
    EXPECT_CALL(mockTestClass, getMax(1, 2)).Times(0);
    ASSERT_EQ(1, 1);
}


