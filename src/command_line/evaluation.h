//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_EVALUATION_H
#define ABSTRACT_PROGRAMMING_EVALUATION_H

#include "EvaluationTree.h"
#include "EvaluationNodeFactory.h"

namespace et {

    template <typename T>
    EvaluationNodeFactory::collector_type init_collector = [] (std::string& s, long l, QueryData** data) {
        *data = new T;
    };

    template <typename T>
    EvaluationNodeFactory::collector_type table_name_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->table_name = s.substr(0, l);
    };

    template <typename T>
    EvaluationNodeFactory::collector_type attribute_name_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->attributes.push_back(std::make_pair(s.substr(0, l), ""));
    };

    template <typename T>
    EvaluationNodeFactory::collector_type attribute_value_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->attributes.back().second = s.substr(0, l);
    };

    template <typename T>
    EvaluationNodeFactory::collector_type predicate_name_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->predicates.push_back(predicate());
        reinterpret_cast<T*>(*data)->predicates.back().lhs = s.substr(0, l);
    };

    template <typename T>
    EvaluationNodeFactory::collector_type predicate_op_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->predicates.back().op = s.substr(0, l);
    };

    template <typename T>
    EvaluationNodeFactory::collector_type predicate_value_collector = [] (std::string& s, long l, QueryData** data) {
        reinterpret_cast<T*>(*data)->predicates.back().rhs = s.substr(0, l);
    };

    void branch_create(EvaluationTree::Node *root, EvaluationNodeFactory& factory) {

        EvaluationNodeFactory::collector_type end_collector = [] (std::string& s, long l, QueryData** data) {
            CreateTableQueryData* create_data = reinterpret_cast<CreateTableQueryData*>(*data);

            std::cout << "create table\ntable name: " << create_data->table_name << std::endl;
            for(int i = 0; i < create_data->attributes.size(); ++i) {
                std::cout << create_data->attributes[i].first << " " << create_data->attributes[i].second << std::endl;
            }
            delete *data;
        };

        EvaluationTree::Node* kw_create = factory.createKeywordNode("create", init_collector<CreateTableQueryData>);
        EvaluationTree::Node* kw_table = factory.createKeywordNode("table");
        EvaluationTree::Node* kw_lpar = factory.createKeywordNode("(");
        EvaluationTree::Node* kw_comma = factory.createKeywordNode(",");
        EvaluationTree::Node* kw_rpar = factory.createKeywordNode(")");

        EvaluationTree::Node* nw_tname = factory.createWordNode(table_name_collector<CreateTableQueryData>);
        EvaluationTree::Node* nw_ftype = factory.createWordNode(attribute_name_collector<CreateTableQueryData>);
        EvaluationTree::Node* nw_fname = factory.createWordNode(attribute_value_collector<CreateTableQueryData>);

        EvaluationTree::Node* end_node = factory.createEndNode(end_collector);

        root->addNeighbour(kw_create);
        kw_create->addNeighbour(kw_table);
        kw_table->addNeighbour(nw_tname);
        nw_tname->addNeighbour(kw_lpar);
        kw_lpar->addNeighbour(nw_ftype);
        nw_ftype->addNeighbour(nw_fname);

        nw_fname->addNeighbour(kw_rpar);
        nw_fname->addNeighbour(kw_comma);

        kw_comma->addNeighbour(nw_ftype);

        kw_rpar->addNeighbour(end_node);
    }

    void branch_delete(EvaluationTree::Node *root, EvaluationNodeFactory& factory) {

        EvaluationNodeFactory::collector_type end_table_collector = [] (std::string& s, long l, QueryData** data) {
            TableQueryData* delete_data = reinterpret_cast<TableQueryData*>(*data);

            std::cout << "delete table\ntable name: " << delete_data->table_name << std::endl;
            delete *data;
        };

        EvaluationNodeFactory::collector_type end_rec_collector = [] (std::string& s, long l, QueryData** data) {
            DeleteRecordsQueryData* delete_data = reinterpret_cast<DeleteRecordsQueryData*>(*data);

            std::cout << "delete from table\ntable name: " << delete_data->table_name << "\n" << "where" << std::endl;
            for(auto it = delete_data->predicates.begin(); it != delete_data->predicates.end(); ++it) {
                std::cout << it->lhs << " " << it->op << " " << it->rhs << std::endl;
            }
            delete *data;
        };

        EvaluationTree::Node* kw_delete = factory.createKeywordNode("delete");

        EvaluationTree::Node* kw_from = factory.createKeywordNode("from", init_collector<DeleteRecordsQueryData>);
        EvaluationTree::Node* kw_where = factory.createKeywordNode("where");
        EvaluationTree::Node* kw_lpar = factory.createKeywordNode("(");
        EvaluationTree::Node* kw_rpar = factory.createKeywordNode(")");

        EvaluationTree::Node* nw_rec_tname = factory.createWordNode(table_name_collector<DeleteRecordsQueryData>);
        EvaluationTree::Node* nw_attr_name = factory.createWordNode(predicate_name_collector<DeleteRecordsQueryData>);
        EvaluationTree::Node* nw_attr_value = factory.createWordNode(predicate_value_collector<DeleteRecordsQueryData>);

        EvaluationTree::Node* op_cmp = factory.createOperatorNode({ "=" }, predicate_op_collector<DeleteRecordsQueryData>);
        EvaluationTree::Node* op_and = factory.createOperatorNode({ "and" });

        EvaluationTree::Node* end_rec = factory.createEndNode(end_rec_collector);

        EvaluationTree::Node* kw_table = factory.createKeywordNode("table", init_collector<TableQueryData>);
        EvaluationTree::Node* nw_table_tname = factory.createWordNode(table_name_collector<TableQueryData>);
        EvaluationTree::Node* end_table = factory.createEndNode(end_table_collector);

        root->addNeighbour(kw_delete);

        kw_delete->addNeighbour(kw_table);
        kw_table->addNeighbour(nw_table_tname);
        nw_table_tname->addNeighbour(end_table);

        kw_delete->addNeighbour(kw_from);
        kw_from->addNeighbour(nw_rec_tname);

        nw_rec_tname->addNeighbour(kw_where);
        nw_rec_tname->addNeighbour(end_rec);

        kw_where->addNeighbour(kw_lpar);
        kw_lpar->addNeighbour(nw_attr_name);
        nw_attr_name->addNeighbour(op_cmp);
        op_cmp->addNeighbour(nw_attr_value);

        nw_attr_value->addNeighbour(kw_rpar);
        nw_attr_value->addNeighbour(op_and);

        kw_rpar->addNeighbour(end_rec);
        op_and->addNeighbour(nw_attr_name);
    }
}

#endif //ABSTRACT_PROGRAMMING_EVALUATION_H
