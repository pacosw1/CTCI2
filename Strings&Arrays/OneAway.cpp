#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

/*
  There are three types of edits that can be performed on strings, insert a char, remove a char , or replace a char, given two strings, check if they are 1 or zero edits away


  thought process:

  Edge case, if difference in len is greater than two chars, we can automatically return false;

  we have three cases

  1. Insert, if one char is missing see if we can insert in order
  2. Replace, if not chars are missing, check if we can replace it in order and get the same result
  3. Delete, if len is not the same and string is almost equal, delete it

  ideas: check one of three,

  check all three edits in steps, break if one fails or succeeds

  start with easy one where only one needs to be traded

  for insert or delete, we need to check if a substring for a exists with a lenght's minus 1;
  so for example;

  dogg
  dog

  substring dog len is 3, while is 4, we know that we can insert or delete g and it will pass the test

*/

bool replace(string, string);

bool insertOrDelete(string, string);
bool OneEdit(string, string);


int main() {
    cout << OneEdit("pasle", "pale");
}


bool OneEdit(string a, string b) {
    return insertOrDelete(a, b) || replace(a, b);
}



bool insertOrDelete(string a, string b) {

    string shawdy = a.length() < b.length() ? a : b;
    string longer = b.length() > a.length() ? b : a;

    int shawdyI = 0;
    int longerI = 0;

    bool edited = false;

    while (longerI < longer.length() && shawdyI < shawdy.length()) {

        char shawdyCurr = shawdy[shawdyI];
        char longerCurr = longer[longerI];

        if (shawdyCurr != longerCurr) {

            if (edited)
                return false;
            edited = true;
        } else {
            shawdyI++;
        }
        longerI++;
    }

    return true;
}



bool replace(string a, string b) //true means test passed
{ //assuming length has already been validated;

    if (a.length() != b.length()) //edge case
        return false;

    int edits = 0;

    for (int i = 0; i < a.length();i++) {

        char currA = a[i];
        char currB = b[i];

        if (currA != currB) //check amount of edits needed
            edits++;

        if (edits > 1) //at most one edit can happen for test to pass;
            return false;
    }

    return true;

}