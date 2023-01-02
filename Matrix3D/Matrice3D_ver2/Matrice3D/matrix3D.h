//matrice3D.h Questo file contiene la classe templata.

//guardie
#ifndef MATRICE3D_H
#define MATRICE3D_H

#include<iostream>
#include<cassert>
#include<algorithm>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

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
    T* _matrix;
    size_type sz_z;
    size_type sz_y;
    size_type sz_x;
	size_type _dim;

public:
  
  
    matrix3D() :
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
    {
    #ifndef NDEBUG
        cout << "matrice vuota creata" << endl;
    #endif
    }
    matrix3D(size_type size_z, size_type size_y, size_type size_x) :
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
        //questo blocco verrà ripetuto più volte nel progetto, questi commenti sono da considerarsi vaidi 
        catch (...)
        {
            clear();//evito memory leack
            throw;//rilancio l'eccezzione
        }
    }
    matrix3D(size_type size_z, size_type size_y, size_type size_x, const T &default_value) : 
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
	{
        assert(size_z > 0);
        assert(size_y > 0);
        assert(size_x > 0);
        try{
            sz_z = size_z;
            sz_y = size_y;
            sz_x = size_x;
			_dim = ((sz_z ) * (sz_y) * (sz_x));
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
        _matrix(nullptr), sz_z(0), sz_y(0), sz_x(0), _dim(0)
    {
        try {
            sz_z = other.size_z();
            sz_y = other.size_y();
            sz_x = other.size_x();
			_dim = other.dim();
			_matrix = new T[_dim];
		
        
			for (size_type i = 0; i < _dim; ++i) {
				_matrix[i] = other._matrix[i];//attenzione
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
	size_type dim(void) const {
		return _dim;
	}

	void clear()
	{
		//for (size_type k = 0; k < sz_z; ++k) {


		//    for (size_type j = 0; j < sz_y; ++j) {

		//        //eliminazione delle righe
		//        delete[] _matrix[k][j];


		//    }

		//    //eliminazione dei piani 
		//    delete[] _matrix[k];

		//}
		sz_x = 0;
		sz_y = 0;
		sz_z = 0;
		_dim = 0;
		//eliminazione della matrice
		delete[] _matrix;

		_matrix = nullptr;
		assert(sz_z == 0);
		assert(sz_y == 0);
		assert(sz_x == 0);
		assert(_matrix == nullptr);
		#ifndef NDEBUG
		cout << "matrice svuotata" << endl;
		#endif
	}
	
    T& operator()(size_type z, size_type y, size_type x) {

		size_type index = 0;

		//caso limite (0, 0, 0) nel ciclo viene saltato
		//per mantenere la tipologia della size unsigned long int e risparimare memoria
		//preferisco fare un controllo in più all'utilizzo dell'operatore ()
		//if (z == 0 && y == 0 && x == 0) {
		//	return _matrix[0];
		//}
    
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
		return _matrix[0];
    }
    const T& operator()(size_type z, size_type y, size_type x) const {
         size_type index =0;
		 if (z == 0 && y == 0 && x == 0) {
			 return _matrix[0];
		 }
        for (size_type k = 0; k < sz_z; ++k) {
           
            for (size_type j = 0; j < sz_y; ++j) {
               

                for (size_type i = 0; i < sz_x; ++i) {
					++index;
					if (z == k && j == y && i == x) {
						return _matrix[index];
					}
                }
                
            }
           

        }
    }
	T& index(int index) 
	{
		return _matrix[index];
	}
	const T& index(int index) const
	{
		return _matrix[index];
	}
 

    friend std::ostream& operator<<(std::ostream& os,
        const matrix3D& mat) {
        os << mat.sz_z << ' ';
        os << mat.sz_y << ' ';
        os << mat.sz_x << ' ';
        
		for (size_type i = 0; i < mat.dim(); ++i) {
			cout << mat._matrix[i] << ' ';
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
                    //imposto il nuovo valore in base a cosa è contenuto nella matrice di partenza

					 res_matrix._matrix[index] = this->operator()(k, j, i);
					 ++index;
                }

            }

        }

        return res_matrix;
    }

    
    bool operator==( const matrix3D &other) const {
        E eql;//creazione dell'oggetto funtore
        size_type x, y, z;//variabili per rendere più chiaro il codice
        x = other.size_x();
        y = other.size_y();
        z = other.size_z();
		
        //contollo la differenza in dimensioni
        if (_dim !=other.dim()) {//non uso il funtore essendo la size un primitivo
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
    //è giusto, fare test
    bool operator!=(const matrix3D& other) const
    {
        return !(this->operator==(other));
    }
	
	template<typename iter>
	void fill(iter b, iter e) {
		
		for (size_type i = 0; i < _dim && b!=e; ++i) {
			_matrix[i] = *b;
			++b;
		}

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

		iterator(const iterator& other): _ptr(other._ptr) {
			
		}

		iterator& operator=(const iterator& other) {
			_ptr = other._ptr;
			return *this;
		}

		~iterator() {}

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
			return _ptr[index];
		}

		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			
			iterator old(*this);
			++_ptr;
			return  old;
		}

		// Operatore di iterazione pre-incremento
		iterator& operator++() {
			++_ptr;
			return *this;
		}

		// Operatore di iterazione post-decremento
		iterator operator--(int) {
			iterator old(*this);
			--_ptr;
			return old;
		}

		// Operatore di iterazione pre-decremento
		iterator& operator--() {
			--_ptr;
			return *this;
		}

		// Spostamentio in avanti della posizione
		iterator operator+(int offset) {
			return iterator(_ptr + offset);
		}

		// Spostamentio all'indietro della posizione
		iterator operator-(int offset) {
			return iterator(_ptr -  offset);
		}

		// Spostamentio in avanti della posizione
		iterator& operator+=(int offset) {
			_ptr += offset;
			return *this;
		}

		// Spostamentio all'indietro della posizione
		iterator& operator-=(int offset) {
			_ptr -= offset;
			return *this;
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const iterator& other) {
			return _ptr - other.ptr;
		}

		// Uguaglianza
		bool operator==(const iterator& other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const iterator& other) const {
			return _ptr != other._ptr;
		}

		// Confronto
		bool operator>(const iterator& other) const {
			return _ptr > other._ptr;
		}


		bool operator>=(const iterator& other) const {
			return _ptr >= other._ptr;
		}

		// Confronto
		bool operator<(const iterator& other) const {
			return _ptr < other._ptr;
		}


		// Confronto
		bool operator<=(const iterator& other) const {
			return _ptr <= other._ptr;
		}


		// Solo se serve anche const_iterator aggiungere le seguenti definizioni

		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			return _ptr != other._ptr;
		}

		// Confronto
		bool operator>(const const_iterator& other) const {
			return _ptr > other._ptr;
		}


		bool operator>=(const const_iterator& other) const {
			return _ptr >= other._ptr;
		}

		// Confronto
		bool operator<(const const_iterator& other) const {
			return _ptr < other._ptr;
		}


		// Confronto
		bool operator<=(const const_iterator& other) const {
			return _ptr <= other._ptr;
		}

		// Solo se serve anche const_iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class matrix3D; // !!! Da cambiare il nome!
        T* _ptr;
        
		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(T* p) {
            _ptr = p;
            
		}

		// !!! Eventuali altri metodi privati

	}; // classe iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(_matrix);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
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


		const_iterator(): _ptr(nullptr) {
			
		}

		const_iterator(const const_iterator& other): _ptr(other._ptr) {
			//!!!
		}

		const_iterator& operator=(const const_iterator& other) {
			_ptr = other._ptr;
			return *this;
		}

		~const_iterator() {}

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
			return _ptr[index];
		}

		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator old(*this);
			++_ptr;
			return old;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			++_ptr;
			return *this;
		}

		// Operatore di iterazione post-decremento
		const_iterator operator--(int) {
			const_iterator old(*this);
			--_ptr;
			return old;
		}

		// Operatore di iterazione pre-decremento
		const_iterator& operator--() {
			--_ptr;
			return *this;
		}

		// Spostamentio in avanti della posizione
		const_iterator operator+(int offset) {
			return const_iterator(_ptr + offset);
		}

		// Spostamentio all'indietro della posizione
		const_iterator operator-(int offset) {
			return const_iterator(_ptr - offset);
		}

		// Spostamentio in avanti della posizione
		const_iterator& operator+=(int offset) {
			_ptr += offset;
			return *this;
		}

		// Spostamentio all'indietro della posizione
		const_iterator& operator-=(int offset) {
			_ptr -= offset;
			return *this;
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const const_iterator& other) {
			return _ptr - other._ptr;
		}

		// Uguaglianza
		bool operator==(const const_iterator& other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator& other) const {
			return _ptr != other._ptr;
		}

		// Confronto
		bool operator>(const const_iterator& other) const {
			return _ptr > other._ptr;
		}


		bool operator>=(const const_iterator& other) const {
			return _ptr >= other._ptr;
		}

		// Confronto
		bool operator<(const const_iterator& other) const {
			return _ptr < other._ptr;
		}


		// Confronto
		bool operator<=(const const_iterator& other) const {
			return _ptr <= other._ptr;
		}


		// Solo se serve anche iterator aggiungere le seguenti definizioni

		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator& other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const iterator& other) const {
			return _ptr != other._ptr;
		}

		// Confronto
		bool operator>(const iterator& other) const {
			return _ptr > other._ptr;
		}


		bool operator>=(const iterator& other) const {
			return _ptr >= other._ptr;
		}

		// Confronto
		bool operator<(const iterator& other) const {
			return _ptr < other._ptr;
		}


		// Confronto
		bool operator<=(const iterator& other) const {
			return _ptr <= other._ptr;
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator& other) {
			_ptr = other._ptr;
		}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator& operator=(const iterator& other) {
			_ptr = other._ptr;
			return *this;
		}

		// Solo se serve anche iterator aggiungere le precedenti definizioni

	private:
		//Dati membro
		T* _ptr;
		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class matrix3D; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(T* p) {
			_ptr = p;
		}

		// !!! Eventuali altri metodi privati

	}; // classe const_iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_matrix);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(_matrix + _dim);
	}


    //private:
    
    void print_matrix(const string message = "", const bool enabled = true) const
    {
     
        #ifndef NDEBUG
        if (enabled == true) 
        {
			
		size_type index =0;
        cout << message<<endl;

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
					
                    cout << _matrix[index] << " ";
					++index;
                }
                
            }
            cout << "]";

        }
        cout << "}" <<std::endl;
        //cout << &_matrix[sz_z-1][sz_y-1][sz_x];
        }
        #endif
        
    }
};


#endif