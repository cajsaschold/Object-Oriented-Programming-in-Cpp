#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    int integer{};
    double real_number{};
    char character{};
    string str{};

    cout << "Enter one integer: ";
    cin >> integer;
    cin.ignore(1000,'\n'); // will ignore 1000 characters, or until a new line is inserted
    cout << "You entered the number: ";
    cout << integer << endl << endl;

    cout << "Enter four integers: ";
    cin >> integer;
    cout << "You entered the numbers: ";
    cout << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer << " ";
    cin >> integer;
    cout << integer << endl << endl;
    
    cout << "Enter one integer and one real number: ";
    cin >> integer;
    cin >> real_number;
    cin.ignore(1000,'\n');
    cout << "The real is: " << setw(11) << right << fixed << setprecision(3) << real_number << endl; //fixed avoids decimals beeing written "e-", and makes setprecision determine the decimal points (and not the nr of significant digits)
    cout << "The integer is: " << setw(8) << right << integer << endl << endl;

    cout << "Enter one real and one integer number: ";
    cin >> real_number;
    cin >> integer;
    cin.ignore(1000,'\n');
    cout << "The real is: " << setfill('.') << setw(11) << right << real_number << endl; //setfill tp fill setw with a character instead of just blank space
    cout << "The integer is: " << setfill('.') << setw(8) << right << integer << endl << endl;

    cout << "Enter a character: ";
    cin >> character;
    cin.ignore(1000,'\n');
    cout << "You entered: " << character << endl << endl;

    cout << "Enter a word: ";
    cin >> str;
    cout << "The word '" << str << "' has " << str.size() << " character(s)." << endl << endl;

    cout << "Enter an integer and a word: ";
    cin >> integer;
    cin >> str;
    cin.ignore(1000,'\n');
    cout << "You entered '" << integer << "' and '" << str << "'." << endl << endl;

    cout << "Enter an character and a word: ";
    cin >> character;
    cin >> str;
    cin.ignore(1000,'\n');
    cout << "You entered the string \"" << str << "\" and the character" << " '" << character << "'." << endl << endl;

    cout << "Enter a word and a real number: ";
    cin >> str;
    cin >> real_number;
    cin.ignore(1000,'\n');
    cout << "You entered \"" << str << "\" and \"" << real_number << "\"." << endl << endl;

    cout << "Enter a text-line: ";
    getline(cin, str); // read lines instead of words and store them in a string
    cout << "You entered: \"" << str << "\"" << endl << endl;

    cout << "Enter a second line of text: ";
    getline(cin, str);
    cout << "You entered: \"" << str << "\"" << endl << endl;

    cout << "Enter three words: ";
    cin >> str;
    cout << "You entered: \'" ;
    cout << str << " ";
    cin >> str;
    cout << str << " ";
    cin >> str;
    cout << str << "\'" << endl;
 
}