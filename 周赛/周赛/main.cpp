#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, an;
	int b, bn;
	cin >> a >> an;
	int ans[20], bns[20];
	for (int i = 0; i < a; i++) cin >> ans[i];
	cin >> b >> bn;
	for (int i = 0; i < b; i++) cin >> bns[i];
	int suma = 0, sumb = 0;
	int n = 1;
	for (int i = a - 1; i >= 0; i--) {
		ans[i] = ans[i] * n;
		suma += ans[i];
		n*= an;
	}
	n = 1;
	for (int i = b - 1; i >= 0; i--) {
		bns[i] = bns[i] * n;
		sumb += bns[i];
		n *= bn;
	}
	if (sumb == suma) {
		cout << "=" << endl;
	}
	else if (sumb > suma) {
		cout << "<" << endl;
	}
	else {
		cout << ">" << endl;
	}
}