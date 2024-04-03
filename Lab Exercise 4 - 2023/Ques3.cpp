#include <iostream>
#include <string>
#include "Ques1.cpp"
#include "Ques2.cpp"
using namespace std;

//219114630 NKOSI LabEx4
class SalesTransaction : public Transaction
{
private: 
   static float commissionPercentage; // class-wide commission percentage
    float bondRegistrationFee;

public: 
    SalesTransaction() : Transaction(), bondRegistrationFee(0.0) {}
    static void changeCommissionPerc(float percentage) { commissionPercentage = percentage;}



    void enterTransaction()
    {
        cout << "Enter Transaction Number: ";
        cin >> transactionNum;
        cout << "Date : " << endl;
        cin >> date;
        cout << "Transaction Amount : R";
        cin >> transactionAmt;
        cout << "Agent Number: ";
        cin >> agentNum;
        cout << "Bond Registration Fee: R";
        cin >> bondRegistrationFee;
        commissionEarned = calculateCommEarned(NULL);
    }

    void displayTransaction()
    {
        cout << "Transaction : " << transactionNum << "Date : " << date  << "Price : R" << transactionAmt << endl;
        cout << "Commission Earned On This Sales Transaction : " << commissionEarned << endl;
        SalesTransaction::displayTransaction(); //Overriden method
    }
    int main()
    {
        SalesTransaction Disp;
        Disp.displayTransaction();
        return 0;
    };

    float calculateCommEarned(Agent* agent)
    {
        if (Agent && agentNum = agent->getAgentNum())
        {
            float commission = (transactionAmt - bondRegistrationFee) * commissionPercentage / 100.0;
            commissionEarned = commission;
            return commission;
        }
        else
        {
            commissionEarned = 0.0;
            return 0.0;
        }
    }
};
