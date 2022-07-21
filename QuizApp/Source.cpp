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

using json = nlohmann::json;

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
		std::cout << "Login:"
			<< "\n1. Admin"
			<< "\n2. Guest" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			Admin::AdminPage();
			break;
		case 2:
			 Guest::GuestPage();
			break;
		default:
			break;
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