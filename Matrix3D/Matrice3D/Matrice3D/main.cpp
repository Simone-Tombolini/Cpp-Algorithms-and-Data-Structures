// main.cpp : Questo file contiene la funzione 'main', in cui sono inseriti i test.

#include <iostream>
#include "matrix3D.h"

using namespace std;
void test_metodi_fonamentali_primitivi(bool set = true) 
{
    if (set == true) {
        cout << "---------------------Test metodi fondamentali primitivi---------------------" << endl;


        //creazione di una matrice vuota, test costruttore di default
        matrix3D<int> matrice0;

        //creazione di una matrice con il valore di default 0.1, test costruttore secondario
        cout << "Matrice con costruttore secondario con default value" << endl;
        matrix3D<double> matrice1(4, 2, 3, 0.1);

        cout << endl;
        cout << "Matrice con costruttore secondario senza default value" << endl;
        matrix3D<float> matrice3(3, 4, 3);

        cout << endl;
        cout << "Matrice con metodo costruttore per copia" << endl;
        matrix3D<double> matrice2(matrice1);

        cout << endl;

        cout << "operatore assegnamento" << endl;
        matrice2 = matrice1;



        //prova di stampa matrice

      
    }
}
void test_metodi_ausiliari_primitivi(bool set = true) {
    if (set == true) {
        cout << "---------------------Test metodi ausiliari primitivi---------------------" << endl;
        cout << "creazione matrice di test" << endl;
        matrix3D<double> matrice1(4, 2, 3, 0.2);
        cout << endl;

        cout << "test operatore ()" << endl;
        cout << "valore non modificato " << matrice1(1, 1, 1) << endl;
        matrice1(1, 1, 1) = 5;
        cout << "valore modificato " << matrice1(1, 1, 1) << endl;

        cout << endl;

        cout << "test getter size" << endl;
        //matrice1.size_z() = 1;
        //erroe in compilazione indica che non posso modificare la size con questi operatori
        cout << "size z: " << matrice1.size_z() << endl;
        cout << "size y: " << matrice1.size_y() << endl;
        cout << "size x: " << matrice1.size_x() << endl;
        cout << endl;

        //vedremo meglio questi test nella serializzazione
        cout << "test operatore <<" << endl;
        cout << matrice1;
        cout << endl;

        cout << "test metodo slice()" << endl;
        matrix3D<double> matrice_tagliata = matrice1.slice(1, 2, 1);
        cout << matrice_tagliata;
        cout << endl;
        cout << "test operatore ==" << endl;
        struct eql_int {
            bool operator()(int a, int b) {
                return a == b;
            }
        };
        matrix3D<double> matrice2(matrice1);
      
        if (matrice1 == matrice2) {
            cout << "matrice1 == matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 == matrice2 risultato: false" << endl;
        }
        cout << "test operatore !=" << endl;
       
        
        if (matrice1 != matrice2) {
            cout << "matrice1 != matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 != matrice2 risultato: false" << endl;
        }
    }
}
void test_matrice_costante_primitivi(bool set = true) 
{
    if (set == true) {
        cout << "---------------------Test matrice costante di primitivi---------------------" << endl;
        cout << "creazione matrice costante" << endl;
        matrix3D<int> const matrice_costante(2, 3, 4, 10);
        cout <<"prova stampa valore "<< matrice_costante(1, 1, 1) << endl;
        //matrice_costante(1, 1, 1) = 2;
        //errore in compilazione
    }
}
int main()
{
    #ifndef NDEBUG
    cout << "Test classe templata matrice3D" << endl;

    test_metodi_fonamentali_primitivi();
    test_metodi_ausiliari_primitivi();
    test_matrice_costante_primitivi(false);
    #endif
}

