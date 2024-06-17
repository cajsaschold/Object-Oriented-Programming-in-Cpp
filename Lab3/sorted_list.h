// TODO: Complementary work needed: Does not compile due to missing header(s).


#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <string>

class Sorted_List {
public:

    Sorted_List() = default;
    Sorted_List(Sorted_List const& other);
    Sorted_List(Sorted_List&& other);
    ~Sorted_List();
    Sorted_List& operator=(Sorted_List const& other);
    Sorted_List& operator=(Sorted_List&& other);

    void insert(int value);
    void remove(int idx);
    void clear();
    void clear_size();
    int get_size() const; 
    int value_at_idx(int idx) const;
    bool is_empty() const;
    std::string list_to_string() const;
    std::string print() const;
    
    
private:

    struct Node {
        int value;
        Node* next;
    };

    Node* first{};
    void insert_next(Node* current, Node* next);
    int size{};
};
#endif
