#include "RBTree.h"

int main()
{
	RBTree* p;
	p = new RBTree;
	int option = 0;
	std::cout << "\n1 - Print tree\n2 - Add element\n3 - Remove element\n4 - Element info\n5 - Min element\n0 - Exit\n";
	do {
		std::cout << "------\n";
		std::cin >> option;
		char ch1 = 0;
		switch (option)
		{
		case 1:
			std::cout << "\n";
			p->print();
			break;
		case 2:
			std::cout << "\nNew element: ";
			std::cin >> ch1;
			p->insert(ch1);
			break;
		case 3:
			std::cout << "\nElement to remove : ";
			std::cin >> ch1;
			p->remove(ch1);
			break;
		case 4:
			std::cout << "\nElement : ";
			std::cin >> ch1;
			//std::cout << 
			p->print_info(p->search(ch1));
			break;
		case 5:
			std::cout << "\n";
			//std::cout << 
			p->minimum(p->get_root());
			break;
		default:
			std::cout << "\nChoose option!\n";
			std::cin >> option;
			break;
		}
	} while (option != 0);

	delete p;
	return 0;
}