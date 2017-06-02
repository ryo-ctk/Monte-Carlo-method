#include <stdio.h>
#include <stdlib.h>

double ran() 
{
    return (double)rand()/((double)RAND_MAX+1);
}

int main()
{
	int i;
	int m=0;
	int k    =  0;
	int l    =  0;
//	double k =  0;
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
	
	
		
	differ = 1;
		
	/* 差分が範囲外の間ループ */
	while( 0.0001 <= differ )
	{
			/* ループ回数カウント */
			m++;
			
//			printf("Please input seed =>"); //seedの入力
//			scanf("%d",&seed);
//			srand(seed);
			rand();

 			for(j=0; j<2; j++)
			{
    			for(i=0; i<2; i++)
				{
					if(i==0)
					{
						x =ran();
					}
					else
					{
						y =ran();
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
						x =ran();
					}
				
					else
					{
						y =ran();
		 			}
			
			
				}
			
			if(  1 >=((x*x)+(y*y))   )
			{
				l++;			
			}	
			
	

//		printf("k=>%d\n",k);
//		printf("l=>%d\n",l);

	
		estab1 = k / j;          
//    	printf("A%.10f\n", estab1);  
	
		estab2 = l / j;          
//   	printf("B%.10f\n", estab2);
	
		/* 差分を出す */
		differ = estab1-estab2;
	
//		printf("%.10f\n", differ);
	
		
			
			/* 差分がマイナスだったら */
			if( 0 > differ )
			{
				/* プラスに変換 */
				differ  = (differ * -1 );
			}
		
		}
		/* 差分範囲内になりました */
	}
	
	/* 差分が範囲内　且つ　確率は0と1以外になりました */
	printf("A%.10f\n", estab1);  
	printf("B%.10f\n", estab2);  
	printf("%.10f\n", differ);  

	
	/* 円周率を出す */
	pi = ( 4 * estab2 );
	printf("円周率＝%f\n", pi );
		
	/* ループ回数表示 */
	printf("ループ回数＝%d\n",m);
		
			
}