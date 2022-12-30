//matrice3D.h Questo file contiene la classe templata.

//guardie
#ifndef MATRICE3D_H
#define MATRICE3D_H

#include<iostream>
#include<cassert>
#include<algorithm>

using namespace std;



template<typename T>
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
            clear();//evito memory leack
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

    T& operator()(size_type z, size_type y, size_type x) const {
        
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
        const matrix3D<T>& mat) {
        os << "{size z: " << mat.sz_z << std::endl;
        os << "size y: " << mat.sz_y << std::endl;
        os << "size x: " << mat.sz_x << "}" << std::endl;
        os << "{";
        for (size_type k = 0; k < mat.sz_z; ++k) {
            if(k!=0)
            os << std::endl;
            os << "[ ";
            for (size_type j = 0; j < mat.sz_y; ++j) {
                if(j!=0)
                os << endl;

                for (size_type i = 0; i < mat.sz_x; ++i) {
                    os << mat(k,j,i) << " ";
                }
                
            }
            os << "]";

        }
        os << "}" <<std::endl;
        return os;
    }
    void swap(matrix3D& other) {
        std::swap(_matrix, other._matrix);
        std::swap(sz_x, other.sz_x);
        std::swap(sz_y, other.sz_y);
        std::swap(sz_z, other.sz_z);
    }

    private:
    
    void print_matrix(const string message = "", const bool enabled = true) const
    {
       /* for (size_type k = 0; k < sz_z; ++k) {
            cout << "pagina " << k<< ":" <<endl;
            
            for (size_type j = 0; j < sz_y; ++j) {
                

                for (size_type i = 0; i < sz_x; ++i) {
                    cout << _matrix[k][j][i] << " ";
                }
                cout << endl;
            }

        }*/
        #ifndef NDEBUG
        if (enabled == true) 
        {
            cout << message<<endl;
            cout << *this;
        }
        #endif
        
    }
};



#endif