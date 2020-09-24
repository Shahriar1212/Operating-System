#include<bits/stdc++.h>
#define MAX 100000
using namespace std;


void createFile();
void searchFile();
void wrongInput();
void showOption();
int getMemory(int numberOfBlocks);


int remainingBlocks;
bool mark[MAX];
int numberOfBlocks,selectedOption;

class File
{
public:
    string name;
    int fileSize;
    vector <int> allocatedBlocks;
};

vector<File> Files;

void createFile()
{
    File file;
    bool isCreateable = false;
    string temp1;
    int temp2;
    printf("Enter File Name: ");
    cin >> temp1;
    printf("Ener File Size: ");
    cin >> temp2;
    if(temp2 > remainingBlocks)
    {
        cout << "File " << temp1 << " can not be created (not enough free blocks)" << endl;
        isCreateable = true;
    }
    else{
        file.name = temp1;
        file.fileSize = temp2;
        while(temp2--)
        {
            int memoryBlocks = getMemory(numberOfBlocks);
            file.allocatedBlocks.push_back(memoryBlocks);
        }
        remainingBlocks -= file.fileSize;
    }
    Files.push_back(file);
    if(!isCreateable)
        cout << "File " << file.name << " Created" << endl;
    cout << "\n";
    showOption();
}
void searchFile()
{
    string temp1;
    printf("Enter File Name to search: ");
    cin >> temp1;
    bool found = false;
    for(File x : Files)
    {
        if(x.name == temp1)
        {
            found = true;
            for(int i=0;i<x.allocatedBlocks.size();i++)
            {
                cout << x.allocatedBlocks[i] << " ";
            }
            cout << "\n";
            break;
        }

    }
    if(found == false)
        cout << "File " << temp1 << " Not Found" << endl;
    cout << "\n";
    showOption();
}

void wrongInput()
{
    printf("Wrong Input\n");
    printf("Please select any of the following options\n\n");
    showOption();
}



void showOption()
{
    printf("Choose Option: \n");
    printf("1 -> Create || ");
    printf("2 -> Search || ");
    printf("3 -> Exit\n");
}

int getMemory(int numberOfBlocks)
{
    int randomNumber;
    do{
        randomNumber = (rand() % numberOfBlocks);
    }while(mark[randomNumber] == true);
    mark[randomNumber] = true;
    return randomNumber;
}

int main()
{
    printf("Enter Number Of Blocks: ");
    scanf("%d",&numberOfBlocks);
    cout << "\n";
    remainingBlocks = numberOfBlocks;

    showOption();


    while(true)
    {
        cout << "select : ";
        scanf("%d",&selectedOption);
        cout << "\n";
        if(selectedOption == 1)
            createFile();
        else if(selectedOption == 2)
            searchFile();
        else if(selectedOption == 3)
            return 0;
        else
            wrongInput();
    }
}
