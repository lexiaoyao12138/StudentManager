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

Node* createNode();										// ����һ�����б�
SNode createSNode();
void update(Node* h);
void initStu(Node *head);
void desktoryNode(Node *h);									// ����
void push_back(Node* h, SNode stu);					// ��� (β��)
void pop(Node* h, SNode stu);							// ����
void delete_id(Node* h);
void delete_name(Node* h);
// void sort(Node* h);										// ����
Node* findStu_id(Node* h, int id);						// ����
Node* findStu_name(Node* h, char* name);
void showAllStu(Node* h);
void printStu(Node* stu);
