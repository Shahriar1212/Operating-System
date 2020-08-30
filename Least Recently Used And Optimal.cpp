#include<bits/stdc++.h>
using namespace std;

int referencesLen;
int frameSize;
int refString[100];
int pageFault_OPR = 0;
int pageHit_OPR = 0;
int pageNo = 0;
int pageFault_LRU = 0;
int furthest;

void OPR()
{
    int check[pageNo];
    for(int i=0;i<pageNo;i++)
        check[i] = 0;

    int i;
    int buffer[frameSize];

    for(i = 0; i < referencesLen; i++)
        if(check[refString[i]] == 0)
        {
            pageFault_OPR++;
            int loc = i;
            if(i >= frameSize)
            {
                furthest = INT_MIN;
                int frameIndex;
                for(frameIndex = 0; frameIndex < frameSize; frameIndex++)
                {
                    int refIndex;
                    for(refIndex = i + 1; refIndex <= referencesLen; refIndex++)
                        if(refString[refIndex] == buffer[frameIndex])
                            break;

                    if(furthest < refIndex)
                    {
                        furthest = refIndex;
                        loc = frameIndex;
                    }
                }
                check[buffer[loc]] = 0;
            }

            buffer[loc] = refString[i];
            check[refString[i]] = 1;
        }
}


void LRU()
{
    int check[pageNo];
    for(int i=0;i<pageNo;i++)
        check[i] = 0;

    int i;
    int buffer[frameSize];

    for(i = 0; i < referencesLen; i++)
        if(check[refString[i]] == 0)
        {
            pageFault_LRU++;
            int loc = i;
            if(i >= frameSize)
            {
                furthest = INT_MAX;
                int frameIndex;
                for(frameIndex = 0; frameIndex < frameSize; frameIndex++)
                {
                    int refIndex;
                    for(refIndex = i - 1; refIndex >= 0; refIndex--)
                        if(refString[refIndex] == buffer[frameIndex])
                            break;

                    if(furthest > refIndex)
                    {
                        furthest = refIndex;
                        loc = frameIndex;
                    }
                }
                check[buffer[loc]] = 0;
            }

            buffer[loc] = refString[i];
            check[refString[i]] = 1;
        }
}

void input()
{
    printf("Number of pages: ");
    scanf("%d",&pageNo);

    printf("Number of Page References: ");
    scanf("%d",&referencesLen);

    printf("Reference String: ");
    for(int i=0; i<referencesLen; i++)
        scanf("%d",&refString[i]);

    printf("Number of Memory Page Frame: ");
    scanf("%d",&frameSize);
}

void output_OPR()
{
    printf("\n===============Optimal Page Replacement Algorithm==============\n");
    int pageFaultRate_OPR = ((pageFault_OPR*100)/referencesLen);
    printf("Number of page fault using Optimal Page replacement Algorithm: %d\n",pageFault_OPR);
    ///printf("Number of page Hit using Optimal Page replacement Algorithm: %d\n",pageHit_OPR);
    printf("Page Fault Rate: %d%c\n\n",pageFaultRate_OPR, '%');
}

void output_LRU()
{
    printf("=========Least Recently Used Page Replacement Algorithm=========\n");
    int pageFaultRate_LRU = ((pageFault_LRU*100)/referencesLen);
    printf("Number of page fault using Least Recently Used Page replacement Algorithm: %d\n",pageFault_LRU);
    printf("Page Fault Rate: %d%c\n\n",pageFaultRate_LRU, '%');
}

int main()
{
    input();
    OPR();
    output_OPR();
    LRU();
    output_LRU();

    return 0;
}


/**
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
*/

