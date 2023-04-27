#include <iostream>
using namespace std;

typedef struct list {
	int n;
	struct list *next;
}t_list;

void push(t_list *&stack, int x);
void pop(t_list *&stack);
void getSum(t_list *stack);

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	t_list *stack = nullptr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if (x == 0) pop(stack);
		else push(stack, x);
	}
	getSum(stack);
}

void push(t_list *&stack, int x)
{
	t_list *new_node = new t_list;
	new_node->n = x;
	new_node->next = stack;
	stack = new_node;
}
void pop(t_list *&stack)
{
	t_list *tmp = stack;
	stack = stack->next;
	free(tmp);
}
void getSum(t_list *stack)
{
	long long result = 0;
	while (stack!=nullptr)
	{
		result += stack->n;
		stack = stack->next;
	}
	cout << result;
}