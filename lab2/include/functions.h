#include <bits/stdc++.h>
using namespace std;
class fullinp
{
    public :
    vector<int> scalar;
    vector<vector<vector<double>>> mat;
;
    
};
fullinp inpreader();
void logger(string s);
vector<vector<double>> submat(vector<vector<double>>& v,vector<vector<double>>& v2);
vector<vector<double>> tran(vector<vector<double>>& v);
vector<vector<double>> sub(vector<vector<double>>& v,int sc);
vector<vector<double>> mul(vector<vector<double>>& v,int sc);
vector<vector<double>> mulmat( vector<vector<double>>& mat1, vector<vector<double>>& mat2);
vector<vector<double>> div(vector<vector<double>>& v,int sc);
void getCofactor(vector<vector<double>>& mat, vector<vector<double>>& temp, int p,int q, int n);
double deter(vector<vector<double>>& mat, int n);
vector<vector<double>> add(vector<vector<double>>& v,int sc);
vector<vector<double>> addmat(vector<vector<double>>& v,vector<vector<double>>& v2);


