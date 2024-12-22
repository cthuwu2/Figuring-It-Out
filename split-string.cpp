// bit of code to split a string into parts of a vector

#include <iostream>
#include<bits/stdc++.h>
 
std::vector<std::string> strings;

void splitString(std::string str, char separator);

int main() {
    
    // Set string being split
    std::string str = "Test string yaaaay.";
    
    // Space is used as a separator
    char separator = ' '; 
    
    splitString(str, separator);

    //literally just checking to see if it worked
    std::cout << strings[2];

    return 0;
}


// Splits string based on seperator. Split string into strings vector  
void splitString(std::string str, char separator) {
    int startIndex = 0, endIndex = 0;
    
    for (int i = 0; i <= str.size(); i++) {
        // Loops through until it reaches seperator or end of input
        
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            std::string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}
