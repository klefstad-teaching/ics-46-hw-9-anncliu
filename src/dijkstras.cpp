#include "dijkstras.h"


void print_path(const vector<int>& v, int total)
{
    for (auto vertex : v)
        cout << vertex << " ";

    cout << endl;
    cout << "Total cost is " << total << endl;
}
