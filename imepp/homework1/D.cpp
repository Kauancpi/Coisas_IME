#include <iostream>
#include <map>
using namespace std;

int main() {
    std::map<std::pair<int, int>, std::string> myMap;

    // Prompt the user to enter key-value pairs
    int key1, key2;
    std::string value;
    int maps;
    cin >> maps;
    int i=0;
    
    while (std::cin >> key1 >> key2 >> value && i<maps-1) {
        myMap[{key1, key2}] = value;
        i++;
    }

    // Access elements using a pair as key
    std::cout << "\nValues entered into the map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "{" << pair.first.first << ", " << pair.first.second << "}: " << pair.second << std::endl;
    }

    return 0;
}