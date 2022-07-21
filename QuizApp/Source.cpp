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
			break;
		case 3:
			LeaderBoard();
		default:
			break;
		}
	}

	static void LeaderBoard()
	{
		system("cls||clear");

		std::fstream leaderStream;





		std::fstream quizFilesR;
		quizFilesR.open("./txtFiles/quiznames.txt", std::ios::in);//write
		std::string line;
		std::vector<std::string> quizNames;
		while (getline(quizFilesR, line))
		{
			quizNames.push_back(line);
		}
		for (size_t i = 0; i < quizNames.size(); i++)
		{
			leaderStream.open("./leaderboard/" + quizNames[i] + ".json", std::ios::in);

			json leaderBoard;
			try
			{
				leaderStream >> leaderBoard;
			}
			catch (const std::exception&)
			{

			}

			std::cout << "`````````````````````````" << std::endl;
			std::cout << quizNames[i] << std::endl;
			for (size_t j = 0; j < leaderBoard.size(); j++)
			{
				std::cout << leaderBoard[j] << std::endl;
			}
			std::cout << "`````````````````````````" << std::endl;
			leaderStream.close();
		}

	}


	static void CreateQuiz()
	{
		system("cls||clear");
		Quiz quiz;
		std::cout << "Enter quiz name: ";
		std::cin >> quiz.fileName;

		std::fstream quizFilesW;

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
		quizFilesW.open("./txtFiles/quiznames.txt", std::ios::app);//write
		quizFilesW << quiz.fileName << '\n';
		quizFilesW.close();
		quiz.reload();
		quiz.writeJson();
	}

	static void StartQuiz()
	{
		srand(time(NULL));
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
			quizFileR.open("./json/" + quizNames[choice - 1] + ".json", std::ios::in);//write
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

		int correctAnswers = 0;
		int wrongAnswers = 0;

		for (size_t i = 0; i < quizFile.size(); i++)
		{
			std::cout << "````````````\n";
			std::cout << quizFile[i][0] << ". ";
			std::cout << quizFile[i][1] << std::endl;
			std::vector<int> answerNumber;
			int randNum;
			for (size_t k = 0; k < quizFile[i][2].size(); k++)
			{
				while (true)
				{
					randNum = 0 + rand() % (quizFile[i][2].size());
					if (std::find(answerNumber.begin(), answerNumber.end(), randNum) != answerNumber.end())
						continue;
					else
					{
						answerNumber.push_back(randNum);
						break;
					}
				}

			}
			int j = 0;
			for (auto index : answerNumber)
			{
				std::cout << char(65 + j++) << ") " << quizFile[i][2][index] << std::endl;
			}
			char ans;
			std::cin >> ans;
			if (ans >= 65 && ans <= 90)
				quizFile[i][2][answerNumber[ans - 65]] == quizFile[i][2][0] ? correctAnswers++ : wrongAnswers++;
			else if (ans >= 97 && ans <= 122)
				quizFile[i][2][answerNumber[ans - 97]] == quizFile[i][2][0] ? correctAnswers++ : wrongAnswers++;
			else wrongAnswers++;
			std::cout << "````````````\n";
		}
		int score = correctAnswers * 60 - wrongAnswers * 40;
		if (score < 0)score = 0;

		std::cout << "Username: " << userName << std::endl;
		std::cout << "Qusetions: " << quizFile.size() << std::endl;
		std::cout << "Correct: " << correctAnswers << std::endl;
		std::cout << "Wrong: " << wrongAnswers << std::endl;
		std::cout << "Score: " << score << std::endl;

		_mkdir("./leaderboard");
		std::fstream leaderStream;
		leaderStream.open("./leaderboard/" + quizNames[choice - 1] + ".json", std::ios::in);


		json leaderBoard;
		try
		{
			leaderStream >> leaderBoard;
		}
		catch (const std::exception&)
		{

		}

		std::cout << leaderStream.is_open() << std::endl;

		leaderStream.close();
		json user;
		user.push_back(quizNames[choice - 1]);
		user.push_back(userName);
		user.push_back(correctAnswers);
		user.push_back(wrongAnswers);
		user.push_back(score);

		leaderBoard.push_back(user);
		leaderStream.open("./leaderboard/" + quizNames[choice - 1] + ".json", std::ios::out);
		leaderStream << leaderBoard;
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