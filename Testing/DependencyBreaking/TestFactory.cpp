#include "gmock/gmock.h"
#include "TestMocks.h"




TEST(Test_ClassFactory, createTestClass_createTestClassInstance_createdTheTestClassInstance)
{
    std::unique_ptr<ITestClass> testClass = TestClassFactory::createTestClass();
    ASSERT_EQ("TestClass", testClass->getName());
}

TEST(Test_ClassFactory, createTestClass_createMockInstance_createdTheMockInstance)
{
    // 1) Create mock
    std::string mockName = "MockTestClass";
    std::unique_ptr<MockTestClass> mockTestClass = std::make_unique<MockTestClass>();

    // 2) Specify expectation of mock
    EXPECT_CALL(*mockTestClass, getName()).WillOnce(Return(mockName));

    // 3) Construct object under test
    TestClassFactory::setTestClass(std::move(mockTestClass));

    // 4) Run code under test
    std::unique_ptr<ITestClass> testClass = TestClassFactory::createTestClass();

    // 5) Check output
    ASSERT_EQ(mockName, testClass->getName());
}
