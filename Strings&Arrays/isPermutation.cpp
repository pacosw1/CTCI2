
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

/*
    Given two strings, write a method to decide if one is a permutation of the other;

    Permutation = An ordered combination, meaning position does matter

    formula = n^r where n = possible digits, and r = the ones we choose from

    if number shouldnt be repeated, we subtract each time, this is known as the factorial of something = 15 * 14 * 13 * 12 * 11

    formula (n!) / (n-r)!  n = number of things to choose from, r = the ones we choose, again no repetition, and order matters;


    x = abc
    y = djjjjjjabcdsd

*/

bool isPermutation(string a, string b);

int main() {
    cout << isPermutation("Hello", "olleh");
}



bool isPermutation(string a, string b) {

    map<char, int> hash;

    //edge cases
    if (a.length() != b.length()) { //if lengths are different, they cant be permutations
        return false;
    }

    //we have to loop and save amount of times that each char is stored
    for (int i = 0; i < a.length();i++) {

        char curr = a[i];

        if (!hash[curr])
        { //if doesnt exists, add it;
            hash[curr] = 1;
        }
        else //else add to it
        {
            hash[curr] += 1;
        }
    }

    //check b has same exact letters, no matter the order
      for (int i = 0; i < b.length();i++) {

        char curr = b[i];

        if (!hash[curr])
        { //if doesnt exists, add it;
            return false;
        }
        else //else add to it
        {
            hash[curr] -= 1;
        }
    }

    //make sure exact number of letters exist, must be 0;
    map<char, int>::iterator it;

    for (it = hash.begin(); it != hash.end(); it++)
    {

        if (it->second != 0)
        {
            return false;
        }
   }

   return true;
}