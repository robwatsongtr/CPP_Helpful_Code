/*
Rob Watson' s practice on std::map in 2020
taken from internet and my brain, just trying it out
*/

#include <iostream>
#include <map>
#include <string>

int main () {

	// Declare a map named grade_list as a string / char name-value pair
	std::map<std::string, char> grade_list;

	// put some data in to that bad boy using [] notation
	grade_list["John"] = 'B';
	grade_list["Barb"] = 'C';
	grade_list["Mike"] = 'A';

	std::cout << std::endl;

	// test to see what happens outputting the value of a nonexistent key
	std::cout << grade_list["James"] << "uhhwhat" << '\n';

	// put some more data into that bad boy using insert instead
	grade_list.insert(std::make_pair("Jeff", 'B'));
	grade_list.insert(std::make_pair("Julie", 'D'));

	// example code to find keys
	std::cout << "Joseph Appears " << grade_list.count("Joseph") << " times" << '\n';
	std::cout << "Mike Appears " << grade_list.count("Mike") << " times" << '\n';

	auto it2 = grade_list.find("Joseph");
	if (it2 == grade_list.end()) {
		std::cout << "Joseph is not in the list" << "\n\n";
	}

	// change entries
	grade_list["Jeff"] = 'F'; // change Jeff
	grade_list["John"] = 'A';  // change John
	grade_list.insert(std::pair<std::string, char>("Julie", 'F')); // didn't change!!!
	grade_list["Julie"] = 'V'; // changed it!

	// output the map using standard for loop and iterator/pointer
	// Note that James was created as a name, but with no value
	// **Attempting to access a key using operator[] will cause the map to
	// create an entry for that key, using the pair <Key, new ValueType()>**

	for(auto it = grade_list.begin(); it != grade_list.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	std::cout << '\n';

	// range based for loop with no iterator
	for(auto it : grade_list) {
		std::cout << it.first << ": " << it.second << '\n';
	}


}
