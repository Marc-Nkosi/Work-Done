#pragma once
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cstring>

//219114630 NKOSI LM CC2
class FindReplace
{
public:
    void findAndReplace(std::string& line, const std::string& searchStr, const std::string& replaceStr)
    {
        size_t pos = 0;
        while ((pos = line.find(searchStr, pos)) != std::string::npos)
        {
            line.replace(pos, searchStr.length(), replaceStr);
            pos += replaceStr.length();
        }
    }

    void findAndReplaceInFile(const std::string& searchStr, const std::string& replaceStr)
    {
        std::ifstream ifs("StockList.txt");
        std::ofstream ofs("StockModified.txt");
        if (ifs.is_open() && ofs.is_open())
        {
            std::string line;
            while (std::getline(ifs, line)) {
                findAndReplace(line, searchStr, replaceStr);
                ofs << line << std::endl;
            }

            std::cout << "Text replaced successfully!" << std::endl;
        }
        else
        {
            std::cerr << "Error opening files!" << std::endl;
        }

        ifs.close();//Close file after operation is complete
        ofs.close();//Close file after operation is complete
    }
};
