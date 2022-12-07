#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class ATM
{
    string machineAuthentication;
    
    public:
        
        void insertCard(Card c);
        void prompts(string s);
        string getMachineAuthentication();
        string encryptAccountAndPIN(string account, string PIN);
        void enterAmount(float amount);
        void payOutMoney (float amount);
        void enterPIN (string PIN);
};

class Card
{
    string AccountNumber;

    public:
        string getAccountNumber();
};

class Bank
{
    public:
       bool verify(string encryptedAccAndPin);
       void drawMoney(string account, float amount);
};

class BankAccount
{
    string ID;
    float balance;

    public:
        float getBalance();
        void setBalance(float f);
};