#include <stdbool.h>

#define N 100

typedef struct user {
	char name[N];
	char passwd[N];
	struct user* next;
}UserNode;

UserNode* createNode_user();
UserNode* initUser();
void addUser(UserNode *h, char *name, char *pwd);
bool findUser(UserNode* h, char *name, char *pwd);         // ≤È’“
bool search(UserNode* h, char* name);
void showAll(UserNode* h);
void deleteUser(UserNode *h);
void printUser(UserNode* s);
void updateUser(UserNode* s);