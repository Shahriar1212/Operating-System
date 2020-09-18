/**
    First come first serve disk-arm scheduling algorithm
**/

#include<bits/stdc++.h>
using namespace std;


int head_number;
int current_pos;
int request_number;
int head;
vector<int> request;


void input();
int FCFS();
void print_output(int seek_time);

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
}


int FCFS()
{
    int movement = 0;
    int total_movement = 0;
    for(int i=0;i<request.size();i++)
    {
        movement = abs(head - request[i]);
        total_movement += movement;
        head = request[i];
    }

    return total_movement;

}

void print_output(int seek_time)
{
    printf("\n\n===============First Come First Serve Disk Scheduling Algorithm===============\n\n");
    printf("Cylinder Serving Order: ");
    for(int i=0;i<request.size();i++)
    {
        printf("%d",request[i]);
        if(i!=request.size()-1)
            printf("->");
    }
    printf("\nTotal Cylinder Movement : %d\n",seek_time);
}

int main()
{
    input();
    int seek_time = FCFS();
    print_output(seek_time);
}


/**

Input Output
============

Number of heads: 199
Number of request: 8
Cylinder request: 98 183 37 122 14 124 65 67
Current head position: 53


===============First Come First Serve Disk Scheduling Algorithm===============

Cylinder Serving Order: 98->183->37->122->14->124->65->67
Total Cylinder Movement : 640

Process returned 0 (0x0)   execution time : 7.559 s
Press any key to continue.


**/
