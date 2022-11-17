#include<iostream>
#include "LCS.h"
using namespace std;

int main(int argc, char *argv[]){
    //tests
    cout << "Starting tests of LCS"<< endl<<endl;

    cout << "equal string" << endl;
    cout << LCS("aaaa", "aaaa", true) << endl;

    cout << "2 empry string" << endl;
    cout << LCS("", "", true) << endl;

    cout << "1 empry string" << endl;
    cout << LCS("a", "", true) << endl;
    cout << LCS("", "b", true) << endl;

    cout << "1 and 1  different string" << endl;
    cout << LCS("a", "b", true) << endl;

    cout << "300 string equal" << endl;
    cout << LCS("aeVR6mTCLMZbXmy2eymGXdc4ZCgEFrQun1ODzgpZuLhiIHs26TdzV3UBiYM24rWfcjlRKBov5xVnRQp4OgCeJb35qWQ09MUOE97hQbKPgqyFGgE0mrSKYs7jEBd0OEQCdajb8Ntj4xSmPxPuVFUPY1GJFMDg7gnLtc5yoiJ63vKdyXm7t6fP8qeFxhCdhrBIk18KXyuHGsXsg2stuQcLG2Z9iYNZZOPb0dTVS1XX1Nbsj8Yk7kqIqbudTxX8U0vkF4q8qcqm25Gwo7T8saMUVrWW1QZYWuD4wKFQNj43HryD", "aeVR6mTCLMZbXmy2eymGXdc4ZCgEFrQun1ODzgpZuLhiIHs26TdzV3UBiYM24rWfcjlRKBov5xVnRQp4OgCeJb35qWQ09MUOE97hQbKPgqyFGgE0mrSKYs7jEBd0OEQCdajb8Ntj4xSmPxPuVFUPY1GJFMDg7gnLtc5yoiJ63vKdyXm7t6fP8qeFxhCdhrBIk18KXyuHGsXsg2stuQcLG2Z9iYNZZOPb0dTVS1XX1Nbsj8Yk7kqIqbudTxX8U0vkF4q8qcqm25Gwo7T8saMUVrWW1QZYWuD4wKFQNj43HryD", false) << endl;
   
    cout << endl << "start lcs len printing, same tests" << endl;
    cout << "equal string" << endl;
    cout << LCS_len("aaaa", "aaaa", true) << endl;

    cout << "2 empry string" << endl;
    cout << LCS_len("", "", true) << endl;

    cout << "1 empry string" << endl;
    cout << LCS_len("a", "", true) << endl;
    cout << LCS_len("", "b", true) << endl;

    cout << "1 and 1  different string" << endl;
    cout << LCS_len("a", "b", true) << endl;

    cout << "300 string equal" << endl;
    cout << LCS_len("aeVR6mTCLMZbXmy2eymGXdc4ZCgEFrQun1ODzgpZuLhiIHs26TdzV3UBiYM24rWfcjlRKBov5xVnRQp4OgCeJb35qWQ09MUOE97hQbKPgqyFGgE0mrSKYs7jEBd0OEQCdajb8Ntj4xSmPxPuVFUPY1GJFMDg7gnLtc5yoiJ63vKdyXm7t6fP8qeFxhCdhrBIk18KXyuHGsXsg2stuQcLG2Z9iYNZZOPb0dTVS1XX1Nbsj8Yk7kqIqbudTxX8U0vkF4q8qcqm25Gwo7T8saMUVrWW1QZYWuD4wKFQNj43HryD", "aeVR6mTCLMZbXmy2eymGXdc4ZCgEFrQun1ODzgpZuLhiIHs26TdzV3UBiYM24rWfcjlRKBov5xVnRQp4OgCeJb35qWQ09MUOE97hQbKPgqyFGgE0mrSKYs7jEBd0OEQCdajb8Ntj4xSmPxPuVFUPY1GJFMDg7gnLtc5yoiJ63vKdyXm7t6fP8qeFxhCdhrBIk18KXyuHGsXsg2stuQcLG2Z9iYNZZOPb0dTVS1XX1Nbsj8Yk7kqIqbudTxX8U0vkF4q8qcqm25Gwo7T8saMUVrWW1QZYWuD4wKFQNj43HryD", false) << endl;
    
    return 0;
}