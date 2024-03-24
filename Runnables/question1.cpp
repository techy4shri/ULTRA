#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include "Algorithms/Dijkstra/Dijkstra.h"  
using namespace std;

extern const GRAPH floridaGraph;
extern const vector<int> floridaWeights;

int main() {
    random_device rd;
    chrono::mt19937 generator(rd());
    uniform_int_distribution<Vertex> distribution(0, floridaGraph.numVertices() - 1);

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 200; ++i) {
        Vertex source = distribution(generator);
        Vertex target = distribution(generator);

        Dijkstra<GRAPH> dijkstra(floridaGraph, floridaWeights);
        dijkstra.run(source, target); 
    }

    auto end = high_resolution_clock::now();
    duration<double> total_run = end - start;

    cout << "Total runtime in seconds for 200 random Dijkstra: " << total_run.count() <<endl;

    return 0;
}
