#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"
#include <iostream>
using namespace std;

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

LZespolona Oblicz (WyrazenieZesp);
ostream & operator << (ostream &StrmWyj, Operator Op);
ostream & operator << (ostream &StrmWyj, WyrazenieZesp WyrZ);

#endif
