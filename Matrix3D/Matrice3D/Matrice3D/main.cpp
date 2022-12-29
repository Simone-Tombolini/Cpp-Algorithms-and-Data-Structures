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
    matrix3D<int> pippo0; 
    
    //creazione di una matrice con il valore di default 0.1, test costruttore secondario
    matrix3D<double> pippo1(4, 2, 3, 0.1);
    
    matrix3D<double> pippo2(pippo1);

    cout<< pippo1(1, 1, 1) << endl;
}


int main()
{
    cout << "Test classe templata matrice3D" << endl;

    test_metodi_fonamentali();
    
}

