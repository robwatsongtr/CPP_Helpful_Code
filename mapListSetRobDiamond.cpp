//
//  main.cpp
//  map_and_list
//
//  Created by Robert Watson on 12/19/19.
//  Copyright © 2019 Robert Watson. All rights reserved.
//

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

struct Walk {
    std::string name;
    unsigned long time_seconds;

    bool operator<(const Walk& other) const {
        return name < other.name || (name == other.name && time_seconds < other.time_seconds);
    }
};

// BEGIN Splitter class ---------------------------------------------
class WalkSplitter {
private:
		// declare a map that is a name value pair called walks_
        std::map<std::string, std::set<Walk>> walks_;

public:
        void doSplit(std::list<Walk> &);
        void dump();
};

// Splitter Methods -------------------------------------------------
void WalkSplitter::doSplit(std::list<Walk>& walks) {
	for (Walk w : walks) {
        walks_[w.name].insert(w);
    }

}

void WalkSplitter::dump() {
    for (auto wl : walks_) {
        std::cout << "Walk " << wl.first << ":" << std::endl;
            for (Walk w : wl.second) {
                std::cout << "Time " << w.time_seconds << std::endl;
            }
    }
    std::cout << "Done" << std::endl;
}
// END Splitter class---------------------------------------------------



int main() {
    std::list<Walk> walklist {
        { "foo", 100 },
        { "bar", 110 },
        { "foo", 105 },
        { "bar", 95 },
        { "baz", 200 }
    };

    WalkSplitter splitter;
    splitter.doSplit(walklist);
    splitter.dump();

}
