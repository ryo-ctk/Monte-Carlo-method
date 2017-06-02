#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

double ran() 
{
    return (double)rand()/((double)RAND_MAX+1);
}
int main()
{
	int i;
	
	int k    =  0;
	int l    =  0;
//	double k =  0モンテカルロ;
	double j =  0;
	double A  = 0;
	double B  = 0;
	double rn = 0;
	double x  = 0;
	double y  = 0;
	double estab1  = 0;/* 確率1  */
    double estab2  = 0;/* 確率2  */
	double differ  = 0;/* 差分   */
	double pi      = 0;/* 円周率 */
	long seed; 
	
	printf("Please input seed =>"); //seedの入力
	scanf("%d",&seed);
	srand(seed);
//	rand(); 
 	for(j=0; j<10000000; j++)
	{
    	for(i=0; i<2; i++)
		{
			if(i==0)
			{
				
				
//				printf("x1=%f\n",ran());
				x =ran();
//				printf("x1=%f\n",x);
			}
			else
			{
//				y = rand();
//				printf("y1=%f\n",y);
//				printf("y1=%f\n",ran());
				y =ran();
//				printf("y1=%f\n",y);
		    }
			
			
		}
		if(  1 >=((x*x)+(y*y))   )
		{
			k++;
			
			
		}
/////////////////////////////////////////////////////////////////////////		
		for(i=0; i<2; i++)
		{
			if(i==0)
			{
//				x = rand();
//				printf("x2=%f\n",x);
//				printf("x2=%f\n",ran());
				x =ran();
//				printf("x2=%f\n",x);
			}
			else
			{
//				y =rand();
//				printf("y2=%f\n",y);
//				printf("y2=%f\n",ran());
				y =ran();
//				printf("y2=%f\n",x);
		    }
			
			
			}
		if(  1 >=((x*x)+(y*y))   )
		{
			l++;

		}	
			
	}

	printf("k=>%d\n",k);
	printf("l=>%d\n",l);

	
	A = k / j;          
    printf("A%.10f\n", A);  
	
	B = l / j;          
    printf("B%.10f\n", B);
	
	printf("%.10f\n", A-B);
	
		
    
}