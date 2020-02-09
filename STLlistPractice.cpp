// this is some code to practice STL lists

#include <list>
#include <iostream>
#include <string>

void displayList(std::list<int>& l) {
	for(int x : l) std::cout << x << ' ';
	std::cout << std::endl << std::endl;
}

int main () {
	int nums = 15;
	std::list<int> intList;
	std::list<int> intList2;

	for(int idx = 0; idx < nums; ++idx) {
		intList.push_front(idx*2);
	}

	for(int idx = 0; idx < nums; ++idx) {
		intList2.push_back(idx*2);
	}

	displayList(intList);
	displayList(intList2);
}
