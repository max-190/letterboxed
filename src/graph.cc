#include "../inc/graph.h"

Node::Node(char letter)
        : letter(letter) {}

Graph::Graph() {

}

Graph::~Graph() {
    Node node, next_node;
    for (auto it = map.begin(); it != map.end(); it++) {
        node = it->second;
        // TODO: check for nullptr?
        while (node.next != nullptr) {
            nextNode == node.next;
            delete node;
        }
        // Delete final node
        delete node;
    }
}

bool Graph::add(char from) {
    return false;
}

bool Graph::add(char from, char dest) {
    return false;
}

bool Graph::remove(char from) {
    return false;
}

bool Graph::remove(char from, char dest) {
    return false;
}