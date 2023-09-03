#include <iostream>
#include "menu.h"

void KiirFo()
{
    std::cout<<"VALASZTHATO MENUPONTOK:\n\n"
        "(1) Film bevitele\n"
        "(2) Filmek listazasa\n"
        "(3) Kereses\n"
        "(4) Kedvencek kiirasa\n"
        "(9) kilepes\n"<<std::endl;

    std::cout<< "Ezek kozul valasszon: 1, 2, 3, 4, 9"<<std::endl;

    std::cout<<"valasz: ";
}

void FoMenu(Tarolo& t)
{
    std::string keresettcim;
    Film* keresett;
    char tipus = ' ';
    std::string cim;
    int ora;
    int perc;
    int ev;
    bool kedvenc;
    int korhatar;
    std::string leiras;
    int valasz = 0;
    Dokumentum ujdokumentum;
    Csaladi ujcsaladi;

    while(valasz != 9)
    {
        KiirFo();
        std::cin>>valasz;
        RosszValasz(valasz);
        switch(valasz)
        {
            case 1:
                std::cout << "Adja meg a film tipusat (d - dokumentum, c - csaladi)" << std::endl << "Tipus: ";
                std::cin >> tipus;
                if (tipus == 'd' || tipus == 'c') {
                    std::cout << "Uj cim: ";
                    std::getline(std::cin, cim);
                    std::getline(std::cin, cim);
                    RosszValasz(cim);
                    std::cout << "Uj atekido (Eloszor ora, majd perc):" << std::endl << "Ora: ";
                    std::cin >> ora;
                    RosszValasz(ora);
                    std::cout << "Perc: ";
                    std::cin >> perc;
                    RosszValasz(perc);
                    std::cout << "Uj kiadasi ev: ";
                    std::cin >> ev;
                    RosszValasz(ev);
                    std::cout << "Kedvenc:(0 Nem | 1 Igen) ";
                    std::cin >> kedvenc;
                    RosszValasz(kedvenc);
                    if (tipus == 'd') {
                        std::cout << "Uj leiras: ";
                        std::getline(std::cin, leiras);
                        std::getline(std::cin, leiras);
                        RosszValasz(leiras);
                        t.add(new Dokumentum(Ido(ora, perc), cim, ev, kedvenc, leiras));
                    }
                    else if (tipus == 'c') {
                        std::cout << "Uj korhatar: ";
                        std::cin >> korhatar;
                        RosszValasz(korhatar);
                        t.add(new Csaladi(Ido(ora, perc), cim, ev, kedvenc, korhatar));
                    }
                }
                break;
            case 2:
                system("CLS"); /*konzol tartalmanak torlese, uj lap*/
                t.list();
                break;
            case 3:
                //system("CLS"); /*konzol tartalmanak torlese, uj lap*/
                
                std::cout << "Adja meg a film cimet: ";
                std::cin >> keresettcim;
                keresett = t.keres(keresettcim);
                if(keresett != nullptr)
                    KeresMenu(keresett, t);
                system("CLS");
                break;
            case 4:
                system("CLS"); /*konzol tartalmanak torlese, uj lap*/
                std::cout << "KEDVENCEK:" << std::endl;
                t.kedvenckiir();
        }

    }
}
void KiirKeres()
{
    std::cout<<"VALASZTHATO MENUPONTOK:\n\n"
        "(1) Modositas\n"
        "(2) Torles\n"
        "(9) Visszalepes a fomenube\n"<<std::endl;

    std::cout<< "Ezek kozul valasszon: 1, 2, 9"<<std::endl;

    std::cout<<"valasz: ";
}



void KeresMenu(Film* film, Tarolo& t)
{
    system("CLS"); /*konzol tartalmanak torlese, uj lap*/
    int valasz = 0;
    std::string ujcim;
    int ujora;
    int ujperc;
    int ujev;
    bool ujkedvenc;
    int ujkorhatar;
    std::string ujleiras;

    std::cout << "TIPUS \t CIM \t KIADASI EV \t JATEKIDO \t LEIRAS/KORHATAR \t KEDVENC" << std::endl;
    film->Kiir();
    while(valasz != 9)
    {
        KiirKeres();

        std::cin>>valasz;
        RosszValasz(valasz);

        switch(valasz)
        {
            case 1:
                //system("CLS"); /*konzol tartalmanak torlese, uj lap*/
                std::cout << "Korabbi cim: " << film->getCim() << std::endl;
                std::cout << "Uj cim: ";
                std::getline(std::cin, ujcim);
                std::getline(std::cin, ujcim);
                RosszValasz(ujcim);
                std::cout << "Korábbi jatekido: " << film->getHossz() << std::endl;
                std::cout << "Uj atekido (Eloszor ora, majd perc):" << std::endl << "Ora: ";
                std::cin >> ujora;
                RosszValasz(ujora);
                std::cout << "Perc: ";
                std::cin >> ujperc;
                RosszValasz(ujperc);
                std::cout << "Korabbi kiadasi ev: " << film->getEv() << std::endl;
                std::cout << "Uj kiadasi ev: ";
                std::cin >> ujev;
                RosszValasz(ujev);
                std::cout << "Kedvenc volt? (- Nem | + Igen): ";
                if (film->getKedvenc())	std::cout << "+" << std::endl;
                else std::cout << "-" << std::endl;
                std::cout << "Kedvenc:(0 Nem | 1 Igen) ";
                std::cin >> ujkedvenc;
                RosszValasz(ujkedvenc);
                if (film->getTipus() == "Dokumentum film") {
                    std::cout << "Korabbi leiras: " << film->getLeiras() << std::endl;
                    std::cout << "Uj leiras: ";
                    std::getline(std::cin, ujleiras);
                    std::getline(std::cin, ujleiras);
                    RosszValasz(ujleiras);
                    film->DokModosit(Ido(ujora, ujperc), ujcim, ujev, ujkedvenc, ujleiras);
                }
                else if (film->getTipus() == "Csaladi film") {
                    std::cout << "Korábbi korhatar: " << film->getKorhatar() << std::endl;
                    std::cout << "Uj korhatar: ";
                    std::cin >> ujkorhatar;
                    RosszValasz(ujkorhatar);
                    film->CsalModosit(Ido(ujora, ujperc), ujcim, ujev, ujkedvenc, ujkorhatar);
                }
                std::cout << "Modositva" << std::endl;
                break;
            case 2:
                
                std::cout<<"Torolve"<<std::endl;
                t.torol(film);
                break;

        }

    }
}
