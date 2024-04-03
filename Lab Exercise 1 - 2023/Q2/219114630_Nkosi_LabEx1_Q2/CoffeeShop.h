#pragma once
#include <iostream>
#include <fstream>
#include <string>
//219114630 NKOSI LM Q2.PART1
class CoffeeShop 
{
private:
    std::string ShName,FName;
    std::string Product[5];
    int QuantityA[5];
    double Price[5];
    double Turnover;
 
public:
      CoffeeShop(std::string ShName)
    {
        double Price[5];
        int QuantityA[5];
        ShName = "Cafe by Nkosi";
        Turnover = 0.0;
    }
 
    //Loading of the File
    void loadProducts(std::string FName) {
        std::string PLine;
        std::ifstream file(FName);
        int a = 0;

        while (std::getline(file, PLine) && a < 5)
        {
            size_t position1 = 0, position2 = 0;
            position2 = PLine.find(',', position1);
            Product[a] = PLine.substr(position1, position2 - position1);
            position1 = position2 + 1;
            position2 = PLine.find(',', position1);
            QuantityA[a] = std::stoi(PLine.substr(position1, position2 - position1));
            position1 = position2 + 1;
            Price[a] = std::stod(PLine.substr(position1));
            a++;
        }
        file.close();
    }
    //Method to search for the product
    int Search(std::string PName)
    {
        for (int i = 0; i < 5; i++)
        {
            if (Product[i] == PName)
            {
                return i;
            }
        }
        return -1;
    }
 
    //Method to buy a product
    bool Buy(double Cash, std::string PName, int QuantityP)
    {
        int index = Search(PName);
        if (index == -1)
        {
            std::cout << "Invalid Product Name" << std::endl;
            return false;
        }
        double cost = Price[index] * QuantityP;
        if (Cash < cost)
        {
            std::cout << "You do not have enough money!!" << std::endl;
            return false;
        }
        if (QuantityP > QuantityA[index])
        {
            std::cout << "There's not enough quantity" << std::endl;
             return false;
        }
        QuantityA[index] -= QuantityP;
        Turnover += cost;
        std::cout << "Transaction Successful" << std::endl;
        return true;
    }
 
    //Displaying Product Info
    void Display()
    {
        std::cout << "Product Information : " << std::endl;
        for (int i = 0; i < 5 ; i++)
        {    
         std::cout << Product[i] << " - " << QuantityA[i] << " Available, R" << Price[i] << " Per Unit" << std::endl;
        }
        std::cout << "Today's Turnover : R" << Turnover << std::endl;
    } 
};
