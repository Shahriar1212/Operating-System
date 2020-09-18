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
    freopen("input.txt", "r", stdin);
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