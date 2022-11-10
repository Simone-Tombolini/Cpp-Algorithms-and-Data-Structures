#ifndef _LCS
#define _LCS

    #include<string>
    
    using namespace std;

    typedef unsigned short int usi;
    typedef unsigned int uint;
    typedef unsigned long int uli;

    string LCS(const string &x, const string &y);

    void inizalize_matrix(const string &x, const string &y, uint *p);
    void inizalize_matrix(const string &x, const string &y, uli *p);
    void inizalize_matrix(const string &x, const string &y, usi *p);

#endif