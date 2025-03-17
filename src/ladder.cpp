#include <map>

#include "ladder.h"


void error(string word1, string word2, string msg)
{
    cout << "Error occurred on words \"" << word1 << "\" and \"" << word2 << "\". ";
    cout << msg << endl;
}


void build_char_map(map<char, int>& char_map, const std::string& word, const char& element)
{

    map<char, int>::iterator it = char_map.find(element);
    if (it != char_map.end())
        char_map[element] += 1;
    else
        char_map[element] = 0;
}


bool is_editable(map<char, int>& map1, map<char, int>& map2)
{
    int num_diffs = 0;
    for (auto it = map1.begin(); it != map1.end(); ++it)
    {
        char key = it -> first;
        if (map2.find(key) == map2.end() || map1[key] != map2[key])
            ++num_diffs;
        
        if (num_diffs > 1)   
            return false;
    }

    return true;
}


bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    map<char, int> str1chars;
    map<char, int> str2chars;
    int min_len = fmin(str1.length(), str2.length());

    for (int i = 0; i < min_len; ++i)
    {
        build_char_map(str1chars, str1, str1[i]);
        build_char_map(str2chars, str2, str2[i]);
    }

    return is_editable(str1chars, str2chars);
}


bool is_adjacent(const string& word1, const string& word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    int len_diff = abs(len1 - len2);

    if (len_diff > 1)
        return false;

    return edit_distance_within(word1, word2, 1);
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    // queue<vector<string>> ladder_queue;
    // vector<string> begin_ladder(1, begin_word);
    // ladder_queue.push(begin_ladder);

    // set<string> visited;
    // visited.insert(begin_word);

    // while (!ladder_queue.empty())
    // {
    //     vector<string> partial_ladder = ladder_queue.front();
    //     ladder_queue.pop();

    //     string last_word = partial_ladder.pop_back();
    //     for (string word : word_list)
    //     {
    //         if (is_adjacent(last_word, word))
    //         {
    //             if (visited.find(word) == visited.end())
    //             {
    //                 visited.insert(word);
    //                 vector<string> ladder_cpy(partial_ladder);
    //                 partial_ladder.push_back(word);

    //                 if (word == end_word)
    //                     return ladder_cpy;

    //                 ladder_queue.push(ladder_cpy);
    //             }
    //         }
    //     }
    // }   

    vector<string> empty_ladder;
    return empty_ladder; //fix
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
    if (ladder.empty())
        cout << "Word ladder not found" << endl;
    else
    {
        cout << "Word ladder found: ";
        for (string word : ladder)
            cout << word << " "; 

        cout << endl;
    }
}


void verify_word_ladder()
{

}
