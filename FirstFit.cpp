/**
        Memory Management Of an OS
        First Fit Algorithm
**/
#include <bits/stdc++.h>
#include <utility>
using namespace std;

int holeNumber;
int requestNumber;
int request[100];
int totalFragmentation= 0;
pair <string, int> hole[100];
bool isFailed = false;
bool found = false;


string int_to_str(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

void input()
{
    //freopen("input_best_fit.txt", "r", stdin);
    printf("Enter Total Block Number: ");
    scanf("%d",&holeNumber);
    printf("Enter Each Block Size: ");
    for(int i=0; i<holeNumber; i++)
    {
        int temp;
        scanf("%d",&temp);
        string s = "Block ";
        hole[i].first = s + int_to_str(i);
        hole[i].second = temp;
    }
    printf("Enter Total Request Number: ");
    scanf("%d",&requestNumber);

    printf("Enter Each Request Size: ");
    for(int i=0; i<requestNumber; i++)
        scanf("%d",&request[i]);

}

int firstFit()
{

    for(int i=0; i<requestNumber; i++)
    {

        found = false;
        int index = -1;
        for(int j=0; j<holeNumber; j++)
        {
            if(hole[j].second >= request[i] && found == false)
            {
                index = j;
                found = true;
            }
        }
        if(index==-1)
        {
            isFailed = true;
            printf("[-] %d is failed to serve\n",request[i]);
            printf("Quiting Simulation\n");
            printf("Calculating External Fragmentation\n");
        }
        if(isFailed)
        {
            for(int k=0; k<holeNumber; k++)
            {
                totalFragmentation += hole[k].second;
            }
            return totalFragmentation;
        }
        if(index != -1)
        {
            printf("[+] %d is served by %s\n",request[i],hole[index].first.c_str());
            printf("%s new size is : (%d - %d = %d)\n",hole[index].first.c_str(),hole[index].second,request[i], (hole[index].second-request[i]));
            hole[index].second -= request[i];
            printf("=====================================\n");
        }
    }

    return totalFragmentation;
}

void remainingBlocks()
{
    printf("Remaining Blocks Size : \n");
    printf("Memory Block\t\tSize\n");
    for(int i=0; i<holeNumber; i++)
    {
        printf(" %s\t\t %d\n",hole[i].first.c_str(),hole[i].second);
    }
}

void initialBlockSize()
{
    printf("\n\nInitial Blocks Size : \n");
    printf("Memory Block\t\tSize\n");
    for(int i=0; i<holeNumber; i++)
    {
        printf(" %s\t\t %d\n",hole[i].first.c_str(),hole[i].second);
    }
    printf("\n\n");
}

int main()
{
    input();
    initialBlockSize();
    int externalFragmentation = firstFit();
    printf("\nExternal Fragmentation: %d\n\n",externalFragmentation);
    remainingBlocks();

    return 0;
}



/**
input
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40
*/


/**
Input Output
============

Enter Total Block Number: 5
Enter Each Block Size: 50 200 70 115 15
Enter Total Request Number: 10
Enter Each Request Size: 100 10 35 15 23 6 25 55 88 40


Initial Blocks Size :
Memory Block            Size
 Block 0                 50
 Block 1                 200
 Block 2                 70
 Block 3                 115
 Block 4                 15


[+] 100 is served by Block 1
Block 1 new size is : (200 - 100 = 100)
=====================================
[+] 10 is served by Block 0
Block 0 new size is : (50 - 10 = 40)
=====================================
[+] 35 is served by Block 0
Block 0 new size is : (40 - 35 = 5)
=====================================
[+] 15 is served by Block 1
Block 1 new size is : (100 - 15 = 85)
=====================================
[+] 23 is served by Block 1
Block 1 new size is : (85 - 23 = 62)
=====================================
[+] 6 is served by Block 1
Block 1 new size is : (62 - 6 = 56)
=====================================
[+] 25 is served by Block 1
Block 1 new size is : (56 - 25 = 31)
=====================================
[+] 55 is served by Block 2
Block 2 new size is : (70 - 55 = 15)
=====================================
[+] 88 is served by Block 3
Block 3 new size is : (115 - 88 = 27)
=====================================
[-] 40 is failed to serve
Quiting Simulation
Calculating External Fragmentation

External Fragmentation: 93

Remaining Blocks Size :
Memory Block            Size
 Block 0                 5
 Block 1                 31
 Block 2                 15
 Block 3                 27
 Block 4                 15

Process returned 0 (0x0)   execution time : 15.379 s
Press any key to continue.
**/
