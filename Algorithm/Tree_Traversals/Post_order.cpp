#include<iostream>
using namespace std;
class Tree {
public:
    int data;
    Tree* left, * right;
};
void PostOrder(Tree* tree) {
    if (tree != NULL) {
        PostOrder(tree->left);
        PostOrder(tree->right);
				cout << tree->data << endl;
    }
}
int main() {
    int n;
    cin >> n;
    Tree tree[101];//n이 100보다 작다
    for (int i = 1; i <= n+1;i++) {
        tree[i].data = 0;
        tree[i].left = nullptr;
        tree[i].right = nullptr;
    }
    tree[1].data = 1;
    for (int i = 0; i < n; i++) {
        int x, y;//x 부모,y 자식
        cin >> x >> y;
        tree[y].data = y;
        tree[x].left == nullptr ? tree[x].left = &tree[y] : tree[x].right = &tree[y];
    }
    PostOrder(&tree[1]);
}