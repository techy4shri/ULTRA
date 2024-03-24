#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "Dijkstra.h"
#include "Graph.h"

using namespace std;

void ParseDIMACS(ifstream& file, Graph& graph) {
  string line;
  while (getline(file, line)) {
    if (line.empty() || line[0] == 'c') continue;
    istringstream iss(line);
    char type;
    iss >> type;
    if (type == 'p') {
      int num_nodes, num_edges;
      iss >> num_nodes >> num_edges;
      graph.Init(num_nodes);
    } 
    if (type == 'a') {
      int source, target;
      double weight = 1.0; // Assuming unit weight
      iss >> source >> target >> weight;
      source--; target--; 
      graph.AddEdge(source, target, weight);
    }
  }
}

int main(){
  Graph graph;
  ifstream file("file://SHRI003/Users/Administrator/Desktop/Garima/B.Sc%20(Hons.)%20Computer%20Science/TRANSPORT%20WEB%20APP/USA-road-d.FLA.gr")

  if(!file,is_open()){
    cerr<<"Error opening DIMACS file!"<<endl;
    return 1;
  }
  ParseDIMAC(file, graph);
  file.close();

  default_random_engine generator(time(0));
  uniform_int_distribution<Vertex> distribution(0, graph.GetNumNodes() -1);
  double total_runtime = 0.0;
  for (int i = 0; i < 200; ++i) {
    int source = distribution(generator);
    int target = distribution(generator);
    auto start = high_resolution_clock::now();
    Dijkstra<Graph> dijkstra(graph);
    dijkstra.run(source, target);
    auto end = high_resolution_clock::now();
    total_runtime += duration<double>(end - start).count();
  }

  cout<< "Total runtime in seconds for 200 random Dijkstra: " << total_runtime <<endl;

  return 0;
}
