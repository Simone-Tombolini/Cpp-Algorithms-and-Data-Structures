// main.cpp : Questo file contiene la funzione 'main', in cui sono inseriti i test.

#include <iostream>
#include "matrix3D.h"

using namespace std;
void test_metodi_fonamentali() 
{
    #ifndef NDEBUG
        cout << "---------------------Test metodi fondamentali---------------------" << endl;
    #endif
   
    //creazione di una matrice vuota, test costruttore di default
    matrix3D<int> matrice0; 
    
    //creazione di una matrice con il valore di default 0.1, test costruttore secondario
    cout << "Matrice con metodo costruttore secondario" << endl;
    matrix3D<double> matrice1(4, 2, 3, 0.1);

    cout << "Matrice con metodo costruttore per copia" << endl;
    matrix3D<double> matrice2(matrice1);

    cout << "valore non modificato " << matrice1(1, 1, 1) << endl;
    matrice1(1, 1, 1) = 5;
    cout << "valore modificato " << matrice1(1, 1, 1) << endl;
    
    matrice2 = matrice1;
    //prova di stampa matrice
    cout << matrice1;
}


int main()
{
    cout << "Test classe templata matrice3D" << endl;

    test_metodi_fonamentali();
    
}

