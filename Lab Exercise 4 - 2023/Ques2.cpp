#include <iostream>
#include <string>
#include "Ques1.cpp"
using namespace std;

//219114630 NKOSI LabEx4
class Transaction
{
public:
    int transactionNum;
    int agentNum;
    string date;
    float transactionAmt;
    float commissionEarned; 
 
    Transaction()
    {
        transactionNum = 0;
        agentNum = 0;
        date = "";
        transactionAmt = 0.0;
        commissionEarned = 0.0;
    }
 
    Transaction(int tNum, int aNum, string d, float tAmt, float cEarned)
    {
        transactionNum = tNum;
        agentNum = aNum;
        date = d;
        transactionAmt = tAmt;
        commissionEarned = cEarned;
    }
 
    void enterTransaction()
    {
        cout << "Enter Transaction Number : ";
        cin >> transactionNum;
        cout << "Date (DD/MM/YYYY) : ";
        cin >> date;
        cout << "Transaction Amount : ";
        cin >> transactionAmt;
        cout << "Agent Number : ";
        cin >> agentNum;
        commissionEarned = 0.0;
    }
    void displayTransaction()//public method displayTransaction that receives the commission earned by the agent for that particular transaction
    {
        cout << "Transaction :    " << transactionNum  << "Date : " << date << "Price : R" << transactionAmt << endl;
    }
    float calculateCommEarned(Agent agent)//public method calculateCommEarned that receives an Agent object, and that calculates and returns the commission that the agent will earn on the transaction
    {
        float commissionRate = 0.0;
        if (transactionAmt > 0)
        {
            if (transactionAmt >= 1000000)
            {
                commissionRate = 0.05;
            }
            else if (transactionAmt >= 500000)
            {
                commissionRate = 0.04;
            }
            else if (transactionAmt >= 250000)
            {
                commissionRate = 0.03;
            }
            else
            {
                commissionRate = 0.02;
            }
        }
        commissionEarned = transactionAmt * commissionRate;
        agent = agent + commissionEarned;
        return commissionEarned;
    }
    float getCommEarned() //public accessor method to get the commission earned on the transaction.
    {         
        return commissionEarned;
    }
    int getAgentNum()//public accessor method that will return the agent number of the agent that handled the transaction.
    {
        return agentNum;
    }
};