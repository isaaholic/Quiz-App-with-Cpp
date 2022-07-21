#include <iostream>
#include "json.hpp"
#include <Windows.h>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <direct.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

using json = nlohmann::json;

#include "Controller.h"
#include "Answers.h"
#include "Question.h"
#include "Quiz.h"

#include "User.h"
#include "Admin.h"
#include "Guest.h"


class Start
{
	static void Login()
	{
		int choice = 0;
		int c = 0;
		while (1)
		{
			system("cls");
			std::cout << "Login:"
				<< "\nAdmin";
			c == 0 ? std::cout << "<" : std::cout<<"*";
			std::cout<< "\nGuest";
			c == 1 ? std::cout << "<" : std::cout << "*";
			std::cout<< "\nExit";
			c == 2 ? std::cout << "<" : std::cout << "*";

			Controller::Control(c, 2, choice);

			switch (choice)
			{
			case 1:
				Admin::AdminPage();
				choice = 0;
				break;
			case 2:
				Guest::GuestPage();
				choice = 0;
				break;
			case 3:
				exit(0);
				break;
			}
		}
	}


public:
	static void StartUp()
	{
		Login();
	}
};


int main()
{
	Start::StartUp();




	return EXIT_SUCCESS;
}