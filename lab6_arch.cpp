#include "stdafx.h"
#include <iostream>
#include "header.h"

int main() {
	vector v1(1, 2);
	v1.printcoord();
	vectorE v2(1, 2, 3);
	v2.printcoord();
	v2.printLength();
	system("pause");
	return 0;
}
