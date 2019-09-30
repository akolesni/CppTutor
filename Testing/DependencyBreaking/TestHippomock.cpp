#include "gtest/gtest.h"
#include "hippomocks.h"

#include "TestClass.h"


TEST(TestHippomock, onCallFunc_callGlobalUser_assert)
{
    MockRepository mocks;
    mocks.OnCallFunc(get2).Return(10);

    ASSERT_EQ(13, add2(3));
}

TEST(TestHippomock, getFileSize_fileOpened_expectedSize)
{
    long result = 1000L;
    MockRepository mocks;
    mocks.ExpectCallFunc(fopen).Return((FILE*) 10);
    mocks.ExpectCallFunc(ftell).Return(result);
    mocks.ExpectCallFunc(fclose).Return(0);

    ASSERT_EQ(result, getFileSize("C:/path/"));
}

TEST(TestHippomock, getFileSize_fileNotOpened_expectedSize)
{
    MockRepository mocks;
    mocks.ExpectCallFunc(fopen).Return((FILE*) NULL);
    mocks.NeverCallFunc(ftell);
    mocks.NeverCallFunc(fclose);

    ASSERT_EQ(-1L, getFileSize("C:/path/to/file.txt"));
}
