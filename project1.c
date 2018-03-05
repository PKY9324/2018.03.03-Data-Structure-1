#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int SortAndSwap(void);
int swap(int* arrayA, int* arrayB);
int printFactorial(void);
int factorial(int n);
int printFibonacci(void);
int fibonacci(int n);
int matrixMult(void);

int main() {

	SortAndSwap();
	printFactorial();
	printFibonacci();
	matrixMult();

	system("pause");
}

int SortAndSwap(void) {
	int *array;
	int size, min, i = 0, j = 0;

	puts("�������� ���� & SWAP");
	printf("�迭�� ũ�⸦ �Է����ּ��� : ");

	scanf_s("%d", &size, sizeof(size));

	puts("");

	array = (int*)malloc(size * sizeof(int));

	printf("�迭�� ���� �Է����ּ��� : ");

	for (int i = 0; i < size; i++) 
	{
		scanf_s("%d", &array[i], sizeof(array[i]));
	}

	puts("");

	//SORT
	for (i = 0; i < size - 1; i++) 
	{
		min = i;
		for (j = i + 1; j < size; j++) 
		{
			if (array[j] < array[min]) 
			{
				min = j;
			}
		}
		//SWAP
		swap(&array[i], &array[min]);
	}

	printf("���� ��� : ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	puts("\n");
}

int printFactorial(void) {
	int x;

	printf("���丮�� �Է� (x!) : ");

	scanf_s("%d", &x, sizeof(x));

	puts("");

	printf("���丮�� %d! ��� : %d",x, factorial(x));

	puts("\n");
}

int printFibonacci(void) {
	int n;

	printf("�Ǻ���ġ n������ : ");

	scanf_s("%d", &n, sizeof(n));

	puts("");

	printf("�Ǻ���ġ %d������ ��� : ", n);

	for (int i = 1; i < n + 1; i++) 
	{
		printf("%d ", fibonacci(i));
	}

	puts("\n");
}

int matrixMult(void) { //2x2 ��� ����
	int arrA[2][2] = { {1,2},{3,4} },
		arrB[2][2] = { {5,6},{7,8} },
		arrC[2][2] = { 0, };

	int i, j, k, sum = 0;

	puts("2x2 ��� ����");

	for (i = 0; i < 2; i++)
	{
		for (k = 0; k < 2; k++)
		{
			sum = 0;
			for (j = 0; j < 2; j++)
			{
				sum += arrA[i][j] * arrB[j][k];
			}
			arrC[i][k] = sum;
		}
	}

	puts("��� ���");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", arrC[i][j]);
		}
		printf("\n");
	}

}

int swap(int* arrayA, int* arrayB) { //swap�Լ�
	int swap;

	swap = *arrayA;
	*arrayA = *arrayB;
	*arrayB = swap;
}

int factorial(int n) { //���丮�� ����Լ�

	if (n == 1) return 1;

	return n * factorial(n - 1);
}

int fibonacci(int n) { //�Ǻ���ġ ����Լ�

	if (n == 0) return 0;
	
	else if (n == 1) return 1;
	
	else return fibonacci(n - 1) + fibonacci(n - 2);
}