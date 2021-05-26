#include "csv.h"

#include <iostream>
#include <sstream>

// Feed this function 1 line a time
std::vector<std::string> lineTokenizer1(std::istream& str)
{
    std::vector<std::string> result;
    std::string line;

    std::getline(str,line);

    std::stringstream  lineStream(line);
    std::string cell;

    while(std::getline(lineStream,cell,','))
    {
        result.push_back(cell);
    }

    if(!lineStream && cell.empty())
    {
        result.emplace_back("");
    }

    return result;
}
