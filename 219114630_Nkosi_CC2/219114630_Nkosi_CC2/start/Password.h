#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <thread>

//219114630 NKOSI LM CC2


class Password
{
public :
    bool authenticate(const std::string& username, const std::string& password)
    {
        std::ifstream file("Passwords.txt");
        std::string line;

        while (std::getline(file, line)) {
            std::string storedUsername, Password;
            size_t separatorPos = line.find(':');
            if (separatorPos != std::string::npos) {
                storedUsername = line.substr(0, separatorPos);
                Password = line.substr(separatorPos + 1);

                if (username == storedUsername && password == Password) {
                    file.close();//Close file after operation is complete
                    return true;
                }
            }
        }

        file.close();//Close file after operation is complete
        return false;
    }

};
