#include "../inc/graph.h"

Node::Node() {}

Node::Node(char letter)
        : letter(letter), next(nullptr) {}

Node::Node(char letter, Node *next)
        : letter(letter), next(next) {}

Graph::Graph() {

}

Graph::~Graph() {
    Node *node, *old_node;
    for (auto it = letter_graph.begin(); it != letter_graph.end(); it++) {
        old_node = it->second;
        if (old_node == nullptr) {
            continue;
        }
        node = old_node->next;
        while (node != nullptr) {
            delete old_node;
            old_node = node;
            node = node->next;
        }
    }
}

void Graph::add(char from) {
    letter_graph.insert({from, nullptr});
}

void Graph::add(char from, char dest) {
    auto item = letter_graph.find(from);

    if (item == letter_graph.end()) {
        add(from);
    }

    Node *next_node = item->second;
    item->second = new Node(dest, next_node);
}

void Graph::remove(char from) {
    Node *node = letter_graph.find(from)->second;

    if (node == nullptr) {
        return;
    }

    while (node->next != nullptr) {
        remove(node);
    }
    delete node;
    letter_graph.erase(from);
}

void Graph::remove(char from, char dest) {
    Node *node = letter_graph.find(from)->second;

    if (node == nullptr) {
        return;
    }

    Node *node_before = node;
    node = node->next;
    
    while (node != nullptr) {
        if (node->letter == dest) {
            remove(node_before);
        }
        node_before = node;
        node = node->next;
    }
}

void Graph::remove(Node *node) {
    if (node == nullptr || node->next == nullptr) {
        return;
    }

    Node *delete_node = node->next;
    node->next = delete_node->next;
    delete delete_node;
}