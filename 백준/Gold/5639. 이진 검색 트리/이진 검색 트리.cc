#include <iostream>

using namespace std;

typedef struct t_list {
	int value;
	struct t_list *leftChild;
	struct t_list *rightChild;
}t_list;

void insertNode(int v, t_list * &current);
void postOrder(t_list * &current);

int main(){
	//ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	t_list *tree = new t_list;
	tree->leftChild = nullptr;
	tree->rightChild = nullptr;
	tree->value = 0;

	int v;
	while (scanf("%d", &v) != EOF) {
		if (v == EOF) break;
		insertNode(v, tree);
	}
	postOrder(tree);
}

void insertNode(int v, t_list * &current)
{
	t_list *root = current;
	t_list *new_node = new t_list;
	new_node->leftChild = nullptr;
	new_node->rightChild = nullptr;
	new_node->value = v;
	
	if (current->value == 0) {
		current = new_node;
		return;
	}
	while (current != nullptr) {
		if (current->value > v) {
			if (current->leftChild == nullptr) {
				current->leftChild = new_node;
				break;
			}
			else current = current->leftChild;
		}
		else if (current->value < v) {
			if (current->rightChild == nullptr) {
				current->rightChild = new_node;
				break;
			}
			else current = current->rightChild;
		}
	}
	current = root;
}

void postOrder(t_list * &current)
{
	if (current->leftChild != nullptr) postOrder(current->leftChild);
	if (current->rightChild != nullptr) postOrder(current->rightChild);
	cout << current->value << "\n";
}