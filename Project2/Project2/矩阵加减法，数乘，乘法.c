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


int number = 0;    //记录总共有多少个矩阵了 

int main()
{
	int choice = 1;
	int i, j;
	printf("输入你要输入的矩阵的个数： \n");
	scanf("%d", &i);
	number += i;						//number多了i个 
	for (j = 0; j < i; j++)				//j变为i 
	{
		printf("请输入你要输入的第%d个矩阵的行数和列数：\n", j + 1);
		scanf("%d%d", &group[j].matrix_row, &group[j].matrix_column);
		printf("请输入第%d个矩阵的行和列（中间用空格隔开）：\n", j + 1);
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
	default:printf("输入指令不正确!请重新输入"); break;
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
	printf("[1]代表矩阵加法\n");
	printf("[2]代表矩阵减法\n");
	printf("[3]代表矩阵乘法\n");
	printf("[4]代表矩阵数乘\n");
	printf("[0]代表退出\n");
	printf("请输入你的选择：");



}
void matrix_multiplication(void)
{
	int i, j, m, n, k;
	printf("请选择你要进行乘法的两个矩阵：");
	scanf("%d%d", &i, &j);
	i = i - 1; j = j - 1;
	if (group[i].matrix_column != group[j].matrix_row)
	{
		printf("这两个矩阵不能相乘");
	}
	else {
		for (m = 0; m < group[i].matrix_row; m++)
		{
			for (n = 0; n < group[j].matrix_column; n++)
			{
				for (k = 0; k < group[i].matrix_column; k++)
				{
					group[number].matrix[m][n] += group[i].matrix[i][k] * group[j].matrix[k][j];    //矩阵乘法需要三重循环别搞混了 
				}
				printf("%.3f\t", group[number].matrix[m][n]);
			}
			printf("\n");													//每输出一行后都要记得换行 
		}
		group[number].matrix_row = group[i].matrix_row;
		group[number].matrix_column = group[j].matrix_column;
		printf("矩阵的乘法已经被存贮在第%d个矩阵中\n", ++number); 	      //每次number都要＋1 
	}
}

void matrix_addition(choice)
{
	int i, j, m, n, k;
	printf("请选择你要进行乘法的两个矩阵：");
	scanf("%d%d", &i, &j);
	i = i - 1;
	j = j - 1;
	if (group[i].matrix_row != group[j].matrix_row || group[i].matrix_column != group[j].matrix_column)
	{
		printf("这两个矩阵不能相加减！");

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
		printf("矩阵的加减法已经被存贮在第%d个矩阵中\n", ++number);
	}

}
void matrix_scalar_multiplication(void)
{
	int i, j, m, n, num;
	printf("请输入你要进行数乘的矩阵：");
	scanf("%d", &i);
	i = i - 1;
	printf("请输入你要进行数乘的数：");
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
	printf("矩阵的数乘已经被存贮在第%d个矩阵中\n", ++number);
}