// För att köra valgrind:
// g++ -std=c++17 -g test_sorted_list.cc sorted_list.cc 
// valgrind --tool=memcheck --leak-check=yes ./a.out

// För att köra vanligt test med catch
// g++ -std=c++17 test_main.o test_sorted_list.cc sorted_list.cc
// ./a.out


// The reason for having two defines is that we could not get valgrind
// and the regular testing with catch to work on the same define. An 
// lab assitant said that this was okay.

// Use this line for valgring
#define CATCH_CONFIG_MAIN
// Use this line for regular testing
//#define CATCH

#include "catch.hpp"
#include "sorted_list.h"
using namespace std;

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};

  REQUIRE( l.is_empty() == true );
  REQUIRE( l.get_size() == 0 );
}

//=======================================================================
// Test cases for is_empty()
//=======================================================================
TEST_CASE("Empty list") {
  Sorted_List l{};
  REQUIRE(l.is_empty());
}

TEST_CASE("Non empty list") {
  Sorted_List l{};
  l.insert(1);
  REQUIRE_FALSE(l.is_empty());
}

TEST_CASE("Non empty list (2 elements)") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  REQUIRE_FALSE(l.is_empty());
}


//=======================================================================
// Test cases for print() and insert()
//=======================================================================
TEST_CASE("Print non empty list where insert is in increasing order") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.insert(3);
  CHECK(l.print() == "1,2,3");
}

TEST_CASE("Print non empty list where we insert the same number") {
  Sorted_List l{};
  l.insert(1);
  l.insert(1);
  CHECK(l.print() == "1,1");
}

TEST_CASE("Print non empty list where insert is in decreasing order") {
  Sorted_List l{};
  l.insert(6);
  l.insert(5);
  l.insert(4);
  CHECK(l.print() == "4,5,6");
}

TEST_CASE("Print empty list") {
  Sorted_List l{};
  CHECK(l.print() == "");
}

//=======================================================================
// Test cases for size()
//=======================================================================
TEST_CASE("size = 0") {
  Sorted_List l{};
  CHECK(l.get_size() == 0);
}

TEST_CASE("size = 1") {
  Sorted_List l{};
  l.insert(1);
  CHECK(l.get_size() == 1);
}

TEST_CASE("size = 2") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  CHECK(l.get_size() == 2);
}

//=======================================================================
// Test cases for value_at_idx()
//=======================================================================
TEST_CASE("Value at idx 0") {
  Sorted_List l{};
  l.insert(1);
  CHECK(l.value_at_idx(0) == 1);
}

TEST_CASE("Value at idx 1") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  CHECK(l.value_at_idx(1) == 2);
}

TEST_CASE("Value at idx 2") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  CHECK(l.value_at_idx(2) == 3);
}

TEST_CASE("Value at idx that does not exist") {
  Sorted_List l{};
  l.insert(1);
  CHECK(l.value_at_idx(2) == -1);
}

TEST_CASE("Value at idx that is negative") {
  Sorted_List l{};
  l.insert(1);
  CHECK(l.value_at_idx(-1) == -1);
}

TEST_CASE("Value at idx with empty list") {
  Sorted_List l{};
  CHECK(l.value_at_idx(0) == -1);
}

//=======================================================================
// Test cases for remove()
//=======================================================================

TEST_CASE("Remove at index 1 (becomes empty list)") {
  Sorted_List l{};
  l.insert(1);
  l.remove(0);
  CHECK(l.print() == "");
}

TEST_CASE("Remove at index 2") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.remove(1);
  CHECK(l.print() == "1");
}

TEST_CASE("Remove at index that does not exist") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.remove(3);
  CHECK(l.print() == "1,2");
}

TEST_CASE("Remove at index that is negative") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.remove(-1);
  CHECK(l.print() == "1,2");
}

TEST_CASE("Remove from empty list") {
  Sorted_List l{};
  l.remove(0);
  CHECK(l.print() == "");
}

//=======================================================================
// Test cases for copy constructor
//=======================================================================

TEST_CASE("Test copy constructor 1)") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  
  Sorted_List copy{l};
  CHECK(copy.print() == "1,2");
}

TEST_CASE("Test copy constructor for empty list)") {
  Sorted_List l{};
  
  Sorted_List copy{l};
  CHECK(copy.print() == "");
}

TEST_CASE("Test copy constructor, remove from copy") {
  Sorted_List l{};
  l.insert(1);

  Sorted_List copy{l};
  copy.remove(0);
  CHECK(copy.print() == "");
  CHECK(l.print() == "1");
}

TEST_CASE("Test copy constructor, insert to copy") {
  Sorted_List l{};
  l.insert(1);

  Sorted_List copy{l};
  copy.insert(2);
  CHECK(copy.print() == "1,2");
  CHECK(l.print() == "1");
}

//=======================================================================
// Test cases for move constructor
//=======================================================================

TEST_CASE("Test move constructor)") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  
  Sorted_List l2{std::move(l)};
  CHECK(l.is_empty());
  CHECK_FALSE(l2.is_empty());
  CHECK(l2.list_to_string() == "1,2");
}

TEST_CASE("Test move constructor for empty list)") {
  Sorted_List l{};
  Sorted_List l2{std::move(l)};

  CHECK(l.is_empty());
  CHECK(l2.is_empty());
  CHECK(l2.list_to_string() == "");
}

//=======================================================================
// Test cases for copy assignment operator
//=======================================================================
TEST_CASE("Test copy assignment operator)") {
  Sorted_List l{};
  Sorted_List l2{};
  l.insert(1);
  l.insert(2);

  l2 = l;
  
  CHECK(l.get_size() == 2);
  CHECK(l2.get_size() == 2);
}

TEST_CASE("Test copy assignment operator when l2 has values before copy)") {
  Sorted_List l{};
  Sorted_List l2{};
  l2.insert(1);
  
  l2 = l;
  
  CHECK(l.get_size() == 0);
  CHECK(l2.get_size() == 0);
}

TEST_CASE("Test copy assignment operator for self assignment)") {
  Sorted_List l{};
  l.insert(1);
  l = l;
  
  CHECK(l.get_size() == 1);
}

TEST_CASE("Test copy assignment operator for empty list") {
  Sorted_List l{};
  Sorted_List l2{};
  l2 = l;
  
  CHECK(l.is_empty());
}

TEST_CASE("Test copy assignment operator, remove from copy") {
  Sorted_List l{};
  Sorted_List l2{};
  l.insert(1);
  l.insert(2);

  l2 = l;
  l2.remove(1);

  CHECK(l.get_size() == 2);
  CHECK(l2.get_size() == 1);
  CHECK(l2.print() == "1");
}

TEST_CASE("Test copy assignment operator, insert to copy") {
  Sorted_List l{};
  Sorted_List l2{};
  l.insert(1);
  l.insert(2);

  l2 = l;
  l2.insert(3);
  
  CHECK(l.get_size() == 2);
  CHECK(l2.get_size() == 3);
  CHECK(l2.print() == "1,2,3");
}

//=======================================================================
// Test cases for move assignment operator
//=======================================================================
TEST_CASE("Test move assignment operator)") {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);

  Sorted_List l2;
  l2 = std::move(l);
  
  CHECK(l.get_size() == 0);
  CHECK(l2.get_size() == 2);
  CHECK(l2.list_to_string() == "1,2");
}

TEST_CASE("Test move assignment operator when l2 has values before copy)") {
  Sorted_List l{};
  Sorted_List l2{};
  l.insert(1);
  l.insert(2);
  l2.insert(5);

  l2 = std::move(l);
  
  CHECK(l.get_size() == 0);
  CHECK(l2.get_size() == 2);
  CHECK(l2.list_to_string() == "1,2");
}

TEST_CASE("Test move assignment operator for self-assignment)") {
  Sorted_List l{};
  l.insert(1);

  l = std::move(l);
  
  CHECK(l.get_size() == 1);
}

TEST_CASE("Test move assignment operator for empty list") {
  Sorted_List l{};
  Sorted_List l2{};

  l2 = std::move(l);
  
  CHECK(l.is_empty());
}
