#ifndef LB_GRAPH_H
#define LB_GRAPH_H

#include <iostream>
#include <map>

class Node {
public:
    Node();

    Node(char letter);

    Node(char letter, Node *next);

private:
    char letter;
    Node *next;

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
    // Prints the graph using DOT-notation to the console. 
    // Graph can be viewed using Graphviz, for example with 
    // https://dreampuf.github.io/GraphvizOnline/
    void print_graph();

private:
    // Private removal function for node with given pointer.
    // node->next is to be removed.
    void remove(Node *node);

    std::map<char, Node *> letter_graph;
};

#endif