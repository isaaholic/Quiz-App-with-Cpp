#pragma once
class Guest : public User
{
public:
	static void GuestPage()
	{
		bool isRunning = true;
		int choice = 0;
		int c = 0;
		while (isRunning)
		{
			system("cls||clear");
			std::cout << "choose:";
			std::cout << "\n1. start quiz";
			c == 0 ? std::cout << "<" : std::cout << "*";
			std::cout << "\n2. leader board";
			c == 1 ? std::cout << "<" : std::cout << "*";
			std::cout << "\n3. Back";
			c == 2 ? std::cout << "<" : std::cout << "*";
			Controller::Control(c, 2, choice);
			switch (choice)
			{
			case 1:
				Admin::StartQuiz();
				choice = 0;
				break;
			case 2:
				Admin::LeaderBoard();
				choice = 0;
				break;
			case 3:
				isRunning = false;
				choice = 0;
				break;
			}
		}
	}
};

