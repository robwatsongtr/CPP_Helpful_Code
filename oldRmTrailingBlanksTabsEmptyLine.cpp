// CPP
// Remove Trailing Blanks
// Ignore empty lines
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    
    while(getline(cin, input)) {
        auto rit = input.rbegin();
       
        if (input.empty()) continue;
        for(; rit != input.rend(); ++rit) {
            if(*rit != ' ' && *rit != '\t') break;
        }
        cout << "\'";
        for(auto it = input.begin(); it != rit.base(); ++it) {
            cout << *it;
        }
        cout << "\'" << '\n';
    }
}
