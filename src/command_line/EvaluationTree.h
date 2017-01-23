//
// Created by kamil on 19.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_EVEALUATION_TREE_H
#define ABSTRACT_PROGRAMMING_EVEALUATION_TREE_H


#include <vector>
#include <functional>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include "QueryData.h"

class EvaluationTree {
public:

    class Node {
    public:
        typedef std::function<long(std::string &, QueryData **)> predicate_type;

        QueryData **data;

        std::vector<Node *> neighbors;
        predicate_type predicate;

        Node(const predicate_type &predicate) :
                neighbors(), predicate(predicate), data() {
        }

        void addNeighbour(Node *node) {
            node->data = data;
            neighbors.emplace_back(node);
        }
    };

private:
    Node root;

public:
    EvaluationTree() : root([](std::string &, QueryData **) { return true; }) {
        root.data = new QueryData *;
    }

    ~EvaluationTree() {
        delete root.data;
    }

    Node *getRootNode() {
        return &root;
    }

    void evaluate(std::string &dql) {
        long pos = 0;
        Node *currentNode = &root;

        do {
            bool found = false;
            for (auto n: currentNode->neighbors) {
                pos = n->predicate(dql, n->data);

                if (pos > 0) {

                    while (isspace(dql[pos]))
                        pos++;

                    dql = std::move(dql.substr((unsigned long) pos, dql.size() - pos));
                    currentNode = n;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        } while (pos >= 0);
    }
};


#endif //ABSTRACT_PROGRAMMING_TREE_H
