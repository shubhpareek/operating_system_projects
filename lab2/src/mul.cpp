#include "../include/functions.h"
vector<vector<double>> mulmat( vector<vector<double>>& mat1, vector<vector<double>>& mat2)
{
    int R1= mat1.size();
    int R2= mat2.size();

    int C2= mat2[0].size();
    vector<vector<double>> rslt(R1,vector<double>(C2));
    
     if(mat1[0].size()!=mat2.size())
     {
     	logger("mul.cpp : operand sizes not suitable for matrix multiplication");
     	exit(1);
     }
     
    for (int i = 0; i < R1; i++) {
    
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
 
            //cout<<rslt[i][j]<<",";
        }
 
        //cout<<"\n";
    }
    return rslt;
}
