#include "ladder.h"


bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    return false; //fix
}


bool is_adjacent(const string& word1, const string& word2)
{
    return false; //fix
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    vector<string> ladder;
    return ladder; //fix
}


void load_words(set<string> & word_list, const string& file_name)
{
    ifstream in(file_name);
    for (string word; getline(in, word);)
        word_list.insert(word);
    in.close();
}


void print_word_ladder(const vector<string>& ladder)
{

}


void verify_word_ladder()
{

}
