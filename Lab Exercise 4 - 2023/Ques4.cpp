#include <iostream>
#include <string>
#include "Ques1.cpp"
#include "Ques2.cpp"
#include "Ques3.cpp"
using namespace std;

//219114630 NKOSI LabEx4
class RentalTransaction : public Transaction
{
public:
    int rentalPeriod;
    static float commissionPerc;
    RentalTransaction() : Transaction(), rentalPeriod(0) {}
    void enterTransaction();
    void displayTransaction();
    void calculateCommEarned(Agent& agent);
    
    static void changeCommissionPerc(float newCommissionPerc)
    {
        commissionPerc = newCommissionPerc;
    }

    int main()
    {
        SalesTransaction Sales;
        Sales.enterTransaction();
        return 0;
    }
};

float RentalTransaction::commissionPerc = 0.0;

void RentalTransaction::enterTransaction()
{
    Transaction::enterTransaction();//Overriden method
};

void RentalTransaction::displayTransaction()
{
    Transaction::displayTransaction();//Overriden method
};

void RentalTransaction::calculateCommEarned(Agent& agent) //Overriding method calculateCommEarned that receives an Agent object
{
    if (getAgentNum() == agentNum)
    {
        commissionEarned = transactionAmt * rentalPeriod * commissionPerc / 100.0f;
    }
    else
    {
        commissionEarned = 0.0;
    }
};