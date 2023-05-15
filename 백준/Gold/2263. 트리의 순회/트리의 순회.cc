#include <iostream>
#include <deque>
#include <vector>

using namespace std;


vector<int>inorder;
vector<int>postorder;
vector<int>preorder;

void makePreOrder(int start_in, int end_in, int start_post, int end_post);

int main() {
	int n;
	scanf("%d", &n);

	for(int i=0;i<n;i++) {
		int v;
		scanf("%d", &v);
		inorder.push_back(v);
	}
	
	for(int i=0;i<n;i++) {
		int v;
		scanf("%d", &v);
		postorder.push_back(v);
	}

	makePreOrder(0, n - 1, 0, n - 1);
	//for(int i=0;i<n;i++) printf("%d ", preorder[i]);
}

//0, n-1, postorder.back()으로 시작.
//start_i + 1, n-1, postorder.back()으로 계속 재귀
//그 밑에는 0, start_i - 1, postorder.back()으로 계속 재귀
//앗 이 반대로 해야댐
void makePreOrder(int start_in, int end_in, int start_post, int end_post)
{
	if (start_in > end_in || start_post > end_post) return;

	int curRoot = postorder[end_post];
	printf("%d ", curRoot);
	//일단 preorder에 밀어넣고,
	int curRootIndex;
	for(curRootIndex = start_in; curRootIndex <= end_in; curRootIndex++)
	{
		if (inorder[curRootIndex] == curRoot) break;
	}
	//현재 루트의 inorder인덱스를 찾고,
	//쪼갤만큼 쪼갠거면 리턴,
	int left_size = curRootIndex - start_in;
	makePreOrder(start_in, curRootIndex - 1, start_post, start_post + left_size - 1);
	makePreOrder(curRootIndex + 1, end_in, start_post + left_size, end_post - 1);
	//inorder에서 현재 루트의 왼쪽편으로 반가르고
	//돌아와서는 다시 inorder에서 현재 루트의 오른편으로 반가름
}