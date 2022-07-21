#pragma once
class Guest : public User
{
public:
	static void GuestPage()
	{
		bool isRunning = true;
		while (isRunning)
		{
			system("cls||clear");
			int choice = 0;
			std::cout << "choose:"
				<< "\n1. start quiz"
				<< "\n2. leader board"
				<< "\n3. Back" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1:
				Admin::StartQuiz();
				break;
			case 2:
				Admin::LeaderBoard();
				break;
			case 3:
				isRunning = false;
				break;
			}
		}
	}
};

