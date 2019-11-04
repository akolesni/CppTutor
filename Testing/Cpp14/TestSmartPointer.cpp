#include "gtest/gtest.h"
#include "MyStruct.h"
#include <memory>

namespace test::SmartPointer
{
class Foo
{
private:
    unsigned char value1{};
    int value2{};
    long long value3{};
};

class Holder
{
    Holder(const std::shared_ptr<Foo> _ptr):
    mMyPtr{_ptr}
    {}
private:
    std::shared_ptr<Foo> mMyPtr;
};

void foo1(const std::shared_ptr<Foo> _foo)
{

}

}

using test::SmartPointer::Foo;

TEST(TestUnique, test)
{
    {
        std::unique_ptr<test::MyStruct> uPtr{new test::MyStruct};
    }
    std::cout << "----- scope end";

    ASSERT_EQ(1, 1);
}

TEST(TestSharedPtr, test)
{
    test::MyStruct inst1;
    ASSERT_EQ(1, 1);

}

