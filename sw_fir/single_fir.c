#include <stdio.h>
#include <stdlib.h>

void fir(short *a,short b);

int main()
{
	short x;
	short y;
	int i;
	//init fir suppose start sequence is 58 zero
	for(i=0;i<58;i++)
		fir(&y,0);
	while(scanf("%d",&x)!=EOF)
	{
		fir(&y,x);	
		printf("%d",y);
	}
	printf("\n");
}
