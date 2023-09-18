#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int MST_Prims_Algorithm(int graph[7][7])
{


    bool FreqV[7];

    for(int i=0; i<7; i++)
    {
        FreqV[i]=false;
    }


    FreqV[0] = true;

    int row;
    int col;

    cout << "  Edge" << "      " << "cost"<< endl;
    cout << "------------------";
    int totalcost=0;
    cout << endl;
    for (int E=0;E < 6;++E)
    {

        int minmun = INT_MAX;
        row = 0;
        col = 0;

        for (int i = 0; i < 7; i++)
        {
            if (FreqV[i])
            {
                for (int j = 0; j < 7; j++)
                {
                    if (!FreqV[j] && graph[i][j])
                    {
                        if (minmun > graph[i][j])
                        {
                            minmun = graph[i][j];
                            row = i;
                            col = j;
                        }

                    }
                }
            }
        }
        cout << row+1 <<  "  -->  " << col+1 << "    " << graph[row][col];
        totalcost+=graph[row][col];
        cout << endl;
        FreqV[col] = true;

    }
    return totalcost;

}

int main ()
{
    int graph[7][7] = {{ 0, 2, 4, 1, 0 ,0 , 0},
                       { 2, 0, 0, 3, 10 ,0 , 0},
                       { 4, 0, 0, 2, 0 ,5 , 0},
                       { 1, 3, 2, 0, 7 ,8 , 4},
                       { 0, 10, 0, 7, 0 ,0 , 6},
                       { 0, 0, 5, 8, 0 ,0 , 1},
                       { 0, 0, 0, 4, 6 ,1 , 0}
    };
    int t= MST_Prims_Algorithm(graph);
    cout << "Total Minimum Cost = " << t<< endl;
    return 0;
}
