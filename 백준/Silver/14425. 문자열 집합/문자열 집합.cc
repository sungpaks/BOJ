//문자열의 길이를 키값으로 매치
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)

typedef struct s_list {
	char* value;
	struct s_list* next;
}list;

list* bucketArray[502];
int m = 499;

int hashFunction(char* key) {
	int converted = 0;
	for (int i = 0;i < strlen(key);i++) {
		converted += key[i];
	}
	return converted % m + 1;
}

int findElement(char* key) {
	int v = hashFunction(key);
	list* current = bucketArray[v];
	int cnt = 1;
	while (current) {
		if (strcmp(current->value,key) == 0) return cnt;
		cnt++;
		current = current->next;
	}
	return 0;
}

void insertItem(char* key) {
	int v = hashFunction(key);
	list* new_node = (list*)malloc(sizeof(list));
	new_node->next = 0;
	//strcpy(new_node->value, key);
	new_node->value = strdup(key);
	if (!bucketArray[v]) {
		bucketArray[v] = new_node;
		return;
	}
	new_node->next = bucketArray[v];
	bucketArray[v] = new_node;
}

int removeElement(char* key) {
	int v = hashFunction(key);
	int cnt = 1;
	if (!bucketArray[v]) return 0;
	else {
		list* current = bucketArray[v];
		list* prev = 0;
		while (current) {
			if (strcmp(current->value, key) == 0) break;
			prev = current;
			current = current->next;
			cnt++;
		}
		if (!current) return 0;
		if (!prev) bucketArray[v] = bucketArray[v]->next;
		else prev->next = current->next;
		free(current);
	}
	return cnt;
}

void initBucketArray() {
	for (int i = 1;i <= m;i++) bucketArray[i] = 0;
}

void print() {
	for (int i = 1;i <= m;i++) {
		list* current = bucketArray[i];
		while (current) {
			printf(" %s", current->value);
			current = current->next;
		}
	}
	printf("\n");
}

int main() {
	initBucketArray();
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0;i < N;i++) {
		char s[501] ;
		scanf("%s", s);
		insertItem(s);
		//print();
	}
	int sum = 0;
	for (int i = 0;i < M;i++) {
		char s[501];
		scanf("%s", s);
		if (findElement(s)) {
			sum++;
		}
	}
	printf("%d", sum);
}
