#include <iostream>
#include <string>
#include "myclass.h"

int main()
{
    int count = 0;

    const char *szTestString1 = "Ni nI NI nI Ni";
    const wchar_t *szTestString2 = L"Ni nI NI nI Ni";

    /*
    Steps:
    1. Convert c_style string to string.
    2. Create an instance of MyClass with appropriate string type.
    3. Invoke getNiCount, and store count in a variable. 
    4. Invoke replaceNiWithNI, which will update the string in place.
    5. Invoke the displayMessage funtion of MyClass.
    */

    // test with ASCII string.
    std::string testString1(szTestString1); 

    MyClass<std::string> myClass1;

    count = myClass1.getNiCount(testString1);
    myClass1.replaceNiWithNI(testString1); 

    myClass1.displayMessage(count, testString1);


    // test with Unicode string.
    std::wstring testString2(szTestString2);

    MyClass<std::wstring> myClass2;

    count = myClass2.getNiCount(testString2);
    myClass2.replaceNiWithNI(testString2);

    myClass2.displayMessage(count, testString2);

    return 0;
}
