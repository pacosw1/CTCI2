
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

/*
   given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. a permutation
   is a rearrangments of letters. Doesn't have to be an actual word or words

   Thought Process:

   1. Break it down. How do we know if something is a palindrome ? it most have the same amount of letters if the length is even, or only one on its own if its odd

   example: bob  b: 2 o: 1  odd, we have even num of B's and one O. so it works

   this way we can use a hash table to count the occurance for each letter and check these two cases.

*/

bool permutationPalindrome(string);

int main() {
    cout << permutationPalindrome("Tact Coa");
}


bool permutationPalindrome(string s) {

    //cover the edge cases
    if (s.length() == 0)
        return false;

    //"we can't directly check the lenght of the string since it contains spaces, but we can use the map, or a counter var
    map<char, int> hash;

    int len = 0;


    //count letters and total actual letters in string
    for (int i = 0; i < s.length();i++) {

        char curr = tolower(s[i]); //make all chars lower case;

        if (curr == ' ') //skip whitespaces
            continue;

        if (!hash[curr]) {  //if char not saved, add it
            hash[curr] = 1;
            len++;
        } else { //just add one
            hash[curr]++;
            len++;
        }
    }

    bool evenLen = len % 2 == 0;

    map<char, int>::iterator it;

    int oddOccurs = 0;

    for (it = hash.begin(); it != hash.end();it++) {

        char letter = it->first;
        char occurs = it->second;

        if (evenLen && occurs % 2 != 0) { //if even length, all must be even
               return false;
        } 
        else if (occurs % 2 != 0 && !evenLen) //if not even len, only one must be uneven;
        { 
            if (++oddOccurs > 1)
                return false;
        }
    }

    return true; //if program does not end, we can assume its a palindrome;
}