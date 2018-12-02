/*
 ONLY PROBLEM IS ASSIGNING MANAGER ID IN ASCENDING ORDER, FROM 1001 TO ....
 NOT FROM .... TO 1001
 */

//RUNNING EVENT MANAGEMENT SYSTEM

#include <iostream>
#include "REMS.h"
using namespace std;


void initPayment(payment *head, int n)
{
    head->amount = n;
    head->next = NULL;
}
void makePayment(payment *head, int a)
{
    payment *newNode = new payment;
    newNode->amount=a;;
    newNode->payID = 12345;
    newNode->next = NULL;
    payment *cur = head;
    
    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        
        cur = cur->next;
        
    }
}

void DisplayPaymentsSummary(payment *head)
{
    double sum=0;
    payment *cur = head;
    while(cur)
    {
        sum=sum+cur->amount;
        cur = cur->next;
    }
    cout<<endl<<endl<<"TOTAL INCOME : "<<sum<<endl;
}


void initRace(race *head, int n)
{
    head->raceno = n;
    head->next = NULL;
}

void CreateRace(race *head)
{
    int count=0;
    race *newNode = new race;
    cout<<"Enter race name :";cin>>newNode->racename;
    cout<<"Registration fee :";cin>>newNode->racefees;
    newNode->raceno=1;
    newNode->next = NULL;
    race *cur = head;
    
    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        
        cur = cur->next;
        cur->raceno++;
        count++;
    }
    cout<<"\aCongratulations! Your race,is Now Registered"<<endl<<endl;
}
void DisplayAvailableRaces(race *head)
{
    cout<<"\nAVAILABLE REGISTERED RACES"<<endl;
    race *cur = head->next;
    cout<<"racename\trace code\trace fees"<<endl;
    while(cur)
    {
        cout<<cur->racename<<"          \t"<<cur->raceno<<"         \t"<<cur->racefees<<endl;
        cur = cur->next;
        
    }
}
void SearchRaceCode(race *head)
{
    cout<<"\n\nRACE REGISTRATION\n\nEnter Race Code : ";
    int rcode;cin>>rcode;
    payment *phead;
    phead=new payment;
    initPayment(phead, 0);
    
    race *cur = head->next;
    while(cur)
    {
        if(cur->raceno==rcode)
        {
            cout<<"Race "<<cur->raceno<<" Found"<<endl;
            cout<<"RACE NAME : "<<cur->racename<<"\nRACE FEES : "<<cur->racefees<<endl;
            
            cout<<"\nEnter Race Fees to complete registration : ";int pay;cin>>pay;
            if(pay<cur->racefees)
            {
                cout<<"Insufficient Amount"<<endl;
            }
            else
            {
                
                makePayment(phead,pay);
                cout<<"\aApproved Payment!"<<endl;
                
            }
            return;
        }
        cur = cur->next;
    }
    cout<<"\bINVALID RACE CODE!\n"<<endl;
}


void iniRunners(runners *head, string n)
{
    head->runnername = n;
    head->next = NULL;
}
void RegisterandRun(runners *head)
{
    runners *newNode = new runners;
    cout<<endl<<endl<<"RUNNER REGISTRATION\nRunner's Name : ";
    cin>>newNode->runnername;
    
    newNode->next = NULL;
    runners *cur = head;
    
    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
    cout<<"\aCongratulations!You have successfully Registered the race."<<endl<<endl;
}



void iniManagers(managers *head, string n)
{
    head->managername = n;
    head->next = NULL;
}
void ManagerRegistration(managers *head)
{
    managers *newNode = new managers;
    
    cout<<"\nManager's Name : ";
    cin>>newNode->managername;
    newNode->managerID=1001;
    cout<<"Congratulations "<<newNode->managername<<"!You are now Registered"<<endl;
    cout<<"MANAGER ID: ";
    
    newNode->next = NULL;
    managers *cur = head;
    
    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
        cur->managerID++;/*
                          ONLY PROBLEM IS ASSIGNING MANAGER ID IN ASCENDING ORDER, FROM 1001 TO ....
                          NOT FROM .... TO 1001
                          */
    }
    
}

void SearchManager(managers *head)
{
    race *head2= new race;
    initRace(head2, 10000);
    runners *BigHead2= new runners;
    iniRunners(BigHead2, "RUNNERS");
    
    
    int mid;
    cout<<"\nCREATE RACE:\n\nEnter Manager ID : ";
    cin>>mid;
    
    managers *cur = head->next;
    while(cur)
    {
        if(cur->managerID==mid)
        {
            cout<<"\nManager "<<cur->managerID<<" Found"<<endl;
            cout<<"MANAGER NAME : "<<cur->managername<<endl<<endl<<endl;
            

            char choice,choice2;
            do
            {
                
                CreateRace(head2);
                
                
                cout<<"\nTo Register another race, Press 1. Or any other button to quit : ";cin>>choice;
                cout<<endl<<endl;
            }
            while(choice=='1');
            cout<<endl<<"---------------------------------------------------------------------------"<<endl;
            cout<<"RUNNER SESSION";
            cout<<endl<<"---------------------------------------------------------------------------"<<endl;
            
            do
            {
                RegisterandRun(BigHead2);
                DisplayAvailableRaces(head2);
                SearchRaceCode(head2);
                
                cout<<"To Register another runner, Press 1. Or any other button to quit : ";cin>>choice2;
                cout<<endl<<endl;
            }
            while(choice2=='1');
            return;
        }
        
        cur = cur->next;
    }
        cout<<"\nINVALID MANAGER ID!! You can not Create a Race. \nPlease Enter Valid ID or Register as a Manger"<<endl;
    
}


void RegisterandCreateRace(managers *head)
{
    managers *head1 = new managers;
    iniManagers(head1, "meneja");
    cout<<endl<<"---------------------------------------------------------------------------"<<endl;
    cout<<"MANAGER SESSION";
    cout<<endl<<"---------------------------------------------------------------------------"<<endl;
    char choice0;int temp=1001;
    do
    {
        
        ManagerRegistration(head1);
        
        
        cout<<temp++<<"\n\nTo Register another manager, Press 1. Or any other button to quit : ";cin>>choice0;
        cout<<endl;
    }
    while(choice0=='1');
    SearchManager(head1);
}
/*
 void summary(managers *head,race *head2 ,runners *head3,payment *head4)
 {
 cout<<"\nSUMMARY"<<endl;
 race *cur = head2->next;
 while(cur)
 {
 cout<<cur->racename<<"\t"<<cur->raceno<<"\t"<<cur->racefees<<endl;
 cur = cur->next;
 
 }
 }
 struct summary:public race,public managers, public payment,public runners
 {
 
 summary * next;
 };*/

int main()
{
    managers *BigHead= new managers;
    iniManagers(BigHead,"MANAGERS \n");
    RegisterandCreateRace(BigHead);
    

    cout<<endl<<"---------------------------------------------------------------------------"<<endl;
    cout<<"******* T h a n k   Y o u   F o r   U s i n g   o u r   S y s t e m *******";
    cout<<endl<<"---------------------------------------------------------------------------"<<endl;
    
    return 0;
}
/*
 ONLY PROBLEM IS ASSIGNING MANAGER ID IN ASCENDING ORDER, FROM 1001 TO ....
 NOT FROM .... TO 1001
 */
