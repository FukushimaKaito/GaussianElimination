/*------------------------------------------------
�ۑ�6�@�K�E�X�̏����@
4I31�@�����J�l
2014/11/17
------------------------------------------------*/

#include <stdio.h>
#include <math.h>

//3�ϐ��A��1��������
#define n 3

/*�g���W���s��*/
double a[3][n + 1] = {
	{ 3, 3, 1, 10 },
	{ 2, 4, -1, 7 },
	{ 1, 1, 5, 18 }
};

/*�O���[�o���ϐ�*/
int i, j, k;
double p;

/*		�s�{�b�g�I��	*/
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

/*		�O�i����	*/
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

/*		��ޑ��	*/
void koutai(void)
{
	for (k = n - 2; k >= 0; k--){
		for (i = k + 1; i <= n - 1; i++){
			a[k][n] = a[k][n] - a[k][i] * a[i][n];
		}
	}
}

/*		main�֐�	*/
int main(void)
{
	printf("�ۑ�6�@�K�E�X�̏����@\n");
	printf("���̊g���W���s��ł��D\n");
	//�s��\��
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < n + 1; v++)
		{
			printf("%2.3lf	", a[u][v]);
		}
		printf("\n");
	}
	printf("\n");

	zensin();//�O�i����
	koutai();//��ޑ��

	printf("�K�E�X�̏����@��K�p���������ł��D\n");
	printf("x = %lf\n", a[0][n]);
	printf("y = %lf\n", a[1][n]);
	printf("z = %lf\n", a[2][n]);
	getch();

	return 0;
}