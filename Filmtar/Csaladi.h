#pragma once
#include "Film.h"

class Csaladi : public Film {
	int korhatar;
public:
	Csaladi(Ido hossz = Ido(), std::string cim = "NINCS", int ev = 0, bool kedvenc = false, int korhatar = 0)
		: Film(hossz, cim, ev, kedvenc, "Csaladi film"), korhatar(korhatar) {
	}
	std::string getLeiras() { std::cout << "Nincs korhatar"; return ""; }
	int getKorhatar() {  return korhatar; };
	void Kiir();
	void fajlbaIr(std::ofstream& fstr);
	void CsalModosit(Ido h, std::string c, int e, bool k, int korh);
	void DokModosit(Ido h, std::string c, int e, bool k, std::string l);
};