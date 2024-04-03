#include <iostream>
#include <string>
#include "Ques1.cpp"
#include "Ques2.cpp"
#include "Ques3.cpp"
#include "Ques4.cpp"
using namespace std;

//219114630 NKOSI LabEx4
int main()
{
    Agent nameAgent;//Calling Method
    nameAgent.enterAgent();

    RentalTransaction myRentDisp;//Calling Method
    myRentDisp.displayTransaction();
    return 0;

    SalesTransaction mySalesDisp;//Calling Methods
    mySalesDisp.displayTransaction();
    return 0;

    SalesTransaction::changeCommissionPerc(7.5);// Set commission percentages
    RentalTransaction::changeCommissionPerc(4);// Set commission percentages


    Agent agents[3]; //Array for Agents
    SalesTransaction sales[10];//Array for Sales Transactions
    RentalTransaction rentals[10];//Array for Rental Transactions

    string agent1,agent2,agent3;

    //information for Agents
    for (int g = 0; g < 3; g++)
    {
        std::cout << "Enter Agent " << g << endl;
        agents[g];
    }

    //information for Sales Transactions
    for (int l = 0; l < 10; l++)
    {
        std::cout << "Sales Transaction " << l << endl;
        sales[l];
    }

    //information for Rental Transactions
    for (int m = 0; m < 10; m++)
    {
        std::cout << "Rental Transaction " << m << endl;
        rentals[m];
    }


    for (int i = 0; i < 3; i++)// Accumulate commission earned by each Agent
    {
        Agent* agent = &agents[i];
        float commissionEarned = 0;

        for (int j = 0; j < 10; j++) //commission earned on SalesTransactions
        {
            if (sales[j].getAgentNum() == agent->getAgentNum())
            {

                commissionEarned += sales[j].calculateCommEarned(agent);
                std::cout << "Transaction"<< mySalesDisp.transactionNum <<"Date" << mySalesDisp.date <<"Price"<< mySalesDisp.transactionAmt <<"Commission earned on this sales transaction: R" << commissionEarned <<endl;
            }
        }

        for (int z = 0; z < 10; z++)//commission earned on RentalTransactions
        {
            if (rentals[z].getAgentNum() == agent->getAgentNum())
            {
                commissionEarned += rentals[z].calculateCommEarned(agent);
                std::cout << "Transaction"<< myRentDisp.transactionNum << "Date" << myRentDisp.date << "Price" << myRentDisp.transactionAmt << "Commission earned on this rental transaction: R" << commissionEarned << endl;
            }
        }
        //Print payslip for current agent
        std::cout << "Agent" << myRentDisp.agentNum << "Name"<< nameAgent.agent_name << "Price"<< mySalesDisp.transactionAmt << "Total Commission Earned : R" << commissionEarned << endl;
    }

    Agent* agentOfTheMonth = nullptr;
    float highestCommission = 0;

    for (int p = 0; p < 3; p++)// Determine agent of the month
    {
        Agent* agent = &agents[p];
        float commissionEarned = 0;

        for (int j = 0; j < 10; j++)//commission earned on SalesTransactions
        {
            if (sales[j].getAgentNum() == agent->getAgentNum())
            {
                commissionEarned += sales[j].calculateCommEarned(agent);
            }
        }

        for (int s = 0; s < 10; s++)// commission earned on RentalTransactions
        {
            if (rentals[s].getAgentNum() == agent->getAgentNum())
            {
                commissionEarned += rentals[s].calculateCommEarned(agent);
            }
        }

        if (commissionEarned > highestCommission)
        {
            highestCommission = commissionEarned;
            agentOfTheMonth = agent;
            std::cout << "Agent of the month: " << agentOfTheMonth->agent_name << endl;
        }
    }
    delete agentOfTheMonth;
    return 0;
};