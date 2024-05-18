### 트리 ( Tree ) 란

![image](https://github.com/pastjung/DataStructure/assets/87860163/ec3813c2-7c18-44b7-ba81-7e9bfe771d1b)

- 노드로 구성된 계층적 자료구조
- 최상위 노드 ( 루트 노드 ) 를 가진다
- 루트 노드는 0개 이상의 자식 노드 ( child node ) 를 갖고 있다
- 그 자식 노드 또한 0개 이상의 자식 노드를 갖고 있고, 이는 반복적으로 정의된다.

### 특징

- **싸이클 ( Cycle ) 이 존재할 수 없다.**
- **그래프 ( Graph ) 의 한 종류**이다
- 싸이클이 없는 하나의 **연결 그래프 ( Connected Graph )** 혹은 **방항성이 있는 비순환 그래프 ( Directed Acyclic Graph, DAG )** 의 한 종류이다.
- 노드의 수가 N 인 트리는 **항상 N-1 개의 간선**을 가진다 ( 즉, 간선은 항상 Vertex 의 개수 - 1 개 )
- **루트 노드**에서 **어떤 노드로 가는 경로는 유일**하다
- **임의의 두 노드 간의 경로**는 반드시 **유일한 경로**만을 가진다
- **한개의 루트 노드만이 존재**하며, 모든 자식 노드는 **한개의 부모 노드**만을 가진다
- 순회는 전위, 후위, 중위로 이루어지고 이 3가지 모두 DFS / BFS 안에 있다.

### 핵심 용어

- **노드 ( Node 혹은 Vertex : 정점 )** : 데이터를 저장하는 위치
- **간선 ( Edge )** : 노드를 연결하는 선( link, branch 라고도 부름 )
- **Root Node** : 부모가 없는 노드, 트리는 하나의 루트 노드만을 가진다.
- **단말 ( Leaf ) Node** : 자식이 없는 노드(차수가 0인 노드), '말단 노드' 또는 '잎 노드'라고도 부른다.
- **내부 ( internal ) Node** : 단말 노드가 아닌 노드
- **형제 ( Sibiling ) Node** : 같은 부모를 가지는 노드
- **부모 ( Parent ) Node** : 해당 노드의 상위에 연결된 노드
- **자식 ( Child ) Node** : 해당 노드의 하위에 연결된 노드
- **노드의 크기 ( Size )** : 자신을 포함한 모든 자손 노드의 개수
- **노드의 깊이 ( Depth )** : 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
- **노드의 레벨 ( Level )** : 트리의 특정 깊이를 가지는 노드의 집합
- **노드의 차수 ( Degree )** : 노드의 서브트리 수
- **트리의 차수 ( Degree of Tree )** : 트리의 최대 차수
- **트리의 높이(깊이) ( Height )** : 루트 노드에서 가장 깊숙이 있는 노드의 깊이
→ 즉, `max( node level )`

### **이진 트리 ( Binary Tree )**

각 노드가 최대 두 개의 자식 노드(왼쪽 자식과 오른쪽 자식)를 가지는 트리

1. **포화 이진 트리 ( Full Binary Tree )**
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/c1601ebc-9afb-4de4-ba56-866f416de796)
    
    - 모든 노드가 0개 또는 2개의 자식 노드를 가지는 이진 트리
    - 즉, 모든 내부 노드가 정확히 두 개의 자식 노드를 가진다
2. **퍼펙트 이진 트리 ( Perfect Binary Tree )**
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/51f77ebb-8d0a-452d-9058-42f50dc5c93d)
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/a6a7766c-8b7f-4434-88b1-148161b273b7)
    
    - 모든 내부 노드가 두 개의 자식 노드를 가지고, 모든 리프 노드가 동일한 깊이를 가지는 이진 트리
    - Height 가 h 인 Perfect Binary Tree 는 `2^h - 1` 개의 노드를 가진다
    - ex. height 가 4이고, 노드의 개수가 15 개
3. **완전 이진 트리 ( Complete Binary Tree )**
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/f9bfc646-1ea1-4e77-80bc-c68fd958f01c)
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/c21b3420-da7f-4110-b61d-7ae44031662c)
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/854b7bb1-6345-43a3-97bf-f69ec530b9bf)
    
    - 모든 레벨이 완전히 채워져 있으며, 마지막 레벨은 왼쪽부터 순서대로 채워진 이진 트리
    - Complete Binary Tree 구조를 그대로 사용하여 Binary Heap 데이터 구조를 만들 수 있다. 
    ( 이것이 Heap 이다 )
    - 구현에는 Array 를 사용하는 것이 일반적이다.
    - 종류
        - **이진 힙 ( Binary Heap )**
            - 주로 우선순위 큐를 구현하는데 사용
            - 모든 레벨이 완전히 채워져 있고, 마지막 레벨은 왼쪽부터 순서대로 채워진다
            - 종류
                - 최소 힙 ( Min Heap )
                    - 모든 부모 노드가 자식 노드보다 작거나 같은 값을 가지는 Heap
                - 최대 힙 ( Max Heap )
                    - 모든 부모 노드가 자식 노드보다 크거나 같은 값을 가지는 Heap
        - **이진 탐색 트리 ( Binary Search Tree, BST )**
            - 왼쪽 자식 노드의 값은 부모 노드의 값보다 작고, 오른쪽 자식 노드의 값은 부모 노드의 값보다 큰 트리
            - 삽입, 삭제, 검색 연산이 효율적으로 수행 가능
4. **균형 이진 트리 ( Balanced Binary Tree )**
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/0a081c26-595b-44bf-b6de-dce46081a920)
    
    - 왼쪽 및 오른쪽 서브트리의 높이 차이가 1 이하인 이진 트리
    - O(log N) 시간에 Insert 와 Find 를 할 수 있을 정도로 균형이 잘 잡혀있다.
    - 종류
        - AVL 트리 ( AVL Tree )
            - 각 노드의 왼쪽 서브트리와 오른쪽 서브트리의 높이 차이가 1 이하가 되도록 유지하는 트리
        - 레드-블랙 트리 ( Red - Black Tree )
            - 각 노드가 빨간색 또는 검은색을 가지며 특정 규칙에 따라 트리의 균형을 유지하는 트리
5. **비균형 이진 트리**
    - 왼쪽 또는 오른쪽 서브트리의 높이가 현저히 차이나는 트리
6. **퇴화 트리 ( Degenerate Binary Tree or Pathological Binary Tree )**
    
    ![image](https://github.com/pastjung/DataStructure/assets/87860163/b8256f45-8b05-4afa-82e9-0ea5e01c95ba)
    
    - 모든 노드가 하나의 자식 노드만을 가지는 트리
    - 이 경우 트리는 선형 구조 ( 리스트 ) 와 유사하게 된다
    - 연결 리스트 ( Linked List ) 와 성능이 동일하다

### **그 외 ( 별로 중요 X )**

- 일반 트리 ( General Tree )
- B-트리 ( B - Tree )
    - 균형을 유지하며 많은 수의 자식을 가질 수 있는 트리
        - 데이터베이스 및 파일 시스템에서 사용
        - B-트리의 변형으로 B+ 트리, B* 트리가 존재
- T-트리
- AA 트리

### 구현 방법

1. **인접 행렬 ( Adjacency Matrix ) 이용**
→ 인접한 노드를 1로 표시, 인접하지 않은 노드를 0으로 표시

![image](https://github.com/pastjung/DataStructure/assets/87860163/23ba3162-1636-4198-bf05-ff25f6fc98e0)

1. **인접 배열 ( Adjacency Array ) 이용 / 혹은 인접 리스트 ( Adjacency List )
→**  인접 리스트를 구현하기 위해서는 STL 의 Vector 를 사용하는 것이 편리하다
    - 무향 그래프인 경우
        
        ![image](https://github.com/pastjung/DataStructure/assets/87860163/faa5fd95-ddcd-4d19-a6d2-b85d3bea5a35)
        
    - 유향 그래프의 경우
        
        ![image](https://github.com/pastjung/DataStructure/assets/87860163/6abb16c2-6877-4fa5-a891-a0ef99386fbe)
        
    1. 1차원 배열에 자신의 부모 노드만 저장하는 방법
        
        ```
        // n 개의 노드를 가진 완전 이진 트리의 경우
        1. Parent(i)     : i / 2           ( if, i != 1 )
        2. leftChild(i)  : 2i              ( if, 2i <= n )
        									 왼쪽 자식 없음   ( if, 2i + 1 <= n )
        3. rightChild(i) : 2i + 1          ( if, 2i + 1 <= n )
        									 오른쪽 자식 없음 ( if, 2i + 1 > n )
        ```
        
    2. 2차원 배열에 자식 노드를 저장하는 방법 ( ex. 이진 트리의 경우 )
        
        ```
        A[i][0] = 왼쪽 자식 노드, A[i][1] : 오른쪽 자식 노드
        ```
        

### 트리의 순회 ( Tree Traversal ) 방법

**트리 순회란**

트리에 있는 모든 노드를 한 번씩만 방문하는 것을 말함

1. **중위 순회 ( Inorder Travaersal )**
    - LVR : 왼쪽 자식 방문 → 루트 방문 → 오른쪽 자식 방문
    
    ```cpp
    // 재귀(Recursive) 방식
    template <class T>
    void Tree<T>::Inorder(TreeNode<T> *currentNode) {
    	if(currentNode){
        	Inorder(currentNode->leftChild);   // 왼쪽 자식 방문
          Visit(currentNode);                // 루트 방문
          Inorder(currentNode->rightChild);  // 오른쪽 자식 방문
      }
    }
    ```
    
    ```cpp
    // non-recursive 방식
    void Tree<T>::NonrecInorder() {
    	Stack<TreeNode<T>*> s;
      TreeNode<T> *currentNode = root;
      while(1){
        while(currentNode) {                     //Move down leftChild fields
          s.Push(currentNode);
          currentNode = currentNode->leftChild;
        }
        if( s.IsEmpty() ) return;
        currentNode = s.Top; 
        s.Pop();
        Visit(currentNode);
        currentNode = currentNode->rightChild;
      }
    }
    ```
    
2. **전위 순회 ( Preorder Traversal )**
    - VLR : 루트 방문 → 왼쪽 자식 방문 → 오른쪽 자식 방문
    
    ```cpp
    template<class T>
    void Tree<T>::Preorder(TreeNode<T> *currentNode){
      if(currentNode){
        visit(currentNode);                   // 루트 방문
        Preorder(currentNode->leftChild);     // 왼쪽 자식 방문
        Preoreder(currentNode->rightChild);   // 오른쪽 자식 방문
      }
    }
    ```
    
3. **후위 순회 ( Postorder Traversal )**
    - LRV : 왼쪽 자식 방문 → 오른쪽 자식 방문 → 루트 방문
    
    ```cpp
    template<class T>
    void Tree<T>::Postorder(TreeNode<T> *currentNode){
      if(currentNode){
        Postorder(currentNode->leftChild);    // 왼쪽 자식 방문
        Postoreder(currentNode->rightChild);  // 오른쪽 자식 방문
        visit(currentNode);                   // 루트 방문
      }
    }
    ```
    

---
