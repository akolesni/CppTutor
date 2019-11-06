#ifndef TESTING_PACKAGEWRITER_H
#define TESTING_PACKAGEWRITER_H

#include "Common/FileSystemUtility.h"

namespace old
{
class PackageWriter
{
public:
    void CreateDestinationDir( std::filesystem::path const& rDestinationPath );
};
}
namespace neu
{
    class PackageWriter
    {
        PackageWriter(std::unique_ptr<Common::IFileSystemUtility> _fileSystemUtility) :
                m_fileSystemUtility(std::move(_fileSystemUtility))
        {}

//    void SetFileSystemUtility(std::unique_ptr<Common::IFileSystemUtility> _fileSystemUtility)
//    {
//        this->m_fileSystemUtility = std::move(_fileSystemUtility);
//    }


        void CreateDestinationDir(Common::Path const &rDestinationPath);

    private:
        std::unique_ptr<Common::IFileSystemUtility> m_fileSystemUtility;
//    const Common::IFileSystemUtility& m_fileSystemUtility;
    };
}
namespace exception
{
    class RuntimeError :public std::exception
    {
        using std::exception::exception;
    public:
        RuntimeError(const std::string&){}
    };
    using InvalidArgument = RuntimeError;
}

#endif //TESTING_PACKAGEWRITER_H
