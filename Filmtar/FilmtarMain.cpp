
#include "menu.h"
#include "Test.h"
	
int main()
{
	std::string file = "mentett.txt";
	std::fstream fstr(file);
	Tarolo t;
	t.fajlolvas(fstr);
	Test();
	std::cout << "FOMENU" << std::endl;
	FoMenu(t);
	//ofstr.open(file, std::ofstream::out | std::ofstream::trunc);
	std::ofstream ofstr(file);
	t.fajlbair(ofstr);
	std::cout << "VEGE" << std::endl;
	return 0;
}

