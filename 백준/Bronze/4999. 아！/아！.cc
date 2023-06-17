#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main () {
	char first[1001]={0};
	char second[1001]={0};
	scanf("%s\n%s", first, second);
	if (strlen(first) < strlen(second))printf("no");
	else printf("go");
}