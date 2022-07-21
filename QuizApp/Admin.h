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
				//quizQuestions.push_back(que);
				quiz.addQuestion(*que);
				i++;
				question.clear();
				/*std::cout << "Question " << i << ": ";
				getline(std::cin, question);*/
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
	}

public:

	static void AdminPage()
	{
		bool isRunning = true;
		while (isRunning)
		{
			system("cls||clear");
			int choice = 0;
			std::cout << "choose:"
				<< "\n1. create quiz"
				<< "\n2. start quiz"
				<< "\n3. leader board"
				<< "\n4. Back" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1:
				CreateQuiz();
				break;
			case 2:
				Admin::StartQuiz();
				break;
			case 3:
				Admin::LeaderBoard();
				break;
			case 4:
				isRunning = false;
				break;
			}
		}
	}
};

