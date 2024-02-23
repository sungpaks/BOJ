#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node{
    int number, x, y;
}node;
typedef struct vertex{
    int number, x, y;
    struct vertex *right;
    struct vertex *left;
}vertex;

vector<node> nodes;
vertex *root;
vertex *getNewVertex(int number, int x, int y) {
    vertex *newVertex = new vertex;
    newVertex->number = number;
    newVertex->x = x;
    newVertex->y = y;
    newVertex->right = NULL;
    newVertex->left = NULL;
    return newVertex;
}

bool compare(node a, node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void make_tree(vertex *parent, vertex *child) {
    if (parent->x > child->x) {
        if (parent->left == NULL) {
            parent->left = child;
        }
        else {
            make_tree(parent->left, child);
        }
    }
    else {
        if (parent->right == NULL) {
            parent->right = child;
        }
        else {
            make_tree(parent->right, child);
        }
    }
}

vector<int>pre;
vector<int>post;
void preorder(vertex *cur) {
    if (!cur) return;
    pre.push_back(cur->number);
    preorder(cur->left);
    preorder(cur->right);
}
void postorder(vertex *cur) {
    if (!cur) return;
    postorder(cur->left);
    postorder(cur->right);
    post.push_back(cur->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0;i<nodeinfo.size();i++) {
        nodes.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(nodes.begin(), nodes.end(), compare);
    
    root = getNewVertex(nodes[0].number, nodes[0].x, nodes[0].y);
    for(int i=1;i<nodes.size();i++) {
        vertex *cur = getNewVertex(nodes[i].number, nodes[i].x, nodes[i].y);
        make_tree(root, cur);
    }
    preorder(root);
    postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}