### Node 란

![image](https://github.com/pastjung/DataStructure/assets/87860163/577b0dd5-dd04-4548-b177-c3823ae9c04f)


### 단일 연결 리스트( Singly Linked List ) 란

![image](https://github.com/pastjung/DataStructure/assets/87860163/5cd92614-efca-41dd-9500-c219adfa8dd7)


- 각 요소가 데이터와 다음 요소를 참조(링크)하는 정보를 포함하는 노드로 구성
- 데이터의 **동적 추가, 삭제에 효율적**
 - 노드를 추가/삭제 후 연결 정보만 수정해주면 되기 때문에 **O(1) 시간**이 걸림
- **특정 위치의 노드를 검색**하는 것은 상대적으로 **비효율적**
 - 처음부터 차례대로 접근해야 하기 때문에 **최악의 경우** **O(n) 시간**이 걸림

### **핵심 개념**

1. **노드(Node)**: 링크드 리스트의 기본 단위로서, 데이터를 저장하는 *데이터 필드* 와 다음 노드를 가리키는 *링크 필드* 로 구성
2. **포인터**:각 노드 안에서, 다음이나 이전의 노드와의 연결 정보를 가지고 있는 공간
3. **헤드(Head)**: 링크드 리스트에서 가장 처음 위치하는 노드를 가리킨다. 리스트 전체를 참조하는데 사용
4. **테일(Tail)**: 링크드 리스트에서 가장 마지막 위치하는 노드를 가리킨다. 이 노드의 링크 필드는 Null을 가리킨다

### 시간 복잡도

| 자료구조 | 검색 (값) | 추가 (add) | 삭제 (delete) |
| --- | --- | --- | --- |
| 연결 리스트 (Linked List) | O(n) | O(1) | O(1) |

### 장점

1. **동적 크기**
 - 미리 데이터의 크기를 지정할 필요가 없다.
 - 런타임 중에도 데이터를 추가하거나 삭제하는 것이 가능
 - 반면, 배열은 미리 데이터의 크기를 지정해야만 한다.
2. **효율적인 메모리 사용 ( 동적인 메모리 크기 )**
 - 노드가 메모리의 어디서든 위치할 수 있기 때문에 메모리를 효율적으로 활용할 수 있다.
 - 반면, 배열은 연속적인 메모리 공간을 필요로 하기 때문에, 크기를 변경하려면 메모리를 재배치해야 할 수도 있다.
3. **데이터 삽입 및 삭제에 용이하고 효율적**
 - 특정 노드의 참조만 변경하면 되므로 노드 삽입/삭제 과정이 간단하다
 - 반면, 배열의 경우 삽입/삭제 후 데이터를 재배치해야 하므로 더 많은 시간이 소요될 수 있다.
 - 즉, 배열처럼 구조의 재구성이 필요 없다

### 단점

1. **직접 접근 불가능 ( 비효율적인 검색 )**
 - 특정 인덱스의 요소에 접근하려면 처음부터 해당 인덱스까지 순차적으로 이동해야 한다
 - 반면, 배열은 인덱스를 이용한 직접적인 데이터 접근이 가능하다
2. **메모리 오버헤드**
 - 각 노드는 데이터 필드와 함께 링크(참조) 필드를 가지고 있어야 하므로 추가적인 메모리를 사용하게 된다.
 - 연결 리스트는 배열에 비해 메모리 오버헤드가 크다고 볼 수 있다.
3. **역방향 탐색의 어려움**
 - 일반적으로 단방향 연결 리스트에서는 노드들이 다음 노드만을 참조하므로, 역방향으로 탐색하는 것이 어렵다.
 - 해당 문제는 이중 연결 리스트를 사용하면 해결할 수 있지만, 또 다른 메모리 오버헤드가 발생하게 되는 문제가 발생한다.
4. **복잡한 구현**
 - 배열에 비해 구현이 복잡하다.
 - 특히 노드 삽입/삭제 시 링크를 정확히 관리해야 하므로 버그가 발생할 가능성이 높다.

### 사용

- 메모리 크기가 정해져 있지 않을 때 사용
- 데이터를 연속적으로 빠르게 삽입 / 제거가 필요할 때 사용
- ex. 이미지 뷰어, 갤러리, 음악 플레이어 등

### 구현 방법

```cpp
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	String element;
	Node* nextNode;
	friend class LinkedList;
};
```

```cpp
class LinkedList {
private:
	StringNode* head;
	StringNode* tail;
	
public:
	StringLinkedList();
	~StringLinkedList();
	
	bool empty() const;
	Elem front() const;
	void addFront(const String& element);
	void removeFront();
	void addBack(const String& element);
	void removeBack();
};
```

### 이중 연결 리스트( Doubly Linked List )

![image](https://github.com/pastjung/DataStructure/assets/87860163/b1e45719-d5b3-4b5c-a8b2-c1960af5c778)

- 연결 리스트의 확장 개념
- 각 노드가 이전 노드와 다음 노드를 모두 참조

### 구현 방법

```cpp
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	String element;
	Node* leftNode;
	Node* rightNode;
	friend class LinkedList;
};
```

```cpp
class LinkedList {
private:
	StringNode* head;
	StringNode* tail;
	
public:
	StringLinkedList();
	~StringLinkedList();
	
	bool empty() const;
	Elem front() const;
	void addFront(const String& element);
	void removeFront();
	void addBack(const String& element);
	void removeBack();
};
```

### 원형 연결 리스트( Circular Linked List )

![image](https://github.com/pastjung/DataStructure/assets/87860163/8f369e13-0ca6-4606-b222-d24ed21495d5)

- 연결 리스트의 확장 개념
- 마지막 노드가 처음 노드를 참조
