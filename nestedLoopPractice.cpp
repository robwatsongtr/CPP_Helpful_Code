// Nested Loop practice
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

    string first;
    cout << "Type something: ";
    cin >> first;
    
    string second;
    cout << "Type something: ";
    cin >> second;
    
   /* string third;
    cout << "Type something: ";
    cin >> third; */
  
    
    for(int i = 0; i < 5; ++i) {
        cout << i << " " << first << '\n';
            for(int j = 0; j < 5; ++j) {
                cout << j << " " << second << '\n';
            }
    }
    
}
