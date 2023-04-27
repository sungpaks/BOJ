#include <iostream>
#include <string>

using namespace std;

typedef struct list{
	int num;
	list* next;
}t_list;
void push(t_list *&stack, int x);
void pop(t_list *&stack);
void size(t_list *stack);
void empty(t_list *stack);
void top(t_list *stack);


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	t_list *stack;
	stack = nullptr;

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string in;
		cin>>in;
		if (in == "push")
		{
			int x;
			cin >> x;
			push(stack, x);
		}
		else if (in == "pop")
			pop(stack);
		else if (in == "size")
			size(stack);
		else if (in == "empty")
			empty(stack);
		else if (in == "top")
			top(stack);
	}
}

void push(t_list *&stack, int x)
{
	t_list *new_node = new t_list;
	new_node->num = x;
	new_node->next = stack;
	stack = new_node;
}
void pop(t_list *&stack)
{
	if(stack == nullptr) {
		cout<<"-1\n";
		return;
	}
	cout << stack->num <<"\n";
	t_list *tmp = stack;
	stack = stack->next;
	free(tmp);
}
void size(t_list *stack)
{
	int cnt = 0;
	while (stack!=nullptr) {
		stack=stack->next;
		cnt++;
	}
	cout << cnt << "\n";
}
void empty(t_list *stack)
{
	if (stack==nullptr) cout<< "1\n";
	else cout << "0\n";
}
void top(t_list *stack)
{
	if(stack == nullptr) {
		cout<<"-1\n";
		return;
	}
	cout << stack->num << "\n";
}