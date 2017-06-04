#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double ran() 
{
	/* 乱数の範囲を0から1に設定する */
    return (double)rand()/((double)RAND_MAX+1);
}

int main()
{
	int i;
	int m	  = 0;		/*ループ回数		  */
	int k     = 0;		/*円内に入っている回数*/
	int l     = 0;		/*円内に入っている回数*/
	double j  = 0;
	double x  = 0;		/*  座標x  */
	double y  = 0;		/*  座標y  */
	double estab1  = 0;	/*  確率1  */
    double estab2  = 0;	/*  確率2  */
	double differ  = 0;	/*  差分   */
	double pi      = 0;	/*  円周率 */
	long seed;			/* 乱数の種*/
	
	
		
	differ = 1;
		
	/* 差分が範囲外の間ループ */
	while( 0.0001 <= differ )
	{
			/* ループ回数カウント */
			m++;
			/*  乱数の種を設定    */
			printf("Please input seed =>"); //
			scanf("%d",&seed);
			srand(seed);

			/*乱数の種を時刻に設定*/
//			srand((unsigned)time(NULL));
			
			/*  乱数を自動で生成  */
//			rand();
			
			/*x軸とy軸を2個ずつ作成*/
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
			
			
			
				/*円内に入っているかを判定*/
				if(  1 >((x*x)+(y*y))   )
				{
					
				/*円内に入っている回数    */
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
			
				if(  1 >((x*x)+(y*y))   )
				{
					l++;			
				}	
			}//j++の{}
	
        /*円内に入った回数*/
//		printf("k=>%d\n",k);
//		printf("l=>%d\n",l);

	    /*円内に入った確率*/
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
		
//		}j++の{}
		/* 差分範囲内になりました */
	}
	
	/* 差分が範囲内　且つ　確率は0と1以外になりました */
	printf("確率1 ＝%.10f\n", estab1);  
	printf("確率2 ＝%.10f\n", estab2);  
	printf("差分  ＝%.10f\n", differ);  

	
	/* 円周率を出す */
	pi = ( 4 * estab2 );
	printf("円周率＝%f\n", pi );
		
	/* ループ回数表示 */
	printf("ループ回数＝%d\n",m);
		
			
}