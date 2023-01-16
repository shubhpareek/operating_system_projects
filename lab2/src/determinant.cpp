#include "../include/functions.h"
void cofactor(vector<vector<double>>& mat, vector<vector<double>>& temp, int p,int q, int r)
{
    int i=0, j=0;
    for(int row=0; row<r; row++)
    {
        for(int col=0; col<r; col++)
        {
            if(row!=p && col!=q)
            {
                temp[i][j]=mat[row][col];
                j++;
                if(j+1==r) {i++;j=0;}
            }
        }
    }
}
double deter(vector<vector<double>>& mat, int n)
{
	if(mat.size()!=mat[0].size())
	{
		logger("determinant.cpp : row size not equalto column size");
		exit(1);
	}
    double result=0;
    if(n==1) {return mat[0][0];}
    vector<vector<double>> temp(n+1,vector<double>(n+1));
    int s=1;
    for(int i=0; i<n; i++)
    {
        cofactor(mat,temp,0,i,n);
        result+=s*deter(temp, n - 1)*mat[0][i];
        s=-s;
    }
    return result;
}
