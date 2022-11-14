#include "LCS.h"
#include <iostream>




string LCS(const string& x, const string& y) 
{
    string res = "";
    if (x != "" && y != "") 
    {

        //allocating memory
        usi matrix_type = 0;
        uli** matrix_long = new uli * [(uli)y.length() + 1];
        usi** matrix_short = new usi* [(usi)y.length() + 1];
        uint** matrix = new uint * [(uint)y.length() + 1];
        //max number of bit that are required for showing the matrix
        uli x_bit_max = ceil(log2(x.length())) + 1;
        uli y_bit_max = ceil(log2(y.length())) + 1;


        //if else statmet that deteminate the correct type of data to use
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            //allocating memory
            //matrix_short;
            matrix_type = 1;
            inizalize_matrix_len(x, y, matrix_short, (int)x.length() + 1, (int)y.length() + 1);

        }
        else if (x_bit_max < sizeof(uint) * 8 && y_bit_max < sizeof(uint) * 8)
        {
           /* allocating memory
            matrix;*/
            matrix_type = 2;
            inizalize_matrix_len(x, y, matrix, (int)x.length() + 1, (int)y.length() + 1);


        }
        else if (x_bit_max < sizeof(uli) * 8 && y_bit_max < sizeof(uli) * 8)
        {
       /*     allocating memory
            matrix_long;*/
            matrix_type = 3;
            inizalize_matrix_len(x, y, matrix_long, (int)x.length() + 1, (int)y.length() + 1);

        }
        else
        {
            cout << "out of memory";
        }


        usi** matrix_len = new usi * [(usi)y.length() + 1];
        inizalize_matrix_len(x, y, matrix_len, x.length() + 1, y.length() + 1);

        inizalize_matrix(x, y, matrix_short, matrix_len, (int)x.length() + 1, (int)y.length() + 1);
        
        delete[] matrix_len;

        usi* pointer = &matrix_short[1][1];
        cout <<pointer[1]<<endl;

    }
    
    
    return res;
}
string LCS_return() 
{
    return"";
}
void inizalize_matrix(const string& x, const string& y, usi** matrix, usi** matrix_len, const int& size_x, const int& size_y)
{
    //0 = null
    //1 diagonal
    //2 up
    //3 left
    // 
    //inizializing array and firs coloum
    for (int i = 0; i < size_y; i++) {


    }
  
    //inizializing first row
    matrix[0] = new usi[size_x];
    for (int i = 0; i < size_x; i++)
    {
        matrix[0][i] = 0;

    }
    for (int i = 1; i < size_y; i++)
    {
        matrix[i] = new usi[size_x];
        matrix[i][0] = 0;
        for (int j = 1; j < size_x; j++)
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
        if (i <= size_y ) 
        {
            delete[] matrix_len[i -1];
        }
        
    }

    cout << "stampa matrice movimenti" << endl;
    print_matrix(matrix, size_x, size_y);

}

/**
 * @brief Main function for Longerst Common Subsecuqnce
 *
 * 
 * @param x First string
 * @param y Second String
 * @return string Resoult of oparation
 */
void LCS_len_table_matrix(const string& x, const string& y)
{
    

    if (x != "" && y != "")
    {

    }


    
}
int LCS_len_table(const string &x, const string &y, bool print = false)
{
    int res = 0;

    if(x != "" && y!="")
    {
        //max number of bit that are required for showing the matrix
        uli x_bit_max = ceil(log2(x.length())) +1;
        uli y_bit_max = ceil(log2(y.length())) +1;
        

        //if else statmet that deteminate the correct type of data to use
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            //allocating memory
            usi **matrix = new usi*[(usi) y.length() +1];
           
            inizalize_matrix_len(x, y, matrix, (int)x.length()+ 1, (int)y.length() +1);
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
            
            inizalize_matrix_len(x, y, matrix, (int)x.length() + 1, (int)y.length() + 1);
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
            
            inizalize_matrix_len(x, y, matrix, (int)x.length() + 1, (int)y.length() + 1);
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

    cout << "the length of the lcs is: " << res << endl;

    return res;
}

void inizalize_matrix_len(const string &x, const string &y, usi **matrix, const int &size_x, const int &size_y )
{
    //inizializing array and firs coloum
    for (int i = 0; i < size_y; i++) {
        matrix[i] = new usi[size_x];
        matrix[i][0] = 0;
        
    }
    //inizializing first row
    for (int i = 0; i < size_x; i++)
    {
        matrix[0][i] = 0;
        
    }
    //filling matrix
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
    //printig
    print_matrix(matrix, size_x, size_y);
}

//Same logic whit different typ of data

void inizalize_matrix_len(const string& x, const string& y, uint **matrix, const int& size_x, const int& size_y)
{

    for (int i = 0; i < size_y; i++) {
        matrix[i] = new uint[size_x];
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
    print_matrix(matrix, size_x, size_y);
}

void inizalize_matrix_len(const string& x, const string& y, uli** matrix, const int& size_x, const int& size_y)
{

    for (int i = 0; i < size_y; i++) {
        matrix[i] = new uli[size_x];
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

void print_matrix(uint **matrix, int l1, int l2)
{
    cout << "start print matrix: " << endl << endl;

    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < l1; j++)
        {

            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void print_matrix(uli **matrix, int l1, int l2)
{
    cout << "start print matrix: " << endl << endl;

    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < l1; j++)
        {

            cout << matrix[i][j];
        }
        cout << endl;
    }
}
