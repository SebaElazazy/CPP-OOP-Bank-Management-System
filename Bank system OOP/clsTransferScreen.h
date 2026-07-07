#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
class clsTransferScreen:protected clsScreen

{
    static void _PrintClientCard(clsBankClient Client) {

        cout << "Client Card:" << endl;

        cout << "-----------------------\n\n";
        cout << "Full Name: " << Client.FullName()<<endl;
        cout << "ACC Num: " << Client.AccountNumber()<<endl;
        cout << "Balance: " << Client.AccountBalance << endl;
        cout << "-----------------------\n\n";


    }

public:

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber;
        cout << Message << endl;
      
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));

        _PrintClientCard(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To: "));

        _PrintClientCard(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClientCard(SourceClient);
        _PrintClientCard(DestinationClient);


    }

};