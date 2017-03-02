#include<iostream>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
long int randomNumber = 19724860;
class Bank
{
    string name,address,mobileNumber,email;
    long double balance=0;
    long int accountNumber=0;
public:
    void openNewAccount();
    friend void showAllAccountsInfo(Bank obj[],int i);
    friend void showAnAccountInfo(Bank obj[],int i);
    friend void withdraw(Bank obj[],int i);
    friend void deposit(Bank obj[],int i);
    friend void showBalanceInfo(Bank obj[],int i);
};
void Bank :: openNewAccount()
{
    cin.ignore();
    cout<<"\nEnter name: ";
    getline(cin,name);
    cout<<"Enter address: ";
    getline(cin,address);
    cout<<"Enter mobile number: ";
    getline(cin,mobileNumber);
    cout<<"Enter e-mail: ";
    getline(cin,email);
    cout<<"\nCongratulations, a new account was registered in the system."<<endl;
    accountNumber = randomNumber;
    cout<<name<<" was assigned the following account number: "<<accountNumber<<endl<<endl;
    randomNumber++;
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
void showAllAccountsInfo(Bank obj[], int i)
{
    if(i==0)
    {
        cout<<"No account registered in the bank"<<endl<<endl;
        return;
    }
    int index;
    for(index=1;index<=i;index++)
    {
        cout<<"\nAccount number "<<index<<endl;
        cout<<"Name: "<<obj[index].name<<"\nAccount number: "<<obj[index].accountNumber<<"\nAddress: "<<obj[index].address<<"\nE-mail: "<<obj[index].email<<"\nMobile number: "<<obj[index].mobileNumber<<"\nBalance: "<<obj[index].balance<<endl<<endl;
    }usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
void showAnAccountInfo(Bank obj[], int i)
{
    if(i==0)
    {
        cout<<"No account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index=1,flag=0;
    cout<<"\nEnter Account Number to display the details of the same: ";
    cin>>check;
    for(index=1;index<=i;index++)
    {
        if((obj[index].accountNumber)==check)
        {
            flag=1;
            verified = index;
        }
    }
    if(flag==1)
    {
        cout<<"Name: "<<obj[verified].name<<"\nAccount number: "<<obj[verified].accountNumber<<"\nAddress: "<<obj[verified].address<<"\nE-mail: "<<obj[verified].email<<"\nMobile number: "<<obj[verified].mobileNumber<<"\nBalance: "<<obj[verified].balance<<endl<<endl;

    }
    else
    {
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
void withdraw(Bank obj[],int i)
{
    if(i==0)
    {
        cout<<"\nNo account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index,flag=0;
    cout<<"\nEnter Account Number to withdraw: ";
    cin>>check;
    for(index=1;index<=i;index++)
    {
        if((obj[index].accountNumber)-check==0)
        {
            flag=1;
            verified = index;
        }
    }
    if(flag==1)
    {
        if(obj[verified].balance == 0)
        {
            cout<<"\nAccount has insufficient balance\n"<<endl;
            return ;
        }
        long double amount;
        cout<<"Enter amount to be withdrawn: ";
        cin>>amount;
        if(amount>=obj[verified].balance)
        {
            cout<<"\nBalance is insufficient for that amount of withdrawal.\nBalance: "<<obj[verified].balance<<"\nAmount Entered: "<<amount<<endl<<endl;
            return ;
        }
        obj[verified].balance = obj[verified].balance - amount;
        cout<<"Balance after withdrawal: "<<obj[verified].balance<<endl<<endl;
    }
    else
    {
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
void deposit(Bank obj[] , int i)
{
    if(i==0)
    {
        cout<<"\nNo account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index,flag=0;
    cout<<"\nEnter Account Number to deposit: ";
    cin>>check;
    for(index=1;index<=i;index++)
    {
        if((obj[index].accountNumber)-check==0)
        {
            flag=1;
            verified = index;
        }
    }
    if(flag==1)
    {
        long double amount;
        cout<<"Enter amount to be deposited: ";
        cin>>amount;
        obj[verified].balance = obj[verified].balance + amount;
        cout<<"Balance after money deposition: "<<obj[verified].balance<<endl<<endl;
    }
    else
    {
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
void showBalanceInfo(Bank obj[],int i)
{
    if(i==0)
    {
        cout<<"\nNo account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index,flag=0;
    cout<<"\nEnter Account Number to display the details of the same: ";
    cin>>check;
    for(index=1;index<=i;index++)
    {
        if((obj[index].accountNumber)-check==0)
        {
            flag=1;
            verified = index;
        }
    }
    if(flag==1)
    {
        cout<<"Balance for "<<obj[verified].name<<" is "<<obj[verified].balance<<endl<<endl;
    }
    else
    {
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
int main()
{
    int choice,i=0;
    string password="geu123";
    string input;
    Bank obj[100];
    cout<<"Enter root password: ";
    cin>>input;
    system("CLS");
    if(input.compare(password)==0)
    {
        cout<<"Bank Software Loading menu..."<<endl;
        usleep(200000);
        do{
                usleep(200000);
                cout<<"\nEnter your choice:\n1: Open a new account\n2: List the accounts registered\n3: List details for a user\n4: Withdraw from savings\n5: Deposit savings into account\n6: List the balance of a user\n9: Exit the software"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 1:
                    i++;
                    obj[i].openNewAccount();
                    break;
                case 2:
                    showAllAccountsInfo(obj,i);
                    break;
                case 3:
                    showAnAccountInfo(obj,i);
                    break;
                case 4:
                    withdraw(obj,i);
                    break;
                case 5:
                    deposit(obj,i);
                    break;
                case 6:
                    showBalanceInfo(obj,i);
                    break;
                case 9:
                    break;
                default:
                    cout<<"\nInvalid input"<<endl;
                }
        }while(choice!=9);
    }
    else
        cout<<"Root access not granted"<<endl;
}
