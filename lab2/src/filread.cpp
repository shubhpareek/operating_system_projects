#include "../include/functions.h"
fullinp inpreader()
{
    string s1="aldfjaj";
    // if(s1.find(',')!=string::npos)
    // cout << s1.find(',');
    // else
    vector<vector<int>>  dim;
    vector<vector<double>>  bada;
    int rc=0,dc=0;
    vector<int> scal;
    
    while (!cin.eof()&&getline(cin,s1))
    {
            s1=std::regex_replace(s1,std::regex("^ +| +$|( ) +"),"$1");
            if(s1.find('#')!=string::npos)
            {
            	logger("file read.cpp: found a commment in input");
                continue;
            }
            if(s1.find(',')!=string::npos)
            {
            	logger("file read.cpp: parsing a matrix row in input");
                int num=0,las=0;
                bada.push_back({});
                for(int i=0;i<s1.length();i++)
                {
                    if(s1[i]!=',')
                    {
                        num++;
                    }
                    else
                    {
                        bada[rc].push_back(stoi(s1.substr(las,num)));
                        las=i+1;
                        num=0;
                    }   
                    
                }
                string  ss=to_string(bada[rc].size());
                logger("file read.cpp: this row had "+ss+" columns");
                rc++;
                continue;
            }
            if(s1.find(' ')!=string::npos)
            {
                //cout << dc << endl;
                logger("file read.cpp: parsing dimensions of a matrix from input");
                int snum=0,slas=0;
                dim.push_back({});
                for(int i=0;i<s1.length();i++)
                {
                    if(s1[i]!=' ')
                    {
                        snum++;
                    }
                    else
                    {
                        dim[dc].push_back(stoi(s1.substr(slas,snum)));
                        //cout << slas <<" " << snum<<endl;
                        slas=i+1;
                        snum=0;
                    }   
                }
                // dim[dc][0]=atoi(s1[0]);
                // dim[dc][1]=atoi(s1[2]);
                dim[dc].push_back(stoi(s1.substr(slas,snum)));
                dc++;
                
                continue;
            }
            else 
            {   
                scal.push_back(stoi(s1));
                continue;
            }
            
    }
    // for(int i=0;i<rc;i++)
    // {
    //     for(int j=0;j<bada[i].size();j++)
    //     {
    //         // << bada[i][j] << " ";
    //     }
    //     // << endl;
    // }
    // << scal <<endl;
    
    // << dim [0][0] <<" " << dim[0][1]<<endl;
    // << dim [1][0] << " " << dim[1][1]<<endl;
    fullinp rt;
    rt.scalar=scal;
    int csum=0;
    string rcc = to_string(rc);
    string dcc = to_string(dc);
    logger("file read.cpp: input had "+dcc+" dimensions");
    logger("file read.cpp: input had "+rcc+" rows of matrix");
    
	if(bada.size()==0||bada[0].size()!=dim[0][1])
	{
		logger("file read.cpp: wrong dimension of matrix for given dimensions");
		exit (1);
	}
    
    
    for(int i=0;i<dc;i++)
    {
   	 vector<vector<double>> t;
        for(int j=0;j<dim[i][0];j++)
        {
        	if(bada[csum+j].size()!=dim[i][1])
        	{
        		logger("file read.cpp: wrong dimension of column size in input");
        		exit (1);
        	}
            t.push_back(bada[csum+j]);
        }
        rt.mat.push_back(t);
        csum+=dim[i][0];
    }
	logger("file read.cpp: matrix parsing done correctly");
    return rt;
}


