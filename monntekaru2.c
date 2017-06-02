#include <stdio.h>


void main()
{
	int m=0;				/* ループ回数をカウントする変数 */
	double estab1=0;		/*確率*/
	double estab2=0;		/*確率*/
	double differ=0;  		/*差分*/
	double pi=0;			/*円周率*/
	
	/* 確率2が0と1の時ループ */
	while( (0 == estab2) || (1 == estab2) )
	{
		/* 差分リセット */
		differ = 1;
		
		/* 差分が範囲外の間ループ */
		while( 0.00001 <= differ )
		{
			/* ループ回数カウント */
			m++;
			
			
			
			
			
			
			/* 差分を出す */
			differ = estab1 - estab2;
			if( 0 > differ )
			{
				differ  = (differ * -1 );
		}
		
	}
	
	/* 差分が範囲内　且つ　確率は0と1以外になりました */
	
	
	/* 円周率を出す */
	pi = ( 4 * estab2 );
	printf("円周率＝", pi );
		
	/* ループ回数表示 */
	printf("ループ回数＝%d\n", m );
		
			
}