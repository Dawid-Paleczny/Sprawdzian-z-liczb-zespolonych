#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <cstdio> // funkcja getchar



using namespace std;

int main(int argc, char **argv)
{
   
    int zatrzymanie_programu;;

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    zatrzymanie_programu = getchar();
    return 1;
  }


  BazaTestu   BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  } 


  
  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_Pytanie;
  LZespolona LZesp_Odpowiedz;
  Wyniki mojewyniki = {0, 0};
  int BladWprowadzania = 0;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_Pytanie)) {
    cout << "Prosze obliczyc: " << WyrZ_Pytanie << '=' << "     Udziel odpowiedzi w postaci ([+lub-]a[+lub-]bi) np (1+2i)" << endl;
    cout << "Twoja odpowiedz to: ";
    while (!(cin >> LZesp_Odpowiedz) && BladWprowadzania < 2) {   //W razie napotkania błedu opróżnia bufor i zeruje obiekt cin
      cin.clear();
      while (cin.get() != '\n')
	;
      cout << "Blad wprowadzania, sprobuj jeszcze raz: ";
      BladWprowadzania++;
    }

    BladWprowadzania = 0;
    mojewyniki.LiczbaPytan++;

    if (LZesp_Odpowiedz == Oblicz(WyrZ_Pytanie)) {   //Sprawdza poprawność odpowiedzi , w razie błędu mówi jak miało być
      cout << "Odpowiedz prawidlowa\n\n";
      mojewyniki.LiczbaPoprawnych++;
    }
    else {
      cout << "Zle, chodzilo o " << Oblicz(WyrZ_Pytanie) << endl << endl;
    }
  }

  cout << "Twoj wynik to: " << PodajWyniki(mojewyniki) << '%';
  cout << endl;
  cout << "Koniec testu" << endl;
  cout << endl;

}
