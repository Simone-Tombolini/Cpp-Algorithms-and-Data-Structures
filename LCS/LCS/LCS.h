#ifndef _LCS
#define _LCS

    #include<string>
    #include <cmath>
    
    using namespace std;

    typedef unsigned short int usi;
    typedef unsigned int uint;
    typedef unsigned long int uli;

    string LCS(const string& x, const string& y, bool print = false);

    void inizalize_matrix(const string& x, const string& y, usi** matrix, usi** matrix_len, const int& size_x, const int& size_y, bool print = false);

    int LCS_len_table(const string &x, const string &y);
  
    void inizalize_matrix_len(const string &x, const string &y, usi **matrix, const int &size_x, const int &size_y, bool print = false);
    void inizalize_matrix_len(const string& x, const string& y, uint **matrix, const int& size_x, const int& size_y);
    void inizalize_matrix_len(const string& x, const string& y, uli **matrix, const int& size_x, const int& size_y);

    void print_matrix(usi **matrix, int l1, int l2);
    void print_matrix(uli **matrix, int l1, int l2);
    void print_matrix(uint **matrix, int l1, int l2);

#endif