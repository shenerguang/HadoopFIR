#include <iostream>
#include <stdio.h>
#include <string>
#include <fcntl.h>
#include <sys/ioctl.h>
using namespace std;


int fir_fd;

int main()
{
	string str;
	int i;
	fir_fd = open("/dev/fir_mod", 0);
//	printf("%d\n",fir_fd);

	while(cin>>str)
	{
		//the key is the original value
		//cout << str << "\t"; 

		//firstly, init fir with 58 zero
		char out_val[4];
//		printf("debug");
    		ioctl(fir_fd,1,0);

		//secondly, do the real fir
		int len = str.length()/4;
		for(i=0;i<len;i++)
		{
			str.copy(out_val+3,1,i*4+3);	
			str.copy(out_val+2,1,i*4+2);	
			str.copy(out_val+1,1,i*4+1);	
			str.copy(out_val+0,1,i*4+0);	
			ioctl(fir_fd,3,(long*)out_val);
			cout << out_val[0] << out_val[1]<<out_val[2] << out_val[3];
		}
		//release sem
    		ioctl(fir_fd,5,0);

		//the value is fir out, and follow a line finish
		cout << endl;
		
	}
 	return 0;
}
