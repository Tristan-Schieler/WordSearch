#include"FileReader.h"
#include<iostream>
#include<fstream>
#include <algorithm>

std::vector<std::string> FileReader::read(std::string pathToFile)
{
    std::ifstream file(pathToFile);

    if(!file.is_open())
    {
        std::cout << "Cannot open given file returning empty" << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::string> result;
    while(getline(file, line))
    {
        if(correctFormat(line))
            result.push_back(line);
        else
            std::cout << "Cannot use non alpha string: " << line << std::endl;
    }
    file.close();

    return result;
}

bool FileReader::correctFormat(std::string& line)
{
    std::string temp;
    for(auto& ch : line)
    {
        if( (ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z'))
        {
            return false;
        }
        tolower(ch);
    }

    return true;
}