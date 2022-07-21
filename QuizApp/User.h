#pragma once

class User
{
public:
	std::string userName;
	int correctAnswers = 0;
	int wrongAnswers = 0;
	int score = 0;

protected:

	static void jsonSort(json Json)
	{
		for (size_t i = 0; i < Json.size(); i++)
		{
			for (size_t j = 0; j < Json.size() - i - 1; j++)
			{
				if (Json[j][4] > Json[j + 1][4])
				{
					auto temp = Json[j];
					Json[j] = Json[j + 1];
					Json[j + 1] = temp;
				}
			}
		}
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

		User user;

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
				quizFile[i][2][answerNumber[ans - 65]] == quizFile[i][2][0] ? user.correctAnswers++ : user.wrongAnswers++;
			else if (ans >= 97 && ans <= 122)
				quizFile[i][2][answerNumber[ans - 97]] == quizFile[i][2][0] ? user.correctAnswers++ : user.wrongAnswers++;
			else user.wrongAnswers++;
			std::cout << "````````````\n";
		}
		int score = user.correctAnswers * 60 - user.wrongAnswers * 40;
		if (score < 0)score = 0;

		std::cout << "Username: " << userName << std::endl;
		std::cout << "Qusetions: " << quizFile.size() << std::endl;
		std::cout << "Correct: " << user.correctAnswers << std::endl;
		std::cout << "Wrong: " << user.wrongAnswers << std::endl;
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
		json userJson;
		userJson.push_back(quizNames[choice - 1]);
		userJson.push_back(user.userName);
		userJson.push_back(user.correctAnswers);
		userJson.push_back(user.wrongAnswers);
		userJson.push_back(user.score);

		leaderBoard.push_back(userJson);
		leaderStream.open("./leaderboard/" + quizNames[choice - 1] + ".json", std::ios::out);
		leaderStream << leaderBoard;
		Sleep(2000);
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

			jsonSort(leaderBoard);

			std::cout << "`````````````````````````" << std::endl;
			std::cout << quizNames[i] << std::endl;
			for (size_t j = 0; j < leaderBoard.size(); j++)
			{
				std::cout << leaderBoard[j][1] << ' ';
				std::cout << leaderBoard[j][2] << ' ';
				std::cout << leaderBoard[j][3] << ' ';
				std::cout << leaderBoard[j][4] << std::endl;
			}
			std::cout << "`````````````````````````" << std::endl;
			leaderStream.close();
		}
		Sleep(2000);


	}
};