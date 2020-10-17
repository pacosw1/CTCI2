


#include <iostream>
#include <string>
#include <set> 

using namespace std;

bool isUnique(string input);

int main() {

    cout << isUnique("Helo");
}

/*
    Implementin an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures.
    Optimal solution: hash tables;
    Follow up (no data structures): n^2
*/

bool isUnique(string input) {

    set<char> existingChars;

    //loop and save unique chars, if one already exists, not unique
    for (int i = 0; i < input.length();i++) {

        char curr = input[i];

        //if character found previously just exit
        if (existingChars.find(curr) != existingChars.end()) {
            return false;
        } else { //if not, add it to the list
            existingChars.insert(curr);
        }
    }

    //if cycle finishes without return false, all chars are unique
    return true;
}