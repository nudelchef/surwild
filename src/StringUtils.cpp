#include "StringUtils.h"

namespace StringUtils
{

    std::string removeSpaces(std::string str)
    {
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

}
