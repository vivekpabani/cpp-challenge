#include <string>
#include "myclass.h"
#include "gtest/gtest.h"


// test count Ni

TEST(MyClassTest, CountNiNullString)
{
    const char *s1 = "";
    std::string ss1(s1);

    MyClass <std::string> myClass1;
    EXPECT_EQ(0, myClass1.getNiCount(ss1));

    const wchar_t *s2 = L"";
    std::wstring ss2(s2);

    MyClass <std::wstring> myClass2;
    EXPECT_EQ(0, myClass2.getNiCount(ss2));
}

TEST(MyClassTest, CountNiZeroInstance)
{
    const char *s1 = "NI nI NI nI NI";
    std::string ss1(s1);

    MyClass <std::string> myClass1;
    EXPECT_EQ(0, myClass1.getNiCount(ss1));

    const wchar_t *s2 = L"NI nI NI nI NI";
    std::wstring ss2(s2);

    MyClass <std::wstring> myClass2;
    EXPECT_EQ(0, myClass2.getNiCount(ss2));
}

TEST(MyClassTest, CountNiMultipleInstances)
{
    const char *s1 = "Ni nI NI nI NiNiNiN ni" ;
    std::string ss1(s1);

    MyClass <std::string> myClass1;
    EXPECT_EQ(4, myClass1.getNiCount(ss1));

    const wchar_t *s2 = L"NINi nI NI nI NI Ni";
    std::wstring ss2(s2);

    MyClass <std::wstring> myClass2;
    EXPECT_EQ(2, myClass2.getNiCount(ss2));
}


// test replace Ni

TEST(MyClassTest, ReplaceNiNullString)
{
    const char *s1 = "";
    std::string ss1(s1);
    const char *expected1 = "";

    MyClass <std::string> myClass1;
    myClass1.replaceNiWithNI(ss1);
    EXPECT_STREQ(expected1, ss1.c_str());

    const wchar_t *s2 = L"";
    std::wstring ss2(s2);
    const wchar_t *expected2 = L"";

    MyClass <std::wstring> myClass2;
    myClass2.replaceNiWithNI(ss2);
    EXPECT_STREQ(expected2, ss2.c_str());
}

TEST(MyClassTest, ReplaceNiZeroInstance)
{
    const char *s1 = "NI nI NI nI NI";
    std::string ss1(s1);
    const char *expected1 = "NI nI NI nI NI";

    MyClass <std::string> myClass1;
    myClass1.replaceNiWithNI(ss1);
    EXPECT_STREQ(expected1, ss1.c_str());

    const wchar_t *s2 = L"NI nI NI nI NI";
    std::wstring ss2(s2);
    const wchar_t *expected2 = L"NI nI NI nI NI";

    MyClass <std::wstring> myClass2;
    myClass2.replaceNiWithNI(ss2);
    EXPECT_STREQ(expected2, ss2.c_str());
}

TEST(MyClassTest, ReplaceNiMultipleInstances)
{
    const char *s1 = "Ni nI NI nI NiNiNiN ni";
    std::string ss1(s1);
    const char *expected1 = "NI nI NI nI NINININ ni";

    MyClass <std::string> myClass1;
    myClass1.replaceNiWithNI(ss1);
    EXPECT_STREQ(expected1, ss1.c_str());

    const wchar_t *s2 = L"NINi nI NI nI NI Ni";
    std::wstring ss2(s2);
    const wchar_t *expected2 = L"NINI nI NI nI NI NI";

    MyClass <std::wstring> myClass2;
    myClass2.replaceNiWithNI(ss2);
    EXPECT_STREQ(expected2, ss2.c_str());
}
