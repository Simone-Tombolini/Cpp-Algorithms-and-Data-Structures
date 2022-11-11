#include "LCS.h"
#include <iostream>
#include <cmath>



string LCS(const string& x, const string& y);
/**
 * @brief Main function for Longerst Common Subsecuqnce
 *
 * 
 * @param x First string
 * @param y Second String
 * @return string Resoult of oparation
 */
string LCS_len_table(const string &x, const string &y)
{
    string res = "";
    
    if(x != "" && y!="")
    {
        //max number of bit
        uli x_bit_max = ceil(log2(x.length())) +1;
        uli y_bit_max = ceil(log2(y.length())) +1;
      
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            
            usi **matrix = new usi*[(usi) y.length() +1];
            inizalize_matrix_len(x, y, matrix, (int)x.length()+ 1, (int)y.length() +1);
           

        }
        
        
    }
    return res;
}

void inizalize_matrix_len(const string &x, const string &y, usi **matrix, const int &size_x, const int &size_y )
{

    for (int i = 0; i < size_y; i++) {
        matrix[i] = new usi[size_x];
        matrix[i][0] = 0;
        
    }

    for (int i = 0; i < size_x; i++)
    {
        matrix[0][i] = 0;
        
    }
    for (int i = 1; i < size_y; i++)
    {
        for (int j = 1; j < size_x; j++)
        {
            if (x[j-1] == y[i-1]) 
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else if (matrix[i-1][j]>=matrix[i][j-1])
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else 
            {
                matrix[i][j] = matrix[i][j -1];
            }
            
        }

    }
    print_matrix(matrix, size_x, size_y);
}

void print_matrix(usi** matrix, int l1, int l2) 
{
    cout << "start print matrix: " << endl<< endl;

    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < l1; j++) 
        {
            
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
