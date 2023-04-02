//#include<iostream>
//using namespace std;
//class Base {
//public:
//	Base() {
//		m_A = 100;
//		cout << "Base构造函数" << endl;
//	}
//	//重载
//	void func() {
//		cout << "Base -> func()" << endl;
//	}
//	void func(int a) {
//		cout << "Base -> func(int a)" << endl;
//	}
//	~Base() {
//		cout << "Base析构函数" << endl;
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
//		cout << "Son构造函数" << endl;
//	}
//	void func() {
//		cout << "Son -> func()" << endl;
//	}
//	~Son() {
//		cout << "Son析构函数" << endl;
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
//	//证明父类所有权限的属性，都会被子类继承下去
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
//	//通过类名访问
//	cout << "Son m_F" << Son::m_F << endl;
//	//第一个双冒号代表通过类名的方式访问，第二个表示访问父类作用域下的m_F
//	//也可以Base::m_F 表示通过类名方式调用Base下的m_F
//	cout << "Base m_F" << Son::Base::m_F << endl;
//}
//class Animal{
//public:
//	int m_A;
//};
////虚继承virtual，Animal称为虚基类
//class Sheep : virtual public Animal{};
//class Tuo :virtual public Animal{};
//class SheepTuo : public Sheep , public Tuo{
//
//};
//void test04() {
//	SheepTuo st;
//	st.m_A = 28;
//	//我们只需要一份，但现在有两份，如何解决?
//}
//int main() {
//	test04();
//	return 0;
//}

//#include<iostream>
//#include<vector>
////标准算法头文件
//#include<algorithm>
//using namespace std;
//void myPrint(int val) {
//	cout << val << endl;
//}
//void test01() {
//	vector<int> v;
//	//push_back插入数据
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	//通过迭代器访问容器中的数据
//	//v.begin()起始迭代器，指向容器第一个元素
//	//v.end()结束迭代器，指向容器最后一个元素的下一个位置
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
//	//STL标准算法
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
	//虚函数
	virtual void speak() {
		cout << "动物叫" << endl;
	}
};
class Cat : public Animal {
public:
	void speak() {
		cout << "小猫叫" << endl;
	}
};
void doSpeak(Animal& animal) {
	animal.speak();
}
int main() {
	Cat cat;
	doSpeak(cat);
}