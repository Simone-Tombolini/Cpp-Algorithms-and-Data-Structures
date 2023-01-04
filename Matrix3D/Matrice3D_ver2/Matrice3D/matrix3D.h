//matrice3D.h Questo file contiene la classe templata.

//guardie
#ifndef MATRICE3D_H
#define MATRICE3D_H

#include<iostream>
#include<cassert>
//#include<algorithm>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

#ifndef NDEBUG
#include<string>
#endif

using namespace std;

template<typename T>
struct eql_default {
    bool operator()(T a, T b) {
        return a == b;
    }
};

template<typename T, typename E = eql_default<T>>
class matrix3D
{
private:
	//definizione del tipo della size
	typedef unsigned long int size_type;
	
	T* _matrix; //puntatore all'array
	//dimensioni sui piani z, y, x
	size_type sz_z;
	size_type sz_y;
	size_type sz_x;
	//dimensione totale della matrice
	size_type _dim;

public:

	/**
	 * @brief Costruttore di default
	 * Costruisce una matirce vuota, dov3e il puntatore è a nullptr e le
	 * 3 dimensioni sono uguali 0.
	 */
	matrix3D() :
		_matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
		//stampa di debug
		print_message("matrice vuota creata");
	}
	/**
	 * @brief Costruttore secondario senza valore di default
	 * Costruisce una matirce dove le dimensioni sono impostate ai 3 parametri di ingresso,
	 * e non inizializza i valori con nulla, quindi il compilatore assegna valori randomici
	 * la dimesione totale è definita da z*y*x.
	 * @param size_z Dimensione piani
	 * @param size_y Dimensione righe
	 * @param size_x Dimensione colonne
	 * @pre le 3 dimensioni devono essere maggiori di 0 altrimenti la matrice risulta insensata
	 */
	matrix3D(const size_type size_z, const size_type size_y, const size_type size_x) :
		_matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
		assert(size_z > 0);
		assert(size_y > 0);
		assert(size_x > 0);
		try {
			sz_z = size_z;
			sz_y = size_y;
			sz_x = size_x;
			_dim = (sz_z) * (sz_y) * (sz_x);
			//creazione array dei piani
			_matrix = new T[_dim];

			//stampa di debug
			print_matrix("matrice creata");

		}
		//questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
		//in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
		//per riportarla ad uno stato coerente e rilancio l'eccezione
		//questo blocco verra' ripetuto piu' volte nel progetto
		//questi commenti sono da considerarsi vaidi per tutte le volte che verra' usata una struttura di questto tipo
		catch (...)
		{
			clear();//evito memory leak
			throw;//rilancio l'eccezzione
		}
	}
	/**
	 * @brief Costruttore secondario con valore di default
	 * Costruisce una matirce dove le dimensioni sono impostate ai 3 parametri di ingresso,
	 * e inizializza i valori con il parametro default_value, esso deve essere dello stesso tipo della matrice o castabile
	 * la dimesione totale è definita da z*y*x.
	 * @param size_z Dimensione piani
	 * @param size_y Dimensione righe
	 * @param size_x Dimensione colonne
	 * @param default_value Valore di default impostao dalla matrice
	 * @pre le 3 dimensioni devono essere maggiori di 0 altrimenti la matrice risulta insensata
	 */
	matrix3D(const size_type size_z, const size_type size_y, const size_type size_x, const T& default_value) :
		_matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
		assert(size_z > 0);
		assert(size_y > 0);
		assert(size_x > 0);
		try {
			sz_z = size_z;
			sz_y = size_y;
			sz_x = size_x;
			_dim = ((sz_z) * (sz_y) * (sz_x));
			_matrix = new T[_dim];
			for (size_type i = 0; i < _dim; ++i) {
				_matrix[i] = default_value;
			}

			//stampa di debug
			print_matrix("matrice creata");

		}
		//questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
		//in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
		//per riportarla ad uno stato coerente e rilancio l'eccezione
		//questo blocco verr� ripetuto pi� volte nel progetto, questi commenti sono da considerarsi vaidi 
		catch (...)
		{
			clear();//evito memory leack
			throw;//rilancio l'eccezzione
		}
	}
	/**
	 * @brief Distruttore
	 *	Richiama il meotdo clear() per eliminare la matirce anche dallo heap ed eviatare tutti i memory leak
	 *  Richiamato automaticamente dal compilatore, mai non chiamare espilicitamente. 
	 */
	~matrix3D()
	{
		clear();
		print_message("matrice distrutta");
	}

	/**
	 * @brief Costruttore per copia
	 * Costruisce una nuova matrice copiando tutti i parametri da una già esistente,
	 * che deve essere dello stesso tipo della nuova matrice
	 * in cui si vuole effettuare una copia, l'altra matirce (da inserire nel parametro other)
	 * non verrà modificata
	 * @param other Matrice che verra' usata per la copia
	 */
	matrix3D(const matrix3D<T>& other) :
		_matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
		try {
			//copio i parametri
			sz_z = other.size_z();
			sz_y = other.size_y();
			sz_x = other.size_x();
			_dim = other.dim();
			//creo il nuovo array
			_matrix = new T[_dim];


			for (size_type i = 0; i < _dim; ++i) {
				//copio i parametri
				_matrix[i] = other._matrix[i];
			}
			//stampa di debug
			print_matrix("matrice copiata");

		}
		//questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
		//in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
		//per riportarla ad uno stato coerente e rilancio l'eccezione
		//questo blocco verr� ripetuto pi� volte nel progetto, questi commenti sono da considerarsi vaidi 
		catch (...)
		{
			clear();//evito memory leak
			throw;//rilancio l'eccezzione
		}
	}
	/**
	 * @brief Costruttore di conversione
	 * Costruttore che serve per permettere di convertire due matrix3D definite 
	 * con tipi diversi ma castabili fra di loro.
	 * Il tipo di partenza della matrice utile è il tipo C, quello di arrivo è quello definito
	 * dalla nuova matrice.
	 * Viene effettuato lo staic_cast e non un altro tipo di cast per evitare di reintepretare i dati 
	 * in maniera non corretta.
	 * Se lo static_cast non è fattibile il compilatore dara' errore.
	 * @tparam C Tipo della matrice other di partenza
	 * @param other Matrice di tipo diverso su cui viene effettuato il cast
	 */
	template <typename C>
	matrix3D(const matrix3D<C>& other)
		: _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
		//imposto i valori per la nuova matrice
		sz_z = other.size_z();
		sz_y = other.size_y();
		sz_x = other.size_x();
		_dim = other.dim();
		//creo l'array
		_matrix = new T[_dim];

		
		for (size_type i = 0; i < _dim; ++i) {//scorro la matrice
			//qui viene effettuato il cast
			_matrix[i] = static_cast<T>(other[i]);
		}
		//stampa di debug
		print_matrix("matrice castata");
	}

	/**
	 * @brief Operatore di assegamento
	 * Serve per asseganre ad una matrice gia' esistente un altra matrice
	 * @param other matrce da copiare
	 * @return matrix3D& - riferiemnto alla matrice 
	 */
	matrix3D& operator=(const matrix3D& other)
	{
		if (this != &other)
		{
			matrix3D tmp(other);
			this->swap(tmp);
		}
		return *this;
	}

	/**
	 * @brief Operatore ad una dimensione che ritorna il dato contenuto in una cella della matrice 
	 * Ritorna il parametro della matrice ad una posizione monodimensionale, l'ordine è lo stesso degli
	 * iteratori, rendendo questo metodo un alternativa alla creazione di un iteratore ed all'utilizzao del metodo[]
	 * dell'iteratore, non non è definita una versione costante  per non permettere la sola lettura ad una matirce
	 * non costante (metodo non richiesto dal progetto, leggere la relazione per le motivazioni di questa scelta implementativa)
	 * @param i indice in cui si richiedono i dati
	 * @return T& - ritorna il valore della matrice non costante
	 */
	T& operator[](const size_type i)
	{
		return _matrix[i];
	}
	 /**
	 * @brief Operatore ad una dimensione che ritorna il dato contenuto in una cella della matrice 
	 * Ritorna il parametro della matrice ad una posizione monodimensionale, l'ordine è lo stesso degli
	 * iteratori, rendendo questo metodo un alternativa alla creazione di un iteratore ed all'utilizzao del metodo[]
	 * dell'iteratore, non non è definita una versione costante  per non permettere la sola lettura ad una matirce
	 * non costante (metodo non richiesto dal progetto, leggere la relazione per le motivazioni di questa scelta implementativa)
	 * @param i indice in cui si richiedono i dati
	 * @return const T& - ritorna il valore della matrice costante
	 */
	const T& operator[](const size_type i) const
	{
		return _matrix[i];
	}

	/**
	 * @brief Getter numero di piani (asse z)
	 * Ritorna quanti piani sono presenti nella matrice
	 * @return size_type 
	 */
    size_type size_z(void) const{
        return sz_z;
    }

	/**
	 * @brief Getter numero di righe (asse y)
	 * Ritorna quante righe sono presenti nella matrice
	 * @return size_type 
	 */
    size_type size_y(void) const {
        return sz_y;
    }

	/**
	 * @brief Getter numero di righe (asse x)
	 * Ritorna quante colonne sono presenti nella matrice
	 * @return size_type 
	 */
    size_type size_x(void) const {
        return sz_x;
    }

	/**
	 * @brief Getter della dimensione totale della matrice
	 * Ritorna la somma di tutte le celle disponibli in tutta la matrice
	 * @return size_type 
	 */
	size_type dim(void) const {
		return _dim;
	}
	/**
	 * @brief Dealloca la memoria utilizzata 
	 * Metodo molto importante per l'implementazione del pattern RAII,
	 * dealloca la memoria allocata dai costruttori nello heap, e rende matrice una matrice vuota
	 */
	void clear()
	{
		//imposta le dimensioni a 0
		sz_x = 0;
		sz_y = 0;
		sz_z = 0;
		_dim = 0;
		//eliminazione della matrice
		delete[] _matrix;
		//imposta il puntatore a nullptr
		_matrix = nullptr;
		//post condizioni di controllo, piuttosto ridondanti ma le inserisco ugualmente
		assert(sz_z == 0);
		assert(sz_y == 0);
		assert(sz_x == 0);
		assert(_matrix == nullptr);
		//stampa di debug
		print_message("matrice svuotata");
	}


	//ATTENZIONE

	//RICORDARSI DI INSERIRE NOME DI ECCEZIONE CUSTOM IN DOC



	/**
	 * @brief Operatore (), prinipale metodo di lettura e scrittura
	 * Questo è il principlae metodo di lettura e scrittura della classe,
	 * i 3 parametri indicano la posizione in cui si vuole accedere alla matrice, 
	 * l'operatore retituisce il riferimento al dato richiesto nella posizione.
	 * Se si cerca di accedere a dei dati con anche solo un indice fuori dalla matrice 
	 * verra' lanciata un eccezione di tipo "RICORDARSI DI INSERIRE NOME DI ECCEZIONE CUSTOM", si ricorda che la matrice parte dalla posizione 0 0 0
	 * e finisce a z-1, y-1,x-1, usando quindi la stessa convenzione dei normali array definiti in C++, 
	 * ma utilizzando 3 dimensioni al posto che una.  
	 * @param z Parametro di accesso per i piani
	 * @param y Parametro di accesso per le righe
	 * @param x Parametro di accesso per le colonne
	 * @return T& - refernce non costante al dato puntato
	 */
    T& operator()(const size_type z, const size_type y, const size_type x) {

		size_type index = 0;

        for (size_type k = 0; k < sz_z; ++k) {
           
            for (size_type j = 0; j < sz_y; ++j) {
               

                for (size_type i = 0; i < sz_x; ++i) {
					
					if (z == k && j == y && i == x) {
						return _matrix[index];
					}
					++index;
                }
                
            }

        }

		
		
		
    }

	//RICORDARSI ANCHE QUI

	/**
	 * @brief Operatore (), prinipale metodo di sola lettura
	 * Questo è il principlae metodo di sola lettura della classe,
	 * i 3 parametri indicano la posizione in cui si vuole accedere alla matrice, 
	 * l'operatore retituisce il riferimento costante al dato richiesto nella posizione.
	 * Se si cerca di accedere a dei dati con anche solo un indice fuori dalla matrice 
	 * verra' lanciata un eccezione di tipo "RICORDARSI DI INSERIRE NOME DI ECCEZIONE CUSTOM", si ricorda che la matrice parte dalla posizione 0 0 0
	 * e finisce a z-1, y-1,x-1, usando quindi la stessa convenzione dei normali array definiti in C++,
	 * ma utilizzando 3 dimensioni al posto che una.  
	 * @param z Parametro di accesso per i piani
	 * @param y Parametro di accesso per le righe
	 * @param x Parametro di accesso per le colonne
	 * @return T& - refernce costante al dato puntato
	 */
    const T& operator()(const size_type z, const size_type y, const size_type x) const {

		size_type index = 0;

		for (size_type k = 0; k < sz_z; ++k) {

			for (size_type j = 0; j < sz_y; ++j) {


				for (size_type i = 0; i < sz_x; ++i) {

					if (z == k && j == y && i == x) {
						return _matrix[index];
					}
					++index;
				}

			}

		}
		
    }

 
	/**
	 * @brief Operatore di stream
	 * riddefinizione dell'operatore di stream
	 * I dati vengono serarati dal carattere ' ' e nient'altro
	 * vengono inviati al canale di stream nella maniera più neutra possibile, in quest'ordine:
	 * (Size asse z) (Size asse y) (Size asse x) (sequenza di dati) 
	 * La funzione è templata sulla matrice ed è messa
     * friend perchè accediamo ai dati privati della matrice.
	 * @param os stream di output
	 * @param mat la matirce da spedire sullo stream
	 * @return std::ostream& - lo stream di output
	 */
    friend std::ostream& operator<<(std::ostream& os,
        const matrix3D& mat) {
		//spedisco le size	
        os << mat.sz_z << ' ';
        os << mat.sz_y << ' ';
        os << mat.sz_x << ' ';
        //spedisco i dati
		for (size_type i = 0; i < mat.dim(); ++i) {
			cout << mat._matrix[i] << ' ';
		}
        //non stampo la riga di fine perchè generalmente ci pensa chi utilizza la classe
		//os << std::endl;
        return os;
    }

	/**
	 * @brief Funzione swap
	 * Utilizzo la funzione swap definita nella std
	 * per reimplementarla per la matrice
	 * @param other matirce da scambiare
	 */
    void swap(matrix3D& other) {
        std::swap(_matrix, other._matrix);
        std::swap(sz_x, other.sz_x);
        std::swap(sz_y, other.sz_y);
        std::swap(sz_z, other.sz_z);
    }
	/**
	 * @brief Metodo slice che permette di tagliare la matrice
	 * Questo metodo ritorna una matrce più piccola della matrice su cui è applicata
	 * Questo metodo prende in igresso 3 coppie di indici per poter permettere di indicare
	 * da che punto a che punto della matrice effettuare il taglio.
	 * Ovviamente se gli indici non rispettano i parametri dell'operatore () opuure 
	 * il primo indice è superiore al secondo viene lanciata un eccezioen del tipo "INSEIRE TIPO QUI"
	 * @param z1 primo indice dei piani 
	 * @param z2 secondo indice dei piani
	 * @param y1 primo indice delle righe
	 * @param y2 secondo indice delle righe
	 * @param x1 primo indice delle colonne 
	 * @param x2 secondo indice delle colonne
	 * @return matrix3D - la matrice tagliata
	 */
    matrix3D slice(const size_type z1, const size_type z2, const size_type y1, const size_type y2, const size_type x1, const size_type x2) const{
		assert(z1 >= 0);
		assert(y1 >= 0);
		assert(x1 >= 0);
		assert(z2 <= sz_z);
        assert(y2 <= sz_y);
        assert(x2 <= sz_x);
		size_type size_z = z2 -z1;
		size_type size_y = y2 - y1;
		size_type size_x = x2 - x1;

        matrix3D<T> res_matrix(size_z, size_y, size_x);
		size_type index = 0;
        for (size_type k = z1; k < z2; ++k) {//scorro i piani

            for (size_type j = y1; j < y2; ++j) {//scorro le righe

                for (size_type i = x1; i < x2; ++i) {//scorro le colonne
                    //imposto il nuovo valore in base a cosa e' contenuto nella matrice di partenza

					 res_matrix._matrix[index] = this->operator()(k, j, i);
					 ++index;
                }

            }

        }

        return res_matrix;
    }

    /**
     * @brief Operatore ==
     * Questo operatore bianrio confronta le dimensioni e i valori della matrice
	 * di destra this con quella di sinistra other.
	 * La logica di confronto è definita da un funtore generico di tipo E.
	 * Nel caso il funtore dia un ritorno positivo per tutti i valori e le dimensioni siano uguali 
	 * E' definito un funtore di default all'intenro del file della classe, che utilizza a sua volta
	 * l'operatore == del tipo T che deve essere definito per poter accedere a questa possibilita',
	 * essendo che la maggior parte delle volte logica va bene.
	 * Rimane sempre e comunque disponibile l'opzione di definire un funtore personalizzato con una logia 
	 * a se' stante. 
     * @param other seconda matrice
     * @return true - le due matrici hanno le stesse dimensioni e i valori (secondo la logica del funtore E)
     * @return false - le due matrici non hanno le stesse dimensioni e i valori (secondo la logica del funtore E)
     */
    bool operator==( const matrix3D<T,E> &other) const {
        E eql;//creazione dell'oggetto funtore
        size_type x, y, z;//variabili per rendere piu' chiaro il codice
        x = other.size_x();
        y = other.size_y();
        z = other.size_z();
		
        //contollo la differenza in dimensioni
        if (sz_x != x && sz_y != y && sz_z != z) {//non uso il funtore essendo la size un primitivo
            return false;
        }
        //nel caso fossero uguali contollo i valori
		for (size_type i = 0; i < x; ++i) {//scorro le colonne
			if (!(eql(other._matrix[i], _matrix[i]))) //utilizzio il funtore per contollare la differenza fra due 
			{
				return false;
			}

		}
        return true;

    }
     /**
     * @brief Operatore !=
     * Questo operatore bianrio confronta le dimensioni e i valori della matrice
	 * di destra this con quella di sinistra other.
	 * La logica di confronto è definita da un funtore generico di tipo E.
	 * Nel caso il funtore non dia un ritorno positivo per tutti i valori e le dimensioni siano uguali 
	 * E' definito un funtore di default all'intenro del file della classe, che utilizza a sua volta
	 * l'operatore == del tipo T che deve essere definito per poter accedere a questa possibilita',
	 * essendo che la maggior parte delle volte logica va bene.
	 * Rimane sempre e comunque disponibile l'opzione di definire un funtore personalizzato con una logia 
	 * a se' stante.
     * @param other seconda matrice
     * @return true - le due matrici non hanno le stesse dimensioni e i valori (secondo la logica del funtore E)
     * @return false - le due matrici hanno le stesse dimensioni e i valori (secondo la logica del funtore E)
     */
    bool operator!=(const matrix3D& other) const
    {
        return !(this->operator==(other));
    }
	
	/**
	 * @brief Funzione fill
	 * Funzione che prende in ingresso due iteratori generici
	 * su di tipo T e riempe la matrice secondo quegli iteratori
	 * L'ordine di riempimento della matrice è lo stesso definito dagli iteratori della classe matrice
	 * partendo dal primo parametro di begin e finendo all'iteratore di end
	 * @tparam iter - tipo dell'iteratore
	 * @param b iteratore di inizio (begin)
	 * @param e iteratore di fine (end)
	 */
	template<typename iter>
	void fill(iter b, iter e) {
		//AGGIUNGERE TRY
		for (size_type i = 0; i < _dim && b!=e; ++i) {
			_matrix[i] = *b;
			++b;
		}

	}

    //random access iteretor

   

	
	class const_iterator; // forward declaration dell'iiteratore costante

	class iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef T* pointer;
		typedef T& reference;

		/**
		 * @brief costruttore del nuovo iteratore
		 * Costruisce un nuovo iteratore che punta a nulla
		 */
		iterator(): _ptr(nullptr) {
			
		}
		/**
		 * @brief costruttore per copia
		 * Costruisce la copia di un nuovo iteratore
		 * @param other vecchio iteratore
		 */
		iterator(const iterator& other): _ptr(other._ptr) {
			
		}
		/**
		 * @brief Operatore assegnamento
		 * Operatore assegnamento
		 * @param other 
		 * @return iterator& 
		 */
		iterator& operator=(const iterator& other) {
			_ptr = other._ptr;
			return *this;
		}

		/**
		 * @brief Distruttore
		 * Distrugge l'iteratore
		 */
		~iterator() {}

		/**
		 * @brief Operatore *
		 * Ritorna il dato riferito dall'iteratore (deferenziamento)
		 * @return reference 
		 */
		reference operator*() const {
            return *_ptr;
		}

		/**
		 * @brief Operatore ->
		 * Ritorna il puntatore al dato riferito dall'iteratore
		 * @return pointer 
		 */
		pointer operator->() const {
            return _ptr;
		}

		// Operatore di accesso random
		/**
		 * @brief Operatore []
		 * Ritorna il dato alla posizione definita dall'indice
		 * @param index indice della posizione ritornare
		 * @return reference 
		 */
		reference operator[](int index) {
			return _ptr[index];
		}

		/**
		 * @brief Operatore matrice++
		 * Operatore di iterazione post-incremento
		 * @return iterator 
		 */
		iterator operator++(int) {
			
			iterator old(*this);
			++_ptr;
			return  old;
		}

		/**
		 * @brief Operatore ++matrice
		 * Operatore di iterazione pre-incremento
		 * @return iterator 
		 */
		iterator& operator++() {
			++_ptr;
			return *this;
		}

		/**
		 * @brief Operatore matrice--
		 * Operatore di iterazione post-decremento
		 * @return iterator 
		 */
		iterator operator--(int) {
			iterator old(*this);
			--_ptr;
			return old;
		}

		/**
		 * @brief Operatore --matrice
		 * Operatore di iterazione pre-decremento
		 * @return iterator 
		 */
		iterator& operator--() {
			--_ptr;
			return *this;
		}

		/**
		 * @brief Operatore +
		 * Spostamento in avanti della posizione secondo l'offset
		 * @param offset indica di quanto spostarsi
		 * @return iterator 
		 */
		iterator operator+(int offset) {
			return iterator(_ptr + offset);
		}

		/**
		 * @brief Operatore - spostamento
		 * Spostamento all'indietro della posizione secondo l'offset
		 * @param offset indica di quanto spostarsi
		 * @return iterator 
		 */
		iterator operator-(int offset) {
			return iterator(_ptr -  offset);
		}

		/**
		 * @brief Operatore +=
		 * Spostamento in avanti e assegnamento
		 * @param offset indica di quanto spostarsi
		 * @return iterator& 
		 */
		iterator& operator+=(int offset) {
			_ptr += offset;
			return *this;
		}

		/**
		 * @brief Operatore -= 
		 * Spostamento all'indietro e assegnamento
		 * @param offset indica di quanto spostarsi
		 * @return iterator& 
		 */
		iterator& operator-=(int offset) {
			_ptr -= offset;
			return *this;
		}

		// Numero di elementi tra due iteratori
		/**
		 * @brief Operatore - differenza
		 * Restituisce la differenza di distanza fra due iteratori
		 * @param other 
		 * @return difference_type 
		 */
		difference_type operator-(const iterator& other) {
			return _ptr - other.ptr;
		}

		/**
		 * @brief Operatore ==
		 * Se i due iteratroi puntano alla stessa cella di memoria sono ugualiquidni ritorna true, altrimenti false
		 * @param other iteratore di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator==(const iterator& other) const {
			return _ptr == other._ptr;
		}
		
		/**
		 * @brief Operatore !=
		 * Se i due iteratroi non puntano alla stessa cella di memoria non sono uguali quidni ritorna true, altrimenti false
		 * @param other iteratore di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator!=(const iterator& other) const {
			return _ptr != other._ptr;
		}

		/**
		 * @brief Operatore >
		 * Confronta i due iteratori, se quello di sinistra è strettamente maggiore allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>(const iterator& other) const {
			return _ptr > other._ptr;
		}

		/**
		 * @brief Operatore >=
		 * Confronta i due iteratori, se quello di sinistra è maggiore o uguale allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>=(const iterator& other) const {
			return _ptr >= other._ptr;
		}

		/**
		 * @brief Operatore <
		 * Confronta i due iteratori, se quello di sinistra è strettamente minore allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<(const iterator& other) const {
			return _ptr < other._ptr;
		}


		/**
		 * @brief Operatore <=
		 * Confronta i due iteratori, se quello di sinistra è minore o uguale allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<=(const iterator& other) const {
			return _ptr <= other._ptr;
		}

//cambio
		

		friend class const_iterator;

		/**
		 * @brief Operatore == iteratore const
		 * Se i due iteratroi puntano alla stessa cella di memoria sono ugualiquidni ritorna true, altrimenti false.
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator==(const const_iterator& other) const {
			return _ptr == other._ptr;
		}

		/**
		 * @brief Operatore != iteratore const
		 * Se i due iteratroi non puntano alla stessa cella di memoria non sono uguali quidni ritorna true, altrimenti false
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator!=(const const_iterator& other) const {
			return _ptr != other._ptr;
		}

		
		/**
		 * @brief Operatore > iteratore const
		 * Confronta i due iteratori, se quello di sinistra è strettamente maggiore allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>(const const_iterator& other) const {
			return _ptr > other._ptr;
		}

		/**
		 * @brief Operatore >= iteratore const
		 * Confronta i due iteratori, se quello di sinistra è maggiore o uguale allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>=(const const_iterator& other) const {
			return _ptr >= other._ptr;
		}

		
		/**
		 * @brief Operatore < iteratore const
		 * Confronta i due iteratori, se quello di sinistra è strettamente minore allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<(const const_iterator& other) const {
			return _ptr < other._ptr;
		}


		/**
		 * @brief Operatore <= iteratore const
		 * Confronta i due iteratori, se quello di sinistra è minore o uguale allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<=(const const_iterator& other) const {
			return _ptr <= other._ptr;
		}

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.

		friend class matrix3D;
        T* _ptr;
        
		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(T* p) {
            _ptr = p;
            
		}


	};

	/**
	 * @brief crea un iteratore all'inizio della matrice
	 * Crea un iteratore che punta all'inizio della matrice che corrisponde
	 * alla poszione 0 0 0 (tranne per una matrice vuota che è nullptr)
	 * @return iterator l'iteratore creato
	 */
	iterator begin() {
		return iterator(_matrix);
	}

	/**
	 * @brief crea un iteratore alla fine della matrice
	 * Crea un iteratore che punta alla fine della matrice che corrisponde
	 * alla poszione z-1 y-1 x-1 (tranne per una matrice vuota che è nullptr)
	 * @return iterator l'iteratore creato
	 */
	iterator end() {
		return iterator(_matrix + _dim);
	}



	class const_iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef const T* pointer;
		typedef const T& reference;


		/**
		 * @brief costruttore del nuovo iteratore
		 * Costruisce un nuovo iteratore che punta a nulla
		 */
		const_iterator(): _ptr(nullptr) {
			
		}
		/**
		 * @brief costruttore per copia
		 * Costruisce la copia di un nuovo iteratore
		 * @param other vecchio iteratore
		 */
		const_iterator(const const_iterator& other): _ptr(other._ptr) {
			
		}
		/**
		 * @brief Operatore assegnamento
		 * Operatore assegnamento
		 * @param other 
		 * @return iterator& 
		 */
		const_iterator& operator=(const const_iterator& other) {
			_ptr = other._ptr;
			return *this;
		}
		/**
		 * @brief Distruttore
		 * Distrugge l'iteratore
		 */
		~const_iterator() {}

		/**
		 * @brief Operatore *
		 * Ritorna il dato riferito dall'iteratore (deferenziamento)
		 * @return reference 
		 */
		reference operator*() const {
			return *_ptr;
		}

		/**
		 * @brief Operatore ->
		 * Ritorna il puntatore al dato riferito dall'iteratore
		 * @return pointer 
		 */
		pointer operator->() const {
			return _ptr;
		}

		// Operatore di accesso random
		/**
		 * @brief Operatore []
		 * Ritorna il dato alla posizione definita dall'indice
		 * @param index indice della posizione ritornare
		 * @return reference 
		 */
		reference operator[](int index) {
			return _ptr[index];
		}

		/**
		 * @brief Operatore matrice++
		 * Operatore di iterazione post-incremento
		 * @return iterator 
		 */
		const_iterator operator++(int) {
			const_iterator old(*this);
			++_ptr;
			return old;
		}

		/**
		 * @brief Operatore ++matrice
		 * Operatore di iterazione pre-incremento
		 * @return iterator 
		 */
		const_iterator& operator++() {
			++_ptr;
			return *this;
		}

		/**
		 * @brief Operatore matrice--
		 * Operatore di iterazione post-decremento
		 * @return iterator 
		 */
		const_iterator operator--(int) {
			const_iterator old(*this);
			--_ptr;
			return old;
		}

		/**
		 * @brief Operatore --matrice
		 * Operatore di iterazione pre-decremento
		 * @return iterator 
		 */
		const_iterator& operator--() {
			--_ptr;
			return *this;
		}

		/**
		 * @brief Operatore +
		 * Spostamento in avanti della posizione secondo l'offset
		 * @param offset indica di quanto spostarsi
		 * @return iterator 
		 */
		const_iterator operator+(int offset) {
			return const_iterator(_ptr + offset);
		}

		/**
		 * @brief Operatore - spostamento
		 * Spostamento all'indietro della posizione secondo l'offset
		 * @param offset indica di quanto spostarsi
		 * @return iterator 
		 */
		const_iterator operator-(int offset) {
			return const_iterator(_ptr - offset);
		}

		/**
		 * @brief Operatore +=
		 * Spostamento in avanti e assegnamento
		 * @param offset indica di quanto spostarsi
		 * @return iterator& 
		 */
		const_iterator& operator+=(int offset) {
			_ptr += offset;
			return *this;
		}

		/**
		 * @brief Operatore -= 
		 * Spostamento all'indietro e assegnamento
		 * @param offset indica di quanto spostarsi
		 * @return iterator& 
		 */
		const_iterator& operator-=(int offset) {
			_ptr -= offset;
			return *this;
		}

				/**
		 * @brief Operatore - differenza
		 * Restituisce la differenza di distanza fra due iteratori
		 * @param other 
		 * @return difference_type 
		 */
		difference_type operator-(const const_iterator& other) {
			return _ptr - other._ptr;
		}

		/**
		 * @brief Operatore ==
		 * Se i due iteratori puntano alla stessa cella di memoria sono ugualiquidni ritorna true, altrimenti false
		 * @param other iteratore di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator==(const const_iterator& other) const {
			return _ptr == other._ptr;
		}

		/**
		 * @brief Operatore !=
		 * Se i due iteratroi non puntano alla stessa cella di memoria non sono uguali quidni ritorna true, altrimenti false
		 * @param other iteratore di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator!=(const const_iterator& other) const {
			return _ptr != other._ptr;
		}

		/**
		 * @brief Operatore >
		 * Confronta i due iteratori, se quello di sinistra è strettamente maggiore allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>(const const_iterator& other) const {
			return _ptr > other._ptr;
		}

		/**
		 * @brief Operatore >=
		 * Confronta i due iteratori, se quello di sinistra è maggiore o uguale allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>=(const const_iterator& other) const {
			return _ptr >= other._ptr;
		}

		/**
		 * @brief Operatore <
		 * Confronta i due iteratori, se quello di sinistra è strettamente minore allora ritorna true, altrimenti false 
		 * @param other iteratore di sinistra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<(const const_iterator& other) const {
			return _ptr < other._ptr;
		}


		/**
		 * @brief Operatore <= iteratore const
		 * Confronta i due iteratori, se quello di sinistra è minore o uguale allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<=(const const_iterator& other) const {
			return _ptr <= other._ptr;
		}


		friend class iterator;

		/**
		 * @brief Operatore ==, parametro non const
		 * Se i due iteratroi puntano alla stessa cella di memoria sono ugualiquidni ritorna true, altrimenti false.
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori non costanti
		 * @param other iteratore costante di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator==(const iterator& other) const {
			return _ptr == other._ptr;
		}

		/**
		 * @brief Operatore != iteratore non const
		 * Se i due iteratroi non puntano alla stessa cella di memoria non sono uguali quidni ritorna true, altrimenti false
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori non costanti
		 * @param other iteratore costante di destra
		 * @return true - i due iteratroi puntano alla stessa cella di memoria
		 * @return false - i due iteratroi non puntano alla stessa cella di memoria
		 */
		bool operator!=(const iterator& other) const {
			return _ptr != other._ptr;
		}

		/**
		 * @brief Operatore > iteratore non const
		 * Confronta i due iteratori, se quello di sinistra è strettamente maggiore allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore non costante di destra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>(const iterator& other) const {
			return _ptr > other._ptr;
		}

        /**
		 * @brief Operatore >= iteratore non const
		 * Confronta i due iteratori, se quello di sinistra è maggiore o uguale allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore non costante di destra
		 * @return true - l'iteratore destra è non maggiore di quello di sinistra
		 * @return false - l'iteratore destra è maggiore di quello di sinistra
		 */
		bool operator>=(const iterator& other) const {
			return _ptr >= other._ptr;
		}

		/**
		 * @brief Operatore < iteratore const
		 * Confronta i due iteratori, se quello di sinistra è strettamente minore allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<(const iterator& other) const {
			return _ptr < other._ptr;
		}


		/**
		 * @brief Operatore <= iteratore const
		 * Confronta i due iteratori, se quello di sinistra è minore o uguale allora ritorna true, altrimenti false 
		 * Redifinizione aggiuntiva per interfacciarsi agli ieratori costanti
		 * @param other iteratore costante di destra
		 * @return true - l'iteratore destra è maggiore di quello di sinistra
		 * @return false - l'iteratore destra è non maggiore di quello di sinistra
		 */
		bool operator<=(const iterator& other) const {
			return _ptr <= other._ptr;
		}

		
		/**
		 * @brief Costruttore di conversione
		 * Permette di convertire un interetor ad un const_iteretor
		 * @param other 
		 */
		const_iterator(const iterator& other) {
			_ptr = other._ptr;
		}

		// Assegnamento di un iterator ad un const_iterator
		/**
		 * @brief Operatore di assegnamento con parametro non costante
		 * Operatore di assegnamento con parametro non costante
		 * @param other iteratore non costante
		 * @return const_iterator& 
		 */
		const_iterator& operator=(const iterator& other) {
			_ptr = other._ptr;
			return *this;
		}

	private:
		//Dati membro
		T* _ptr;
		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class matrix3D;

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(T* p) {
			_ptr = p;
		}

	}; 

	/**
	 * @brief crea un iteratore costante all'inizio della matrice
	 * Crea un iteratore che punta all'inizio della matrice che corrisponde
	 * alla poszione 0 0 0 (tranne per una matrice vuota che è nullptr)
	 * @return iterator l'iteratore creato
	 */
	const_iterator begin() const {
		return const_iterator(_matrix);
	}

	/**
	 * @brief crea un iteratore costante  alla fine della matrice
	 * Crea un iteratore che punta alla fine della matrice che corrisponde
	 * alla poszione z-1 y-1 x-1 (tranne per una matrice vuota che è nullptr)
	 * @return iterator l'iteratore creato
	 */
	const_iterator end() const {
		return const_iterator(_matrix + _dim);
	}


    //private:

	//funzioni di debug della classe

	/**
	 * @brief stampa un messaggio su cout
	 * Questa è una funzione solo dedicata al debug, se esiste il tag speciale
	 * NDEBUG la funzione non avrà alcun effetto e sarà vuota,
	 * altrimenti stampa un messaggio su cout e va a capo
	 * se enabled viene settato a false la funzione comunque non avrà alcun effetto,
	 * di default è settato a true.
	 * @param message il messaggio da stampare
	 * @param enabled se impostato a false nullifica la funzione
	 */
	void print_message(const string message, const bool enabled = true) {
		#ifndef NDEBUG
		if (enabled == true) 
		{
			cout << message << endl;
		}
		#endif
	}
	/**
	 * @brief stampa la matrice su cout
	 * stampa un messaggio su cout
	 * Questa è una funzione solo dedicata al debug, se esiste il tag speciale
	 * NDEBUG la funzione non avrà alcun effetto e sarà vuota,
	 * altimenti stampa prima un messaggio, se richiesto, poi le dimensioni della matrice fra {}
	 * e infine stampa la matrice stessa prima fra {} poi per dividere un piano dall'altro 
	 * lo fa con le [], le rige andando a capo e le colonne con ' '.
	 * @param message messaggio da stampare, se non richiesto non lo stampa
	 * @param enabled se impostato a false nullifica la funzione
	 */
    void print_matrix(const string message = "", const bool enabled = true) const
    {
     
        #ifndef NDEBUG
        if (enabled == true) 
        {
			
		size_type index =0;
		//stamoo il messaggio
        cout << message << endl;
		//stampo le size
        cout << "{size z: " << sz_z << std::endl;
        cout << "size y: " << sz_y << std::endl;
        cout << "size x: " << sz_x << "}" << std::endl;
        cout << "{";//apro la matrice

        for (size_type k = 0; k < sz_z; ++k) {
            if(k!=0)
            cout << std::endl;//ad ogni piano vado a capo
            cout << "[ ";//stampo le parentesi
            for (size_type j = 0; j < sz_y; ++j) {
                if(j!=0)
                cout << endl;//a capo ad ogni riga

                for (size_type i = 0; i < sz_x; ++i) {
					
                    cout << _matrix[index] << " ";//stampo il contenuto e lo spazio
					++index;
                }
                
            }
            cout << "]";//chiudo il piano

        }
        cout << "}" <<std::endl;//chiudo la matrice
        
        }
        #endif
	
    }

};

//funzioni globali

/**
 * @brief Funzione che tranforma una matrice
 * data una Matrix3D parametro matrix (su tipi T) e un generico funtore F, ritorna una nuova
 * Matrix3D(su tipi Q) i cui elementi sono ottenuti applicando il funtore agli elementi di matirx
 * @tparam T il tipo della matrice da cui vanno presi gli elementi non traformati
 * @tparam Q il tipo della matrice su cui applicare il funtore
 * @tparam F il tipo del funtore
 * @tparam iter 
 * @param matrix 
 * @return matrix3D<Q> 
 */
template<typename T, typename Q, typename F>
matrix3D<Q> transform(const matrix3D<T> &matrix) 
{
	
	F f;
	matrix3D<Q> res_matrix(matrix.size_z(), matrix.size_y(), matrix.size_x());
	typename matrix3D<T>::const_iterator b, e;
	typename matrix3D<Q>::iterator res_b, res_e;
	b = matrix.begin();
	e = matrix.end();
	res_b = res_matrix.begin();
	res_e = res_matrix.end();
	for (; b != e; ++b) {
		*res_b = f(static_cast<Q>(*b));
		++res_b;
	}
	cout << "fine transform" << endl;
	return res_matrix;
}

#endif