#ifndef _LCS
#define _LCS

    #include<string>
    #include <cmath>
    #include<iostream>
    
    using namespace std;

    typedef unsigned short int usi;
    typedef unsigned int uint;
    typedef unsigned long int uli;

    string LCS(const string& x, const string& y, const bool print = false);

    int LCS_len(const string& x, const string& y, bool print = false);

    template <typename T> void print_matrix(T** matrix, uli l1, uli l2);

    template <typename T, typename Q> string find_LCS(T pointer, Q x_len, Q y_len, const string &x, const string &y) {
        string res = "";
        while (pointer[y_len][x_len] != 0)//if 0 is encountered the lcs is ternmined
        {
            if (pointer[y_len][x_len] == 1)
            {
                //in case of diagonal add the resoult to the lcs
                res = x[x_len - 1] + res;
                x_len -= 1;
                y_len -= 1;


            }
            else if (pointer[y_len][x_len] == 2)//in case of up move the index y up
            {

                y_len -= 1;

            }
            else {//in case of left move the index x left
                x_len -= 1;

            }
        }
        return res;
    }
    template <typename T, typename V, typename Q> void inizalize_matrix(const string &x, const string &y, T** matrix, V** matrix_len, const Q& size_x, const Q& size_y, bool print = false)
    {
        //0 = null
        //1 diagonal
        //2 up
        //3 left

        //inizializing first row
        matrix[0] = new T[size_x];
        for (T i = 0; i < size_x; i++)
        {
            matrix[0][i] = 0;

        }
        for (T i = 1; i < size_y; i++)
        {
            matrix[i] = new T[size_x];
            matrix[i][0] = 0;
            for (T j = 1; j < size_x; j++)
            {

                if (x[j - 1] == y[i - 1])
                {

                    matrix[i][j] = 1;
                }
                else if (matrix_len[i - 1][j] >= matrix_len[i][j - 1])
                {
                    matrix[i][j] = 2;
                }
                else
                {
                    matrix[i][j] = 3;
                }


            }
            if (i <= size_y)
            {
                delete[] matrix_len[i - 1];
            }

        }
        delete[] matrix_len[size_y - 1];
        if (print) {
            std::cout << "print movemnt matrix" << std::endl;
            print_matrix(matrix, size_x, size_y);
        }


    }
  
    
    template <typename T> void inizalize_matrix_len(const string& x, const string& y, T** matrix, const uli& size_x, const uli& size_y, bool print = false)
    {
        //inizializing array and firs coloum
        for (T i = 0; i < size_y; i++) {
            matrix[i] = new T[size_x];
            matrix[i][0] = 0;

        }
        //inizializing first row
        for (T i = 0; i < size_x; i++)
        {
            matrix[0][i] = 0;

        }
        //filling matrix
        for (T i = 1; i < size_y; i++)
        {
            for (T j = 1; j < size_x; j++)
            {
                if (x[j - 1] == y[i - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                else if (matrix[i - 1][j] >= matrix[i][j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j];
                }
                else
                {
                    matrix[i][j] = matrix[i][j - 1];
                }

            }

        }
      //  printig
      if (print)
      {
          cout << "print len matrix" << endl;
          print_matrix(matrix, size_x, size_y);
      }

    }

    template <typename T> void print_matrix(T** matrix, uli l1, uli l2)
    {
        cout << "start print matrix: " << endl;

        for (uli i = 0; i < l2; i++)
        {
            for (uli j = 0; j < l1; j++)
            {

                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

#endif