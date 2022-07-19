#pragma once
class Answers
{
public:
	std::vector<Answers*> answer;
	json answers;

	Answers() = default;

	//Answers(std::string a,std::string b,std::string c,std::string d):varA(a),varB(b),varC(c),varD(d)
	//{
	//	answers.push_back(varA);
	//	answers.push_back(varB);
	//	answers.push_back(varC);
	//	answers.push_back(varD);
	//}

	void addAnswers(std::vector<std::string> answ)
	{
		for (size_t i = 0; i < answ.size(); i++)
		{
			answers.push_back(answ[i]);
		}
	}

};

