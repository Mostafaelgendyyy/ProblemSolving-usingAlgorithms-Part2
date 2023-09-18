#include<iostream>
#include<algorithm>
using namespace std;

class Job
{
    char JobID;
    int deadline;
    int profit;
public:
    char getJobId() const {
        return JobID;
    }

    void setJobId(char jobId) {
        JobID = jobId;
    }

    int getDeadline() const {
        return deadline;
    }

    void setDeadline(int deadline) {
        Job::deadline = deadline;
    }

    int getProfit() const {
        return profit;
    }

    void setProfit(int profit) {
        Job::profit = profit;
    }

    Job(char ID, int time, int pr) {
        this->JobID=ID;
        this->deadline=time;
        this->profit=pr;
    }
};

bool CompareProfits(Job x, Job y)
{
    if (x.getProfit()> y.getProfit())
        return true;
    return false;
}

void GetJobSchedule(Job AllJ[], int Capacity)
{
    sort(AllJ, AllJ + Capacity, CompareProfits);
    int Res[Capacity];
    bool Frequenc[Capacity] ;
    for (int i =0; i < Capacity; ++i)
    {
        Frequenc[i]= false;
    }

    for (int i=0; i < Capacity; i++)
    {
        for (int j= min(Capacity, AllJ[i].getDeadline()) - 1; j >= 0; j--)
        {
            if (Frequenc[j] == false)
            {
                Res[j] = i;
                Frequenc[j] = true;
                break;
            }
        }
    }
    for (int i=0; i < Capacity; i++)
    {
        if (Frequenc[i] == true)
        {
            cout << AllJ[Res[i]].getJobId() << "  ";
        }
    }
}

int main()
{
    Job ob1[] = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30} };
    int S = sizeof(ob1) / sizeof(ob1[0]);
    cout << "Output of Example 1 " <<endl;
    cout<< "Following is maximum profit sequence of jobs: " <<endl;
    GetJobSchedule(ob1, S);

    cout<<endl <<endl<<endl<<endl;

    Job ob2[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    S= sizeof(ob2) / sizeof(ob2[0]);
    cout << "Output of Example 2 " <<endl;
    cout << "Following is maximum profit sequence of jobs: " <<endl;
    GetJobSchedule(ob2, S);
    return 0;
}