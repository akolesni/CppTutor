#ifndef TESTING_PACKAGEWRITER_H
#define TESTING_PACKAGEWRITER_H

#include "Common/FileSystemUtility.h"

class PackageWriter
{
    PackageWriter(std::unique_ptr<Common::IFileSystemUtility> _fileSystemUtility):
        m_fileSystemUtility(std::move(_fileSystemUtility)){}

    void SetFileSystemUtility(std::unique_ptr<Common::IFileSystemUtility> _fileSystemUtility)
    {
        this->m_fileSystemUtility = std::move(_fileSystemUtility);
    }


    void CreateDestinationDir();

private:
    std::unique_ptr<Common::IFileSystemUtility> m_fileSystemUtility;
//    const Common::IFileSystemUtility& m_fileSystemUtility;
};
#endif //TESTING_PACKAGEWRITER_H
