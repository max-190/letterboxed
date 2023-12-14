#include "../inc/graph.h"

Node::Node(char letter)
        : letter(letter), next(nullptr) {}

Node::Node(char letter, Node *next)
        : letter(letter), next(next) {}

Graph::Graph() {

}

Graph::~Graph() {
    Node node, next_node;
    for (auto it = letter_graph.begin(); it != letter_graph.end(); it++) {
        node = it->second;
        // TODO: check for nullptr?
        while (node.next != nullptr) {
            next_node == node.next;
            delete node;
        }
        // Delete final node
        delete node;
    }
}

void Graph::add(char from) {
    letter_graph.insert(from, nullptr);
}

void Graph::add(char from, char dest) {
    if (letter_graph.find(from) == letter_graph.end()) {
        add(from);
    }

    auto item = letter_graph.find(from);
    Node next_node = item->second;
    item->second = new Node(dest, next_node);
}

void Graph::remove(char from) {
    return false;
}

void Graph::remove(char from, char dest) {
    return false;
}