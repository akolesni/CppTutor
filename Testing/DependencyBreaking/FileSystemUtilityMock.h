#ifndef TESTING_PACKAGEWRITERMOCK_H
#define TESTING_PACKAGEWRITERMOCK_H

#include "gmock/gmock.h"
#include "Common/FileSystemUtility.h"

using namespace testing;
class FileSystemUtilityMock : public Common::IFileSystemUtility
{
public:
    MOCK_METHOD1(IsDirectory, bool(const Path&));
    MOCK_METHOD1(CreateDirectory, bool(const Path&));
    MOCK_METHOD1(Exists, bool(const Path&));
};
#endif //TESTING_PACKAGEWRITERMOCK_H
