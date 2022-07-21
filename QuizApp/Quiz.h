#pragma once
class Quiz
{
public:
	std::string fileName;
	json quizFile;
	std::vector<Question> questions;
	

	Quiz() = default;

	Quiz(std::string fName) :fileName(fName)
	{

	}

	void addQuestion(Question q)
	{
		questions.push_back(q);
	}

	void reload()
	{
		for (size_t i = 0; i < questions.size(); i++)
		{
			json j;
			j.push_back(questions[i].number);
			j.push_back(questions[i].question);
			j.push_back(questions[i].answers.answers);
			quizFile[i] = j;
		}
		_mkdir("./json");
		std::ofstream writer;
		writer.open("./json/" + fileName + ".json");
		writer << quizFile.dump(4);
	}

	void writeJson()
	{
		std::cout << fileName;
		std::ifstream reader("./json/" + fileName + ".json");
		reader >> quizFile;
		reader.close();
		for (size_t i = 0; i < questions.size(); i++)
		{
			std::cout << quizFile[i];
			std::cout << std::endl;
		}
	}
};

