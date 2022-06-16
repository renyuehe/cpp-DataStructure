#include "Array.h"

#include <iostream>
using namespace std;

void test01() {
	Array<int> arr;
	for (int i = 0; i < 10; ++i) {
		arr.addLast(i);
	}
	arr.print();
	arr.set(2, 8);
	arr.print();
	arr.addFirst(10);
	arr.add(3, 4);
	arr.add(-1, 4);
	arr.print();
	for (int i = 0; i < 8; ++i) {
		arr.remove(2);
	}
	arr.remove(11);
	arr.print();
	cout << arr.get(2) << endl;
	cout << arr.get(8) << endl;
	cout << arr.find(8) << '\t' << arr.contains(8) << endl;
	cout << arr.find(2) << '\t' << arr.contains(2) << endl;
}


int main() {

	test01();

	return 0;
}


