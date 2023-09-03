#include "Csaladi.h"
#include "memtrace.h"

void Csaladi::Kiir() {
	std::cout << getTipus() << '\t' << getCim() << '\t' << getEv() << '\t' << getHossz() << '\t' << korhatar << '\t';
	if (getKedvenc())	std::cout << "+" << std::endl;
	else std::cout << "-" << std::endl;
}
void Csaladi::fajlbaIr(std::ofstream& fstr) {
	fstr << getTipus() << '\t';
	fstr << getCim() << '\t' << getEv() << '\t' << getHossz().GetOra() << '\t' << getHossz().GetPerc() << '\t';
	fstr << korhatar << '\t' << getKedvenc() << '\t';
}
void Csaladi::CsalModosit(Ido h, std::string c, int e, bool k, int korh) {
	setIdo(h);
	setCim(c);
	setEv(e);
	setKedvenc(k);
	korhatar = korh;
}
void Csaladi::DokModosit(Ido h, std::string c, int e, bool k, std::string l) {
	std::cout << "Nem lehetseges" << std::endl;
}