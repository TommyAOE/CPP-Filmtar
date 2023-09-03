#pragma once
#include<iostream>

class Ido {
	int ora;
	int perc;
public:
	Ido(int ora = 0, int perc = 0) : ora(ora), perc(perc){}
	Ido(const Ido& rhs) : ora(rhs.ora), perc(rhs.perc){}
	int GetOra() { return ora; }
	int GetPerc() { return perc; }
	bool operator==(Ido rhs);
	bool operator!=(Ido rhs);
};
std::ostream& operator<<(std::ostream& os, Ido& ido);
