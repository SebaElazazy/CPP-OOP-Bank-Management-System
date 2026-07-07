#pragma once
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "ShowMainScreen.h"
#include "clsAddNewClientScreen.h"



class clsLoginScreen :protected clsScreen
{

private:

 

    static  bool _Login()
    {
     
        short counter = 3;
        bool LoginFaild = false;

        string Username, Password;
   
        do
        {
          
            if (LoginFaild)
            {
                counter--;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "you have " << counter << " trial(s) to log in." << endl;
            
            }
            if (counter == 0) {
                cout << "you are locked After " << counter << "trials." << endl;
                return 0;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        ShowMainScreen::ShowMainMenue();

        return true;

         

    }

   

public:


    static bool ShowLoginScreen()
    {
     
            system("cls");
            _DrawScreenHeader("\t  Login Screen");
            return _Login();
       

    }
};