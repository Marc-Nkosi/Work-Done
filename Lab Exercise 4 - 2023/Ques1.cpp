#include <iostream>
#include <cstring>
using namespace std;

//219114630 NKOSI LabEx4
class Agent
{
public:
    int agentNum; 
    char agent_name[100];
    float total_commission;


    Agent(int agentNum = 0, const char* agent_name = "", float total_commission = 0.0) : agentNum(agentNum), total_commission(total_commission)
    {
        strcpy(this->agent_name, agent_name);
    }
 
    Agent(const Agent& other)
    {
        agentNum = other.agentNum;
        strcpy(agent_name, other.agent_name);
        total_commission = other.total_commission;
    }
 
    void enterAgent()
    {
        cout << "Enter agent number: ";
        cin >> agentNum;
        cout << "Enter agent name: ";
        cin.ignore();
        cin.getline(agent_name, 100);
    }
 
    void displayAgent() const
    {
        cout << "Agent : " << agentNum << "    " << agent_name << "     Total Commission Earned: " << total_commission << endl;
    }
 
    int getAgentNum() const
    {
        return agentNum;
    }
 
    float getTotalCommission() const
    {
        return total_commission;
    }
 
    Agent operator+(float commission) const
    {
        return Agent(agentNum, agent_name, total_commission + commission);
    }
 
    Agent& operator=(const Agent& other)
    {
        agentNum = other.agentNum;
        strcpy(agent_name, other.agent_name);
        total_commission = other.total_commission;
        return *this;
    }

    bool operator>(const Agent& other) const
    {
        return total_commission > other.total_commission;
    }
};