#ifndef LB_GRAPH_H
#define LB_GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
public:
    // Create empty graph
    Graph();
    // Add node to graph.
    void add(char from);
    // Add edge to existing node; adds both nodes in case they do not yet exist.
    void add(char from, char dest);
    // Remove node from graph, including in- and outgoing edges.
    void remove(char from);
    // Removes edge from graph.
    void remove(char from, char dest);
    // Prints the graph using DOT-notation to the console. 
    // Graph can be viewed using Graphviz, for example with 
    // https://dreampuf.github.io/GraphvizOnline/
    void print_graph();

private:
    // Removes outgoing edges of all nodes pointing to dest
    void remove_outgoing(char dest);

    // Map containing Key char representing the node value
    // and a Value vector<char> representing the list of outgoing edges
    std::unordered_map<char, std::vector<char>> letter_graph;
};

#endif