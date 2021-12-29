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

- [전위 순회(PreOrder)](../../Algorithm/Tree_Traversals/Pre_order.cpp)
    
    현재 노드→왼쪽 노드→오른쪽 노드
    
- [중위 순회(InOrder)](../../Algorithm/Tree_Traversals/In_order.cpp)
    
    왼쪽 노드→현재 노드→오른쪽 노드
    
- [후위 순회(PostOrder)](../../Algorithm/Tree_Traversals/Post_order.cpp)
    
    왼쪽 노드→오른쪽 노드→현재 노드