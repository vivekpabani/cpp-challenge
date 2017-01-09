#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <boost/algorithm/string/replace.hpp>

template<typename T>
class MyClass
{
public:
    int getNiCount(const T& in_s) const;
    void replaceNiWithNI(T& in_s) const;
    T getNi() const;
    void displayMessage(int count, const T& in_s) const;  
};


/*
    Count and return the occurance of search string "Ni" in the input string. 
*/

template<typename T>
int MyClass<T>::getNiCount(const T& in_s) const {
    int count = 0;

    // Get the appropriate "Ni" string based on template parameter T.
    T strNi = getNi();


    /* Start with the first index of strNi. 
       Search for next index till not reached end of string. start from last index + size of search string.
       Increment the count everytime a match is found.
    */

    for (int index = in_s.find(strNi); index != std::string::npos; index = in_s.find(strNi, index + strNi.size()))
    {
        ++count;
    }

    return count;
}


/*
    Replace the search string "Ni" with "NI" in place.
    Used replace all method from boost-replace library.
*/

template<typename T>
void MyClass<T>::replaceNiWithNI(T& in_s) const {
    boost::replace_all(in_s, "Ni", "NI");
}


/*
    Get the search string "Ni" according to the input string type(string/wstring).
*/

template <>
std::string MyClass<std::string>::getNi() const{
    std::string st = "Ni";
    return st;
}

template <>
std::wstring MyClass<std::wstring>::getNi() const{
    std::wstring st = L"Ni";
    return st;
}


/*
    Display message according to the input string type(string/wstring).
*/

template <>
void MyClass<std::string>::displayMessage(int count, const std::string& in_s) const{
    // Print with std::cout in case of std::string.
    std::cout << "Found " << count << " occurrences of Ni. New string: " << in_s << std::endl;
}

template <>
void MyClass<std::wstring>::displayMessage(int count, const std::wstring& in_s) const{
    // Print with std::wcout in case of std::wstring.
    std::wcout << "Found " << count << " occurrences of Ni. New string: " << in_s << std::endl;
}

#endif
