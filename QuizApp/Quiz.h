#pragma once
class Quiz
{
private:
	std::string fileName;
	std::string author;
	json quizFile;
	std::vector<Question> questions;
public:
	Quiz(std::string fName, std::string author) :fileName(fName), author(author)
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
			quizFile[i] = j;
		}
		std::ofstream writer;
		writer.open(fileName + ".json");
		writer << quizFile.dump(1);
	}

	void writeJson()
	{
		std::ifstream reader(fileName + ".json");
		reader >> quizFile;
		reader.close();
		for (size_t i = 0; i < questions.size(); i++)
		{
			std::cout << quizFile[i];
		}
	}
};

