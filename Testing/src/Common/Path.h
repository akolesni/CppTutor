#ifndef TESTING_PATH_H
#define TESTING_PATH_H

#include <filesystem>
namespace Common {
class Path : public std::filesystem::path {
public:
    using std::filesystem::path::path;
};
}
#endif //TESTING_PATH_H
