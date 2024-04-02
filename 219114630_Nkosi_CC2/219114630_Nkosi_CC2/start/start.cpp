#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <iomanip>
#include <cstring>
#include "Password.h"
#include "FindReplace.h"
#include "DisplayStock.h"

//219114630 NKOSI LM CC2
using namespace std;
struct Product //Structure to hold the product's name,quantity & price
{
    string name;  
    int quantity;
    double price;
};
vector<Product> inventory;//Assigning vector to temporarily store the product information
mutex mtx;//Multithreading initiated
condition_variable cv;//Multithreading initiated

    Password Pass; //Calling the Password Class and Set Object
    FindReplace FindR;//Calling the FindReplace Class and Set Object
    DisplayStock Disp;//Calling the DisplayStock Class and Set Object

void addStock()//addStock Method
{
    string name;
    int quantity;
    double price;
    fstream myfile;//Assign textfile Variable
    fstream myfileCost;//Assign textfile Variables

    myfile.open("StockList.txt", ios::app);//Open StockList file & Append new information 
    myfileCost.open("StockCost.txt", ios::app);//Open StockCost file & Append new information 

        if (myfile.is_open())
        {
            std::cout << "Enter Product Name: ";
            cin >> name;
            std::cout << "Enter Quantity: ";
            cin >> quantity;
            std::cout << "Enter Price: ";
            cin >> price, "\n";

            myfile << "Product Name : ";
            myfile << name << endl;//Written or appended to file
            myfile << "Product Quantity : ";
            myfile << quantity << endl;;//Written or appended to file
            myfile << "Product Price : R";
            myfile << price << endl;//Written or appended to file
            myfile << "\n";
            myfile << "R";
            myfileCost << quantity;//Written or appended to file
            myfileCost << ",";
            myfileCost << price << endl;//Written or appended to file
            myfileCost << "\n";

            myfile.close();//Close file after operation is complete
            myfileCost.close();

            Product product;
            product.name = name;
            product.quantity = quantity;
            product.price = price;

            inventory.push_back(product);
        }
        std::cout << "Stock added successfully!" << endl;
}

void makePurchase()//makePurchase method
{
    string name;
    int quantity;
    fstream mypurch;//Assign textfile Variable
    mypurch.open("StockPurchases.txt", ios::app);//Open StockPurchase file & Append new information 
    std::cout << "Enter Product Name : ";
    cin >> name;
    std::cout << "Enter Product Quantity : ";
    cin >> quantity;

    for (auto& product : inventory)
    {
        if (product.name == name)
        {
            if (product.quantity >= quantity) {
                product.quantity -= quantity;
                std::cout << "Purchase Successful!" << endl;
                
                if (mypurch.is_open())
                {
                    mypurch << "Product(s) Purchased " << endl;
                    mypurch << "Product Name : ";
                    mypurch << name << endl;
                    mypurch << "Product Quantity : ";
                    mypurch << quantity << endl;;
                    mypurch << "\n";

                    mypurch.close();
                }
                return;
            }
            else
            {
                std::cout << "Purchase Unsuccessful, Insufficient Stock!" << endl;
                return;
            }
        }
    }
    std::cout << "Product not found!" << endl;
}

void modifyItem()//ModifyItem method
{
    string name;
    int choice;

    int offset;
    string line;

    ifstream Mymodify;//Assign textfile Variable
    ofstream Mymodifyrep;//Assign textfile Variable
    Mymodify.open("StockList.txt");//Open StockList file
    Mymodifyrep.open("StockModified.txt");//Open StockModified file

    lock_guard<mutex> lock(mtx);//locking mutex object

    std::cout << "Enter product name: ";
    cin >> name;


    if (Mymodify.is_open()) //Search for product in appropriate file with that information
    {
        while (!Mymodify.eof())
        {
            getline(Mymodify, line);
            if ((offset = line.find(name,0)) != string::npos)
            {
                std::cout << "Product has been found. What do you want to modify?" << endl;
            }
        }
    }
    else
    {
        std::cout << "Could not open file" << endl;
    }
    Mymodify.close();//Close file after operation is complete
 
    auto product = find_if(inventory.begin(), inventory.end(), [name](const Product& p)//Search for product in vector storage
        {
        return p.name == name;//Return product name from the vector storage
        });

    if (product != inventory.end())
    {
        std::cout << "1. Product Name" << endl;
        std::cout << "2. Quantity" << endl;
        std::cout << "3. Price" << endl;
        std::cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter new product name: ";
            cin >> product->name;//Modify Product Name

            std::cout << "Product name modified successfully!" << endl;
            break;
        case 2:
            std::cout << "Enter new quantity: ";
            cin >> product->quantity;//Modify Product Quantity
            std::cout << "Quantity modified successfully!" << endl;
            break;
        case 3:
            std::cout << "Enter new price: ";
            cin >> product->price;//Modify Product Price
            std::cout << "Price modified successfully!" << endl;
            break;
        default:
            std::cout << "Invalid choice!" << endl;
            break;
        }
    }
    else {
        std::cout << "Product not found!" << endl;
    }
}

double calculateStockValue()//calculateStockValue method
{
    std::ifstream file("StockCost.txt");
    std::string line;
    double stockValue = 0.0;

    lock_guard<mutex> lock(mtx);//locking mutex object

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string symbol;
            int quantity;
            double costPerShare;

            if (iss >> symbol >> quantity >> costPerShare) {
                double totalCost = quantity * costPerShare;
                stockValue += totalCost;
            }
        }

        file.close();//Close file after operation is complete
    }
    else
    {
        std::cerr << "Error opening file: " << std::endl;
    }
    return stockValue;//return stockValue
}

int main()
{
    //Assigning String and an Int Variable
    int choice2;

    string username;
    string password;

    string searchstr;
    string replacestr;
    string line;

    ifstream Mycred;//Assign textfile Variable
    fstream mypass;//Assign textfile Variable

    double stockValue = calculateStockValue();
    


    while (true)
    {
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        std::cout << "                                                   Stock Management System" << endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        std::cout << "1. Create Account" << endl;
        std::cout << "2. Login" << endl;
        std::cout << "3. Exit" << endl;
        cin >> choice2;

        switch (choice2)
        {
        case 1:
            mypass.open("Passwords.txt", ios::app);//Appending information of new credentials to the Passwords textfile
            if (mypass.is_open())
            {
                std::cout << "Enter Username : ";
                cin >> username;//Enter new username that will be stored in the passwords file
                std::cout << "Enter Password : ";
                cin >> password;//Enter new password that will be stored in the passwords file

                mypass << username;//Appending the new username in the passwords file
                mypass << ":";
                mypass << password;//Appending the new password in the passwords file
                mypass << "\n";

                mypass.close();//Close file after operation is complete
            }
            break;
        case 2:
            int choice;

            std::cout << "Enter Username: ";
            cin >> username;//Enter username that needs to be found in the passwords file
            std::cout << "Enter Password: ";
            cin >> password;//Enter password that needs to be found in the passwords file

            Mycred.open("Passwords.txt");//Accessing or reading of credentials in the Passwords textfile
            if (Mycred.is_open())
            {
                if (Pass.authenticate(username, password))
                {
                    std::cout << "Authentication successful!" << std::endl;
                    while (true)
                    {

                        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        std::cout << "                                                   Stock Management System" << endl;
                        std::cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        std::cout << "1. Add Stock" << endl;
                        std::cout << "2. Make Purchase" << endl;
                        std::cout << "3. Modify Item" << endl;
                        std::cout << "4. Display Stock" << endl;
                        std::cout << "5. Calculate Stock Value" << endl;
                        std::cout << "6. Exit" << endl;
                        std::cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice)//Choices or options of our system
                        {
                        case 1:
                            std::cout << "                             " << endl;

                            addStock();//Calling the addStock Method
                            thread(addStock).detach();//detaching thread
                            std::cout << "                             " << endl;
                            break;
                        case 2:
                            std::cout << "                             " << endl;
                            makePurchase();//Calling the makePurchase Method
                            thread(makePurchase).detach();//detaching thread
                            std::cout << "                             " << endl;
                            break;
                        case 3:
                            std::cout << "                             " << endl;
                            modifyItem();//Calling the ModifyItem Method
                            std::cout << "Enter Product Name you want to check" << endl;
                            std::cin >> searchstr; // Enter Value that needs to be found in the stock
                            std::cout << "Enter the new Product Name you want" << endl;
                            std::cin >> replacestr;// Enter Value that will replace the existing stock name
                            FindR.findAndReplaceInFile(searchstr, replacestr);//detaching thread
                            thread(modifyItem).detach();
                            std::cout << "                             " << endl;
                            break;
                        case 4:
                            std::cout << "                             " << endl;
                            Disp.displayStock();//Calling the displayStock Method
                            std::cout << "                             " << endl;
                            break;
                        case 5:
                            std::cout << "                             " << endl;
                            calculateStockValue();//Calling the calculateStockValue Method
                            std::cout << "Stock Value: R" << stockValue << std::endl;
                            thread(calculateStockValue).detach();//detaching thread
                            std::cout << "                             " << endl;
                            break;
                        case 6:
                            return 0;
                        default:
                            std::cout << "Invalid choice!" << endl;
                            break;
                        }
                    }
                    while (choice != 6)
                        return 0;
                }
                else
                {
                    std::cout << "Authentication failed!" << std::endl;//Conditional statement if a certain condition has not been met
                }
                Mycred.close();//Close file after operation is complete
                break;
        case 3:
            return 0;
            break;
        default:
            break;
            }
        }
    }
}