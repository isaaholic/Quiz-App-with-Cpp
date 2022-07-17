#pragma once

class Question
{
public:
	int number;
	std::string question;
	Answers anw;

	Question() = default;

	Question(int number, std::string ques, Answers anw) :number(number), question(ques), anw(anw){}
};