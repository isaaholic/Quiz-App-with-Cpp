#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
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
			// StartQuiz();
		case 3:
			// LeaderBoard();
		default:
			break;
		}
	}


	static void CreateQuiz()
	{
		system("cls||clear");
		Quiz quiz;
		std::cout << "Enter quiz name: ";
		std::cin >> quiz.fileName;

		std::fstream quizFilesW;
		quizFilesW.open("quiznames.txt", std::ios::app);//write
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

		std::fstream quizFilesR;
		quizFilesR.open("quizNames.txt", std::ios::in);//write
		std::cout << "`````````````````````````" << std::endl;
		std::string line;
		while (getline(quizFilesR, line))
		{
			if (line.find("quiz") != std::string::npos)
			{
				std::cout << line << std::endl;
			}
		}
		std::cout << "`````````````````````````" << std::endl;

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
	//json j;
	//std::string name;
	//std::string name2;
	//std::cin >> name;
	//std::cin >> name2;
	//j.push_back(name);
	//j.push_back(name2);
	//std::ofstream writer;
	//writer.open("ex2.json");
	//writer << j.dump(2);
	//std::ifstream reader("ex2.json");
	//json Jread;
	//reader >> Jread;
	//reader.close();
	//std::cout << Jread[0][0];

	//Answers a1("an", "bn", "cn", "dn");
	//Question q1("sss");
	//q1.anw = a1;
	//Answers a2("aw", "bw", "cw", "dw");
	//Question q2("sad");
	//q2.anw = a2;
	//Quiz quiz("quiz1", "Isa");
	//quiz.addQuestion(q1);
	//quiz.addQuestion(q2);

	//quiz.reload();

	//quiz.writeJson();


	//json j1;
	//json j2;
	//j1.push_back(1);
	//j2.push_back(2);
	//j1.push_back("sss");
	//j2.push_back("aaa");
	//json quizFile;
	//quizFile[0] = j1;
	//quizFile[1] = j2;
	//std::ofstream writer;
	//writer.open("que1.json");
	//writer << quizFile.dump(2);
	//writer.close();
	//std::ifstream reader("que1.json");
	//reader >> quizFile;
	//reader.close();
	//std::cout << quizFile;

	//std::string name;
	//getline(std::cin, name);
	//std::cout << name;

	//std::fstream quizFiles;
	//quizFiles.open("quizNames.txt", std::ios::in);//write
	//std::cout << "`````````````````````````" << std::endl;
	//std::string line;
	//while (getline(quizFiles, line))
	//{
	//	std::cout << line << std::endl;
	//}
	//std::cout << "`````````````````````````" << std::endl;

	return EXIT_SUCCESS;
}