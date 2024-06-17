#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    string s{};
    int n{0};
    int sum{};
    double average{};
    int shortest{};
    string shortest_word{};
    int longest{};
    string longest_word{};

    ifstream ifs{"hej.txt"};
    ifs.seekg(0, ios::end); //moves pointer to end

    if (ifs.tellg() == 0) {  //tellg gives the position of the pointer, if the position would be 0 at the nd of the file, the dile would be empty
        cout << "The file is empty" << endl;
    }
    else {
        ifs.seekg(0, ios::beg); //moves pointer to beginning (otherwise we would get that the file has no words)
        while (ifs >> s) {
        
        sum += s.length(); //the total amount of letters in the file

        if (s.length() <= shortest || shortest == 0) { // need the || statement, otherwise the shortest would be empty
            shortest = s.length();
            shortest_word = s;
        }

        else if (s.length() >= longest) {
            longest = s.length();
            longest_word = s;
        }

        n += 1;
    }

    cout << endl;
    cout << "There are " << n << " words in the file." << endl;
    cout << "The shortest word was \"" << shortest_word << "\" with "<< shortest << " character(s)." << endl;
    cout << "The longest word was \"" << longest_word << "\" with "<< longest << " character(s)." << endl;
    
    average = sum / n;

    cout << "The average length was " << average << " character(s)." << endl;


    }
    
    return 0;
}