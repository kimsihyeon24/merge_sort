#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;
int move_count = 0;
int compare_count = 0;

int sorted[MAX_SIZE]; // 추가 공간이 필요
// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		compare_count++;
		if (list[i] <= list[j]) { 
			sorted[k++] = list[i++]; 
		}
		else {
			sorted[k++] = list[j++]; 
		}
	}

	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++) 
			sorted[k++] = list[l];
			
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++) 
			sorted[k++] = list[l];
			
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		move_count++;
	}
	
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		
		merge(list, left, mid, right);    // 합병
		for (int i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	}
	
}



int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (int a = 0; a < 20; a++) {
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		}
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		}
		printf("\nOriginal List %d\n", a + 1);
		for (i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n\n");

		merge_sort(list, 0, n-1);
		
	}
	printf("Average Move Count : %d\n", move_count / 20); // 이동횟수 출력
	printf("Average Compare Count : %d\n", compare_count / 20); // 비교횟수 출력
	
}