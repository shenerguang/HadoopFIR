#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void fir(long *a,long b);

int main()
{
	string str;
	char in_val[4];
	char buf;
	int i;
	while(cin>>str)
	{
		//the key is the original value
		//cout << str << "\t"; 

		//firstly, init fir with 58 zero
		char out_val[4];
		for(i=0;i<59;i++)
			fir((long*)out_val,0);
		
		//secondly, do the real fir
		int len = str.length()/4;
		for(i=0;i<len;i++)
		{
			str.copy(in_val+3,1,i*4+3);	
			str.copy(in_val+2,1,i*4+2);	
			str.copy(in_val+1,1,i*4+1);	
			str.copy(in_val+0,1,i*4+0);	
			fir((long*)out_val, *(long*)in_val);
			cout << out_val[0] << out_val[1]<<out_val[2] << out_val[3];
		}

		//the value is fir out, and follow a line finish
		cout << endl;
		
	}
 	return 0;
}
