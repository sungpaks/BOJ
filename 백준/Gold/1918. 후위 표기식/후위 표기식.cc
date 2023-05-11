#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
	char elem;
	struct stack *next;
}stack;

void push(char c);
char pop();
void conversion(char s[]);
stack *top = NULL;
int op_check(char c);

int main()
{
	char s[101] = {0};
	scanf("%s", s);
	conversion(s);
}

void conversion(char s[])
{
	int flag = 0;
	int i = 0;
	while (s[i])
	{ //우선순위가 top보다 큰게 나오면 그냥 push,
	//우선순위가 top보다 작거나 같으면 top보다 우선순위 클 때까지 pop함
		if ('A' <= s[i] && s[i] <= 'Z') printf("%c", s[i]);
		else if ((i==0 || op_check(s[i-1])) && \
		(!op_check(s[i+1])) && \
		(s[i] == '-' || s[i] == '+'))
		{
			if (s[i] == '-') push('n');
			else if (s[i] == '+') push('p');
		}
		else if (s[i] == '(') 
		{
			push(s[i]);
			if (s[i+1] == '|' || s[i+1] == '&') push(s[++i]);
		}
		//왼쪽 괄호가 나오면 스택에 넣고, 이후 연산 우선순위로 이용
		else if (s[i] == ')') 
		{
			while (top->elem != '(')
				printf("%c", pop());
			pop();
		}
		else if (top == NULL && op_check(s[i]))
		{
			push(s[i]);
			if (s[i+1] == '|' || s[i+1] == '&') push(s[++i]);
		}
		else if (0 < op_check(s[i]) && op_check(s[i]) <= op_check(top->elem))
		{
			while (top != NULL && op_check(s[i]) <= op_check(top->elem) && top->elem != '(')
				printf("%c", pop());
			push(s[i]);
			if (s[i+1] == '|' || s[i+1] == '&') push(s[++i]);
		}
		else if (op_check(s[i]) > op_check(top->elem))
		{
			push(s[i]);
			if (s[i+1] == '|' || s[i+1] == '&') push(s[++i]);
		}
		i++;
	}
	while (top != NULL) printf("%c", pop());
	printf("\n");
}

int op_check(char c)
{
	if (c == '!' || c == 'n' || c == 'p') return 6;
	else if (c == '*' || c == '/') return 5; 
	else if (c == '-' || c == '+') return 4;
	else if (c == '<' || c == '>') return 3;
	else if (c == '&') return 2;
	else if (c == '|') return 1;
	else return 0;
}

void push(char c)
{
	stack *new_node;
	new_node = (stack *)malloc(sizeof(stack));
	new_node->elem = c;
	if (top == 0) new_node->next = NULL;
	else new_node->next = top;
	top = new_node;
}
char pop()
{
	if (top == 0) return 0;
	char return_value = top->elem;
	stack *tmp = top;
	top = top->next;
	free(tmp);
	if (return_value == 'p') return_value = '+';
	else if (return_value == 'n') return_value = '-';
	return return_value;
}