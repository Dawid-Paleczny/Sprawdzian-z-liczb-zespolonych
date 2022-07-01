#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"
/*
 * Modeluje pojęcie wyników, pomaga śledzić liczbę pytań oraz łączną liczbę poprawnych odpoiedzi.
 */
struct Wyniki {
  int LiczbaPytan;
  int LiczbaPoprawnych;
};
/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};

int PodajWyniki(Wyniki mojewyniki);

/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );

#endif
