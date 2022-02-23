#include <iostream>
#include <string>
using namespace std;

enum   //make the cases more readable
{
    Exit,
    Check_Balance,
    Withdraw_Money,
    Deposit_Money,
    Surprise,
    Savings
};

class Account
{
public:
    Account(long Start_money = 0)
        : _balance(Start_money)
    {}

    void CheckBalance()
    {
        cout << "There's " << _balance << " pounds left in your account" << endl;
    }

    long WithDraw()
    {
        long withDraw = 0;
        cout << "How much money do you want to withdraw: " << endl;
        cin >> withDraw;
        while((_balance - withDraw) < 0)
        {
            cout <<"Your current balance is less than the money you want to withdraw,"<< endl;
            cout <<"Please input your withdraw number again: "<< endl;
            cin >> withDraw;
        }
        _balance -= withDraw;
        return _balance;
    }

    long Deposit()
    {
        long deposit = 0;
        cout << "How much money do you want to deposit: " << endl;
        cin >> deposit;
        _balance += deposit;
        return _balance;
    }

    //"Surprise" can change your balance from 1000 pounds less to 1000 pounds more randomly
    long Surprise()
    {
        int surprise_money = rand()%2001 - 1000;
        if(surprise_money > 0)
            cout << "GOOD LUCK TODAY!! You just winned " << surprise_money << " pounds" << endl;
        else if(surprise_money < 0)
            cout << "BAD LUCK TODAY.. You just lost " << -surprise_money << " pounds" << endl;
        else
            cout << "Your surpise-money is 0" << endl;
        _balance += surprise_money;
        if(_balance < 0)
        {
            cout <<"You are broke."<< endl << "GAME OVER"<< endl;
            exit(-1);
        }
        return _balance;
    }

    //Your balance will have 0.2% more in total after everytime you save your money
    long Saving()
    {
        long saving = 0;
        cout << "How much money do you want to save: " << endl;
        cin >> saving;
        _balance += saving;
        _balance *= 1.02;
        return _balance;
    }

private:
    long _balance;
};

void StartMenu()
{
    cout << "Create your bank's name: " << endl;
    string name;
    cin >> name;
    cout << "Welcome to " << name << " Bank. What would you like to do?" <<endl;
    cout <<"|---------------------------------------------------|"<< endl;
    cout <<"|****  1.Check_Balance   ***    2.Withdraw_Money ***|"<< endl;
    cout <<"|****  3.Deposit_Money   ***      4.Surprise     ***|"<< endl;
    cout <<"|****************     5.Savings    *****************|"<< endl;
    cout <<"|****************      0.Exit      *****************|"<< endl;
    cout <<"|---------------------------------------------------|"<< endl;
}

void Menu()
{
    cout <<"|---------------------------------------------------|"<< endl;
    cout <<"|****  1.Check_Balance   ***    2.Withdraw_Money ***|"<< endl;
    cout <<"|****  3.Deposit_Money   ***      4.Surprise     ***|"<< endl;
    cout <<"|****************     5.Savings    *****************|"<< endl;
    cout <<"|****************      0.Exit      *****************|"<< endl;
    cout <<"|---------------------------------------------------|"<< endl;
}

int main()
{
    srand((unsigned int)time(nullptr));
    //initial the start-money
    cout << "How much money do you like to start as your bank account: " << endl;
    long StartMoney = 0;
    cin >> StartMoney;
    while(StartMoney < 0)
    {
        cout << "Please enter with a positive balance: " << endl;
        cin >> StartMoney;
    }
    Account a(StartMoney);     //create an account
    StartMenu();
    int num;
    while(cin >> num)
    {
        switch (num)
        {
            case Exit:
            {
                cout << "Exiting from your account..." <<endl;
                cout << "Exit successful" <<endl;
                return 0;
            }
            case Check_Balance:
            {
                a.CheckBalance();
                cout << endl;
                Menu();
                break;
            }
            case Withdraw_Money:
            {
                a.WithDraw();
                a.CheckBalance();
                cout << endl;
                Menu();
                break;
            }
            case Deposit_Money:
            {
                a.Deposit();
                a.CheckBalance();
                cout << endl;
                Menu();
                break;
            }
            case Surprise:
            {
                a.Surprise();
                a.CheckBalance();
                cout << endl;
                Menu();
                break;
            }
            case Savings:
            {
                a.Saving();
                a.CheckBalance();
                cout << endl;
                Menu();
                break;
            }
            default:
            {
                cout << "Wrong number, please input your choice again: ";
                break;
            }
        }
    }
    return 0;
}
