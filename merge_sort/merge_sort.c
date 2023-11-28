#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;
int move_count = 0;
int compare_count = 0;

int sorted[MAX_SIZE]; // �߰� ������ �ʿ�
// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		compare_count++;
		if (list[i] <= list[j]) { 
			sorted[k++] = list[i++]; 
		}
		else {
			sorted[k++] = list[j++]; 
		}
	}

	if (i > mid) 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++) 
			sorted[k++] = list[l];
			
	else 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++) 
			sorted[k++] = list[l];
			
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
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
		mid = (left + right) / 2;              // ����Ʈ�� �յ����
		merge_sort(list, left, mid);     // �κи���Ʈ ����
		merge_sort(list, mid + 1, right);//�κи���Ʈ ����
		
		merge(list, left, mid, right);    // �պ�
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
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		}
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		}
		printf("\nOriginal List %d\n", a + 1);
		for (i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n\n");

		merge_sort(list, 0, n-1);
		
	}
	printf("Average Move Count : %d\n", move_count / 20); // �̵�Ƚ�� ���
	printf("Average Compare Count : %d\n", compare_count / 20); // ��Ƚ�� ���
	
}