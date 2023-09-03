#include "Dokumentum.h"
#include "memtrace.h"


Dokumentum::Dokumentum(Dokumentum& d) : Film(d) {
	std::cout << "DokumentumModosit" << std::endl;
	leiras = d.leiras;
}
void Dokumentum::Kiir() {
	std::cout << getTipus() << '\t' << getCim() << '\t' << getEv() << '\t' << getHossz() << '\t' << leiras << '\t';
	if (getKedvenc())	std::cout << "+" << std::endl;
	else std::cout << "-" << std::endl;
}
Dokumentum& Dokumentum::operator=(Dokumentum& rhs) {
	Film::operator=(rhs);
	if (leiras != rhs.leiras)	leiras = rhs.leiras;
	return *this;
}
void Dokumentum::fajlbaIr(std::ofstream& fstr) {
	fstr << getTipus() << '\t';
	fstr << getCim() << '\t' << getEv() << '\t' << getHossz().GetOra() << '\t' << getHossz().GetPerc() << '\t';
	fstr << leiras << '\t' << getKedvenc() << '\t';
}
void Dokumentum::DokModosit(Ido h, std::string c, int e, bool k, std::string l) {
	setIdo(h);
	setCim(c);
	setEv(e);
	setKedvenc(k);
	leiras = l;
}
void Dokumentum::CsalModosit(Ido h, std::string c, int e, bool k, int korh) {
	std::cout << "Nem lehetseges" << std::endl;
}