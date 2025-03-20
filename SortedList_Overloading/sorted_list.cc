#include <iostream>
#include "sorted_list.h"

using namespace std;

void Sorted_List::insert(int value) {
    Node* tmp = new Node{value, nullptr};
    
    if(first == nullptr) {
        first = tmp;
        this->size++;
        return;
    }
    else if(value < first->value) {
        tmp->next = first;
        first = tmp;
        this->size++;
        return;
    }
    else {
        insert_next(first, tmp);
    }
}

void Sorted_List::insert_next(Node* current, Node* insert) {

    if(current->next == nullptr) {
        current->next = insert;
        insert->next = nullptr;
        this->size++;
        return;
    } else if(insert->value <= current->next->value) {
        insert->next = current;
        current->next = nullptr;
        this->size++;
        return;
    } else {
        insert_next(current->next, insert);
    }
}

void Sorted_List::remove(int idx) {
    Node* current{};
    Node* temp{};
    current = first;
    int listSize{};
    listSize = get_size();

    // Checks if idx is out of bounds or if the list is empty
    if(idx > listSize || idx < 0 || first == nullptr) {
        return;
    }

    if (idx == 0) {
        temp = first;
        first = first->next;
        this->size--;
        delete temp;
    } else {
        for (int i = 0; i < idx - 1; i++) {
            current = current->next;
        }

        temp = current->next;
        current->next = temp->next;
        this->size--;
        delete temp;
    }

}

string Sorted_List::list_to_string() const{
    Node* tmp{};
    tmp = first;
    string output{};
    int listSize{};
    listSize = get_size();

    for (int i = 0; i < listSize; i++)
    {
        output = output + to_string(tmp->value) + ",";
        tmp = tmp->next;
    }
    
    // Removes the last comma
    if (!output.empty()) {
        output.pop_back();
    }
    return output;
}


string Sorted_List::print() const{
    string str{};
    if(is_empty()) {
        str = "";
    } else {
        str = list_to_string();
        cout << str << endl;
    } 

    return str;
}

bool Sorted_List::is_empty() const{
    return(first == nullptr);
}

int Sorted_List::get_size() const {
    return size;
}

int Sorted_List::value_at_idx(int idx) const {
    Node* tmp{};
    tmp = first;
    int listSize{};
    listSize = get_size();

    // Checks if idx is out of bounds or if the list is empty
    if(idx > listSize || idx < 0 || first == nullptr) {
        return -1;
    }

    for (int i = 0; i < idx; i++)
    {
        tmp = tmp->next;
    }

    return tmp->value;
}

// Destructor
Sorted_List::~Sorted_List() {
    Node* current{};
    current = first;

    while(current != nullptr) {
        Node* tmp{};
        tmp = current;
        current = tmp->next;
        delete tmp;
    }
}

// Copy constructor
Sorted_List::Sorted_List(Sorted_List const& other) : first(nullptr){

    if(other.first != nullptr) {
        Node* check = other.first;
        Node* copy = new Node{check->value, nullptr};
        first = copy;  // Setting the new list's first node
        check = check->next;
        size = other.get_size();

        while(check != nullptr) {
            copy->next = new Node{check->value, nullptr};
            copy = copy->next;
            check = check->next;
        }
    }
}

// Move constructor
Sorted_List::Sorted_List(Sorted_List&& other) {

    size = other.get_size();
    first = other.first;
    other.first = nullptr;
}

// Copy assignment operator. Copies the content from the original list
// to the copy. It also removes any content if the copy has elements
// to not have any memory leaks
Sorted_List& Sorted_List::operator=(Sorted_List const& other) {

    // Check for self-assignment
    if (this != &other) {
        clear();
        Sorted_List temp{other};
        size = other.get_size();
        swap(first, temp.first);
        return *this;
    }

    return *this;
}

// Help function for clearing a list
void Sorted_List::clear() {

    while(first != nullptr) {
        remove(0);
    }
}

// Help function for clearing a lists size
void Sorted_List::clear_size() {
    size = 0;
}

// Move assignment operator. Moves the content from the original list to the new
// and assigns the orignals first node to nullptr
Sorted_List& Sorted_List::operator=(Sorted_List&& other) {

    // Check for self-assignment
    if (this != &other) {
        clear();
        size = other.get_size();
        other.clear_size();
        first = other.first;
        other.first = nullptr;
        return *this;
    }

    return *this;
}
