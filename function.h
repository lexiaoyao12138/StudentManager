#define  _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "user.h"
#include "public.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getLoginInfo(UserNode *head) {
	// 管理员
	char* admin = "admin";
	char name[100];
	char pwd[100];
	Myprint();
	printf("Enter name:");
	scanf("%s", name);  getchar();
	Myprint();
	printf("Enter password:");
	scanf("%s", pwd); getchar();
	if (findUser(head, name, pwd)) {
		if (strcmp(name, admin) == 0)  return 0;
		else						return 1;
	}
	else {
		return -1;
	}
}




void Case1(Node *h_stu, Node *temp, int* flag_1, char *name) {
	Myprint();
	printf("1. id  2. name\n");
	printf("plesee enter:");
	scanf("%d", flag_1);
	getchar();
	switch (*flag_1) {
	case 1:
		Myprint();
		printf("enter want to search id:");

		scanf("%d", flag_1);
		temp = findStu_id(h_stu, *flag_1);
		if (temp != NULL) {
			// printf("result: %d, %d, %s\n", temp->data.id, temp->data.age, temp->data.name);
			printStu(temp);
		}
		else {
			printf("查找失败!");
		}
		break;
	case 2:
		Myprint();
		printf("please enter want to search name:");

		scanf("%s", name);
		getchar();
		temp = findStu_name(h_stu, name);
		if (temp != NULL) {
			printStu(temp);
		}
		else {
			printf("查找失败!");
		}
		break;

	default:
		break;
	}

}

void Case2(Node *h) {
	SNode stu = createSNode();
	// printf("please enter your id:");
	// scanf("%d", &stu.id);
	// getchar();

	// printf("please enter your age:");
	// scanf("%d", &stu.age);
	// getchar();

	// printf("please enter your name:");
	// scanf("%s", stu.name);
	// getchar();

	push_back(h, stu);
	printf("add successful!\n");
}


void Case3(Node *h) {
	showAllStu(h);
}

void Case4(Node *h_stu, int* flag_1) {
	Myprint();
	printf("1. id  2. name\n");
	printf("plesee enter:");
	scanf("%d", flag_1);
	getchar();
	switch (*flag_1) {
	case 1:
		delete_id(h_stu);
		break;

	case 2:
		delete_name(h_stu);
		break;

	default:
		break;
	}
}

// add
void Case5(UserNode *h_user) {
	Myprint();
	char name[100];
	char pwd[100];

	printf("please Enter your name：");
	scanf("%s", name);
	getchar();

	printf("please Enter your password:");
	scanf("%s", &pwd);
	getchar();

	addUser(h_user, name, pwd);
}

void Case6(UserNode *h) {
	showAll(h);
}

void Case7(UserNode *h) {
	deleteUser(h);
}


void Case8(UserNode *h) {
	char name[100];
	scanf("%s", name);
	getchar();

	search(h, name);
}

void Case9(Node* h) {
	update(h);
}

void Case10(UserNode *h) {
	update(h);
}

void start() {
	// 初始化
	UserNode* h_user = initUser();     // 读入注册用户
	Node* h_stu = createNode();        
	initStu(h_stu);						// 读入所有成员

	int		flag = 0, flag_1 = 0;  
	char	name[100];
	SNode	stu;
	Node*	temp = (Node *)malloc(sizeof(Node));

	if (getLoginInfo(h_user) == 0) {
		Myprint();
		printf("login successful!\n");
		while (1) {              // 
			Myprint();
			scanf("%d", &flag);
			switch (flag) {
			case 1: Case1(h_stu, temp, &flag_1, name); break;

			case 2: Case2(h_stu); break;

			case 3: Case3(h_stu); break;

			case 4: Case4(h_stu,  &flag_1); break;

			case 5: Case5(h_user); break;

			case 6: Case6(h_user); break;

			case 7: Case7(h_user); break;

			case 8: Case8(h_user); break;

			case 9:	Case9(h_stu); break;

			case 10: Case10(h_user); break;
			
			case 11:  exit(1);

			default:
				break;
			}

		}
	}
	// 学生登录
	else if (getLoginInfo(h_user) == 1) {
		while (1) {
			Myprint();
			scanf("%d", &flag);
			getchar();

			switch (flag) {
			case 1:	break;

			case 2:	break;

			case 3:	exit(1);

			default:
				break;
			}
		}
	}
	// 登录失败
	else {
		exit(-1);
	}
}
