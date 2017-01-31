//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_EVALUATIONNODEFACTORY_H
#define ABSTRACT_PROGRAMMING_EVALUATIONNODEFACTORY_H

#include "EvaluationTree.h"
#include <cstring>

class EvaluationNodeFactory {

    std::vector<EvaluationTree::Node *> nodes;

public:
    typedef std::function<void(std::string &, long, QueryData **)> collector_type;

    EvaluationNodeFactory() : nodes() {};

    ~EvaluationNodeFactory() {
        for (int i = 0; i < nodes.size(); ++i) {
            delete nodes[i];
        }
        nodes.clear();
    }

    EvaluationTree::Node *createKeywordNode(const char *keyword) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            if (s.find(keyword) == 0) {
                return (long) strlen(keyword);
            }
            return -1l;
        });
        nodes.push_back(node);
        return node;
    }

    EvaluationTree::Node *createKeywordNode(const char *keyword, collector_type &collector) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            long length = strlen(keyword);
            if (s.find(keyword) == 0) {
                collector(s, length, data);
                return length;
            }
            return -1l;
        });
        nodes.push_back(node);
        return node;
    }

    EvaluationTree::Node *createWordNode(collector_type &collector) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            long pos = 0;
            while ((s[pos] >= '0' && s[pos] <= '9') || (s[pos] >= 'A' && s[pos] <= 'z' && pos < s.size()))
                pos++;
            collector(s, pos, data);
            return pos;
        });
        nodes.push_back(node);
        return node;
    }

    EvaluationTree::Node *createOperatorNode(std::vector<std::string> ops) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            for (auto it = ops.begin(); it != ops.end(); ++it) {
                if (s.find(*it) == 0) {
                    return (long) it->length();
                }
            }
            return -1l;
        });
        nodes.push_back(node);
        return node;
    }

    EvaluationTree::Node *createOperatorNode(std::vector<std::string> ops, collector_type &collector) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            for (auto it = ops.begin(); it != ops.end(); ++it) {
                if (s.find(*it) == 0) {
                    long pos = it->length();
                    collector(s, pos, data);
                    return pos;
                }
            }
            return -1l;
        });
        nodes.push_back(node);
        return node;
    }

    EvaluationTree::Node *createEndNode(collector_type &collector) {
        EvaluationTree::Node *node = new EvaluationTree::Node([=](std::string &s, QueryData **data) {
            if (s.empty()) {
                collector(s, -1, data);
                return -1l;
            }
            return 0l;
        });
        nodes.push_back(node);
        return node;
    }
};

#endif //ABSTRACT_PROGRAMMING_EVALUATIONNODEFACTORY_H
