#include "../include/functions.h"
vector<vector<double>> submat(vector<vector<double>>& v,vector<vector<double>>& v2)
{
    vector<vector<double>> ans;
    if(v.size()!= v2.size() || v[0].size()!= v2[0].size())
    {
    	logger("sub.cpp: size of operand matrices don't match");
    	exit(1);
    }
    for(int i=0;i<v.size();i++)
    {
    ans.push_back({});
        for(int j=0;j<v[i].size();j++)
        {
            ans[i].push_back(v[i][j]-v2[i][j]); 
        }
        
    }
    return ans;

}

