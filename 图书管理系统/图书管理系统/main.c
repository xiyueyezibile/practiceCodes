/**
* 图书管理系统(开发日记)
* 大纲
* 角色：
*	1.学生
*	2.admin
*学生操作：
*	1.查询图书
*	2.借阅图书
*	3.归还图书
* admin:
*	1.增加图书
*	2.删除图书
*	3.改变图书借阅状态
*	4.查询图书
* 登录模块(23-4-8 finished)
*	1.对比账号密码完成登录
* 图书模块
*	1.文件读取图书(23-4-8 finished)
*/
#include "main.h"
void menu() {
	printf("*********************************\n");
	printf("*********图书借阅系统************\n");
	printf("************1.登录***************\n");
	printf("************0.退出***************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void menu_books() {
	printf("*********************************\n");
	printf("*********图书借阅系统************\n");
	printf("************1.查询图书***********\n");
	printf("************0.退出***************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void clearInput() {
	while (getchar() != '\n');
}
void changeData(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')str[i] = '\0';
	}
}
void init() {
	init_Books();

}
int main() {
	FILE* file;
	//初始化配置
	init();
	//登录状态
	int isEnter = 0;
	do {
		char account[NAMESPACE] = {0};//账号
		char password[NAMESPACE] = { 0 };//密码
		menu();
		int n = 2;
		scanf("%d", &n);//1:登录 0:退出 其他:错误
		clearInput();//清空缓存区函数
		if (n == 1) {
			printf("请输入账号: \n");
			scanf("%s",account);
			clearInput();
			printf("请输入密码: \n");
			scanf("%s", password);
			clearInput();
			file = fopen("./data.txt", "r");
			if (file != NULL) {
				int isaccount = 0;
				char buf[NAMESPACE] = { 0 };
				while (1) {
					char* s = fgets(buf, 20, file);
					//修改读取，使得匹配
					changeData(buf);
					if (s == NULL)break;
					//判断账号是否正确
					if (!strcmp(buf, account) || isaccount) {
						//如果账号输入正确则跳过判断密码，让buf变成密码部分
						if (!isaccount) {
							isaccount = 1;
							continue;
						}
						if (!strcmp(buf, password)) {
							system("cls");
							printf("登录成功\n");
							Sleep(1000);
							system("cls");
							menu_books();
							isEnter = 1;
							break;
						}
					}
				}
				if (!isEnter) {
					printf("登录失败\n");
				}
				fclose(file);
				file = NULL;
			}
		}
		else if (n == 0) {
			break;
		}
		else {
			printf("输入错误，请输入1/0\n");
		}
	} while (1);
	return 0;
}