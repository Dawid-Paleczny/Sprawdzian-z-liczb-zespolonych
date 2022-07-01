#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

using namespace std;

/*!
 * Realizuje wyświetlanie operatora.
 */
ostream & operator << (ostream &StrmWyj, Operator Op)
{
  const char oper [] = {'+', '-', '*', '/'}; //Zamiast mechanizmu switch/case zastosowałem metode przedstawioną na wykładzie
  StrmWyj << oper[Op];
  return StrmWyj;
}

/*!
 * Realizuje wyświetlanie wyrażenia zespolonego w formacie (re+imi) (operator, ale bez nawiasów) (re+imi)
 */
ostream & operator << (ostream &StrmWyj, WyrazenieZesp WyrZ)
{
  return StrmWyj << WyrZ.Arg1 << ' ' << WyrZ.Op << ' ' << WyrZ.Arg2;
}

/*!
 * Realizuje obliczenie podanego wyrażenia zespolonego za pomocą operatorów przeciążonych w LZespolona.cpp
 * Argument: 
 *    WyrZ - wyrażenie zespolone do obliczenia
 * Zwraca:
 *    Wynik zadanego wyrażenia w formie struktury LZespolona.
 * Uwaga:
 * Przy dzieleniu dzielnik nie może być zerem.
 */
LZespolona Oblicz(WyrazenieZesp WyrZ)
{
  switch(WyrZ.Op){
  case Op_Dodaj:
    return WyrZ.Arg1 + WyrZ.Arg2;
  case Op_Odejmij:
    return WyrZ.Arg1 - WyrZ.Arg2;
  case Op_Mnoz:
    return WyrZ.Arg1 * WyrZ.Arg2;
  case Op_Dziel:
    return WyrZ.Arg1 / WyrZ.Arg2;
  }
  return {0,0};
}
