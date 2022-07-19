#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <direct.h>
#include "json.hpp"

using json = nlohmann::json;

#include "Answers.h"
#include "Question.h"
#include "Quiz.h"
#include "Admin.h"


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
			AdminPage();
			break;
		case 2:
			// GuestPage();
			break;
		default:
			break;
		}
	}

	static void AdminPage()
	{
		system("cls||clear");
		int choice = 0;
		std::cout << "choose:"
			<< "\n1. create quiz"
			<< "\n2. start quiz"
			<< "\n3. leader board" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			CreateQuiz();
			break;
		case 2:
			StartQuiz();
		case 3:
			LeaderBoard();
		default:
			break;
		}
	}

	static void LeaderBoard()
	{
		// codespace
	}


	static void CreateQuiz()
	{
		system("cls||clear");
		Quiz quiz;
		std::cout << "Enter quiz name: ";
		std::cin >> quiz.fileName;

		std::fstream quizFilesW;
		_mkdir("./txtFiles");
		quizFilesW.open("./txtFiles/quiznames.txt", std::ios::app);//write
		std::cin.ignore();
		quizFilesW << quiz.fileName << '\n';
		quizFilesW.close();

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
					std::cout << "Answer " << ka++ << ": ";
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

		quiz.reload();
		quiz.writeJson();

		//system("cls||clear");

		//int i = 1;
		//while (1)
		//{
		//	std::string que;
		//	std::cout << "Question " << i << ": ";
		//	getline(std::cin, que);
		//	std::cout << que << std::endl;
		//	std::string varA, varB, varC, varD;
		//	std::cout << "A)  ";
		//	getline(std::cin, varA);
		//	std::cout << "B)  ";
		//	getline(std::cin, varB);
		//	std::cout << "C)  ";
		//	getline(std::cin, varC);
		//	std::cout << "D)  ";
		//	getline(std::cin, varD);
		//	Answers a(varA, varB, varC, varD);
		//	Question q(i, que, a);
		//	quiz.addQuestion(q);
		//	i++;
		//	break;
		//	quizFilesW.close();
		//}
		//quiz.reload();
		//quiz.writeJson();
		//std::fstream quizFilesR;
		//quizFilesR.open("quizNames.txt", std::ios::in);//write
		//std::cout << "`````````````````````````" << std::endl;
		//std::string line;
		//while (getline(quizFilesR, line))
		//{
		//	if (line.find("quiz")!=std::string:: npos)
		//	{
		//		std::cout << line << std::endl;
		//	}
		//}
		//std::cout << "`````````````````````````" << std::endl;
	}

	static void StartQuiz()
	{
		system("cls||clear");
		std::string userName;
		std::cout << "Enter Your Name: ";
		std::cin >> userName;
		std::fstream quizFilesR;
		quizFilesR.open("./txtFiles/quiznames.txt", std::ios::in);//write
		system("cls||clear");
		std::cout << "`````````````````````````" << std::endl;
		std::string line;
		std::vector<std::string> quizNames;
		while (getline(quizFilesR, line))
		{
			std::cout << line << std::endl;
			quizNames.push_back(line);
		}
		std::cout << "`````````````````````````" << std::endl;
		quizFilesR.close();
		std::cout << "Select one: ";
		int choice;
		std::cin >> choice;
		system("cls||clear");
		std::fstream quizFileR;
		try
		{
			quizFileR.open(quizNames[choice - 1] + ".json", std::ios::in);//write
			if (!quizFileR)
			{
				throw "file doesn't exist";
			}
		}
		catch (const char* msg)
		{
			std::cout << msg << std::endl;
			return;
		}
		json quizFile;
		quizFileR >> quizFile;
		quizFileR.close();
		for (size_t i = 0; i < quizFile.size(); i++)
		{
			std::cout << "````````````\n";
			std::cout << quizFile[i][0] << ". ";
			std::cout << quizFile[i][1] << std::endl;
			for (size_t j = 0; j < quizFile[i][2].size(); j++)
			{
				std::cout << char(65 + j) << ") " << quizFile[i][2][j] << std::endl;
			}
			std::cout << "````````````\n";
		}
	}

public:

	static void StartUp()
	{
		// Admin {
		// Create Quiz
		// Guest {
		// Start Quiz
		// Leader Board
		// };};
		Login();

		// *Random Questions
		// *Random Answers
		std::cout << "StartUp is working...\n";
	}
};


int main()
{
	Start::StartUp();
	
	return EXIT_SUCCESS;
}