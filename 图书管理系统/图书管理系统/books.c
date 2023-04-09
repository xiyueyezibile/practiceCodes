#include "main.h"
//����ͼ��ͨѶ¼
typedef struct Books {
	char name[NAMESPACE];//����
	int state;//״̬
	struct Books* next;
	int count;//����
}Books;
//����ͼ��ͨѶ¼
Books* create_Books() {
	Books* bk = (Books*)malloc(sizeof(Books));
	bk->count = 0;
	bk->next = NULL;
	bk->state = 0;
	return bk;
}
//����ͼ��ͨѶ¼
int add_Books(Books* bk, char* name) {
	Books* n = (Books*)malloc(sizeof(Books));
	for (int i = 0; *(name + i) != '\0'; i++) {
		n->name[i] = *(name + i);
		n->name[i + 1] = '\0';
	}
	n->state = 0;
	n->next = bk->next;
	bk->next = n;
	bk->count++;
	return 1;
}
void test_Books(Books* bk) {
	Books* n = bk->next;
	while (n != NULL) {
		printf("%s\n", n->name);
		n = n->next;
	}
}
void init_Books() {
	FILE* f;
	char name[NAMESPACE] = { 0 };
	Books* bk = create_Books();
	f = fopen("./bookdata.txt", "r");
	if (f != NULL) {
		while (1) {
			char* s = fgets(name, 20, f);
			if (s == NULL)break;
			changeData(name);
			add_Books(bk, name);
		}
		fclose(f);
		f = NULL;
	}
	/*test_Books(bk);*/
}