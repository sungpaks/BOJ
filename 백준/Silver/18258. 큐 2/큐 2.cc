#include <iostream>
#include <string>

using namespace std;

class node{
public:
	int elem;
	node *next;
	node *prev;
	
	node(int n)
	{
		this->elem = n;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class MyQueue {
public:
	node *head;
	node *tail;
	int size;
	MyQueue() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	} //head가 들어가는 곳, tail이 나오는 곳
	void push(int x){
		size++;
		node *new_node = new node(x);
		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			new_node->next->prev = new_node;
			head = new_node;
		}
	}
	void pop(){
		if (tail == nullptr)
		{
			cout << "-1\n";
			return;
		}
		size--;
		cout << tail->elem << "\n";
		if (tail == head)
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			node *tmp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete tmp;
		}
	}
	void getSize() { cout << this->size << "\n"; }
	void empty() {
		if (this->size == 0) cout << "1\n";
		else cout << "0\n";
	}
	void front() {
		if (tail == nullptr) cout << "-1\n";
		else cout << tail->elem << "\n";
	}
	void back() {
		if (head == nullptr) cout << "-1\n";
		else cout << head->elem << "\n";
	}
};


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	MyQueue q;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if (s == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") q.pop();
		else if (s == "size") q.getSize();
		else if (s == "empty") q.empty();
		else if (s == "front") q.front();
		else if (s == "back") q.back();
	}
}