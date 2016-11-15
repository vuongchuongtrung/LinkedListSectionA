#include "ListOfDoubles.h"
#include <string>
using namespace std;

int main()
{
	ListOfDoubles list;
	list.insert(9);
	list.insert(8);
	list.insert(7);
	list.insert(6);
	list.insert(5);
	list.insert(4);
	list.insert(3);
	list.insert(2);
	list.insert(1);

	list.displayList();

	list.deleteMostRecent();
	list.displayList();

	list.deleteDouble(-1);
	list.displayList();

	list.~ListOfDoubles();
	system("pause");
	return 0;
}
