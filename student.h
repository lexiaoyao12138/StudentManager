#define Maxsize 100

typedef struct stu {
	int id;
	int age;
	char name[Maxsize];
}	SNode;

typedef struct node_s {
	SNode data;
	struct node_s* prev;
	struct node_s* curr;
}	Node;

Node* createNode();										// 创建一个空列表
SNode createSNode();
void update(Node* h);
void initStu(Node *head);
void desktoryNode(Node *h);									// 销毁
void push_back(Node* h, SNode stu);					// 入队 (尾插)
void pop(Node* h, SNode stu);							// 出队
void delete_id(Node* h);
void delete_name(Node* h);
// void sort(Node* h);										// 排序
Node* findStu_id(Node* h, int id);						// 查找
Node* findStu_name(Node* h, char* name);
void showAllStu(Node* h);
void printStu(Node* stu);
