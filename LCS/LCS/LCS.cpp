#include "LCS.h"
#include <iostream>

using namespace std;




string LCS(const string& x, const string& y, bool print) 
{
    string res = "";
    if (x != "" && y != "") 
    {

        ////allocating memory
        //usi matrix_type = 0;
        //uli** matrix_long = new uli * [(uli)y.length() + 1];
  
        //uint** matrix = new uint * [(uint)y.length() + 1];

    
        //uint** matrix_len = new uint * [(uint)y.length() + 1];
        //uli** matrix_len_long = new uli * [(uli)y.length() + 1];
        //max number of bit that are required for showing the matrix
        uli x_bit_max = ceil(log2(x.length())) + 1;
        uli y_bit_max = ceil(log2(y.length())) + 1;


        //if else statmet that deteminate the correct type of data to use
        if (x_bit_max < sizeof(usi) * 8 && y_bit_max < sizeof(usi) * 8)
        {
            //allocating memory
            //matrix_short;
            usi** matrix_short = new usi * [(usi)y.length() + 1];
            usi** matrix_len_short = new usi * [(usi)y.length() + 1];
            
            inizalize_matrix_len(x, y, matrix_len_short, (int)x.length() + 1, (int)y.length() + 1, print);
            inizalize_matrix(x, y, matrix_short, matrix_len_short, (int)x.length() + 1, (int)y.length() + 1, print);

            delete[] matrix_len_short;
            usi x_len = x.length();
            usi y_len = y.length();
            
            usi** pointer = matrix_short;
         /*   cout << x_len;
                  
            if (pointer[y_len][x_len] == 2) {
                cout << "ok";
            }*/
            while (pointer[y_len][x_len] != 0)
            {
                if (pointer[y_len][x_len] == 1)
                {
                    
                    res = x[x_len - 1] + res;
                    x_len -= 1;
                    y_len -= 1;


                }
                else if (pointer[y_len][x_len] == 2)
                {

                    y_len -= 1;

                }
                else {
                    x_len -= 1;

                }
            }
            for (usi i = 0; i < y.length() + 1; i++)
            {
                delete[] matrix_short[i];
            }

            delete[] matrix_short;

        }
        else if (x_bit_max < sizeof(uint) * 8 && y_bit_max < sizeof(uint) * 8)
        {
           /* allocating memory
          //  matrix;*/
          //  //allocating memory
          ////matrix_short;
          //  uint** matrix = new uint * [(uint)y.length() + 1];
          //  uint** matrix_len = new uint * [(uint)y.length() + 1];
          // 
          //  inizalize_matrix_len(x, y, matrix_len, (int)x.length() + 1, (int)y.length() + 1);
          //  inizalize_matrix(x, y, matrix, matrix_len, (int)x.length() + 1, (int)y.length() + 1);

          //  delete[] matrix_len;
          //  usi x_len = x.length();
          //  usi y_len = y.length();

          //  usi** pointer = matrix;
          //  cout << x_len;

          //  if (pointer[y_len][x_len] == 2) {
          //      cout << "ok";
          //  }
          //  while (pointer[y_len][x_len] != 0)
          //  {
          //      if (pointer[y_len][x_len] == 1)
          //      {

          //          res = x[x_len - 1] + res;
          //          x_len -= 1;
          //          y_len -= 1;


          //      }
          //      else if (pointer[y_len][x_len] == 2)
          //      {

          //          y_len -= 1;

          //      }
          //      else {
          //          x_len -= 1;

          //      }
          //  }
          //  for (usi i = 0; i < y.length() + 1; i++)
          //  {
          //      delete[] matrix_short[i];
          //  }

          //  delete[] matrix_short;

        }
        else if (x_bit_max < sizeof(uli) * 8 && y_bit_max < sizeof(uli) * 8)
        {
       ///*     allocating memory
       //     matrix_long;*/
       //     matrix_type = 3;
       //     inizalize_matrix_len(x, y, matrix_len_long, (int)x.length() + 1, (int)y.length() + 1);

        }
        else
        {
            cout << "out of memory";
        }


       
     
       
    }
    
    
    return res;
}

void inizalize_matrix(const string& x, const string& y, usi** matrix, usi** matrix_len, const int& size_x, const int& size_y, bool print)
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
           
            if (x[j-1] == y[i-1])
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
    delete[] matrix_len[size_y - 1];
    if (print) {
        cout << "stampa matrice movimenti" << endl;
        print_matrix(matrix, size_x, size_y);
    }


}


int LCS_len_table(const string &x, const string &y)
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

void inizalize_matrix_len(const string &x, const string &y, usi **matrix, const int &size_x, const int &size_y, bool print)
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
    if (print) {
        print_matrix(matrix, size_x, size_y);
    }
    
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
