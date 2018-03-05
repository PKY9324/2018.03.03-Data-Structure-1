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

	puts("오름차순 정렬 & SWAP");
	printf("배열의 크기를 입력해주세요 : ");

	scanf_s("%d", &size, sizeof(size));

	puts("");

	array = (int*)malloc(size * sizeof(int));

	printf("배열의 값을 입력해주세요 : ");

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

	printf("정렬 결과 : ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	puts("\n");
}

int printFactorial(void) {
	int x;

	printf("팩토리얼 입력 (x!) : ");

	scanf_s("%d", &x, sizeof(x));

	puts("");

	printf("팩토리얼 %d! 결과 : %d",x, factorial(x));

	puts("\n");
}

int printFibonacci(void) {
	int n;

	printf("피보나치 n번까지 : ");

	scanf_s("%d", &n, sizeof(n));

	puts("");

	printf("피보나치 %d번까지 결과 : ", n);

	for (int i = 1; i < n + 1; i++) 
	{
		printf("%d ", fibonacci(i));
	}

	puts("\n");
}

int matrixMult(void) { //2x2 행렬 곱셈
	int arrA[2][2] = { {1,2},{3,4} },
		arrB[2][2] = { {5,6},{7,8} },
		arrC[2][2] = { 0, };

	int i, j, k, sum = 0;

	puts("2x2 행렬 곱셈");

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

	puts("행렬 출력");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", arrC[i][j]);
		}
		printf("\n");
	}

}

int swap(int* arrayA, int* arrayB) { //swap함수
	int swap;

	swap = *arrayA;
	*arrayA = *arrayB;
	*arrayB = swap;
}

int factorial(int n) { //팩토리얼 재귀함수

	if (n == 1) return 1;

	return n * factorial(n - 1);
}

int fibonacci(int n) { //피보나치 재귀함수

	if (n == 0) return 0;
	
	else if (n == 1) return 1;
	
	else return fibonacci(n - 1) + fibonacci(n - 2);
}