//#include<iostream>
//using namespace std;
//class Base {
//public:
//	Base() {
//		m_A = 100;
//		cout << "Base���캯��" << endl;
//	}
//	//����
//	void func() {
//		cout << "Base -> func()" << endl;
//	}
//	void func(int a) {
//		cout << "Base -> func(int a)" << endl;
//	}
//	~Base() {
//		cout << "Base��������" << endl;
//	}
//	int m_A;
//	static int m_F;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//int Base::m_F = 100;
//class Son : public Base {
//public:
//	Son() {
//		m_A = 200;
//		cout << "Son���캯��" << endl;
//	}
//	void func() {
//		cout << "Son -> func()" << endl;
//	}
//	~Son() {
//		cout << "Son��������" << endl;
//	}
//	int m_D;
//	int m_A;
//	static int m_F;
//};
//int Son::m_F = 100;
//void test01() {
//	Son b;
//	cout << "Son m_A =" << b.m_A << endl;
//	cout << "Base m_A =" << b.Base::m_A << endl;
//	// 4 or 12 or 16?
//	cout << sizeof(Son) << endl;
//	//16
//	//֤����������Ȩ�޵����ԣ����ᱻ����̳���ȥ
//}
//void test02() {
//	Son s;
//	s.func();
//	s.Base::func();
//	s.Base::func(1);
//}
//void test03() {
//	Son s;
//	cout << "Son m_F" << s.m_F << endl;
//	cout << "Base m_F" << s.Base::m_F << endl;
//	//ͨ����������
//	cout << "Son m_F" << Son::m_F << endl;
//	//��һ��˫ð�Ŵ���ͨ�������ķ�ʽ���ʣ��ڶ�����ʾ���ʸ����������µ�m_F
//	//Ҳ����Base::m_F ��ʾͨ��������ʽ����Base�µ�m_F
//	cout << "Base m_F" << Son::Base::m_F << endl;
//}
//class Animal{
//public:
//	int m_A;
//};
////��̳�virtual��Animal��Ϊ�����
//class Sheep : virtual public Animal{};
//class Tuo :virtual public Animal{};
//class SheepTuo : public Sheep , public Tuo{
//
//};
//void test04() {
//	SheepTuo st;
//	st.m_A = 28;
//	//����ֻ��Ҫһ�ݣ������������ݣ���ν��?
//}
//int main() {
//	test04();
//	return 0;
//}

//#include<iostream>
//#include<vector>
////��׼�㷨ͷ�ļ�
//#include<algorithm>
//using namespace std;
//void myPrint(int val) {
//	cout << val << endl;
//}
//void test01() {
//	vector<int> v;
//	//push_back��������
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	//ͨ�����������������е�����
//	//v.begin()��ʼ��������ָ��������һ��Ԫ��
//	//v.end()������������ָ���������һ��Ԫ�ص���һ��λ��
//
//	/*vector<int>::iterator itBegin = v.begin();
//	vector<int>::iterator itEnd = v.end();
//	while (itBegin != itEnd) {
//		cout << *itBegin << endl;
//		itBegin++;
//	}*/
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << endl;
//	}
//	//STL��׼�㷨
//	for_each(v.begin(), v.end(),myPrint);
//}
//
//int main() {
//	test01();
//}

#include<iostream>
using namespace std;
class Animal {
public:
	//�麯��
	virtual void speak() {
		cout << "�����" << endl;
	}
};
class Cat : public Animal {
public:
	void speak() {
		cout << "Сè��" << endl;
	}
};
void doSpeak(Animal& animal) {
	animal.speak();
}
int main() {
	Cat cat;
	doSpeak(cat);
}