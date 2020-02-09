// test program to show operator << and ostream

#include <iostream>

struct whatEver {
	std::string foo;
	int bar = 0;
};

/* This function below says we're going to make the
  << operator so this specific thing: its goign to take an object of type whatEver
  by reference, and its goign to stream out the contents of the foo and bar members
  into a variable of type ostream called str, then return str.

*/
std::ostream & operator<<(std::ostream & str, const whatEver & we) {
	str << "Foo " << we.foo << "; Bar " << we.bar;
	return str;
}

int main() {
	whatEver we;
	we.foo = "HelloBuddy";
	we.bar = 4232;

	std::cout << we << std::endl;
}
