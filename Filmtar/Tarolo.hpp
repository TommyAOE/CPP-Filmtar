#pragma once
#include "Film.h"

#include <iostream>
#include<fstream>
#include <stdexcept>
#include <string>

class Tarolo {
    Film **filmek;
    size_t meret;
public:
    Tarolo() : filmek(nullptr), meret(0) {};
    size_t size() {
        return meret;
    }
    void clear() {
        for (size_t i = 0; i < meret; i++) {
            delete filmek[i];
        }
    }
    void add(Film* film) {
        if (filmek == nullptr) {
            Film** uj = new Film*[1];
            uj[meret] = film;
            filmek = uj;
            meret++;
        }
        else {
            bool benne_van = false;
            for (size_t i = 0; i < meret; i++) {
                if (film->getCim() == filmek[i]->getCim()) {
                    benne_van = true;
                }
            }
            if (!benne_van) {
                Film** uj = new Film * [meret + 1];
                for (size_t i = 0; i < meret; i++) {
                    uj[i] = filmek[i];
                }
                uj[meret] = film;
                delete[] filmek;
                filmek = uj;
                meret++;
            }
            else {
                std::cout << "Van mar ilyen" << std::endl;
                delete film;
            }
        }
        
    }
    void torol(Film* film) {
        for (size_t i = 0; i < meret; i++) {
            if (filmek[i] == film) {
                if (meret > 1) {
                    delete filmek[i];
                    Film** uj = new Film * [meret - 1];
                    for (size_t j = 0; j < i; j++) {
                        uj[j] = filmek[j];
                    }
                    for (size_t j = i; j < meret - 1; j++) {
                        uj[j] = filmek[j + 1];
                    }
                    meret--;
                    delete[] filmek;
                    filmek = uj;
                }
                else {
                    delete filmek[i];
                    delete[] filmek;
                    filmek = nullptr;
                    meret = 0;
                }
            }
        }
    }
    Film* keres(std::string keresett) {
        for (size_t i = 0; i < meret; i++) {
            if (filmek[i]->getCim() == keresett)
                return filmek[i];
        }
        std::cout << "Nincs benne az adatbazisban" << std::endl;
        return nullptr;
    }
    void list() {
        std::cout << "TIPUS \t CIM \t KIADASI EV \t JATEKIDO \t LEIRAS/KORHATAR \t KEDVENC" << std::endl;
        for (size_t i = 0; i < meret; i++) {
            if(meret != 0)
                filmek[i]->Kiir();
        }
    }
    void kedvenckiir() {
        std::cout << "TIPUS \t CIM \t KIADASI EV \t JATEKIDO \t LEIRAS/KORHATAR \t KEDVENC" << std::endl;
        for (size_t i = 0; i < meret; i++) {
            if (meret != 0 && filmek[i]->getKedvenc())
                filmek[i]->Kiir();
        }
    }
    void fajlbair(std::ofstream& fstr) {
        for (size_t i = 0; i < meret; i++) {
            filmek[i]->fajlbaIr(fstr);
        }
        fstr.close();
    }
    
    void fajlolvas(std::fstream& fstr) {
        clear();
        this->meret = 0;
        std::string line;
        const size_t meret = 7;
        std::string tagok[meret];
        size_t i = 0;
        fstr.clear();
        fstr.seekg(0);
        while (std::getline(fstr, line, '\t')) {
            tagok[i] = line;
            i++;
            if (i == meret) {
                std::string cim = tagok[1];
                int ev = std::stoi(tagok[2]);
                Ido hossz(std::stoi(tagok[3]), std::stoi(tagok[4]));
                bool kedvenc = std::stoi(tagok[6]);
                
                if (tagok[0] == "Dokumentum film") {
                    std::string leiras = tagok[5];
                    add(new Dokumentum(hossz, cim, ev, kedvenc, leiras));
                }
                if(tagok[0] == "Csaladi film"){
                    
                    int korhatar = std::stoi(tagok[5]);
                    add(new Csaladi(hossz, cim, ev, kedvenc, korhatar));
                }
                i = 0;
            }
        }
        fstr.clear();
        fstr.seekg(0);
    }
    ~Tarolo() {
        clear();
        meret = 0;
        delete[] filmek;
    }
};