그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다. 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.
    
### 용어

- 노드(node)
    
    트리의 데이터가 저장되는 각 지점
    
- 간선(edge)
    
    노드들을 연결하는 선
    

### 종류

- 이진트리
    
    자식 노드가 2개밖에 없는 트리(모든 트리가 이진 트리는 아님)
    
    - 이진 탐색 트리
        
        모든 노드가 특정 순서를 따르는 속성이 있는 이진 트리
        

### [이진 트리 구현 방법](binarySearchTree.cpp)

### 탐색

- 전위 순회(PreOrder)
    
    현재 노드→왼쪽 노드→오른쪽 노드
    
    ```cpp
    #include<iostream>
    using namespace std;
    class Tree {
    public:
        int data;
        Tree* left, * right;
    };
    void preOrder(Tree* tree) {
        if (tree != NULL) {
            cout << tree->data << endl;
            preOrder(tree->left);
            preOrder(tree->right);
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
        preOrder(&tree[1]);
    }
    ```
    
- 중위 순회(InOrder)
    
    왼쪽 노드→현재 노드→오른쪽 노드
    
    ```cpp
    #include<iostream>
    using namespace std;
    class Tree {
    public:
        int data;
        Tree* left, * right;
    };
    void InOrder(Tree* tree) {
        if (tree != NULL) {
            InOrder(tree->left);
            cout << tree->data << endl;
            InOrder(tree->right);
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
        InOrder(&tree[1]);
    }
    ```
    
- 후위 순회(PostOrder)
    
    왼쪽 노드→오른쪽 노드→현재 노드
    
    ```cpp
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
    ```