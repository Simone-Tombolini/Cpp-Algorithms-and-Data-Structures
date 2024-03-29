//Programmazione C++
//Tombolini Simone 869564
//Esame appello gennaio 2023

// main.cpp : Questo file contiene la funzione 'main', in cui sono inseriti i test.

#include <iostream>
#include <algorithm>
#include<list>
#include<vector>
#include<fstream>
#include "matrix3D.h"

using namespace std;



//funtori e classi per i test
/**
 * @brief Classe di test user
 * Rappresenta un utente con nome e numero di telefono, utilizzata solo a scopo di test.
 */
class user {
public:
    string _name;//nome
    int _number; // numero telefono
    /**
     * @brief Costruttore di default
     * Crea un nuovo oggetto vuoto
     */
    user(): _name(""), _number(0) {}
    /**
     * @brief Disturttore
     * Libera la memoria
     */
    ~user(){}
    /**
     * @brief Costruttore secondario
     * Costuisce un oggetto e inizializza i parametri
     * @param name Nome
     * @param n Numero di telefono
     */
    user(string name, int n) : _name(name), _number(n) {}
};
/**
 * @brief Operatore di stream
 * Stram sulla classe os della libreria standard, necessaria per la classe matrix3D.h
 * @param os 
 * @param u 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const user& u) {
    std::cout << "(" << u._name << "," << u._number << ")";
    return os;
}
/**
 * @brief Funotre di test fra utenti numero 1
 * primo funtore di test
 */
struct eql_user_v1 {
    /**
     * @brief Uguaglianza fra utenti
     * Realizza l'uguaglianza fra due utenti
     * @param u1 utente 1
     * @param u2 utente 2
     * @return true se uguali
     * @return false se diversi
     */
    bool operator()(const user& u1, const user& u2) const {
        return (u1._name == u2._name);
    }
};
/**
 * @brief Funotre di test fra utenti numero 2
 * primo funtore di test
 */
struct eql_user_v2 {
    bool operator()(const user& u1, const user& u2) const {
        return (u1._name == u2._name && u1._number == u2._number);
    }
};
/**
 * @brief Struttura di test che rappresenta un punto
 * Struttura di test che rappresenta un punto
 */
struct point {
    //per scopi di test non e' necessario mettere privati i dati
    int _x; ///< coordinata x del punto
    int _y; ///< coordinata y del punto
    //metodi fondamentali della classe
    /**
     * @brief Construttore
     * Construttore
     */
    point() : _x(0), _y(0) {}
    /**
     * @brief Distruttore
     * distruttore
     */
    ~point() {
       
    }
    /**
     * @brief Costruttore secondario
     * Costruttore secondario
     * @param x 
     * @param y 
     */
    point(int x, int y) : _x(x), _y(y) {}
    /**
     * @brief Costruttore per copia
     * Costruttore per copia
     * @param other 
     */
    point(const point& other) : _x(0) , _y(0) {
        _x = other._x;
        _y = other._y;
    }
    /**
     * @brief Costruttore per copia
     * Costruttore per copia
     * @param other 
     * @return point& 
     */
    point& operator=(const point& other)
    {
        if (this != &other)
        {
            point tmp(other);
            
            this->swap(tmp);
        }
        return *this;
    }
    //swap che e' comoda per operator=
    /**
     * @brief inverte due punti
     * inverte due punti
     * @param other 
     */
    void swap(point& other) {
        std::swap(_x, other._x);
        std::swap(_y, other._y);
    }
};
/**
 * @brief Operatore di stream
 *  Operatore di stream
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const point& p) {
    std::cout << "(" << p._x << "," << p._y << ")";
    return os;
}
/**
 * @brief Funtore di test
 * Funtore di test aggiuntivo
 */
struct eql_point {
    bool operator()(const point& p1, const point& p2) const {
        return (p1._x == p2._x && p1._y == p2._y);
    }
};
/**
 * @brief Funtore di test
 * Funtore di test aggiuntivo
 */
struct int_piu_uno
{
    /**
     * @brief operatore ()
     * logica funtore aggiuntivo
     * @param v 
     * @return int 
     */
    int operator()(int v) {
        return v = v + 1;
    }
};
/**
 * @brief Funtore di test
 * Funtore di test aggiuntivo
 */
struct int_eql_true
{
    /**
     * @brief operatore ()
     * logica funtore aggiuntivo
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool operator()(int a, int b) {
        return true;
    }
};
/**
 * @brief Funtore di test
 * Funtore di test aggiuntivo
 */
struct user_to_int
{
    /**
     * @brief operatore ()
     * logica funtore aggiuntivo
     * @param v 
     * @return int 
     */
    int operator()(user v) {
        int n = v._number;
        return n;
    }
};
/**
 * @brief Funtore di test
 * Funtore di test aggiuntivo
 */
struct double_quadrato
{
    /**
     * @brief operatore ()
     * logica funtore aggiuntivo
     * @param v 
     * @return double 
     */
    double operator()(double v) {
        return v = v * v;
    }
};
/**
 * @brief Test per metodi fonamentali primitivi
 * Metodo che esegue i test dei metodi fonamentali primitivi
 * @param set imposta a false per non eseguire i test
 */
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
/**
 * @brief Test per metodi ausiliari primitivi
 * Metodo che esegue i test dei metodi ausiliari primitivi
 * @param set imposta a false per non eseguire i test
 */
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
        cout << "test eccezione" << endl;
        try
        {
            matrice1(100, 100, 100) = 0.0;
        }
        catch (out_of_bound_exception e) {
            cout << "eccezione con messaggio: '" << e.what() <<
                "' valori z:" << e.get_z() << " y:" << e.get_y() << " x:" << e.get_x() << endl;
        }
        try
        {
            matrice1(-1, 1, 0) = 0.0;
        }
        catch (out_of_bound_exception e) {
            cout << "eccezione con messaggio: '" << e.what() <<
                "' valori z:" << e.get_z() << " y:" << e.get_y() << " x:" << e.get_x() << endl;
        }

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
        int i = 0;
        matrix3D<int> matrice_da_tagliare(2, 3, 4, i);
        int dim = matrice_da_tagliare.dim();
        //uso gli iteratori per vedere se il taglio della matrice ha senso 
        matrix3D<int>::iterator b, e;
        //test begin e end
        b = matrice_da_tagliare.begin();
        e = matrice_da_tagliare.end();
   
        for (int i = 0; b != e; ++b) {//test ++pre
            *b = i;//test
            ++i;
        }
        matrice_da_tagliare.print_matrix("matirce da tagliare");

     
        matrice1(0, 0, 0) = 1.0;
        matrix3D<double> matrice_tagliata = matrice_da_tagliare.slice(1, 2, 0, 3, 0, 2);
        matrice_tagliata.print_matrix();
        try { 
            matrix3D<double> matrice_tagliata2 = matrice1.slice(0, 11, 0, 2, 0, 1); 
        }
        catch(logic_error e) {
            cout << "eccezione con messaggio " << e.what();
        }
        cout << endl;

        cout << "test operatore ==" << endl;

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
        cout << "test operatore == con funtore diverso" << endl;
       
        matrix3D<int> matrice_traformata(2,3,4,10);
        cout << "test transorm" << endl;
        matrice1 = transform<int, double, int_piu_uno>(matrice_traformata);
        cout << "fine test transorm" << endl;
        matrice1(0, 0, 0) = matrice1(0, 0, 0) + 0.42;
        matrice1.print_matrix("risultato transform 1");
        matrice1 = transform<double, int, double_quadrato>(matrice1);
        matrice1.print_matrix("risultato transform 2");
    }
}
/**
 * @brief Test per matrice costante primitivi
 * Metodo che esegue i test della matrice costante primitivi
 * @param set imposta a false per non eseguire i test
 */
void test_matrice_costante_primitivi(bool set = true) 
{


    if (set == true) {
        cout << "---------------------Test matrice costante di primitivi ---------------------" << endl;
        //creazione di una matrice vuota, test costruttore di default
        cout << "creazione matrice costante vuota" << endl;
        const matrix3D<int> matrice0;
        int n = 10;
        cout << "creazione matrice costante con valore di default" << endl;
        const matrix3D<int> matrice1(2, 3, 4, n);
     
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
        const matrix3D<int> matrice_tagliata(matrice1.slice(0, 1, 0, 2, 0, 1));
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
        matrix3D<int> matrice_non_costante(2, 3, 4, 10);
        const matrix3D<double> matrice_traformata(2, 3, 4, 10);
        cout << "test transorm" << endl;
        matrice_non_costante = transform<double, int, int_piu_uno>(matrice_traformata);
        cout << "fine test transorm" << endl;
       
        matrice_non_costante.print_matrix("risultato transform 1");
        matrice_non_costante = transform<int, double, double_quadrato>(matrice1);
        matrice_non_costante.print_matrix("risultato transform 2");
    
    }
}
/**
 * @brief Test per test mirati ad utiizzare le funzioni delle classi custom
 * Metodo che esegue i test mirati ad utiizzare le funzioni delle classi custom
 * @param set imposta a false per non eseguire i test
 */
void test_classe_custom(bool set = true) {
    if (set == true) {
        cout << "---------------------Test con classi custom mirati---------------------" << endl;
        cout << "test mirati a sforzare le classi custom" << endl;
        point punto1(0, 0);
        matrix3D<point, eql_point> matrice_classe_custom1(3,2,6);
        point punto2(0, 1);
        matrix3D<point, eql_point> matrice_classe_custom2(3, 2, 6, punto2);
        cout << matrice_classe_custom1 << endl;
        if (matrice_classe_custom2 == matrice_classe_custom1) { 
            cout << "test passato, grazie al funtore con una logica diversa" << endl; 
        }
        matrice_classe_custom2.print_matrix();

        user utente1("simone", 123456789);
        matrix3D<user, eql_user_v1> matrice_classe_custom3(2, 3, 4, utente1);
        matrice_classe_custom3.print_matrix();
        user utente2("simone", 42);
        matrix3D<user, eql_user_v1> matrice_classe_custom4(2, 3, 4, utente2);
        matrice_classe_custom3.print_matrix();

        user utente3("simone", 123456789);
        matrix3D<user, eql_user_v2> matrice_classe_custom5(2, 3, 4, utente1);
        matrice_classe_custom3.print_matrix();
        user utente4("simone", 42);
        matrix3D<user, eql_user_v2> matrice_classe_custom6(2, 3, 4, utente2);
        matrice_classe_custom3.print_matrix();
        
        //funtori differenti risultati differenti
        assert(matrice_classe_custom3 == matrice_classe_custom4);
        assert(matrice_classe_custom5 != matrice_classe_custom6);
        cout << "funtore 1 risultato " << (matrice_classe_custom3 == matrice_classe_custom4 ) << endl;
        cout << "funtore 2 risultato " << (matrice_classe_custom5 == matrice_classe_custom6) << endl;

        cout << endl << "test generici per le classi custom" << endl;
  

    }
}
/**
 * @brief Test per le classi custom più generali
 * Metodo che esegue test per le classi custom più generali
 * @param set imposta a false per non eseguire i test
 */
void test_classe_custom_generici(bool set = true) {
    if (set == true) {
        //alcuni dei test per i metodi fondamentali sono gi� stati eseguiti
        point punto(2, 2);

        matrix3D<point, eql_point> matrice0;

        matrix3D<point, eql_point>matrice1(2, 3, 4, punto);

        matrix3D<point, eql_point> matrice2(matrice1);

        matrice0 = matrice1;

        matrice0.print_matrix();

        matrice1(1, 1, 1) = punto;

        cout << "test getter size" << endl;
        //matrice1.size_z() = 1;
        //erroe in compilazione indica che non posso modificare la size con questi operatori
        cout << "size z: " << matrice1.size_z() << endl;
        cout << "size y: " << matrice1.size_y() << endl;
        cout << "size x: " << matrice1.size_x() << endl;
        cout << endl;

        cout << "test metodo slice()" << endl;
        point g(2, 3);
        matrix3D<point, eql_point> matrice_da_tagliare(2, 3, 4, point(2,8));
        int dim = matrice_da_tagliare.dim();

        matrice_da_tagliare.print_matrix("matirce da tagliare");


        matrice_da_tagliare(0, 0, 1) = point(1, 1);
        matrix3D<point, eql_point> matrice_tagliata = matrice_da_tagliare.slice(1, 2, 0, 3, 0, 2);
        matrice_tagliata.print_matrix("matirce tagliata");

        try {
            matrix3D<point, eql_point> matrice_tagliata2 = matrice1.slice(0, 11, 0, 2, 0, 1);
        }
        catch (logic_error e) {
            cout << "eccezione con messaggio " << e.what();
        }

        cout << endl;
        const int n = 12;
        user* rubrica = new user[n];
        for (int i = 0; i < n; ++i) {
            rubrica[i] = user("persona", i);
        }
        user utente0("non raggiunto", -1);
        matrix3D<user, eql_user_v1> matrice_da_riempire(2, 3, 4, utente0);
        matrice_da_riempire.fill(rubrica+4, rubrica + n);
        matrice_da_riempire.print_matrix();

        matrix3D<int, int_eql_true> matrice_traformata(2, 3, 4, 10);
        cout << "test transorm" << endl;
        matrice_traformata = transform<user, int, user_to_int>(matrice_da_riempire);
        delete[] rubrica;
    }
}
/**
 * @brief Test per gli iteratori
 * Metodo che esegue i test gli iteratori
 * @param set imposta a false per non eseguire i test
 */
void test_iteratori(bool set = true) {
    if (set == true) {
        cout << "---------------------Test iteratori non costanti---------------------" << endl;
        cout << "creazione matrice" << endl;
        matrix3D<int> matrice(2, 3, 4, 10);
        int dim = matrice.dim();
        matrix3D<int>::iterator b, e;
        //test begin e end
        b = matrice.begin();
        e = matrice.end();
        //faccio in modo che la matrice diventi una sequenza crescente di numeri
        cout << "la dimensione della matrice e': " << dim << endl;
        cout << "test riempimento matirce " << endl;
        for (int i = 0; b != e; ++b) {//test ++pre
            *b = i;//test
            ++i;
        }
       
        matrice.print_matrix("matrice per i test");

        cout << "test operatori unari" << endl;
        e = matrice.end();
        cout << "end: " << *b << endl;
        b = e;
        b = matrice.begin();
        cout<< "begin: " << *b << endl;
        cout << "->: " << b.operator->() << endl;
        b++;
        cout << "++post: " << *b << endl;
        b--;
        cout << "--post: " << *b << endl;
        ++b;
        cout << "++pre: " << *b << endl;
        --b;
        cout << "--pre: " << *b << endl;
        b = b + 2;
        cout << "+: " << *b << endl;
        b = b - 2;
        cout << "-: " << *b << endl;
        b += 2;
        cout << "+=: " << *b << endl;
        b -= 2;
        cout << "-=: " << *b << endl;
        
        cout << "[3]: " << b[3] << endl;

        cout << "test operatori binari" << endl;

        if (b == e) {
            cout << "== non passato" << endl;
        }
        else {
            cout << "== passato" << endl;
        }

        if (b != e) {
            cout << "!= passato" << endl;
        }
        else {
            cout << "!= non passato" << endl;
        }

        if (b <= e) {
            cout << "<= passato" << endl;
        }
        else {
            cout << "<= non passato" << endl;
        }

        if (b < e) {
            cout << "< passato" << endl;
        }
        else {
            cout << "< non passato" << endl;
        }

        if (b >= e) {
            cout << ">= non passato" << endl;
        }
        else {
            cout << ">= passato" << endl;
        }

        if (b > e) {
            cout << "> non passato" << endl;
        }
        else {
            cout << "> passato" << endl;
        }

        matrix3D<int>::const_iterator ec;
        ec = matrice.end();
        
        cout << "test operatori binari interfaccia a iteratore costante" << endl;

        if (b == ec) {
            cout << "== non passato" << endl;
        }
        else {
            cout << "== passato" << endl;
        }

        if (b != ec) {
            cout << "!= passato" << endl;
        }
        else {
            cout << "!= non passato" << endl;
        }

        if (b <= ec) {
            cout << "<= passato" << endl;
        }
        else {
            cout << "<= non passato" << endl;
        }

        if (b < ec) {
            cout << "< passato" << endl;
        }
        else {
            cout << "< non passato" << endl;
        }

        if (b >= ec) {
            cout << ">= non passato" << endl;
        }
        else {
            cout << ">= passato" << endl;
        }

        if (b > ec) {
            cout << "> non passato" << endl;
        }
        else {
            cout << "> passato" << endl;
        }

        

        matrix3D<int> m = matrice.slice(0, 1, 0, 1, 0,1);
        int a[3] = { 43,41,42 };

        cout << "test fill" << endl;
        m.fill(a+2,a+3);
        m.print_matrix("fill con meno elementi");
        matrix3D<double> m2(2, 2, 1, 0.1);
        double d[10] = { 1.2, 2.8, 3.14, 4.6, 5.4, 6.1, 7.8, 8.0, 9.1, 10.2 };
        m2.fill(d, d + 10);
        m2.print_matrix("fill con piu' elementi");
    }
}
/**
 * @brief Test per gli iteratori costanti
 * Metodo che esegue i test gli iteratori costanti
 * @param set imposta a false per non eseguire i test
 */
void test_iteratori_costanti(bool set = true) {
    if (set == true) 
    {
        cout << "---------------------Test iteratori costanti---------------------" << endl;
        cout << "creazione matrice" << endl;
        matrix3D<int> matrice(2, 3, 4, 10);
        int dim = matrice.dim();
        matrix3D<int>::const_iterator b, e;
        matrix3D<int>::iterator b2;
        //test begin e end
        b2 = matrice.begin();
      
        e = matrice.end();
        //faccio in modo che la matrice diventi una sequenza crescente di numeri
        cout << "la dimensione della matrice e': " << dim << endl;
        cout << "test riempimento matirce " << endl;
        for (int i = 0; b2 != e; ++b2) {//test ++pre
            *b2 = i;//test
            ++i;
        }

        matrice.print_matrix("matrice per i test");

        cout << "test operatori unari" << endl;
        e = matrice.end();
        b = matrice.begin();
        cout << "end: " << *b << endl;
        
        
        cout << "begin: " << *b << endl;
        cout << "->: " << b.operator->() << endl;
        b++;
        cout << "++post: " << *b << endl;
        b--;
        cout << "--post: " << *b << endl;
        ++b;
        cout << "++pre: " << *b << endl;
        --b;
        cout << "--pre: " << *b << endl;
        b = b + 2;
        cout << "+: " << *b << endl;
        b = b - 2;
        cout << "-: " << *b << endl;
        b += 2;
        cout << "+=: " << *b << endl;
        b -= 2;
        cout << "-=: " << *b << endl;

        cout << "[3]: " << b[3] << endl;

        cout << "test operatori binari" << endl;

        if (b == e) {
            cout << "== non passato" << endl;
        }
        else {
            cout << "== passato" << endl;
        }

        if (b != e) {
            cout << "!= passato" << endl;
        }
        else {
            cout << "!= non passato" << endl;
        }

        if (b <= e) {
            cout << "<= passato" << endl;
        }
        else {
            cout << "<= non passato" << endl;
        }

        if (b < e) {
            cout << "< passato" << endl;
        }
        else {
            cout << "< non passato" << endl;
        }

        if (b >= e) {
            cout << ">= non passato" << endl;
        }
        else {
            cout << ">= passato" << endl;
        }

        if (b > e) {
            cout << "> non passato" << endl;
        }
        else {
            cout << "> passato" << endl;
        }

        matrix3D<int>::const_iterator ec;
        ec = matrice.end();

        cout << "test operatori binari interfaccia a iteratore costante" << endl;

        if (b == ec) {
            cout << "== non passato" << endl;
        }
        else {
            cout << "== passato" << endl;
        }

        if (b != ec) {
            cout << "!= passato" << endl;
        }
        else {
            cout << "!= non passato" << endl;
        }

        if (b <= ec) {
            cout << "<= passato" << endl;
        }
        else {
            cout << "<= non passato" << endl;
        }

        if (b < ec) {
            cout << "< passato" << endl;
        }
        else {
            cout << "< non passato" << endl;
        }

        if (b >= ec) {
            cout << ">= non passato" << endl;
        }
        else {
            cout << ">= passato" << endl;
        }

        if (b > ec) {
            cout << "> non passato" << endl;
        }
        else {
            cout << "> passato" << endl;
        }
    }
}
/**
 * @brief Test per la serializzazione
 * Metodo che esegue i test per serializzare una matrice su un file
 * @param set imposta a false per non eseguire i test
 */
void test_serializzazione(bool set = true) {
    if (set == true) {
        
        cout << "---------------------Test serializzazione---------------------" << endl;

        
         matrix3D<int> src(5, 3, 4, 0);
         
         matrix3D<int>::iterator b, e;
         //riempo la matrice con qualcosa di pi� interssante di solo 0
         b = src.begin();
         e = src.end();

         for (int i = 0; b != e; ++b) {
             *b = i;
             ++i;
         }

        //questo codice serve per aprire un file
        std::ofstream ofs;
        ofs.open("output.txt");
        if (!ofs.is_open()) {
            std::cerr << "errore apertura file" << std::endl;
            return;
        }
        //scriviamo un file
        ofs << src << endl;
        //ricordarsi di chiudere la connessione
        ofs.close();
      
        // legge i dati e crea una nuova matrice dove salvare i dati
        //apertura stream
        std::ifstream ifs;
        ifs.open("output.txt");
        if (!ifs.is_open()) {
            cerr << "errore apertura file" << endl;
            return;
        }
        //recupero le 3 dimensioni della matrice
        int dimension[3];
        for (unsigned int i = 0; i < 3; ++i)
            ifs >> dimension[i];
        //creazione matrice
        matrix3D<int> dst(dimension[0], dimension[1], dimension[2], 10);
    
        //riempiamo i valori della matrice
        for (unsigned int i = 0; i < dst.dim(); ++i)
            ifs >> dst[i];
        ifs.close();//chiura stream
        //stampe su cout
        cout << "Contenuto della matrice src:" << endl;
        cout << src << endl;

        cout << "Contenuto della matrice  dst:" << endl;
        cout << dst << endl;
    }
}
/**
 * @brief Test per il fallimento della new
 * Metodo che esegue i test il fallimento della new, seguire i commenti
 * @param set imposta a false per non eseguire i test
 */
void test_fallimento_new(bool set = false) {
    if (set = true) {
        //ATTENZIONE
        //eseguire i test sottostanti solo se si vuole provare
        //a simulare una risposta negativa dalla new e controllare che non 
        //ci siano possibilita' di memory leak.
        //eseguire solamente questi test nel codice 
        //per poter fare cio' rendere non commentate le righe e aggiungere ; all'istruzione throw:
        //101, 150, 205, 253
        //nel codice della classe matirx3D.h
        // eseguire i due blocchi di test separatamente
        //RICORDARSI DI RIMETTERE I COMMENTI UNA VOLTA FINITI I TEST

        //primo blocco

        /*try {
            matrix3D<double> matrice1(4, 2, 3, 0.1);
            cout << "Matrice con costruttore secondario con default value: " << "non passato" << endl;
        }
        catch (...) {
            cout << "Matrice con costruttore secondario con default value: " << "passato" << endl;
        }


        try {
            matrix3D<double> matrice2(4, 2, 3);
            cout << "Matrice con costruttore secondario senza default value: " << "non passato" << endl;
        }
        catch (...) {
            cout << "Matrice con costruttore secondario senza default value: " << "passato" << endl;
        }*/

        //secondo blocco
        // attenzione riaggiungere commenti 88 133
        //altrimenti il test � da considerarsi nullo


        /*try {
            matrix3D<double> matrice1(4, 2, 3, 0.1);
            matrix3D<double> matrice2(matrice1);
            cout << "Matrice con costruttore per copia: " << "non passato" << endl;
        }
        catch (...) {
            cout << "Matrice con costruttore per copia: " << "passato" << endl;
        }
        try {
            matrix3D<double> matrice1(4, 2, 3, 0.1);
            matrix3D<int> matrice2 = matrice1;
            cout << "Costruttore di conversione: " << "non passato" << endl;
        }
        catch (...) {
            cout << "Costruttore di conversione: " << "passato" << endl;
        }*/


        //fine test fallimento new riaggiungere tutti i commenti 
    }
}
/**
 * @brief Main
 * Punto di ingresso del programma
 * @return int 
 */
int main()
{
    #ifndef NDEBUG
    cout << "Test classe templata matrice3D" << endl;
    bool set = true;
    test_metodi_fonamentali_primitivi(set);
    test_metodi_ausiliari_primitivi(set);
    test_matrice_costante_primitivi(set);
    test_classe_custom(set);
    test_classe_custom_generici(set);
    test_iteratori(set);
    test_iteratori_costanti(set);
    test_serializzazione(set);
    test_fallimento_new(set); 
    cout << "Fine test classe templata matrice3D" << endl;
    #endif
 
    return 0;
}
