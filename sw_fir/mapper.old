#include <iostream>
#include <stdio.h>
#include <string>
#include <fcntl.h>
#include <sys/ioctl.h>
using namespace std;

static int fir_fd;
char str[2]={0};
short i = 0, flag = 0;

void flush();
void fir(short *a,short b);

int main()
{
 while(scanf("%c",&str[i])!=EOF)
 {
  if(str[i] == ' ' || str[i] == '\n'|| str[i] == '\t')
  {
    //printf("got space\n");
    if(flag)
    {
        if(flag != 2)
            flush();
        printf("\t1\n");
    }
    i = -1;
    flag = 0;
  }
  else if(i==1)
  {
    flush();
    flag = 2;
  }else{
    //printf("here\n");
    flag = 1;
  }
  i++;
 }//while done
 //final flush
 if(i>0)
 {
    flush();
    printf("\t1\n");
 }
 return 0;
}

void flush()
{
    char val[2];
    int j;
    for(j=0;j<68;j++)
    {
	if(j==0)
    		fir((short*)val,0x8000);
	else
    		fir((short*)val,0);
    }	
    //printf("val = %x\n",*(short*)str);
    fir((short*)val,*(short*)str);
    printf("%c%c",val[0],val[1]);
    *(short *)str = 0; 
    i = -1;
}
