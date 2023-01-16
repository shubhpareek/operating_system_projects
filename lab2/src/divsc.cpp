#include "../include/functions.h"
vector<vector<double>> div(vector<vector<double>>& v,int sc)
{
    vector<vector<double>> ans;
    
    if(sc==0){logger("divsc.cpp: division by 0 not allowed ");exit(1);}
    
    for(int i=0;i<v.size();i++)
    {
        ans.push_back({});
        for(int j=0;j<v[i].size();j++)
        {
            ans[i].push_back(v[i][j]/(double)sc); 
        }
        
    }
    return ans;

}
