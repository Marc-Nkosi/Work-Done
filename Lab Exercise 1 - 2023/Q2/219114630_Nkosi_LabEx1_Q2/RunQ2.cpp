#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include<istream>
#include "CoffeeShop.h"
//219114630 NKOSI LM Q2.PART2/RUNQ2
int main()
{
    CoffeeShop CShop("");//Calling CoffeeShop.h
    int selection = 0;//Assigning value to switch variable  
    double Cash;
    std::string PName;
    int Quantity;
    
    std::cout << "Coffee Shop Menu:" << std::endl;
    std::cout << "====================================" << std::endl;
    
    do {
        std::cout << "1. Load Products" << std::endl;
        std::cout << "2. Buy a product" << std::endl;
        std::cout << "3. Display all product info" << std::endl;
        std::cout << "4. Exit........." << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> selection;
        switch (selection)
        {
        case 1:
            std::cout << "Enter filename to load products from: ";
            std::cin >> PName;
            CShop.loadProducts(PName);//Load Method from CoffeeShop.h
            std::cout << "Data Loaded Successfully" << std::endl;
            break;
        case 2:
            std::cout << "Enter amount of money you have : R";
            std::cin >> Cash;
            std::cout << "Enter name of product you want to buy : ";
            std::cin >> PName;
            std::cout << "Enter quantity you want to buy : ";
            std::cin >> Quantity;
            CShop.Buy(Cash, PName, Quantity);//Buy Method from CoffeeShop.h
            //std::cout << "Transaction Successful" << std::endl;
            break;
        case 3:
            CShop.Display();//Display Method from CoffeeShop.h
            break;
        case 4:
            std::cout << "Exiting program" << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again" << std::endl;
            break;
        }
    } while (selection != 4);
    return 0;
}