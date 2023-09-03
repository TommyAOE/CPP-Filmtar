#pragma once
#include"Ido.h"
#include<iostream>
#include<fstream>
class Film {
	Ido hossz;
	std::string cim;
	int ev;
	bool kedvenc;
	std::string tipus;
public:
	Film(Ido hossz = Ido(), std::string cim = "NINCS", int ev = 0, bool kedvenc = false, std::string tipus = "NINCS")
		: hossz(hossz), cim(cim), ev(ev), kedvenc(kedvenc), tipus(tipus){}
	Ido& getHossz() { return hossz; }
	std::string getCim() { return cim; }
	int getEv() { return ev; }
	bool getKedvenc() { return kedvenc; }
	std::string getTipus() { return tipus; }
	virtual std::string getLeiras() = 0;
	virtual int getKorhatar() = 0;
	void setIdo(Ido h) { hossz = h; }
	void setCim(std::string c) { cim = c; }
	void setEv(int e) { ev = e; }
	void setKedvenc(bool k) { kedvenc = k; }
	virtual void DokModosit(Ido h, std::string c, int e, bool k, std::string l) = 0;
	virtual void CsalModosit(Ido h, std::string c, int e, bool k, int korh) = 0;
	virtual void Kiir() = 0;
	virtual void fajlbaIr(std::ofstream& fstr) = 0;
	virtual ~Film(){}
};