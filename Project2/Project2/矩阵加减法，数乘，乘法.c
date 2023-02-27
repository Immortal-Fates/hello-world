#include<stdio.h>


void matrix_multiplication(void);
void matrix_addition(choice);
void matrix_scalar_multiplication(void);
void menu(void);
struct {
	double matrix[20][20];
	int matrix_row;
	int matrix_column;
}group[100];


int number = 0;    //��¼�ܹ��ж��ٸ������� 

int main()
{
	int choice = 1;
	int i, j;
	printf("������Ҫ����ľ���ĸ����� \n");
	scanf("%d", &i);
	number += i;						//number����i�� 
	for (j = 0; j < i; j++)				//j��Ϊi 
	{
		printf("��������Ҫ����ĵ�%d�������������������\n", j + 1);
		scanf("%d%d", &group[j].matrix_row, &group[j].matrix_column);
		printf("�������%d��������к��У��м��ÿո��������\n", j + 1);
		int m, n;
		for (m = 0; m < group[j].matrix_row; m++)
		{
			for (n = 0; n < group[j].matrix_column; n++)
			{
				scanf("%lf", &group[j].matrix[m][n]);

			}
		}

	}
	int choose;
menu:
	menu();
	scanf("%d", &choose);
	switch (choose) {
	case 1:choice = 1, matrix_addition(choice); break;
	case 2:choice = -1, matrix_addition(choice); break;
	case 3:matrix_multiplication(); break;
	case 4:matrix_scalar_multiplication(); break;
	case 0:break;
	default:printf("����ָ���ȷ!����������"); break;
	}
	if (choose != 0)
	{
		goto menu;
	}

end:
	return 0;
}

void menu(void)
{
	printf("[1]�������ӷ�\n");
	printf("[2]����������\n");
	printf("[3]�������˷�\n");
	printf("[4]�����������\n");
	printf("[0]�����˳�\n");
	printf("���������ѡ��");



}
void matrix_multiplication(void)
{
	int i, j, m, n, k;
	printf("��ѡ����Ҫ���г˷�����������");
	scanf("%d%d", &i, &j);
	i = i - 1; j = j - 1;
	if (group[i].matrix_column != group[j].matrix_row)
	{
		printf("���������������");
	}
	else {
		for (m = 0; m < group[i].matrix_row; m++)
		{
			for (n = 0; n < group[j].matrix_column; n++)
			{
				for (k = 0; k < group[i].matrix_column; k++)
				{
					group[number].matrix[m][n] += group[i].matrix[i][k] * group[j].matrix[k][j];    //����˷���Ҫ����ѭ�������� 
				}
				printf("%.3f\t", group[number].matrix[m][n]);
			}
			printf("\n");													//ÿ���һ�к�Ҫ�ǵû��� 
		}
		group[number].matrix_row = group[i].matrix_row;
		group[number].matrix_column = group[j].matrix_column;
		printf("����ĳ˷��Ѿ��������ڵ�%d��������\n", ++number); 	      //ÿ��number��Ҫ��1 
	}
}

void matrix_addition(choice)
{
	int i, j, m, n, k;
	printf("��ѡ����Ҫ���г˷�����������");
	scanf("%d%d", &i, &j);
	i = i - 1;
	j = j - 1;
	if (group[i].matrix_row != group[j].matrix_row || group[i].matrix_column != group[j].matrix_column)
	{
		printf("��������������Ӽ���");

	}
	else {
		for (m = 0; m < group[i].matrix_row; m++)
		{
			for (n = 0; n < group[j].matrix_column; n++)
			{
				group[number].matrix[m][n] = group[i].matrix[m][n] + choice * group[j].matrix[m][n];
				printf("%.3f\t", group[number].matrix[m][n]);
			}
			printf("\n");
		}
		group[number].matrix_row = group[i].matrix_row;
		group[number].matrix_column = group[j].matrix_column;
		printf("����ļӼ����Ѿ��������ڵ�%d��������\n", ++number);
	}

}
void matrix_scalar_multiplication(void)
{
	int i, j, m, n, num;
	printf("��������Ҫ�������˵ľ���");
	scanf("%d", &i);
	i = i - 1;
	printf("��������Ҫ�������˵�����");
	scanf("%d", &num);
	for (m = 0; m < group[i].matrix_row; m++)
	{
		for (n = 0; n < group[i].matrix_column; n++)
		{
			group[number].matrix[m][n] = num * group[i].matrix[m][n];
			printf("%.3f\t", group[number].matrix[m][n]);
		}
		printf("\n");
	}
	group[number].matrix_row = group[i].matrix_row;
	group[number].matrix_column = group[i].matrix_column;
	printf("����������Ѿ��������ڵ�%d��������\n", ++number);
}