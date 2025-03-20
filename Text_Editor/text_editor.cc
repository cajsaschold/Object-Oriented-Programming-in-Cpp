#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include "text_functions.cc"

int main(int argc, char** argv){
    ofstream file{};
    vector<string> text{};
    string word{};

    if (argc < 3) {
        cerr << "Invalid number of arguments" << endl;
        return -1;
    }
    else {

        try {
            string file_name = argv[1];
            text = read_file(file_name);
        }
        catch(const ios_base::failure& e) {
            cerr << "Error: " << e.what() << endl;
            return -1;
        }
       
        vector<string> arguments(argv + 2, argv + argc);

        for (const auto& arg : arguments) {

            if (arg == "--print") {

                print(text);

            } else if (arg == "--frequency") {

                map<string, int> word_freq{frequency(text)};
                vector<pair<string, int>> sorted_value{sort_by_value(word_freq)};
                int longest_word{get_longest_word(text)};
                print_freq_value(sorted_value, longest_word);
                cout << endl;

            } else if (arg == "--table") {

                map<string, int> word_freq{frequency(text)};
                vector<pair<string, int>> sorted_key{sort_by_key(word_freq)};
                int longest_word{get_longest_word(text)};
                print_freq_key(sorted_key, longest_word);

            } else if (arg.rfind("--substitute=", 0) == 0) {

                size_t flag_pos{arg.find('=')};
                string flag{arg.substr(0, flag_pos)};
                string param{arg.substr(flag_pos + 1)};

                size_t param_pos{param.find('+')};

                if (param_pos == string::npos) {
                    cerr << "Input should be on the form: --substitute=<old>+<new>" << endl;
                    return -1;
                }

                string old_word{param.substr(0, param_pos)};
                string new_word{param.substr(param_pos + 1)};

                substitute(text, old_word, new_word);

            } else if (arg.rfind("--remove=", 0) == 0) {

                size_t flag_pos{arg.find('=')};
                string flag{arg.substr(0, flag_pos)};
                string word{arg.substr(flag_pos + 1)};

                remove(text, word);
            } else {

                cerr << "The only valid flags are:\n --print \n --frequencey\n --table\n "
                 << "--substitute=<old>+<new>\n --remove=<word>" << endl;
                return -1;
            }
        }

        return 0;
    }  
}
