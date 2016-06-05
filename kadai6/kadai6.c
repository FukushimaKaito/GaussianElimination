/*------------------------------------------------
課題6　ガウスの消去法
4I31　福嶋開人
2014/11/17
------------------------------------------------*/

#include <stdio.h>
#include <math.h>

//3変数連立1次方程式
#define n 3

/*拡張係数行列*/
double a[3][n + 1] = {
	{ 3, 3, 1, 10 },
	{ 2, 4, -1, 7 },
	{ 1, 1, 5, 18 }
};

/*グローバル変数*/
int i, j, k;
double p;

/*		ピボット選択	*/
void pibot(void)
{
	int w;
	int l = k;
	p = a[k][k];
	for (j = k + 1; j <= n - 1; j++){
		if (fabs(p) < fabs(a[j][k])){
			l = j;
			p = a[j][k];
		}

	}
	if (l != k){
		for (j = k; j <= n; j++){
			w = a[k][j];
			a[k][j] = a[l][j];
			a[l][j] = w;
		}

	}
}

/*		前進消去	*/
void zensin(void)
{
	for (k = 0; k <= n - 1; k++)
	{
		pibot();
		for (j = k + 1; j <= n; j++){
			a[k][j] = a[k][j] / p;
		}
		for (i = k + 1; i <= n - 1; i++){
			for (j = k + 1; j <= n; j++){
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		}
	}
}

/*		後退代入	*/
void koutai(void)
{
	for (k = n - 2; k >= 0; k--){
		for (i = k + 1; i <= n - 1; i++){
			a[k][n] = a[k][n] - a[k][i] * a[i][n];
		}
	}
}

/*		main関数	*/
int main(void)
{
	printf("課題6　ガウスの消去法\n");
	printf("元の拡張係数行列です．\n");
	//行列表示
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < n + 1; v++)
		{
			printf("%2.3lf	", a[u][v]);
		}
		printf("\n");
	}
	printf("\n");

	zensin();//前進消去
	koutai();//後退代入

	printf("ガウスの消去法を適用した答えです．\n");
	printf("x = %lf\n", a[0][n]);
	printf("y = %lf\n", a[1][n]);
	printf("z = %lf\n", a[2][n]);
	getch();

	return 0;
}