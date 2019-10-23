#include "gmock/gmock.h"
#include "TestClass.h"
#include "TestMocks.h"

TEST(Test1, case01)
{
    MockTestClass mockTestClass;
    EXPECT_CALL(mockTestClass, getMax(1, 2)).Times(0);
    ASSERT_EQ(1, 1);
}


