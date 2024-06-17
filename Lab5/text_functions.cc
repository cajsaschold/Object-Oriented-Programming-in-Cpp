#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstring>

using namespace std;

vector<pair<string, int>> sort_by_value(map<string, int> word_freq);
vector<pair<string, int>> sort_by_key(map<string, int> word_freq);


vector<string> read_file(string file_name) {

    vector<string> text;

    fstream ifs(file_name);

    if (!ifs.is_open()) {
        throw ios_base::failure("File not found");
    }

    istream_iterator<string> iis(ifs);
    
    istream_iterator<string> eos;

    copy(iis, eos, back_inserter(text));

    return text;
}


void print(vector<string> text) {

    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
    ostream_iterator<string> oos(cout);
    cout << endl;
}


map<string, int> frequency(vector<string> text) {

    map<string, int> word_freq{};

    auto word_counter = [&word_freq](const string &word){
        word_freq[word]++;
    };

    for_each(text.begin(), text.end(), word_counter);
    return word_freq;
}


vector<pair<string, int>> sort_by_value(map<string, int> word_freq) {

    vector<pair<string, int>> sorted_word_freq(word_freq.begin(), word_freq.end());

    auto compare = [](const auto &a, const auto &b) {
        return a.second > b.second;
    };

    sort(sorted_word_freq.begin(), sorted_word_freq.end(), compare);
    return sorted_word_freq;
}


vector<pair<string, int>> sort_by_key(map<string, int> word_freq) {

    vector<pair<string, int>> sorted_word_freq(word_freq.begin(), word_freq.end());

    auto compare = [](const auto &a, const auto &b) {
        return a < b;
    };

    sort(sorted_word_freq.begin(), sorted_word_freq.end(), compare);
    return sorted_word_freq;
}

int get_longest_word(vector<string> text) {

    // Convert a and b to c-strings as strlen only works on that type
    auto maxString = max_element(text.begin(), text.end(),
    [](const string& a, const string& b) {
        return strlen(a.c_str()) < strlen(b.c_str());
    });

    return maxString->length();
}

void print_freq_value(vector<pair<string, int>> sorted_word_freq, int longest_word) {

    for_each(sorted_word_freq.begin(), sorted_word_freq.end(), [longest_word](const auto &entry) {
        cout << setw(longest_word) << right << entry.first << ": " << entry.second << endl;
    });
}


void print_freq_key(vector<pair<string, int>> sorted_word_freq, int longest_word) {

    for_each(sorted_word_freq.begin(), sorted_word_freq.end(), [longest_word](const auto &entry) {
        cout << setw(longest_word) << left << entry.first << ": " << entry.second << endl;
    });
}


void substitute(vector<string>& text, string& old_word, string& new_word) {

    replace(text.begin(), text.end(), old_word, new_word);
}


void remove(vector<string>& text, string remove_word) {

    text.erase(remove(text.begin(), text.end(), remove_word), text.end());
}
