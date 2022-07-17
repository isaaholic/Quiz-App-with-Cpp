#pragma once
class Answers
{
public:
	std::string varA;
	std::string varB;
	std::string varC;
	std::string varD;
	json answers;

	Answers() = default;

	Answers(std::string a,std::string b,std::string c,std::string d):varA(a),varB(b),varC(c),varD(d)
	{
		answers.push_back(varA);
		answers.push_back(varB);
		answers.push_back(varC);
		answers.push_back(varD);
	}
};

