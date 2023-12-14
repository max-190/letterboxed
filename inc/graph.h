#ifndef LB_GRAPH_H
#define LB_GRAPH_H

#include <map>

class Node {
public:
    Node(char letter);

    Node(char letter, Node *next);

private:
    Node *next;
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
    void add(char from);
    // Add edge to existing node; adds node if doesn't yet exist
    void add(char from, char dest);
    // Remove node from graph, including in- and outgoing edges
    void remove(char from);
    // Remove edge from graph
    void remove(char from, char dest);

private:
    std::map<char letter, Node node> letter_graph;
};

#endif