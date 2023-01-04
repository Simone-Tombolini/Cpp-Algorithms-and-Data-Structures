// main.cpp : Questo file contiene la funzione 'main', in cui sono inseriti i test.

#include <iostream>
#include <algorithm>
#include<list>
#include<vector>
#include "matrix3D.h"

using namespace std;

//funtori per il test
struct int_piu_uno
{
    int operator()(int a) {
        return a = a + 1;
    }
};
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
        matrice1(0, 0, 0) = 1.0;
        matrix3D<double> matrice_tagliata = matrice1.slice(0, 1, 0, 2, 0, 1);
        matrice_tagliata.print_matrix();
        cout << endl;
        cout << "test operatore ==" << endl;
        struct eql_int {
            bool operator()(int a, int b) {
                return a == b;
            }
        };

        matrix3D<double> matrice2(matrice1);
        cout << "test operatore == e !=" << endl;
        if (matrice1 == matrice2) {
            cout << "matrice1 == matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 == matrice2 risultato: false" << endl;
        }             
        if (matrice1 != matrice2) {
            cout << "matrice1 != matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 != matrice2 risultato: false" << endl;
        }
        if (matrice1 == matrice_tagliata) {
            cout << "matrice1 == matrice_tagliata risultato: true" << endl;
        }
        else {
            cout << "matrice1 == matrice_tagliata risultato: false" << endl;
        }

        if (matrice1 != matrice_tagliata) {
            cout << "matrice1 != matrice_tagliata risultato: true" << endl;
        }
        else {
            cout << "matrice1 != matrice_tagliata risultato: false" << endl;
        }
       
        matrix3D<int> matrice_traformata(2,3,4,10);
        cout << "test transorm" << endl;
        matrice1 = transform<int, double, int_piu_uno>(matrice_traformata);
        cout << "fine test transorm" << endl;
        matrice1(0, 0, 0) = matrice1(0, 0, 0) + 0.42;
        matrice1.print_matrix("risultato");
        
    }
}
void test_matrice_costante_primitivi(bool set = true) 
{


    if (set == true) {
        cout << "---------------------Test matrice costante di primitivi ---------------------" << endl;
        //creazione di una matrice vuota, test costruttore di default
        cout << "creazione matrice costante vuota" << endl;
        const matrix3D<int> matrice0;
        cout << "creazione matrice costante con valore di default" << endl;
        const matrix3D<int> matrice1(2, 3, 4, 10);
     
        //errore in compilazione
            
       

        cout << endl;
        cout << "Matrice con costruttore secondario senza default value" << endl;
        const matrix3D<float> matrice3(3, 4, 3);

        cout << endl;
        cout << "Matrice con metodo costruttore per copia" << endl;
        const matrix3D<int> matrice2(matrice1);
        
        cout << endl;

        cout << "operatore assegnamento errore in compilazione" << endl;
        //matrice2 = matrice_costante;

        cout << "test operatore ()" << endl;
        cout << "valore non modificato " << matrice1(1, 1, 1) << endl;
        //matrice1(1, 1, 1) = 5;
        cout << "matrice1(1, 1, 1) = 5 errore in fase di compilazione" << endl;

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
        const matrix3D<int> matrice_tagliata = matrice1.slice(0,1,0, 2, 0,1);
        cout << matrice_tagliata;
        cout << endl;
    
 
        cout << "test operatore == e !=" << endl;
        if (matrice1 == matrice2) {
            cout << "matrice1 == matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 == matrice2 risultato: false" << endl;
        }



        if (matrice1 != matrice2) {
            cout << "matrice1 != matrice2 risultato: true" << endl;
        }
        else {
            cout << "matrice1 != matrice2 risultato: false" << endl;
        }
        if (matrice1 == matrice_tagliata) {
            cout << "matrice1 == matrice_tagliata risultato: true" << endl;
        }
        else {
            cout << "matrice1 == matrice_tagliata risultato: false" << endl;
        }

        if (matrice1 != matrice_tagliata) {
            cout << "matrice1 != matrice_tagliata risultato: true" << endl;
        }
        else {
            cout << "matrice1 != matrice_tagliata risultato: false" << endl;
        }

    
    }
}

void test_iteratori(bool set = true) {
    if (set == true) {
        cout << "---------------------Test iteratori ---------------------" << endl;
        cout << "iteratore non costante" << endl;
        matrix3D<int> matrice(2, 3, 4, 10);
        int dim = matrice.dim();
        matrix3D<int>::iterator b, e;
        //test begin e end
        b = matrice.begin();
        e = matrice.end();
        //faccio in modo che la matrice diventi una sequenza di numeri
        cout << "la dimensione della matrice e': " << dim << endl;
        cout << "test operatori" << endl;
        for (int i = 0; b != e; ++b) {//test ++pre
            *b = i;//test
            ++i;
        }
        matrice.print_matrix();
        b = matrice.begin();
        b++;
        cout << "test ++post :" << *b<<endl;
        matrix3D<int> m = matrice.slice(0, 1, 0, 1, 0,1);
        int a[3] = { 43,41,42 };
        
        m.fill(a+2,a+3);
        m.print_matrix();
      

       
        
      
    }
}
void test_casi_limite(bool set = true) {
    if (set == true) {
        cout << "---------------------Test casi limite ---------------------" << endl;
        matrix3D<int> matrice(2, 3, 2, 10);
        //cout << matrice(2, 3, 2) << endl;
        matrice(0, 0, 0) = 3;
        matrice(1, 2, 1) = 2;

        matrice.print_matrix();
        
        matrix3D<int>::iterator b, e;
        //test begin e end
        b = matrice.begin();
        e = matrice.end();
        b--;
        cout << *b;
         
    }
}
int main()
{
    //#ifndef NDEBUG
    cout << "Test classe templata matrice3D" << endl;

    test_metodi_fonamentali_primitivi();
    test_metodi_ausiliari_primitivi();
    test_matrice_costante_primitivi(false);
    test_iteratori(false);
    test_casi_limite(false);
    cout << "Fine test classe templata matrice3D" << endl;
   /* matrix3D<double> matrice(2, 3, 2, 10.5);
    matrice(1, 1, 1) = 4.7;
    matrix3D<int> m = matrice;*/
    //errore in compilazione v 
    //matrix3D<string> m2 = static_cast<matrix3D<string> >(matrice);
    //m2.print_matrix();
    //#endif
   
}




















