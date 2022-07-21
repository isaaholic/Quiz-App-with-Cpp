#pragma once

class Controller
{
public:

	static void Control(int& c, int cMax, int& choice)
	{
		static int chc;
		switch (chc = _getch())
		{
		case KEY_UP:
			if (c == 0)
				c = cMax;
			else if (c <= cMax)
				c--;
			break;
		case KEY_DOWN:
			if (c == cMax)
				c = 0;
			else if (c < cMax)
				c++;
			break;
		case KEY_ENTER:
			choice = c + 1;
			break;
		}
	}
};