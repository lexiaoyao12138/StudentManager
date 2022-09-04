#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define USER "user_account"


UserNode* createNode_user() {
	UserNode* head = (UserNode*)malloc(sizeof(UserNode));
	head->next = NULL;
	return head;
}

void addUser(UserNode* h, char* name, char* pwd) {
	UserNode* temp = h;
	UserNode* s = createNode_user();
	strcpy(s->name, name);
	strcpy(s->passwd, pwd);
	if (h->next == NULL) {
		h->next = s;
		return;
	}
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = s;
}


// 验证登录
bool findUser(UserNode* h, char* name, char* pwd) {
	UserNode* temp = h->next;
	while (temp) {
		if (strcmp(temp->name, name) == 0) {
			if (strcmp(temp->passwd, pwd) == 0) {
				return true;
			}
			else {
				Myprint();
				printf("Password error!\n");
				return false;
			}
		}
		temp = temp->next;
	}
	return false;
}

UserNode* initUser() {
	UserNode* head = createNode_user();
	int ch;
	char path[100];
	getPath(USER, path);

	// 读取用户名和密码
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		printf("open %s failed\n", USER);
		exit(-1);
	}

	char name[100], pwd[100];
	// 创建结点
	do {
		fscanf(fp, "%s%s\n", name, pwd);
		addUser(head, name, pwd);
	} while ((ch = getc(fp)) != EOF);


	return head;
}

void deleteUser(UserNode* h) {
	char name[100];
	printf("please enter want delete name:");
	scanf("%s", name);
	getchar();

	UserNode* temp = h->next;
	UserNode* prev = h;

	while (temp) {
		if (strcmp(temp->name, name) == 0) {
			if (temp->next == NULL) {
				temp = NULL;
				return;
			}

			prev->next = temp->next;

			free(temp);
			return;
		}

		prev = prev->next;
		temp = temp->next;
	}
	printf("no user\n");
}

void printUser(UserNode* s) {
	printf("username: %s\t password: %s\n", s->name, s->passwd);
}

bool search(UserNode* h, char* name) {
	UserNode* temp = h->next;
	while (temp) {
		if (strcmp(temp->name, name) == 0) {
			printUser(temp);
			return true;
		}
		
		temp = temp->next;
	}
	return false;
}

void showAll(UserNode* h) {
	UserNode* temp = h->next;
	
	while (temp) {
		printf("%s\t%s\n", temp->name, temp->passwd);
	}
}


void updateUser(UserNode *h) {
	UserNode* temp = h->next;

	char path[100];
	getPath(USER, path);

	FILE* fp = fopen(path, "w+");
	if (fp == NULL) {
		printf("open user_account failed!");
		exit(-1);
	}
	
	while (temp) {
		fprintf(fp, "%s %s\n", temp->name, temp->passwd);
		temp = temp->next;
	}

	fclose(fp);
}
