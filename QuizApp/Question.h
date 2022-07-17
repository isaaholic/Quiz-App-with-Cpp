#pragma once

class Question
{
public:
	static int number;
	std::string question;

	Question(std::string ques):question(ques)
	{
		number++;
	}
};

int Question::number = 0;