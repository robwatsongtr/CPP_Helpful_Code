//
// Remove Trailing Blanks and tabs in getline
// Ignore empty lines, ie no input at all or just spaces
//
// Rob Watson and Robert Diamond

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    
    while(getline(cin, input)) {
        
        // initialize a reverse iterator
        auto rit = input.rbegin();
        
        if (input.empty()) continue; // check for totally empty line
        
        // loop to find first non space or tab character so that they are left off
        for(; rit != input.rend(); ++rit) {
            if(*rit != ' ' && *rit != '\t') break;
        }
        
        // check for just spaces: get to 'rend' then some amount of spaces but blank
        if(rit == input.rend()) continue;
        
        // now output the line entered, but ignore blank lines and remove trailing spaces and tabs
        cout << "\'";
        for(auto it = input.begin(); it != rit.base(); ++it) {
            cout << *it;
        }
        cout << "\'" << '\n';
        
    }
}
