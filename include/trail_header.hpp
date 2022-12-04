#include <iostream>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

class testHeaderImport {
    private:

    public:
        std::vector<int> data;
        std::string name = "testHeaderImport";
        void setName(const std::string& newName);
};