#pragma once
#include<iostream>
#include "Film.h"

class Dokumentum : public Film {
	std::string leiras;
public:
	Dokumentum(Ido hossz = Ido(), std::string cim = "NINCS", int ev = 0, bool kedvenc = false, std::string leiras = "NINCS")
		: Film(hossz, cim, ev, kedvenc, "Dokumentum film"), leiras(leiras) {
	}
	Dokumentum(Dokumentum& d);
	std::string getLeiras() { return leiras; }
	int getKorhatar() { std::cout << "Nincs korhatar"; return 0; };
	Dokumentum& operator=(Dokumentum& rhs);
	void Kiir();
	void fajlbaIr(std::ofstream& fstr);
	void DokModosit(Ido h, std::string c, int e, bool k, std::string l);
	void CsalModosit(Ido h, std::string c, int e, bool k, int korh);
};