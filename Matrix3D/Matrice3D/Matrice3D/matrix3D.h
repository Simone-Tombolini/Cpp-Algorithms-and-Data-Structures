//matrice3D.h Questo file contiene la classe templata.

//guardie
#ifndef MATRICE3D_H
#define MATRICE3D_H

#include<iostream>
#include<cassert>
#include<algorithm>

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
    //IMPORTANTE TOGLERE DA PUBBLICO
    typedef unsigned long int size_type;
    T*** _matrix;
    size_type sz_z;
    size_type sz_y;
    size_type sz_x;

public:
  
  
    matrix3D() :
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0)
    {
    #ifndef NDEBUG
        cout << "matrice vuota creata" << endl;
    #endif
    }
    matrix3D(size_type size_z, size_type size_y, size_type size_x) :
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0)
    {
        assert(size_z > 0);
        assert(size_y > 0);
        assert(size_x > 0);
        try {
            sz_z = size_z;
            sz_y = size_y;
            sz_x = size_x;

            //creazione array dei piani
            _matrix = new T * *[size_z];

            for (size_type k = 0; k < size_z; ++k) {

                //creazione degli array delle righe
                _matrix[k] = new T * [size_y];

                for (size_type j = 0; j < size_y; ++j) {

                    //creazione degli array delle colonne
                    _matrix[k][j] = new T[size_x];

                    //le celle non sono inizializzate

            


                }

            }
            //stampa di debug
            print_matrix("matrice creata");

        }
        //questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
        //in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
        //per riportarla ad uno stato coerente e rilancio l'eccezione
        //questo blocco verrà ripetuto più volte nel progetto, questi commenti sono da considerarsi vaidi 
        catch (...)
        {
            clear();//evito memory leack
            throw;//rilancio l'eccezzione
        }
    }
    matrix3D(size_type size_z, size_type size_y, size_type size_x, const T &default_value) : 
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0)
	{
        assert(size_z > 0);
        assert(size_y > 0);
        assert(size_x > 0);
        try{
            sz_z = size_z;
            sz_y = size_y;
            sz_x = size_x;

            //creazione array dei piani
            _matrix = new T** [size_z];
            
            for (size_type k = 0; k < size_z; ++k) {
                
                //creazione degli array delle righe
                _matrix[k] = new T* [size_y];
                
                for (size_type j = 0; j < size_y; ++j) {

                    //creazione degli array delle colonne
                    _matrix[k][j] = new T[size_x];
                   
                    for (size_type i = 0; i < size_x; ++i) {
                        //assegnamento del valore di default a tutte le celle
                        _matrix[k][j][i] = default_value;
            
                    }
               
                }
            
            }
            //stampa di debug
            print_matrix("matrice creata");
          
        }
        //questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
        //in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
        //per riportarla ad uno stato coerente e rilancio l'eccezione
        //questo blocco verrà ripetuto più volte nel progetto, questi commenti sono da considerarsi vaidi 
        catch (...) 
        {
            clear();//evito memory leack
            throw;//rilancio l'eccezzione
        }
	}

	~matrix3D()
	{
        clear();
        #ifndef NDEBUG
        cout << "matrice distrutta" << endl;
        #endif
	}

    matrix3D(const matrix3D<T>& other): 
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0)
    {
        try {
            sz_z = other.sz_z;
            sz_y = other.sz_y;
            sz_x = other.sz_x;

            //creazione array dei piani
            _matrix = new T **[sz_z];

            for (size_type k = 0; k < sz_z; ++k) {

                //creazione degli array delle righe
                _matrix[k] = new T * [sz_y];

                for (size_type j = 0; j < sz_y; ++j) {

                    //creazione degli array delle colonne
                    _matrix[k][j] = new T[sz_x];

                    for (size_type i = 0; i < sz_x; ++i) {
                        //assegnamento del valore di default a tutte le celle
                        _matrix[k][j][i] = other._matrix[k][j][i];

                    }

                }

            }
            //stampa di debug
            print_matrix("matrice copiata");
            
        }
        //questo blocco try catch serve nel caso venga lanciata un eccezione dal fallimento di una new
        //in questo caso la classe potrebbe essere in uno stato incoerente, e quindi effettuo una clear() 
        //per riportarla ad uno stato coerente e rilancio l'eccezione
        //questo blocco verrà ripetuto più volte nel progetto, questi commenti sono da considerarsi vaidi 
        catch (...)
        {
            clear();//evito memory leak
            throw;//rilancio l'eccezzione
        }
    }

    matrix3D& operator=(const matrix3D& other) 
    {
        if (this != &other) 
        {
            matrix3D tmp(other);
            this->swap(tmp);
        }
        return *this;
    }

    size_type size_z(void) const{
        return sz_z;
    }

    size_type size_y(void) const {
        return sz_y;
    }

    size_type size_x(void) const {
        return sz_x;
    }

    T& operator()(size_type z, size_type y, size_type x) {

        return _matrix[z][y][x];
    }
    const T& operator()(size_type z, size_type y, size_type x) const {
        
        return _matrix[z][y][x];
    }

    void clear() 
    {
        for (size_type k = 0; k < sz_z; ++k) {


            for (size_type j = 0; j < sz_y; ++j) {

                //eliminazione delle righe
                delete[] _matrix[k][j];


            }

            //eliminazione dei piani 
            delete[] _matrix[k];

        }
        //eliminazione della matrice
        delete[] _matrix;

        sz_x = 0;
        sz_y = 0;
        sz_z = 0;
        _matrix = nullptr;
        assert(sz_z == 0);
        assert(sz_y == 0);
        assert(sz_x == 0);
        assert(_matrix == nullptr);
        #ifndef NDEBUG
        cout << "matrice svuotata" << endl;
        #endif
    }

    friend std::ostream& operator<<(std::ostream& os,
        const matrix3D& mat) {
        os << mat.sz_z << ' ';
        os << mat.sz_y << ' ';
        os << mat.sz_x << ' ' << std::endl;
        
        for (size_type k = 0; k < mat.sz_z; ++k) {
            if(k!=0)
            os << std::endl;
            
            for (size_type j = 0; j < mat.sz_y; ++j) {
              
                os << endl;

                for (size_type i = 0; i < mat.sz_x; ++i) {
                    os << mat(k,j,i) << ' ';
                }
                
            }
         

        }
        os << std::endl;
        return os;
    }
    void swap(matrix3D& other) {
        std::swap(_matrix, other._matrix);
        std::swap(sz_x, other.sz_x);
        std::swap(sz_y, other.sz_y);
        std::swap(sz_z, other.sz_z);
    }

    matrix3D slice(const size_type size_z, const size_type size_y, const size_type size_x) const{
        assert(size_z <= sz_z);
        assert(size_y <= sz_y);
        assert(size_x <= sz_x);
        matrix3D<T> return_matrix(size_z, size_y, size_x);

        for (size_type k = 0; k < size_z; ++k) {//scorro i piani

            for (size_type j = 0; j < size_y; ++j) {//scorro le righe

                for (size_type i = 0; i < size_x; ++i) {//scorro le colonne
                    //imposto il nuovo valore in base a cosa è contenuto nella matrice di partenza
                    return_matrix(k, j, i) = _matrix[k][j][i];

                }

            }

        }

        return return_matrix;
    }

    
    bool operator==( matrix3D &other) const {
        E eql;//creazione dell'oggetto funtore
        int x, y, z;//variabili per rendere più chiaro il codice
        x = other.size_x();
        y = other.size_y();
        z = other.size_z();
        //contollo la differenza in dimensioni
        if (x != sz_x || y != sz_y || z != sz_z) {//non uso il funtore essendo la size un primitivo
            return false;
        }
        //nel caso fossero uguali contollo i valori
        for (size_type k = 0; k < z; ++k) {//scorro i piani

            for (size_type j = 0; j < y; ++j) {//scorro le righe

                for (size_type i = 0; i < x; ++i) {//scorro le colonne
                    if (!(eql(other(k, j, i), _matrix[k][j][i]))) //utilizzio il funtore per contollare la differenza fra due 
                    {
                        return false;
                    }

                }

            }

        }
        return true;

    }
    //è giusto, fare test
    bool operator!=( matrix3D& other) const
    {
        return !(*this == other);
    }

    //random access iteretor

   

	// Solo se serve anche const_iterator aggiungere la seguente riga
	class const_iterator; // forward declaration

	class iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef T* pointer;
		typedef T& reference;


		iterator(): _ptr(nullptr) {
			
		}

		//iterator(const iterator& other): _ptr(other._ptr) {
		//	
		//}

		//iterator& operator=(const iterator& other) {
		//	//!!!
		//}

		//~iterator() {
		//	//!!!
		//}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
            return *_ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
            return _ptr;
		}

		// Operatore di accesso random
		reference operator[](int index) {
			//!!!
		}

		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			//!!!
		}

		// Operatore di iterazione pre-incremento
		iterator& operator++() {
			
		}

		// Operatore di iterazione post-decremento
		iterator operator--(int) {
			//!!!
		}

		// Operatore di iterazione pre-decremento
		iterator& operator--() {
			//!!!
		}

		// Spostamentio in avanti della posizione
		iterator operator+(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		iterator operator-(int offset) {
			//!!!
		}

		// Spostamentio in avanti della posizione
		iterator& operator+=(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		iterator& operator-=(int offset) {
			//!!!
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const iterator& other) {
			//!!!
		}

		// Uguaglianza
		bool operator==(const iterator& other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator>(const iterator& other) const {
			// !!!!
		}


		bool operator>=(const iterator& other) const {
			/// !!!!
		}

		// Confronto
		bool operator<(const iterator& other) const {
			/// !!!!
		}


		// Confronto
		bool operator<=(const iterator& other) const {
			//!!!
		}


		// Solo se serve anche const_iterator aggiungere le seguenti definizioni

		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator>(const const_iterator& other) const {
			//!!!
		}


		bool operator>=(const const_iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator<(const const_iterator& other) const {
			//!!!
		}


		// Confronto
		bool operator<=(const const_iterator& other) const {
			//!!!
		}

		// Solo se serve anche const_iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class matrix3D; // !!! Da cambiare il nome!
        T*** _ptr;
        size_type _z, _y, _x;
		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(T* ptr, size_type z, size_type y, size_type x) {
            _ptr = ptr;
            _z = z;
            _y = y;
            _x = x;
		}

		// !!! Eventuali altri metodi privati

	}; // classe iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(_matrix, sz_z, sz_y, sz_x);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		return iterator(&_matrix[sz_z - 1][sz_y - 1][sz_x], sz_z, sz_y, sz_x);
	}



	class const_iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef const T* pointer;
		typedef const T& reference;


		const_iterator() {
			//!!!
		}

		const_iterator(const const_iterator& other) {
			//!!!
		}

		const_iterator& operator=(const const_iterator& other) {
			//!!!
		}

		~const_iterator() {
			//!!!
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			//!!!
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			//!!!
		}

		// Operatore di accesso random
		reference operator[](int index) {
			//!!!
		}

		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			//!!!
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			//!!!
		}

		// Operatore di iterazione post-decremento
		const_iterator operator--(int) {
			//!!!
		}

		// Operatore di iterazione pre-decremento
		const_iterator& operator--() {
			//!!!
		}

		// Spostamentio in avanti della posizione
		const_iterator operator+(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		const_iterator operator-(int offset) {
			//!!!
		}

		// Spostamentio in avanti della posizione
		const_iterator& operator+=(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		const_iterator& operator-=(int offset) {
			//!!!
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const const_iterator& other) {
			//!!!
		}

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator>(const const_iterator& other) const {
			//!!!
		}


		bool operator>=(const const_iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator<(const const_iterator& other) const {
			//!!!
		}


		// Confronto
		bool operator<=(const const_iterator& other) const {
			//!!!
		}


		// Solo se serve anche iterator aggiungere le seguenti definizioni

		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator& other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator>(const iterator& other) const {
			//!!!
		}


		bool operator>=(const iterator& other) const {
			//!!!
		}

		// Confronto
		bool operator<(const iterator& other) const {
			//!!!
		}


		// Confronto
		bool operator<=(const iterator& other) const {
			//!!!
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator& other) {
			//!!!
		}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator& operator=(const iterator& other) {
			//!!!
		}

		// Solo se serve anche iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class CLASSE_CONTAINER_PADRE; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		//const_iterator(/*!!!*/) {
		//	//!!! 
		//}

		// !!! Eventuali altri metodi privati

	}; // classe const_iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(/*!!!*/);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(/*!!!*/);
	}


    private:
    
    void print_matrix(const string message = "", const bool enabled = true) const
    {
     
        #ifndef NDEBUG
        if (enabled == true) 
        {
            cout << message<<endl;
            /* for (size_type k = 0; k < sz_z; ++k) {
          cout << "pagina " << k<< ":" <<endl;

          for (size_type j = 0; j < sz_y; ++j) {


              for (size_type i = 0; i < sz_x; ++i) {
                  cout << _matrix[k][j][i] << " ";
              }
              cout << endl;
          }

      }*/
        cout << "{size z: " << sz_z << std::endl;
        cout << "size y: " << sz_y << std::endl;
        cout << "size x: " << sz_x << "}" << std::endl;
        cout << "{";
        for (size_type k = 0; k < sz_z; ++k) {
            if(k!=0)
            cout << std::endl;
            cout << "[ ";
            for (size_type j = 0; j < sz_y; ++j) {
                if(j!=0)
                cout << endl;

                for (size_type i = 0; i < sz_x; ++i) {
                    cout << _matrix[k][j][i] << " ";
                }
                
            }
            cout << "]";

        }
        cout << "}" <<std::endl;
        cout << &_matrix[sz_z-1][sz_y-1][sz_x];
        }
        #endif
        
    }
};


#endif