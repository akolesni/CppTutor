#ifndef TESTING_FILESYSTEMUTILITY_H
#define TESTING_FILESYSTEMUTILITY_H

#include "Path.h"

namespace Common
{
class IFileSystemUtility
{
public:
    virtual bool IsDirectory(const Path& _path) = 0;
    virtual bool CreateDirectory(const Path& _path) = 0;
    virtual bool Exists(const Path& _path) = 0;
};

class FileSystemUtility : public IFileSystemUtility
{
    bool IsDirectory(const Path& _path) override
    {
        return std::filesystem::is_directory(_path);
    }

    bool CreateDirectory(const Path& _path)override
    {
        return std::filesystem::create_directory(_path);
    }

    bool Exists(const Path& _path)override
    {
        return std::filesystem::exists(_path);
    }
};

class FileSystemUtilityFactory
{
public:
    static std::unique_ptr<IFileSystemUtility> createTestClass()
    {
        if (nullptr == s_testClass)
        {
            s_testClass = std::make_unique<FileSystemUtility>();
        }

        return std::move(s_testClass);
    }

    static void setTestClass(std::unique_ptr<IFileSystemUtility>&& testClass)
    {
        s_testClass = std::move(testClass);
    }
private:
    static std::unique_ptr<IFileSystemUtility> s_testClass;
};
}
#endif //TESTING_FILESYSTEMUTILITY_H
