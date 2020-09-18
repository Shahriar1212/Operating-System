/**
===============Circular Scan Disk Arm Scheduling Algorithm===============
*/
#include<bits/stdc++.h>
using namespace std;


int head_number;
int current_pos;
int request_number;
int head;
vector<int> request;
vector<int> req;
int movement = 0;
int total_movement = 0;
int index;

void input()
{
    printf("Number of heads: ");
    scanf("%d",&head_number);
    printf("Number of request: ");
    scanf("%d",&request_number);
    printf("Cylinder request: ");
    for(int i=0;i<request_number;i++)
    {
        int temp;
        scanf("%d",&temp);
        request.push_back(temp);
    }
    printf("Current head position: ");
    scanf("%d",&head);
    req = request;
    req.push_back(head);
}

bool is_req(int a)
{
    bool check = false;
    for(int i=0;i<request.size();i++)
    {
        if(a == request[i])
        {
            check = true;
        }
    }
    return check;
}


void print_output(int index)
{
    printf("\n\n===============Circular Scan Disk Scheduling Algorithm===============\n\n");
    printf("Cylinder Serving Order: \n");
    for(int i=index;i<req.size();i++)
    {
        //if(is_req(req[i]))    // uncommenting this line will print last head even if its not in request
            printf("%d -> ",req[i]);
    }
    for(int i=0;i<index;i++)
        //if(is_req(req[i]))   // uncommenting this line will print first head even if its not in request
            printf("%d -> ",req[i]);
    printf("\nTotal Cylinder Movement : %d\n",total_movement);
}
int CSCAN()
{
    sort(req.begin(), req.end());
    for(int i=0;i<req.size();i++)
    {
        if(req[i] == head)
        {
            index = i;
            break;
        }
    }

    if(index > 0 && index < head_number){
        req.push_back(0);
        req.push_back(head_number);
    }
    sort(req.begin(), req.end());
    for(int i=0;i<req.size();i++)
    {
        if(req[i] == head)
        {
            index = i;
            break;
        }
    }

    for(int i=index;i<req.size();i++)
    {
        movement = abs(head - req[i]);
        total_movement += movement;
        head = req[i];
    }

    for(int i=0;i<index;i++)
    {
        movement = abs(head - req[i]);
        total_movement += movement;
        head = req[i];
    }

    return total_movement;
}

int main()
{
    input();
    int seek_time = CSCAN();
    print_output(index);
}


/**
Input Output
============


Number of heads: 199
Number of request: 8
Cylinder request: 98 183 37 122 14 124 65 67
Current head position: 53


===============Circular Scan Disk Arm Scheduling Algorithm===============

Cylinder Serving Order:
53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 0 -> 14 -> 37 ->
Total Cylinder Movement : 382

Process returned 0 (0x0)   execution time : 6.936 s
Press any key to continue.

**/

