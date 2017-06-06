#include <stdio.h>
#include <stdlib.h>

double ran() 
{
    return (double)rand()/((double)RAND_MAX+1);
}

int main()
{
	int i	  = 0;　　　/* 変数初期化 */
	int m	  = 0;
	int k     = 0;
	int l     = 0;
	
//	double k  = 0;	
	double j  = 0;	
	double A  = 0;　/* 小数点変数初期化 */　　　　　　　　　　
	double B  = 0;
	double rn = 0;
	double x  = 0;
	double y  = 0;
	double zennkai  = 0;/* 前回の確率  */
  	double konnkai  = 0;/* 今回の確率  */
	double differ   = 0;/* 差分       */
	double pi       = 0;/* 円周率     */ 
	
	long seed; 	    /* 乱数の種　 */
	
	
	/* 最初にループを回すため差分を1にする */	
	differ = 1;
		
/////////* 差分が範囲外の間ループ *//////////////////////////////////////////
	while( 0 < differ >= 0.00001 )
	{
		/* ループ回数カウント */
		m++;
			
//			printf("Please input seed =>"); //seedの入力
//			scanf("%d",&seed);
//			srand(seed);
		rand();
		
		/* 2周してｘとｙ座標決める　点生成 */
 		for(i=0; i<2; i++)
		{
			
			if( 0==i )
			{
				x =ran();
			}
			/* ( 1==i )*/
			else
			{
				y =ran();
	 	  	}
		}
		
		/* 点が範囲内か確認 */
		if(  1 >=((x*x)+(y*y))   )
		{
			/* 範囲内に入っている数カウント */
			k++;
		}

		/* 今回確率を出す */
		konnkai = m / k ;  
		
		/* 今回確率が0か1だったら */
		if( 0 == konnkai || 1 == konnkai );
		{
			/* 差分をループさせるように変える */
			differ = 1;
		}
		/* 確率が0、1以外だったら */
		else
		{
			/* 差分を出す */
			differ = zennkai - konnkai;
		
			/* 差分がマイナスだったら */
			if( 0 > differ )
			{
				/* プラスに変換 */
				differ  = (differ * -1 );
			}
			
			/* 確率移動 */
			zennkai = konnkai;
		}
		
		
	}
/////////* 差分範囲内になりました *//////////////////////////////////////	
	
	
	
	printf("A%.10f\n", zennkai);  
	printf("B%.10f\n", konnkai);  
	printf("%.10f\n",   differ);  

	
	/* 円周率を出す */
	pi = ( 4 * estab2 );
	printf("円周率＝%f\n", pi );
		
	/* ループ回数表示 */
	printf("ループ回数＝%d\n",m);
		
			
}
