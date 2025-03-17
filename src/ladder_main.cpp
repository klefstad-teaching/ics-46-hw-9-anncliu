#include "ladder.h"


void print_word_list(set<string> word_list)
{
    for (string word : word_list)
        cout << word << endl;
}

int main()
{
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    // print_word_list(word_list); // test load_words
    return 0;
}