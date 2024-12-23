// cat age to human age converter!

#include <iostream>
#include <iostream>
#include<bits/stdc++.h> 
#include <ctime>
#include <ratio>
#include <chrono>


int targetDate;
int targetMonth;
int targetYear;

std::string monthList[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

std::string userInput;

int daysSinceDate (int targetDate, int targetMonth, int targetYear);
int catAgeToHuman (double days);
bool isNumber(const std::string& s);

int main()
{
    
    std::cout<<"Hi, please enter your cat's birthday in order to calculate it's age in human years.\n";
    
    // get day, month, and year of cat's birth from user
    
    std::cout<<"Day of birth: ";
    std::cin >> targetDate;
    
    std::cout<<"Month of birth: ";
    std::cin >> userInput;
    
    // check if the user inputs the word form of a month instead of a number
    if (!(isNumber(userInput))) {
    
        // if so convert the word to all lowercase for comparison purposes
        
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); 
        
        // loop through the month array to find the numeric version of month
        for (int i = 0; i < 12; i++) {
        
            if (monthList[i]==userInput) {
            targetMonth = i + 1;
            break;
            }
        }
        
        }
    
    std::cout << "Year of birth: ";
    std::cin >> targetYear;
    
    // calculate and display cat's human age
    std::cout<<"\nYour cat is " << catAgeToHuman(daysSinceDate(targetDate, targetMonth, targetYear)) <<" in human years!";
    return 0;
}


int catAgeToHuman (double days) {
    
    double humanAge = 0;
    
    // add years for first year
    if (days > 365) {
        days -= 365;
        humanAge += 15;
    } else {
        // if less than a year old, calculate how much of 15 to add
        humanAge += 15 * (days/365);
        days = 0;
    }
    
    // add years for second year
    if (days > 365) {
        days -= 365;
        humanAge += 9;
    } else {
        // if less than two years old, calculate how much of 9 to add
        humanAge += 9 * (days/365);
        days = 0;
    }
    
    // calculate rest of years
    humanAge+= 4 * (days/365);
   
    // return cat's human age
    return humanAge;
    
    // For cat age: 
    // first year = 15 years
    // second year = 9 years
    // onwards = 4
}


int daysSinceDate (int targetDate, int targetMonth, int targetYear) {
    // system_clock::from_time_t
    using namespace std::chrono;
    
    // create tm with target date, month, and year
    std::tm timeinfo = std::tm();
    timeinfo.tm_year = (targetYear-1900);   // starts at 1900, adds years since to make accurate
    timeinfo.tm_mon = (targetMonth - 1);      // starts at January, adds months since
    timeinfo.tm_mday = targetDate;     // starts on the 1st
    std::time_t tt = std::mktime (&timeinfo);

    system_clock::time_point tp = system_clock::from_time_t (tt);
    system_clock::duration d = system_clock::now() - tp;

    // convert to number of days:
    typedef duration<int,std::ratio<60*60*24>> days_type;
    days_type ndays = duration_cast<days_type> (d);

    // return result
    return ndays.count();
}


bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
