#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
/*
0번은 비운다 --> 연산의 용이성땜시
1번 : 제일 위 (루트)
2,3번 : 루트의 자식 노드
...
i번째의 부모 노드 = i/2
i번째의 왼쪽 자식 노드 2*i
i번째의 오른쪽 자식 노드 2*i+1
*/

int heap[100001];
int n = 0;
void insert(int item);
void pop();
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		int o;
		scanf("%d", &o);
		if (o == 0) pop();
		else insert(o);
	}
}

void insert(int item)
{
	int i = ++n;
	heap[i] = item;
	while(i > 1)
	{
		if (heap[i] > heap[i/2]) 
		{
			swap(&heap[i],&heap[i/2]);
			i = i/2;
		}
		else break;
	}
	//i번째가 자신의 부모인 i/2보다 큼?? ==> 자리 바꾸기
	//그게 아니면? 알맞은 자리임 ==> 반복 끝
	//i가 1이 될 때까지 반복
}

void pop()
{
	if (n == 0)
	{
		printf("0\n");
		return;
	}
	printf("%d\n", heap[1]);
	heap[1] = heap[n];
	heap[n] = 0;
	n--;
	//맨 위를 출력하고, heap의 막내를 맨 위로 올린다
	int i = 1;
	int j = 2 * i;
	while (j <= n) //맨 위로 올라온 놈의 제자리를 찾는 과정
	{
		if (heap[j] < heap[j+1]) j++; 
		if (heap[j] > heap[i])
		{
			swap(&heap[i], &heap[j]);
			i = j;
			j = i * 2;
		}
		else break;
	}
	//swap(&heap[1], &heap[i]);
	//두 자식 중 큰 놈의 위치 j
	//heap[j]보다 heap[i]가 작으면 교체
	//i가 n보다 커질 때까지 반복
}