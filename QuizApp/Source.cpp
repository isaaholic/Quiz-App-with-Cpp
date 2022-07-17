#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
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
			// CreateQuiz();
			break;
		case 2:
			// StartQuiz();
		case 3:
			// LeaderBoard();
		default:
			break;
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

std::string json_read(json j)
{
	const std::string filename = "ex2.json";
	std::ifstream reader(filename);
	reader >> j;
	reader.close();
	return j.dump(2);
}

json json_write(std::string name)
{
	json j;
	j.push_back(name);

	std::ofstream writer;
	writer.open("ex2.json");
	writer << j.dump(1);
	return j;
}


int main()
{
	/*Start::StartUp();*/
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

	Question q1("sss");
	Question q2("sad");
	Quiz quiz("quiz1", "Isa");
	quiz.addQuestion(q1);
	quiz.addQuestion(q2);

	quiz.reload();

	quiz.writeJson();

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


	return EXIT_SUCCESS;
}