#include <iostream>
#include <../list_lib/List.h>

using namespace std;
int main()
{
	TList<int> A;
	TListElem<int>* e1;
	int x1 = 1, x2 = 2, x3 = 3, x4 = 4;

	A.InsFirst(x1);
	A.InsLast(x2);
	e1 = A.GetLast();
	A.InsLast(x4);
	A.Ins(e1, x3);

	cout << A << endl;

	A.Del(e1);
	cout << A;
	return 0;
}
