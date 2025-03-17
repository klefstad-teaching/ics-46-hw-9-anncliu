#include "dijkstras.h"

int main()
{
    string files[] = {"src/small.txt", "src/medium.txt", "src/large.txt"};

    for (string f : files)
    {
        Graph g;
        vector<int> prev;
        file_to_graph(f, g);
        vector<int> distances = dijkstra_shortest_path(g, 0, prev);

        for (int i = 0; i < g.numVertices; ++i)
            print_path(extract_shortest_path(distances, prev, i), distances[i]);

        cout << endl;
    }

    return 0;
}