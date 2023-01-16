#include "../include/functions.h"

vector<vector<double>> add(vector<vector<double>>& v,int sc)
{
    vector<vector<double>> ans;
    for(int i=0;i<v.size();i++)
    {
        ans.push_back({});
        for(int j=0;j<v[i].size();j++)
        {
            ans[i].push_back(v[i][j]+sc); 
        }
        
    }
    return ans;

}
