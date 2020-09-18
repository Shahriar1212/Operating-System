#include<bits/stdc++.h>
using namespace std;

#define RESOURCES 3
#define MX 10

class Process
{
public:
    int id;
    int allocation[RESOURCES];
    int maxx[RESOURCES];
    int need[RESOURCES];
    bool complete = false;
};

Process process[MX];
int n;
int totalResources[RESOURCES];
int available[RESOURCES];
bool complete[MX];
vector<int> sequence;

void input()
{
    //freopen("input.txt", "r", stdin);
    for(int i = 1 ; i <= RESOURCES ; i++)
        cin >> totalResources[i];

    for(int i = 1 ; i <= RESOURCES ; i++)
        cin >> available[i];

    cin >> n;

    for(int i = 1 ; i <=n ; i++)
    {
        process[i].id = i;
        for(int j = 1 ; j <= RESOURCES ; j++)
            cin >>process[i].allocation[j];
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= RESOURCES ; j++)
        {
            cin >>process[i].maxx[j];
            process[i].need[j] = process[i].maxx[j] - process[i].allocation[j];
        }
    }
}

void bankerAlgorithm()
{
    for(int l = 1 ; l <= n ; l++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(!complete[i])
            {
                bool check = true;
                for(int j = 1 ; j <= RESOURCES ; j++)
                {
                    if(process[i].need[j] <= available[j])
                    {
                        check = true;
                    }else{
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    sequence.push_back(process[i].id);
                    complete[i] = true;
                    for(int j = 1 ; j <= RESOURCES ; j++)
                    {
                        available[j] += process[i].allocation[j];
                    }
                }
            }
        }
    }
}

void print()
{
    bool isSafe = true;
    for(int i=1;i<=n;i++)
    {
        if(!complete[i])
        {
            isSafe = false;
            break;
        }
    }

    if(isSafe)
        printf("The System is currently in safe state and \nThe sequence is : ");
    else
        printf("The System is not in safe state\n");

    for(int i=0;i<sequence.size();i++)
    {
        printf("P%d -> ",sequence[i]);
    }
    printf("\n");
    for(int i = 1 ; i<= n ; i++)
    {
        if(!complete[i])
            printf("p%d needs additional resources\n",i);
    }
}
int main()
{
    input();
    bankerAlgorithm();
    print();
}


/**

Input
-----

10 5 7
3 3 2
5
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

**/


/**

Total RESOURCE : A=10, B=5, C=7

|  Process  |  Allocation  |  Max Need  |  Remaining(Need)  |
=============================================================
|           |   A  B  C    |  A  B  C   |    A    B    C    |
=============================================================
|    P1     |   0  1  0    |  7  5  3   |    7    4    3    |
-------------------------------------------------------------
|    P2     |   2  0  0    |  3  2  2   |    1    2    2    |
-------------------------------------------------------------
|    P3     |   3  0  2    |  9  0  2   |    6    0    0    |
-------------------------------------------------------------
|    P4     |   2  1  1    |  4  2  2   |    2    1    1    |
-------------------------------------------------------------
|    P5     |   0  0  2    |  5  3  3   |    5    3    1    |
=============================================================
Max Allocation= 7  2  5


Available = (Total RESOURCE - Max Allocation)
          =  3,  2,  2

**/


/**
Another Input Output
====================

20 19 16
7 9 5
7
1 1 1
2 3 3
3 0 5
2 2 0
3 1 0
1 2 1
1 1 1
7 5 6
5 8 5
9 2 8
8 8 6
14 4 5
4 6 3
2 9 2
The System is currently in safe state and
The sequence is : P1 -> P2 -> P3 -> P4 -> P5 -> P6 -> P7 ->

Process returned 0 (0x0)   execution time : 1.136 s
Press any key to continue.
**/



