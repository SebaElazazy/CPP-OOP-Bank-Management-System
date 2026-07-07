#pragma once
using namespace std;
#include <iostream>
#include "clsDate.h"
class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}


	static int ReadIntNumber(string message = "Invalid number, enter number again")
	{
		int Number;

		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int n1, int n2, string message)
	{
		int number = ReadIntNumber("invalid number, please enter again");
		while (!IsNumberBetween(number, n1, n2)) {
			cout << message << endl;
			number = ReadIntNumber();
		}
		return number;

	}

	static short ReadShortNumberBetween(short n1, short n2, string message)
	{
		short number = ReadIntNumber("invalid number, please enter again");
		while (!IsNumberBetween(number, n1, n2)) {
			cout << message << endl;
			number = ReadIntNumber();
		}
		return number;

	}

	static double ReadDblNumber(string message="Invalid number, enter number again")
	{
		double Number;

		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> Number;
		}
		return Number;
	}

	static float ReadFloatNumber(string message="Invalid number, enter number again")
	{
		float Number;

		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> Number;
		}
		return Number;
	}

	static int ReadDblNumberBetween(int n1, int n2, string message)
	{
		int number = ReadDblNumber("invalid number, please enter again");
		while (!IsNumberBetween(number, n1, n2)) {
			cout << message << endl;
			cin >> number;
		}
		return number;

	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}



};

