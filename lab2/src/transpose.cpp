#include "../include/functions.h"
vector<vector<double>> tran(vector<vector<double>>& v)
{
    //cout<<v.size()<<" "<<v[0].size()<<"\n";
    vector<vector<double>> ans;
    for(int i=0;i<v[0].size();i++)
    {
    ans.push_back({});
        for(int j=0;j<v.size();j++)
        {
            ans[i].push_back(v[j][i]);
        }
    }
    return ans;
}
