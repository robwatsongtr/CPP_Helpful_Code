// simple push_back on vector demo
// with print of vector using ostream_iterator

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    int vecSize = 0;
    std::cout << "Enter the size of the vector. Maximum size is 10: ";
    std::cin >> vecSize;
    
    if (vecSize > 10 || vecSize < 0 ) {
        std::cout << "Invalid size." << std::endl;
        return 0; // I want to throw an exception but I don't remember how
    }
    
    std::vector<int> myVector;
    int val = 0;
    
    while (myVector.size() < vecSize)  {
        
        std::cout << "Enter a number: ";
        std::cin >> val;
        myVector.push_back(val);
        
    }
    
    std::cout << '\n' << "Vector entered" << '\n';
    std::copy(myVector.begin(), myVector.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}
