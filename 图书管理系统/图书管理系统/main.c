/**
* ͼ�����ϵͳ(�����ռ�)
* ���
* ��ɫ��
*	1.ѧ��
*	2.admin
*ѧ��������
*	1.��ѯͼ��
*	2.����ͼ��
*	3.�黹ͼ��
* admin:
*	1.����ͼ��
*	2.ɾ��ͼ��
*	3.�ı�ͼ�����״̬
*	4.��ѯͼ��
* ��¼ģ��(23-4-8 finished)
*	1.�Ա��˺�������ɵ�¼
* ͼ��ģ��
*	1.�ļ���ȡͼ��(23-4-8 finished)
*/
#include "main.h"
void menu() {
	printf("*********************************\n");
	printf("*********ͼ�����ϵͳ************\n");
	printf("************1.��¼***************\n");
	printf("************0.�˳�***************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void menu_books() {
	printf("*********************************\n");
	printf("*********ͼ�����ϵͳ************\n");
	printf("************1.��ѯͼ��***********\n");
	printf("************0.�˳�***************\n");
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
	//��ʼ������
	init();
	//��¼״̬
	int isEnter = 0;
	do {
		char account[NAMESPACE] = {0};//�˺�
		char password[NAMESPACE] = { 0 };//����
		menu();
		int n = 2;
		scanf("%d", &n);//1:��¼ 0:�˳� ����:����
		clearInput();//��ջ���������
		if (n == 1) {
			printf("�������˺�: \n");
			scanf("%s",account);
			clearInput();
			printf("����������: \n");
			scanf("%s", password);
			clearInput();
			file = fopen("./data.txt", "r");
			if (file != NULL) {
				int isaccount = 0;
				char buf[NAMESPACE] = { 0 };
				while (1) {
					char* s = fgets(buf, 20, file);
					//�޸Ķ�ȡ��ʹ��ƥ��
					changeData(buf);
					if (s == NULL)break;
					//�ж��˺��Ƿ���ȷ
					if (!strcmp(buf, account) || isaccount) {
						//����˺�������ȷ�������ж����룬��buf������벿��
						if (!isaccount) {
							isaccount = 1;
							continue;
						}
						if (!strcmp(buf, password)) {
							system("cls");
							printf("��¼�ɹ�\n");
							Sleep(1000);
							system("cls");
							menu_books();
							isEnter = 1;
							break;
						}
					}
				}
				if (!isEnter) {
					printf("��¼ʧ��\n");
				}
				fclose(file);
				file = NULL;
			}
		}
		else if (n == 0) {
			break;
		}
		else {
			printf("�������������1/0\n");
		}
	} while (1);
	return 0;
}