#include "../include/functions.h"
#include <ctime>
void logger(string s)
{
	ofstream fout;
	time_t tim = time(NULL);
	
	fout.open("loggfile",ofstream::app);
	
	fout << ctime(&tim)<<s << endl;

	fout.close();
}
