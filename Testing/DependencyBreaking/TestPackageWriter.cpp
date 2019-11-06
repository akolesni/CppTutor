#include "gmock/gmock.h"
#include "PackageWriter.h"


class TestPackageWriter: public ::testing::Test
{
public:
    void SetUp() override
    {
        if(std::filesystem::exists(m_myPat))
        {
            std::filesystem::remove(m_myPat);
        }
    }
    void TearDown() override
    {
        if(std::filesystem::exists(m_myPat))
        {
            std::filesystem::remove(m_myPat);
        }
    }
    std::filesystem::path m_myPat{"C:\\temp\\packageDir"};
};

TEST_F(TestPackageWriter, createDestinationDir_invalidPath_trowsRuntimeError)
{
    ASSERT_THROW(old::PackageWriter{}.CreateDestinationDir(""), exception::RuntimeError);
}

TEST_F(TestPackageWriter, createDestinationDir_validPath_createdNewDirectory)
{
    ASSERT_FALSE(std::filesystem::exists(m_myPat));
    old::PackageWriter{}.CreateDestinationDir(m_myPat);
    ASSERT_TRUE(std::filesystem::exists(m_myPat));
}

TEST_F(TestPackageWriter, createDestinationDir_directoryExistWithASSETMAP_trowsInvalidArgument)
{
    std::filesystem::path myPath{"C:\\temp\\test111"};
    ASSERT_THROW( old::PackageWriter{}.CreateDestinationDir(myPath), exception::InvalidArgument);
}

TEST_F(TestPackageWriter, createDestinationDir_directoryExist_nothing)
{
    std::filesystem::path myPath{"C:\\temp"};
    ASSERT_TRUE(std::filesystem::exists(myPath));
    old::PackageWriter{}.CreateDestinationDir(myPath);
    ASSERT_TRUE(std::filesystem::exists(myPath));
}
