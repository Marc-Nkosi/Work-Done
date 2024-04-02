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

using namespace std;
//219114630 NKOSI LM CC2

class DisplayStock
{
public:
    void displayStock()
    {
        fstream reader;
        fstream readermodified;

        std::cout << "                                              Current Inventory:" << endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        reader.open("StockList.txt", ios::in);//Open StockList file & Read information 
        if (reader.is_open())
        {
            string rline;
            while (getline(reader, rline))
            {
                std::cout << rline << endl;
            }
            reader.close();//Close file after operation is complete
            return;
        }
        /*for (const auto& product : inventory) {
            std::cout << "Product Name: " << product.name << endl;
            std::cout << "Product Quantity: " << product.quantity << endl;
            std::cout << "Product Price: R" << product.price << endl;
            std::cout << "               " << endl;
        } */

        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        std::cout << "                                              Current Inventory Modified:" << endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        readermodified.open("StockModified.txt", ios::in);//Open StockModified file & Read information 
        if (readermodified.is_open())
        {
            string rmline;
            while (getline(readermodified, rmline))
            {
                std::cout << rmline << endl;
            }
            readermodified.close();//Close file after operation is complete
            return;
        }
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        return;
    }
};
