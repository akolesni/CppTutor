#include "gtest/gtest.h"

int main(int args, char* argv[]) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}


/*
TEST(TestFixture, TestName) {
    // 1) Create mock objects (collaborators)

    // 2) Specify your expectations of them

    // 3) Construct object(s) under test, passing mocks

    // 4) Run code under test

    // 5) Check output (using Google Test or some other framework)

    // 6) Let gmock automatically check mock expectations were met at
    //    end of test
}
*/