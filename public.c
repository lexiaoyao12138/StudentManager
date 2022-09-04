#define _CRT_SECURE_NO_WARNINGS
#include "public.h"
#include <stdio.h>
#include <string.h>

void chint(char* a, int* b) {
	int len = strlen(a);
	int t = 0;
	for (int i = 0; i < len; i++) {
		t = t * 10 + (a[i] - '0');
	}
	*b = t;
}

void Myprint() {
	printf("user>> ");
}

void getPath(char* filename, char *filepath) {
	// 打开配置文件
	FILE* fpConfig = fopen("configure.txt", "r");
	if (fpConfig == NULL) {
		printf("open file failed!\n");
		exit(-1);
	}
	// 读取配置文件成功
	// 读取 user_account 的文件路径
	int ch;
	char fileName[100];
	char path[1024];
	do {
		fscanf(fpConfig, "%s%s", fileName, path);
		if (strcmp(fileName, filename) == 0) {
			strcpy(filepath, path);
			fclose(fpConfig);
			return;
		}
	} while ((ch = getc(fpConfig)) != EOF);

	fclose(fpConfig);
	Myprint();
	printf("not find!\n");

	return -1;
}

