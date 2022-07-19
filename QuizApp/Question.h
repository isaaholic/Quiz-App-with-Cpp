#pragma once

class Question
{
public:
	int number;
	std::string question;
	Answers answers;

	Question() = default;

	Question(int number, std::string ques, Answers anw) :question(ques), answers(answers)
	{
		this->number = number;
	}

};