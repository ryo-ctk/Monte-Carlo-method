//*****************************************************************************************//
//*課題名　　：　プログラム課題　モンテカルロ法 　　                      　　　 　       *//
//*課題内容　：　乱数を利用して円周率を求める                                       　　　*//
//*作者名　　：　平野 西浦                                       　　　        　         *//
//*最終更新日：　2017年6月06日      											          *//
//*																				          *//
//*																				          *//
//*****************************************************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 乱数を作る関数 */
double ran() 
{
	/* 乱数の範囲を0から1に設定する */
    return (double)rand()/((double)RAND_MAX+1);
}


int main()
{
	int i	  	     = 0;    /* 変数初期化           */

	double m 		 = 0;    /* ループ回数＝点総数   */
	double k  		 = 0;    /* 円内に入っている回数 */
	
	double x 		 = 0;    /* 座標 */
	double y 		 = 0;
	
	double zennkai   = 0;    /* 前回の確率           */
  	double konnkai   = 0;	 /* 今回の確率		     */
	double differ    = 0;	 /* 差分                 */
	double pi        = 0;	 /* 円周率      		 */
	
	long seed; 	        	 /* 乱数の種   		     */
	
	
	
	
	/* 最初にループを回すため差分を1 にする */	
	differ = 1;

	/* 乱数の種を設定 */
	printf("seedを入力 =>"); 
	scanf("%d",&seed);
	
	/* randに種を渡す */
	srand(seed);
		
			
			
/////////* 差分が範囲外の間ループ *//////////////////////////////////////////
	while( differ >= 0.00001 )
	{
		/* ループ回数カウント */
		m++;
		
			
		/* 2周して、乱数でｘとｙ座標決める　点生成 */
	 	for(i=0; i<2; i++)
		{			
			if( 0 == i )
			{
				x =ran();
			}
			/* ( 1 == i )*/
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

		/* 今回確率を出す　入った数 / 点総数 */
		konnkai =(k/m) ;  
			
			
		/* 今回確率が0か1だったら */
		if( 0 == konnkai || 1 == konnkai )
		{
			/* 差分をループさせるように変える */
			differ = 1;
		}
		
		
		/* 確率が0、1以外だったら */
		else
		{
			/* 差分を出す */
			differ = ( zennkai - konnkai);
			
			
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
	
	
	/* 差分を表示 */
	printf("差分＝%.10f\n",differ);  
	
	/* 円周率を出す */
	pi = ( 4 * konnkai );
	printf("円周率＝%f\n", pi );
		
	/* ループ回数表示 */
	printf("ループ回数＝%f\n",m);
		
		
		
		
		
		
///////////////////////////////////////////////////////////////////////////
//		 $ ./a.exe
//		 seedを入力 =>63
//		 差分＝0.0000100000
//		 円周率＝3.139881
// 		ループ回数＝21504.000000
////////////////////////////////////////////////////////////////////////////			
}