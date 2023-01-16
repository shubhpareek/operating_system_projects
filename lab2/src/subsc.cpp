#include "../include/functions.h"
vector<vector<double>> sub(vector<vector<double>>& v,int sc)
{
    ///cout<<v.size()<<" "<<v[0].size()<<"\n";
    vector<vector<double>> ans;
    for(int i=0;i<v.size();i++)
    {
        ans.push_back({});
        for(int j=0;j<v[i].size();j++)
        {
            ans[i].push_back(v[i][j]-sc); 
        }
        
    }
    return ans;

}
