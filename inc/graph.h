#ifndef LB_GRAPH_H
#define LB_GRAPH_H

#include <map>

class Node {
public:
    Node();

private:
    int *next;
    char letter;

    friend class Graph;
};

class Graph {
public:
    // Create empty graph
    Graph();
    // Remove all nodes and edges from graph
    ~Graph();
    // Add node to graph
    bool add(char from);
    // Add edge to existing node; adds node if doesn't yet exist
    bool add(char from, char dest);
    // Remove node from graph, including in- and outgoing edges
    bool remove(char from);
    // Remove edge from graph
    bool remove(char from, char dest);

private:
    std::map<char letter, Node node> map;
};

#endif