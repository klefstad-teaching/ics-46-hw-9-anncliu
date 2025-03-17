#include <utility>

#include "dijkstras.h"


using Vertex = int;
using Distance = int;

struct DistanceComparer
{
    bool operator () (const pair<Vertex, Distance>& lhs, const pair<Vertex, Distance>& rhs) const
    {
        return get<1>(lhs) > get<1>(rhs);
    }
};

using distanceMinHeap = priority_queue< pair<Vertex, Distance>, vector< pair<Vertex, Distance>>, DistanceComparer >;


void check_neighbors_weight(const Edge e, vector<Distance>& distances, vector<int>& previous, 
                            vector<bool>& visited, distanceMinHeap& pq)
{
    Vertex curr = e.src;
    Vertex neighbor = e.dst;
    Distance new_distance = distances[curr] + e.weight;

    if (!visited[neighbor] && new_distance < distances[neighbor])
    {
        distances[neighbor] = new_distance;
        previous[neighbor] = curr;
        pq.push({neighbor, new_distance});
    }
}


void visit_next(const Graph& G, vector<Distance>& distances, vector<int>& previous, 
                vector<bool>& visited, distanceMinHeap& pq)
{
    while (!pq.empty())
    {
        Vertex v = get<0>(pq.top());
        pq.pop();

        if (!visited[v])
        {
            visited[v] = true;
            for (Edge e : G[v])
                check_neighbors_weight(e, distances, previous, visited, pq);
        }
    }
}


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;

    vector<Distance> distances(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    distanceMinHeap pq;
    pq.push({source, 0});
    distances[source] = 0;

    visit_next(G, distances, previous, visited, pq);

    return distances;
}


vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination)
{
    stack<Vertex> backwards_path;
    Vertex curr = destination;

    while (curr != -1)
    {
        backwards_path.push(curr);
        curr = previous[curr];
    }   

    vector<Vertex> shortest_path;
    while (!backwards_path.empty())
    {
        shortest_path.push_back(backwards_path.top());
        backwards_path.pop();
    }

    return shortest_path;
}


void print_path(const vector<int>& v, int total)
{
    for (auto vertex : v)
        cout << vertex << " ";

    cout << endl;
    cout << "Total cost is " << total << endl;
}
