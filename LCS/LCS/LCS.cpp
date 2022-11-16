#include "LCS.h"
#include <iostream>
#include<stdexcept>

string LCS(const string &x, const string& y, const bool print)
{
    string res = "";
    if (x != "" && y != "") 
    {

        //max number of bit that are required for max possible number of the matrix
        uli x_bit_max = ceil(log2(x.length())) + 1;
        uli y_bit_max = ceil(log2(y.length())) + 1;


        //if else statmet that deteminate the correct type of data to use, in base at bit max usage, memory optimization
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            //allocating memory of matrix that are required
            
            usi** matrix = new usi * [y.length() + 1];
            usi** matrix_len_short = new usi * [y.length() + 1];
            
            //inizialising the len and the movement matrix
            inizalize_matrix_len(x, y, matrix_len_short, (uli)x.length() + 1, (uli)y.length() + 1, print);
            inizalize_matrix(x, y, matrix, matrix_len_short, (uli)x.length() + 1, (uli)y.length() + 1, print);

            //deallocating memory
            delete[] matrix_len_short;
            matrix_len_short = nullptr; //seafty null setting

            usi x_len = x.length();
            usi y_len = y.length();

            //setting a sefety pointer
            usi** pointer = matrix;

            //following the path of the lcs
            res = find_LCS(pointer, x_len, y_len, x, y);

            //deallocating memory
            for (usi i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix[i];
            }

            delete[] matrix;

        }
        else if (x_bit_max < sizeof(uint) * 8 && y_bit_max < sizeof(uint) * 8)
        {
            //allocating memory of matrix 
            usi** matrix = new usi *[y.length() + 1];
            uint ** matrix_len = new uint *[y.length() + 1];

            //inizialising the len and the movement matrix
            inizalize_matrix_len(x, y, matrix_len, (uli)x.length() + 1, (uli)y.length() + 1, print);
            inizalize_matrix(x, y, matrix, matrix_len, (uli)x.length() + 1, (uli)y.length() + 1, print);

            //deallocating memory
            delete[] matrix_len;
            matrix_len = nullptr; //seafty null setting

            uint x_len = x.length();
            uint y_len = y.length();

            //setting a sefety pointer
            usi** pointer = matrix;

            //following the path of the lcs
            res = find_LCS(pointer, x_len, y_len, x, y);

            //deallocating memory
            for (usi i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix[i];
            }

            delete[] matrix;


        }
        else if (x_bit_max < sizeof(uli) * 8 && y_bit_max < sizeof(uli) * 8)
        {
            //allocating memory of matrix 
            usi** matrix = new usi * [y.length() + 1];
            uli** matrix_len = new uli *[y.length() + 1];

            //inizialising the len and the movement matrix
            inizalize_matrix_len(x, y, matrix_len, (uli)x.length() + 1, (uli)y.length() + 1, print);
            inizalize_matrix(x, y, matrix, matrix_len, (uli)x.length() + 1, (uli)y.length() + 1, print);

            //deallocating memory
            delete[] matrix_len;
            matrix_len = nullptr; //seafty null setting

            uli x_len = x.length();
            uli y_len = y.length();

            //setting a sefety pointer
            usi** pointer = matrix;

            //following the path of the lcs
            res = find_LCS(pointer, x_len, y_len, x, y);

            //deallocating memory
            for (uli i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix[i];
            }

            delete[] matrix;


        }
        else
        {
            cout << "out of memory";
            throw std::invalid_argument("too long string");
        }
       
    }
    
    
    return res;
}

int LCS_len(const string &x, const string &y, bool print)
{
    int res = 0;

    if(x != "" && y!="")
    {
        //max number of bit that are required for showing the matrix
        uli x_bit_max = ceil(log2(x.length())) +1;
        uli y_bit_max = ceil(log2(y.length())) +1;
        

        //if else that deteminate the correct type of data to use
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            //allocating memory
            usi **matrix = new usi*[(usi) y.length() +1];
           
            inizalize_matrix_len(x, y, matrix, x.length()+ 1, y.length() +1, print);
            //saving the result
            res = (int)matrix[y.length()][x.length()];
            //deallocating memory
            
            for (usi i = 0; i < y.length() + 1; i++) 
            {
                delete[] matrix[i];
            }

            delete[] matrix;
   
        }
        else if (x_bit_max < sizeof(uint) * 8 && y_bit_max < sizeof(uint) * 8) 
        {
            //allocating memory
            uint** matrix = new uint * [(uint)y.length() + 1];
            
            inizalize_matrix_len(x, y, matrix, x.length() + 1, y.length() + 1);
            //saving the result
            res = (int)matrix[y.length()][x.length()];
            //deallocating memory
            for (uint i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix[i];
            }

            delete[] matrix;
        }
        else if (x_bit_max < sizeof(uli) * 8 && y_bit_max < sizeof(uli) * 8) 
        {
            //allocating memory
            uli** matrix = new uli * [(uli)y.length() + 1];
            
            inizalize_matrix_len(x, y, matrix, x.length() + 1, y.length() + 1);
            //saving the result
            res = (int)matrix[y.length()][x.length()];
            //deallocating memory
            for (uli i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix[i];
            }

            delete[] matrix;
        }
        else 
        {
            cout << "out of memory";
        }
        
        
    }

    return res;
}
