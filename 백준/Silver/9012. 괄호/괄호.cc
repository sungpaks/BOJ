#include <iostream>
using namespace std;

typedef struct list {
	char c;
	struct list *next;
}t_list;

void push(t_list *&stack, char x);
int pop(t_list *&stack);

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		t_list *stack = nullptr;
		char x[51];
		scanf("%s", x);
		int j=0;
		while (x[j])
		{	
			if (x[j] == '(') push(stack, x[j]);
			else if (x[j] == ')') {
				int tmp = pop(stack);
				if (tmp == -1) break;
			}
			j++;
		}
		if (x[j] == 0 && stack == nullptr) printf("YES\n");
		else printf("NO\n");
	}
}

void push(t_list *&stack, char x)
{
	t_list *new_node = new t_list;
	new_node->c = x;
	new_node->next = stack;
	stack = new_node;
}
int pop(t_list *&stack)
{
	if (stack == nullptr) return -1;
	t_list *tmp = stack;
	stack = stack->next;
	free(tmp);
	return 0;
}