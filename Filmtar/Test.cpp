
#include <iostream>
#include<fstream>
#include "Dokumentum.h"
#include "Csaladi.h"
#include "Tarolo.hpp"
#include "Test.h"
#include "memtrace.h"

void elvalasztas() {
	std::cout << "---------------------------------" << std::endl << std::endl;
}
void fejlec() {
	std::cout << "TIPUS \t CIM \t KIADASI EV \t JATEKIDO \t LEIRAS/KORHATAR \t KEDVENC" << std::endl;
}
void Test() {
	std::string file = "mentettTEST.txt";
	std::ofstream ofstr(file);
	std::fstream fstr(file);
	Tarolo t;
	std::cout << "PROGRAM TESZTELESE:" << std::endl;
	elvalasztas();
	std::cout << "KONSTRUKTOROK:" << std::endl;
	fejlec();
	std::cout << "Dokumentum_0_param_ctor:" << std::endl;
	Dokumentum d1;
	d1.Kiir();
	std::cout << "Dokumentum_teljes_ctor:" << std::endl;
	Dokumentum d2(Ido(2, 30), "Sahara", 1987, 0, "Szahararol szolo dokumentumfilm");
	d2.Kiir();
	std::cout << "Csaladi_0_param ctor:" << std::endl;
	Csaladi cs1;
	cs1.Kiir();
	std::cout << "Csaladi_teljes ctor:" << std::endl;
	Csaladi cs2(Ido(1, 45), "Iron Man", 2008, 1, 12);
	cs2.Kiir();
	elvalasztas();

	std::cout << "TAROLO:" << std::endl;
	std::cout << "Tarolo_hozzaadas_es_lista:" << std::endl;
	t.add(new Dokumentum(Ido(2, 30), "Sahara", 1987, 0, "Szahararol szolo dokumentumfilm"));
	t.add(new Csaladi(Ido(1, 45), "Iron Man", 2008, 1, 12));
	t.list();
	std::cout << "Tarolo_kereses_|Iron Man|:" << std::endl;
	t.keres("Iron Man")->Kiir();
	std::cout << "Film_modosit_|Iron Man 2-re|:" << std::endl;
	t.keres("Iron Man")->CsalModosit(Ido(1, 45), "Iron Man 2", 2008, 1, 12);
	t.list();
	std::cout << "Film_modosit_|Iron Man 2 dokumentumfilmre?|:" << std::endl;
	t.keres("Iron Man 2")->DokModosit(Ido(1, 45), "Iron Man 2", 2008, 1, "Dokumentumfilm?");
	std::cout << "Film_torol_|Iron Man 2|:" << std::endl;
	t.torol(t.keres("Iron Man 2"));
	t.list();
	elvalasztas();
	std::cout << "FAJLKEZELES:" << std::endl;
	std::cout << "File_kiirat:" << std::endl;
	Tarolo t2;
	Csaladi cs3(Ido(2, 45), "Pinoccio", 2000, 0, 6);
	t2.add(new Csaladi(Ido(2, 45), "Pinoccio", 2000, 0, 6));
	t2.add(new Dokumentum(Ido(2, 30), "Termeszet", 1987, 0, "Szahararol szolo dokumentumfilm"));
	t2.list();
	t2.fajlbair(ofstr);
	std::cout << "File_beolvas:" << std::endl;
	t.fajlolvas(fstr);
	t.list();
}