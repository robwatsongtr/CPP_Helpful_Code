
// reverses line input in output by use of a reverse iterator. 

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string input;
    
    while(getline(cin, input)) {
        for(auto it = input.rbegin(); it != input.rend(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }
    
}
