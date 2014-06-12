#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для омена местами элементов
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Функция для проверка массива на упорядочность
int correct( int *arr, int N )
{
	while (--N > 0)
		if (arr[N - 1] > arr[N])
			return 0;
	return 1;
}

// Функция в которой в цикле элементы меняются местами
// Причем местами меняются случайные элементы
void shuffle( int *arr, int N )
{
	int i;
	for (i = 0; i < N; i++)	
		swap(arr + i, arr + (rand() % N));
}

// Собственно функция которая запускает весь этот бордак
void BogoSort( int *arr, int N )
{
	while (!correct(arr, N))
		shuffle(arr, N);
}

void main(){
	int N;
	int *arr;
	int i;

	setlocale(LC_ALL, "Russian"); // Включаем русскую локализацию

	printf("Введите размер массива: "); // Запрашиваем размер массива
	scanf("%d", &N);


	arr = (int *)malloc(N * sizeof(int)); // Выделяем память под наш массив

	for (i=0; i<N; i++) // Заполняем массив рандомными числами
		arr[i] = rand();

	printf("\nМассив до сортировки\n"); // Выводим изначальный, не отсортированный миссив
	for (i=0; i<N; i++)
		printf("%d ", arr[i]);

	BogoSort(arr, N); // Запускаем нами созданную функцию с сортировкой, в качесве параметров передаем ей исходный массив и количество элементов

	printf("\nМассив после сортировки\n"); // Выводим отсортированый масив
	for (i=0; i<N; i++)
		printf("%d ", arr[i]);

	getch();
}
