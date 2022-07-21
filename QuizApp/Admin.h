#pragma once
class Admin : public User
{
private:
	static void CreateQuiz()
	{
		system("cls||clear");
		Quiz quiz;


		std::fstream quizFilesR;
		quizFilesR.open("./txtFiles/quiznames.txt", std::ios::in);//write
		std::string line;
		std::vector<std::string> quizNames;
		while (getline(quizFilesR, line))
		{
			quizNames.push_back(line);
		}
		quizFilesR.close();

		while (1)
		{
			std::cout << "Enter quiz name: ";
			std::cin >> quiz.fileName;
			if (std::find(quizNames.begin(), quizNames.end(), quiz.fileName) != quizNames.end())
			{
				std::cout << "Please set other name";
				Sleep(1500);
				system("cls||clear");
				continue;
			}
			system("clear||cls");
			break;
		}


		std::cin.ignore();


		std::vector<Question*> quizQuestions;
		quizQuestions.push_back(new Question);
		std::vector<std::string> quizAnswers;
		std::string question;
		int choice;
		int i = 1;
		int ka = 1;
		std::string answer;
		bool isRunning = true;

		std::cout << "Question " << i << ": ";
		getline(std::cin, question);

		while (isRunning)
		{
			std::cout << "1: new" << "\n2: back" << "\n3: save\n";
			std::cout << "Choice: ";
			std::cin >> choice;
			std::cin.ignore();
			switch (choice)
			{
			case 1:
				if (!(question.empty()))
				{
					ka != 1 ? (std::cout << "Answer " << ka++ << ": ") : (std::cout << "First Right Answer " << ka++ << ": ");
					getline(std::cin, answer);
					quizAnswers.push_back(answer);
					break;
				}
				std::cout << "Question" << i << ": ";
				getline(std::cin, question);
				break;
			case 2:
			{

				isRunning = false;
				break;
			}
			case 3:
			{
				ka = 1;
				Question* que = new Question;
				que->number = i;
				que->question = question;
				que->answers.addAnswers(quizAnswers);
				quizAnswers.clear();
				quiz.addQuestion(*que);
				i++;
				question.clear();
				break;
			}
			default:
				break;
			}
		}
		_mkdir("./txtFiles");
		std::fstream quizFilesW;
		quizFilesW.open("./txtFiles/quiznames.txt", std::ios::app);//write
		quizFilesW << quiz.fileName << '\n';
		quizFilesW.close();

		quiz.reload();

	}

public:

	static void AdminPage()
	{
		bool isRunning = true;
			int c = 0;
			int choice = 0;
			while (isRunning)
			{
				system("cls||clear");
				std::cout << "choose:"
					<< "\n1. create quiz";
				c == 0 ? std::cout << "<" : std::cout << "*";
				std::cout << "\n2. start quiz";
				c == 1 ? std::cout << "<" : std::cout << "*";
				std::cout << "\n3. leader board";
				c == 2 ? std::cout << "<" : std::cout << "*";
				std::cout << "\n4. Back";
				c == 3 ? std::cout << "<" : std::cout << "*";

				Controller::Control(c, 3, choice);
				switch (choice)
				{
				case 1:
					CreateQuiz();
					choice = 0;
					break;
				case 2:
					Admin::StartQuiz();
					choice = 0;
					break;
				case 3:
					Admin::LeaderBoard();
					choice = 0;
					break;
				case 4:
					isRunning = false;
					choice = 0;
					break;
				}
		}
	}
};

