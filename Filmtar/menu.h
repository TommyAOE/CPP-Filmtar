#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include<fstream>
#include "Dokumentum.h"
#include "Csaladi.h"
#include "Tarolo.hpp"
#include "Test.h"
#include "memtrace.h"

///olvashatosag miatt kulon kiiro fgv a felhasznalo tajekozatasara
void KiirFo();

///fo menu fuggveny
/*
(1) filmek listázása
(2) keresés
(3) teszt
(9) kilepes
*/
void FoMenu(Tarolo& t);
template<typename T>
void RosszValasz(T& valasz) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Rossz tipusu a valasz!" << std::endl;
        std::cout << "Valasz: ";
        std::cin >> valasz;
    }
}
///olvashatosag miatt kulon kiiro fgv a felhasznalo tajekozatasara
void KiirKeres();

///kereses, modositas, torles almenu
/*
(1) modositas
(2) torles
(9) vissza
*/
void KeresMenu(Film* film, Tarolo& t);

#endif // MENU_H_INCLUDED
