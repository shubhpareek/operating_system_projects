#include <bits/stdc++.h>
#include "../include/functions.h"
using namespace std;

int main(int argn, char ** args)
{	
	logger("mainfilecpp: recieved "+to_string(argn-1)+" arguments in input command");
    fullinp ans = inpreader();
    vector<vector<double>>temp=ans.mat[0];
    
    for(int i=1,j=1,k=0;i<argn;i++)
    {
	    if(strcmp("-a",args[i])==0)
	    {
	    	logger("mainfilecpp:  add with scalar started ");
	       temp = add(temp,ans.scalar[k]);
	       logger("mainfilecpp: add with scalar "+to_string(ans.scalar[k])+" completed ");
	       k++;
	       
	    }
	    else if(strcmp("-s",args[i])==0)
	    {
	     	logger("mainfilecpp:  sub with scalar started ");
	   
	       temp = sub(temp,ans.scalar[k]);
	           logger("mainfilecpp: sub with scalar "+to_string(ans.scalar[k])+" completed ");
	   
	       k++;
	    }
	    else if(strcmp("-m",args[i])==0)
	    {
	     	logger("mainfilecpp:  mul with scalar started ");
	   
		temp = mul(temp,ans.scalar[k]);
		    logger("mainfilecpp: mul with scalar "+to_string(ans.scalar[k])+" completed ");
	   
		k++;
	    }
	    else if(strcmp("-d",args[i])==0)
	    {
	     	logger("mainfilecpp:  div with scalar started ");
	   
		temp =div(temp,ans.scalar[k]);
		    logger("mainfilecpp: div with scalar "+to_string(ans.scalar[k])+" completed ");
	   
		k++;
		
	    }
	    else if(strcmp("-A",args[i])==0)
	    {
	    	logger("mainfilecpp: add between two matrix started ");
	   	temp =addmat(temp,ans.mat[j]);
	    	logger("mainfilecpp: add between two matrix completed ");
		j++;
	    }
	    else if(strcmp("-S",args[i])==0)
	    {
	    	logger("mainfilecpp: sub between two matrix started ");
		temp =submat(temp,ans.mat[j]);
	    	logger("mainfilecpp: sub between two matrix completed ");
		j++;		
	    }   
	    else if(strcmp("-M",args[i])==0)
	    {
	    	logger("mainfilecpp: mul between two matrix started ");
		temp = mulmat(temp,ans.mat[j]);
	    	logger("mainfilecpp: mul between two matrix completed ");
		j++;
	    }
	    else if(strcmp("-T",args[i])==0)
	    {
	    	logger("mainfilecpp: transpose of matrix started ");
		temp = tran(temp);
		logger("mainfilecpp: transpose of matrix completed");
	    }   
	    else if(strcmp("-X",args[i])==0)
	    {
	    	logger("mainfilecpp: determinant of matrix started ");
		cout << deter(temp,temp.size())<< endl;
		logger("mainfilecpp: determinant of matrix completed");
		return 0;
	    }
    }	
    
    cout << temp.size() << " " << temp[0].size()<<endl;
    for(int i=0;i<temp.size();i++)
    {
    	for(auto j:temp[i])
    	{
    		cout << j <<",";
    	}
    	cout << endl;
    }
	logger("mainfilecpp: final output written to the stdout");
	logger(" ");
}

// /******************************************************************************

// Welcome to GDB Online.
// GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
// C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
// Code, Compile, Run and Debug online from anywhere in world.

// *******************************************************************************/
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     string si="aldfjaj";
//     // if(si.find(',')!=string::npos)
//     // cout << si.find(',');
//     // else
//     // cout << "gand";
//     vector<vector<int>> bada ;
//     int rc=0;
    
//     while (!cin.eof()&&getline(cin,si)){
            
//             if(si.find('#')!=string::npos)
//             {
//                 continue;
//             }
//             if(si.find(',')!=string::npos)
//             {
//                 int num=0,las=0;
//                 bada.push_back({});
//                 for(int i=0;i<si.length();i++)
//                 {
//                     if(si[i]!=',')
//                     {
//                         num++;
//                     }
//                     else
//                     {
//                         bada[rc].push_back(stoi(si.substr(las,num)));
//                         las=i+i;
//                         num=0;
//                     }   
//                 }
//                 rc++;
//             }
//             if(si.find(' ')!=string::npos)
//             {
//                 continue;
//             }
//             else 
//             {   
//                 continue;
                
//             }
            
//     }
//     for(int i=0;i<rc;i++)
//     {
//         for(int j=0;j<bada[i].size();j++)
//         {
//             cout << bada[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "khatam";
//     return 0;
// }
