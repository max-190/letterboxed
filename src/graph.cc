#include "../inc/graph.h"

Graph::Graph() {

}

void Graph::add(char from) {
    letter_graph.insert({from, std::vector<char>()});
}

void Graph::add(char from, char dest) {
    auto from_it = letter_graph.find(from);

    // Adds node to graph in case it doesn't exist yet
    if (from_it == letter_graph.end()) {
        add(from);
        from_it = letter_graph.find(from);
    }

    if (letter_graph.find(dest) == letter_graph.end()) {
        add(dest);
    }

    // Adds destination node to list of outgoing nodes
    from_it->second.push_back(dest);
}

void Graph::remove(char from) {
    letter_graph.erase(from);
    remove_outgoing(from);
}

void Graph::remove(char from, char dest) {
    std::vector<char> v = letter_graph.find(from)->second;
    for (auto item : v) {
        if (item == dest) {
            item = v.back();
            v.pop_back();
            return;
        }
    }
}

void Graph::print_graph() {
    char print_letter;

    std::cout << "digraph G {" << std::endl;
    for (auto it : letter_graph) {
        print_letter = it.first;
        std::cout << print_letter << " [label=\"" 
                  << print_letter << "\"]" << std::endl;

        std::vector<char> v = it.second;
        for (auto i : v) {
            std::cout << print_letter << " -> " << i << std::endl;
        }
    }
    std::cout << "}" << std::endl;
}

void Graph::remove_outgoing(char dest) {
    for (auto &it : letter_graph) {
        std::vector<char> &v = it.second;
        for (size_t i = 0; i < v.size(); i++) {
            if (v[i] == dest) {
                v[i] = v.back();
                v.pop_back();
                break;
            }
        }
    }
}