#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "user.h"
#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT "user_info"

void initStu(Node* head) {
	char path[100];
	getPath(STUDENT, path);
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		printf("open failed user_info");
		exit(-1);
	}
	
	int		ch;
	//char	id[10];
	//char	age[10];
	int id = -1, age = -1;
	char	name[100];
	SNode	stu;
	Node* temp = head;

	do {
		if (fscanf(fp, "%d%d%s[^\n]", &id, &age, name) == -1) break;
		// chint(id, &stu.id);
		//chint(age, &stu.age);
		stu.id = id;
		stu.age = age;
		strcpy(stu.name, name);
		push_back(temp, stu);
	} while ((ch = getc(fp)) != EOF);

	fclose(fp);

}

void update(Node* h) {
	Node* temp = h->curr;

	char path[100];
	getPath(STUDENT, path);

	FILE* fp = fopen(path, "w+");
	if (fp == NULL) {
		printf("open user_info failed!\n");
	}

	int ch;

	while (temp != h) {
		fprintf(fp, "%d %d %s\n", temp->data.id,
								  temp->data.age,
								  temp->data.name);
		temp = temp->curr;
	}

	fclose(fp);
}

Node* createNode() {
	Node *head = (Node*)malloc(sizeof(Node));
	head->curr = head;
	return head;
}

SNode createSNode() {
	int id, age;
	char name[100];
	SNode stu;
	Myprint();
	printf("Enter stu id age name:");
	scanf("%d %d %s", &id, &age, name);
	getchar();
	stu.id = id;
	stu.age = age;
	strcpy(stu.name, name);
	return stu;
}

void desktoryNode(Node *h) {
	free(h);
}

void push_back(Node* h, SNode stu) {
	Node* temp = h;
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = stu;
	// 只有头结点
	if (temp->curr == temp) {
		temp->curr = s;
		s->prev = temp;
		s->curr = temp;
		temp->prev = s;  // 头结点连接尾结点
	}
	else {
		temp = temp->prev;   // 尾结点
		temp->curr = s;
		s->prev = temp;
		s->curr = h;
		h->prev = s;
	}
}

void pop(Node* h, SNode stu) {
	Node* temp = h;
	if (temp->curr == NULL) {
		return;
	}
	temp = temp->curr;  // 尾结点
	Node* low = temp->prev;
	free(temp);
	low->curr = h;
}

void delete_id(Node* h) {
	printf("Please Enter your want delete id:");
	int id;
	scanf("%d", &id);

	getchar();

	if (h->curr == NULL) return;

	Node* temp = h->curr;
	Node* s = (Node*)malloc(sizeof(Node));

	while (temp != h) {
		if (temp->data.id == id) {
			temp->curr->prev = temp->prev;
			temp->prev->curr = temp->curr;
			printStu(temp);
			printf("already delete successful!\n");
			free(temp);
			return;
		}
		temp = temp->curr;
	}
	printf("No id\n");
}


void delete_name(Node* h) {
	char name[100];
	scanf("%s", name);
	getchar();

	if (h->curr == NULL) return;

	Node* temp = h;
	Node* tail = h->prev;
	Node* s = (Node*)malloc(sizeof(Node));

	while (temp != tail) {
		if (strcmp(temp->data.name, name) == 0) {
			temp->curr->prev = temp->prev;
			temp->prev->curr = temp->curr;
			printStu(temp);
			printf("already delete successful!\n");
			free(temp);
			return;
		}
	}
	printf("No name\n");

}


Node* findStu_id(Node *h, int id) {
	Node* temp = h->curr;
	Node* tail = h->prev;
	while (temp != tail) {
		if (temp->data.id == id) return temp;
		temp = temp->curr;
	}
	return NULL;
}

Node* findStu_name(Node* h, char* name) {
	Node* temp = h->curr;
	Node* tail = h->prev;
	while (temp != tail) {
		if (strcmp(temp->data.name, name) == 0) return temp;
		temp = temp->curr;
	}
	return NULL;
}


void showAllStu(Node* h) {
	Node* temp = h->curr;
	while (temp != h) {
		printf("%d\t%d\t%s\n", temp->data.id,
							   temp->data.age,
			                   temp->data.name);
		temp = temp->curr;
	}
}


void printStu(Node* stu) {
	printf("%d\t%d\t%s\n", stu->data.id,
					       stu->data.age,
						   stu->data.name);
	printf("\n");
}

