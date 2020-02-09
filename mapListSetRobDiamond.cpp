//
//  Created by Robert Diamond as a demonstration of
//  the nested data structures of list and set within a map
//


#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

struct WalkType {
    std::string name;
    unsigned long time_seconds;

    bool operator<(const WalkType& other) const {
		// sort that sorts first by name then by time if the names are equal
        return name < other.name || (name == other.name && time_seconds < other.time_seconds);
    }
};

// BEGIN Splitter class ---------------------------------------------

class WalkSplitter {
private:
		// declare a map called walks_
		// the name is a string, and the value is a set of walkType(s)
        std::map< std::string, std::set<WalkType> > walks_;

public:
        void doSplit(std::list<WalkType> &);
        void dump();
};

// ---------------

// takes a list as input into method, loops the list into  walks_  map
void WalkSplitter::doSplit(std::list<WalkType>& walks) {
	for (WalkType w : walks) {

		// referencing the key w.name in the walks map will create that key if it doesn't exist
		// a map of string to set of walk types (nested data structue);
        walks_[w.name].insert(w); // creates a new set
    }

}

void WalkSplitter::dump() {
    for (auto wl : walks_) {
        std::cout << "Walk " << wl.first << ":" << std::endl;
            for (WalkType w : wl.second) {
                std::cout << "Time " << w.time_seconds << std::endl;
            }
    }
    std::cout << "Done" << std::endl;
}
// END Splitter class---------------------------------------------------

int main() {
    std::list<WalkType> walklist {

        { "foo", 100 },
        { "bar", 110 },
        { "foo", 105 },
        { "bar", 95 },
        { "baz", 200 }

    };
	// declare an obejct called splitter of type WalkSplitter
    WalkSplitter splitter;

	// pass in walklist declared above, do the sorting and splitting
    splitter.doSplit(walklist);

	// output the map to console
    splitter.dump();

}
