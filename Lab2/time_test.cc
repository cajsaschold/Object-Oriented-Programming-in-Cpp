#define CATCH 
#include "catch.hpp" 
#include "time.h" 
using namespace std;
// To run code run the following:
// g++ -std=c++17 test_main.o time_test.cc Lab2.cc
// ./a.out

// CAN IGNORE THIS TODO
// TODO: Complementary work needed: Using to_string to compare the resulting stream      
// is not a great way to test correctness of operator<<, since the operator<< is using   
// to_string. In essence, doing to_string(a) == to_string(a) doesn't really tell you     
// anything. 

// KLAR
// TODO: Complementary work needed: You have no checks for what 
// happens to time when >> fails. (What value should time contain?)

// KLAR
// Comment: You should have more tests for >>
// Hint: See is_valid() tests

// Comment: You should have a test for + and - that spans multiple days
// ex: (17 *24 * 60 * 60) + (5 * 60 * 60) + (37 * 60) + 19

// KLAR TROR JAG
// TODO: Complementary work needed: Test that ++time/--time returns the new value
// Hint: See time++/time-- tests


// Test cases for adding time
TEST_CASE("Add 10 seconds"){
    Time t1 {13,45,02};

    t1=t1+10;

    CHECK(t1.second==12);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Add 61 seconds"){
    Time t1 {13,45,02};

    t1=t1+61;

    CHECK(t1.second==3);
    CHECK(t1.minute==46);
    CHECK(t1.hour==13);
}

TEST_CASE("Add 3602 seconds"){
    Time t1 {13,45,02};

    t1=t1+3602;

    CHECK(t1.second==4);
    CHECK(t1.minute==45);
    CHECK(t1.hour==14);
}

TEST_CASE("Add 39600 seconds (new day)"){
    Time t1 {13,45,02};

    t1=t1+39600;

    CHECK(t1.second==2);
    CHECK(t1.minute==45);
    CHECK(t1.hour==0);
}

TEST_CASE("Add 0 seconds"){
    Time t1 {13,45,02};

    t1=t1+0;

    CHECK(t1.second==2);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

// Test cases for subtracting time

TEST_CASE("Subtract 1 seconds"){
    Time t1 {13,45,02};

    t1=t1-1;

    CHECK(t1.second==1);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Subtract 3 seconds"){
    Time t1 {13,45,02};

    t1=t1-3;

    CHECK(t1.second==59);
    CHECK(t1.minute==44);
    CHECK(t1.hour==13);
}

TEST_CASE("Subtract 3599 seconds"){
    Time t1 {13,45,02};

    t1=t1-3599;

    CHECK(t1.second==3);
    CHECK(t1.minute==45);
    CHECK(t1.hour==12);
}

TEST_CASE("Subtract 46800 seconds (13 hours)"){
    Time t1 {13,45,02};

    t1=t1-46800;

    CHECK(t1.second==2);
    CHECK(t1.minute==45);
    CHECK(t1.hour==0);
}

TEST_CASE("Subtract 0 seconds"){
    Time t1 {13,45,02};

    t1=t1-0;

    CHECK(t1.second==2);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

// Test cases with ++time

TEST_CASE("Time& ++ 1"){
    Time t1 {13,45,02};

    ++t1;

    CHECK(t1.second==3);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& ++ 2"){
    Time t1 {13,45,02};

    ++t1;
    ++t1;

    CHECK(t1.second==4);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& ++ 3"){
    Time t1 {23,59,59};

    ++t1;

    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==0);
}

TEST_CASE("Time& ++ 4"){
    Time t1 {13,45,02};

    (++t1);

    CHECK(t1.second==3);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& ++ 5"){
    Time t1 {13,59,59};

    ++t1;
    ++t1;

    CHECK(t1.second==01);
    CHECK(t1.minute==00);
    CHECK(t1.hour==14);
}

TEST_CASE("Time time++ 2"){
    Time t1 {13,59,59};
    Time t2 {13,59,59};
    t2=++t1;

    CHECK(t2.second==00);
    CHECK(t2.minute==00);
    CHECK(t2.hour==14);
    
    CHECK(t1.second==00);
    CHECK(t1.minute==00);
    CHECK(t1.hour==14);

}

// Test cases with time++
TEST_CASE("Time ++ 1"){
    Time t1 {13,59,59};
    
    t1++;

    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==14);
}

TEST_CASE("Time ++ 2"){
    Time t1 {13,59,59};
    Time t2 {13,59,59};
    t2=t1++;

    CHECK(t2.second==59);
    CHECK(t2.minute==59);
    CHECK(t2.hour==13);
    
    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==14);

}

TEST_CASE("Time ++ 3"){
    Time t1 {13,59,59};
    
    t1++;
    t1++;

    CHECK(t1.second==1);
    CHECK(t1.minute==0);
    CHECK(t1.hour==14);
}

TEST_CASE("Time ++ 4"){
    Time t1 {23,59,59};

    t1++;

    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==0);
}


// Test cases for --time
TEST_CASE("Time& -- 1"){
    Time t1 {13,45,02};

    --t1;

    CHECK(t1.second==1);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& -- 2"){
    Time t1 {13,45,02};

    --t1;
    --t1;

    CHECK(t1.second==0);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& -- 3"){
    Time t1 {0,0,0};

    --t1;

    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==23);
}

TEST_CASE("Time& -- 4"){
    Time t1 {13,45,02};

    (--t1);

    CHECK(t1.second==1);
    CHECK(t1.minute==45);
    CHECK(t1.hour==13);
}

TEST_CASE("Time& -- 5"){
    Time t1 {14,0,1};

    --t1;
    --t1;

    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==13);
}

TEST_CASE("Time --time 2"){
    Time t1 {14,0,0};
    Time t2 {14,0,0};
    t2=--t1;

    CHECK(t2.second==59);
    CHECK(t2.minute==59);
    CHECK(t2.hour==13);
    
    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==13);

}

//Test cases for time--
TEST_CASE("Time time-- 1"){
    Time t1 {14,0,0};
    
    t1--;

    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==13);
}

TEST_CASE("Time -- 2"){
    Time t1 {14,0,0};
    Time t2 {14,0,0};
    t2=t1--;

    CHECK(t2.second==0);
    CHECK(t2.minute==0);
    CHECK(t2.hour==14);
    
    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==13);

}

TEST_CASE("Time -- 3"){
    Time t1 {14,0,0};
    
    t1--;
    t1--;

    CHECK(t1.second==58);
    CHECK(t1.minute==59);
    CHECK(t1.hour==13);
}

TEST_CASE("Time -- 4"){
    Time t1 {0,0,0};

    t1--;

    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==23);
}

// Test cases for to_string()
TEST_CASE("To string - continental noon"){
    Time t1 {12,15,56};
    string std{};

    std=to_string(t1, true);
    

    CHECK(std=="12:15:56");
}

TEST_CASE("To string - continental morning"){
    Time t1 {5,15,56};
    string std{};

    std=to_string(t1, true);
    

    CHECK(std=="05:15:56");
}

TEST_CASE("To string - !continental pm"){
    Time t1 {12,15,56};
    string std{};

    std=to_string(t1, false);
    

    CHECK(std=="12:15:56 pm");
}

TEST_CASE("To string - !continental am"){
    Time t1 {5,15,56};
    string std{};

    std=to_string(t1, false);
    

    CHECK(std=="05:15:56 am");
}

// Test cases for is_am()
TEST_CASE("Is am - morning"){
    Time t1 {5,15,56};

    CHECK(is_am(t1)==true);
}

TEST_CASE("Is am - evening"){
    Time t1 {17,15,56};

    CHECK(is_am(t1)==false);
}

TEST_CASE("Is am - midnight"){
    Time t1 {0,0,0};

    CHECK(is_am(t1)==true);
}

TEST_CASE("Is am -noon"){
    Time t1 {12,0,0};

    CHECK(is_am(t1)==false);
}

// Test cases for ==
TEST_CASE("== - true"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(t1==t2);
}

TEST_CASE("== - false"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(!(t1==t2));
}

// Test cases for !=
TEST_CASE("!= - true"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(!(t1!=t2));
}

TEST_CASE("!= - false"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(t1!=t2);
}

// Test cases for <
TEST_CASE("< true"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(t1<t2);
}

TEST_CASE("< false"){
    Time t1 {13,0,0};
    Time t2 {12,0,0};

    CHECK(!(t1<t2));
}

TEST_CASE("< equal"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(!(t1<t2));
}

// Test cases for >
TEST_CASE("> true"){
    Time t1 {13,0,0};
    Time t2 {12,0,0};

    CHECK(t1>t2);
}

TEST_CASE("> false"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(!(t1>t2));
}

TEST_CASE("> equal"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(!(t1>t2));
}

// Test cases for <=
TEST_CASE("<= (less)"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(t1<=t2);
}

TEST_CASE("<= more"){
    Time t1 {13,0,0};
    Time t2 {12,0,0};

    CHECK(!(t1<=t2));
}

TEST_CASE("<= equal"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(t1<=t2);
}

// Test cases for >=
TEST_CASE(">= (less)"){
    Time t1 {12,0,0};
    Time t2 {13,0,0};

    CHECK(!(t1>=t2));
}

TEST_CASE(">= more"){
    Time t1 {13,0,0};
    Time t2 {12,0,0};

    CHECK(t1>=t2);
}

TEST_CASE(">= equal"){
    Time t1 {12,0,0};
    Time t2 {12,0,0};

    CHECK(t1>=t2);
}

// is_valid()
TEST_CASE("is_valid() true"){
    Time t1 {12,0,0};

    CHECK(is_valid(t1));
}

TEST_CASE("is_valid() hour false"){
    Time t1 {45,0,0};

    CHECK_FALSE(is_valid(t1));
}

TEST_CASE("is_valid() hour false negative"){
    Time t1 {-1,0,0};

    CHECK_FALSE(is_valid(t1));
}

TEST_CASE("is_valid() minute false"){
    Time t1 {14,78,0};

    CHECK_FALSE(is_valid(t1));
}

TEST_CASE("is_valid() minute false negative"){
    Time t1 {14,-78,0};

    CHECK_FALSE(is_valid(t1));
}

TEST_CASE("is_valid() second false"){
    Time t1 {14,0,78};

    CHECK_FALSE(is_valid(t1));
}

TEST_CASE("is_valid() second false negative"){
    Time t1 {14,0,-2};

    CHECK_FALSE(is_valid(t1));
}

// << operator
TEST_CASE("<< test 1"){
    Time t1 {12,0,0};

    std::ostringstream oss{};
    oss << t1;

    CHECK(oss.str()=="12:00:00");
}

// >> operator
TEST_CASE(">> true"){
    Time t1 {};

    std::istringstream iss{"05:23:45"};
    iss >> t1;

    CHECK(to_string(t1, true)=="05:23:45");
}

TEST_CASE(">> hour false"){
    Time t1 {0,0,0};

    std::istringstream iss{"25:23:45"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==0);
}

TEST_CASE(">> hour false (neg)"){
    Time t1 {13,57,03};

    std::istringstream iss{"-3:23:45"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==03);
    CHECK(t1.minute==57);
    CHECK(t1.hour==13);
}

TEST_CASE(">> minute false"){
    Time t1 {12,30,45};

    std::istringstream iss{"07:73:45"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==45);
    CHECK(t1.minute==30);
    CHECK(t1.hour==12);
}

TEST_CASE(">> minute false (neg)"){
    Time t1 {12,00,00};

    std::istringstream iss{"07:-1:45"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==00);
    CHECK(t1.minute==00);
    CHECK(t1.hour==12);
}

TEST_CASE(">> second false"){
    Time t1 {0,0,0};

    std::istringstream iss{"25:23:104"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==0);
    CHECK(t1.minute==0);
    CHECK(t1.hour==0);
}

TEST_CASE(">> second false (neg)"){
    Time t1 {23,59,59};

    std::istringstream iss{"25:23:-78"};
    iss >> t1;

    CHECK(iss.fail());
    CHECK(t1.second==59);
    CHECK(t1.minute==59);
    CHECK(t1.hour==23);
}