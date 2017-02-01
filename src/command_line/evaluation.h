//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_EVALUATION_H
#define ABSTRACT_PROGRAMMING_EVALUATION_H

#include "EvaluationTree.h"
#include "EvaluationNodeFactory.h"
#include "../DatabaseContext.h"

namespace et {

    template<typename T>
    EvaluationNodeFactory::collector_type init_collector = [](std::string &s, long l, QueryData **data) {
        *data = new T();
    };

    template<typename T>
    EvaluationNodeFactory::collector_type table_name_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->table_name = s.substr(0, l);
    };

    template<typename T>
    EvaluationNodeFactory::collector_type attribute_name_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->attributes.push_back(std::make_pair(s.substr(0, l), ""));
    };

    template<typename T>
    EvaluationNodeFactory::collector_type attribute_value_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->attributes.back().second = s.substr(0, l);
    };

    template<typename T>
    EvaluationNodeFactory::collector_type predicate_name_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->predicates.push_back(predicate());
        reinterpret_cast<T *>(*data)->predicates.back().lhs = s.substr(0, l);
    };

    template<typename T>
    EvaluationNodeFactory::collector_type predicate_op_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->predicates.back().op = s.substr(0, l);
    };

    template<typename T>
    EvaluationNodeFactory::collector_type predicate_value_collector = [](std::string &s, long l, QueryData **data) {
        reinterpret_cast<T *>(*data)->predicates.back().rhs = s.substr(0, l);
    };

    void branch_create(EvaluationTree::Node *root, EvaluationNodeFactory &factory, DatabaseContext *context) {

        EvaluationNodeFactory::collector_type end_collector = [&](std::string &s, long l, QueryData **data) {
            TableNameWithAttributes *create_data = reinterpret_cast<TableNameWithAttributes *>(*data);

            context->getTableHandler().createTable(*create_data);

//            std::cout << "create table\ntable name: " << create_data->table_name << std::endl;
//            for (int i = 0; i < create_data->attributes.size(); ++i) {
//                std::cout << create_data->attributes[i].first << " " << create_data->attributes[i].second << std::endl;
//            }
            delete *data;
        };

        EvaluationTree::Node *kw_create = factory.createKeywordNode("create", init_collector<TableNameWithAttributes>);
        EvaluationTree::Node *kw_table = factory.createKeywordNode("table");
        EvaluationTree::Node *kw_lpar = factory.createKeywordNode("(");
        EvaluationTree::Node *kw_comma = factory.createKeywordNode(",");
        EvaluationTree::Node *kw_rpar = factory.createKeywordNode(")", end_collector);

        EvaluationTree::Node *nw_tname = factory.createWordNode(table_name_collector<TableNameWithAttributes>);
        EvaluationTree::Node *nw_ftype = factory.createWordNode(attribute_name_collector<TableNameWithAttributes>);
        EvaluationTree::Node *nw_fname = factory.createWordNode(attribute_value_collector<TableNameWithAttributes>);

        root->addNext(kw_create);
        kw_create->addNext(kw_table);
        kw_table->addNext(nw_tname);
        nw_tname->addNext(kw_lpar);
        kw_lpar->addNext(nw_ftype);
        nw_ftype->addNext(nw_fname);

        nw_fname->addNext(kw_rpar);
        nw_fname->addNext(kw_comma);

        kw_comma->addNext(nw_ftype);
    }

    EvaluationTree::Node *where_clause(EvaluationTree::Node *node, EvaluationNodeFactory &factory) {
        EvaluationTree::Node *kw_where = factory.createKeywordNode("where");
        EvaluationTree::Node *kw_lpar = factory.createKeywordNode("(");
        EvaluationTree::Node *kw_rpar = factory.createKeywordNode(")");

        EvaluationTree::Node *nw_attr_name = factory.createWordNode(predicate_name_collector<TableNameWithWhere>);
        EvaluationTree::Node *nw_attr_value = factory.createWordNode(predicate_value_collector<TableNameWithWhere>);

        EvaluationTree::Node *op_cmp = factory.createOperatorNode({"="},
                                                                  predicate_op_collector<TableNameWithWhere>);
        EvaluationTree::Node *op_and = factory.createOperatorNode({"and"});

        node->addNext(kw_where);

        kw_where->addNext(kw_lpar);
        kw_lpar->addNext(nw_attr_name);
        nw_attr_name->addNext(op_cmp);
        op_cmp->addNext(nw_attr_value);

        nw_attr_value->addNext(kw_rpar);
        nw_attr_value->addNext(op_and);

        op_and->addNext(nw_attr_name);

        return kw_rpar;
    }

    void branch_delete(EvaluationTree::Node *root, EvaluationNodeFactory &factory, DatabaseContext *context) {

        EvaluationNodeFactory::collector_type end_table_collector = [&](std::string &s, long l, QueryData **data) {
            TableName *delete_data = reinterpret_cast<TableName *>(*data);

            std::cout << "delete table\ntable name: " << delete_data->table_name << std::endl;
            delete *data;
        };

        EvaluationNodeFactory::collector_type end_rec_collector = [&](std::string &s, long l, QueryData **data) {
            TableNameWithWhere *delete_data = reinterpret_cast<TableNameWithWhere *>(*data);

            std::cout << "delete from table\ntable name: " << delete_data->table_name << "\n" << "where" << std::endl;
            for (auto it = delete_data->predicates.begin(); it != delete_data->predicates.end(); ++it) {
                std::cout << it->lhs << " " << it->op << " " << it->rhs << std::endl;
            }
            delete *data;
        };

        EvaluationTree::Node *kw_delete = factory.createKeywordNode("delete");

        EvaluationTree::Node *kw_from = factory.createKeywordNode("from", init_collector<TableNameWithWhere>);

        EvaluationTree::Node *nw_rec_tname = factory.createWordNode(table_name_collector<TableNameWithWhere>);

        EvaluationTree::Node *kw_table = factory.createKeywordNode("table", init_collector<TableName>);
        EvaluationTree::Node *nw_table_tname = factory.createWordNode(table_name_collector<TableName>);
        EvaluationTree::Node *end_table = factory.createEndNode(end_table_collector);

        EvaluationTree::Node *end_rec = factory.createEndNode(end_rec_collector);

        root->addNext(kw_delete);

        kw_delete->addNext(kw_table);
        kw_table->addNext(nw_table_tname);
        nw_table_tname->addNext(end_table);

        kw_delete->addNext(kw_from);
        kw_from->addNext(nw_rec_tname);

        EvaluationTree::Node *where = where_clause(nw_rec_tname, factory);

        nw_rec_tname->addNext(end_rec);

        where->addNext(end_rec);
    }

    void branch_select(EvaluationTree::Node *root, EvaluationNodeFactory &factory, DatabaseContext *context) {
        EvaluationNodeFactory::collector_type end_collector = [&](std::string &s, long l, QueryData **data) {
            TableNameWithWhere *select_data = reinterpret_cast<TableNameWithWhere *>(*data);

            std::cout << "select from table\ntable name: " << select_data->table_name << "\n" << "where" << std::endl;
            for (auto it = select_data->predicates.begin(); it != select_data->predicates.end(); ++it) {
                std::cout << it->lhs << " " << it->op << " " << it->rhs << std::endl;
            }
            delete *data;
        };

        EvaluationTree::Node *kw_select = factory.createKeywordNode("select", init_collector<TableNameWithWhere>);
        EvaluationTree::Node *kw_from = factory.createKeywordNode("from");

        EvaluationTree::Node *nw_tname = factory.createWordNode(table_name_collector<TableNameWithWhere>);

        EvaluationTree::Node *end = factory.createEndNode(end_collector);

        root->addNext(kw_select);
        kw_select->addNext(kw_from);
        kw_from->addNext(nw_tname);

        EvaluationTree::Node *where = where_clause(nw_tname, factory);

        where->addNext(end);
    }

    void branch_insert(EvaluationTree::Node *root, EvaluationNodeFactory &factory, DatabaseContext *context) {

        EvaluationNodeFactory::collector_type end_collector = [&](std::string &s, long l, QueryData **data) {
            TableNameWithValues *insert_data = reinterpret_cast<TableNameWithValues *>(*data);

            std::cout << "insert into table\ntable name: " << insert_data->table_name << "\n" << "where" << std::endl;
            for (auto it = insert_data->values.begin(); it != insert_data->values.end(); ++it) {
                std::cout << *it << std::endl;
            }

            std::unique_ptr<TableDefinition> table = context->getTableHandler().getTableByName(s);

            auto index_handler = std::unique_ptr<DataTypeHandler>(new IndexHandler((*table).indexPosition));
            auto index_file = context->getIndexFile();
            auto data_file = context->getDataFile();

            for (int i = 0; i < (*table).attributes.size(); ++i){
                auto attr_handler = std::unique_ptr<DataTypeHandler>((*(*table).attributes.at(i)).getHandler());
                std::string attr_value = insert_data->values.at(i);
                (*attr_handler).setData(attr_value);
                long address = data_file.write(attr_handler);   //TODO czy index nie mial przechowywac adresu poczatku wiersza? po co nam adresy kazdego pola w bazie
            }

            index_file.read(index_handler);
            (*index_handler).addIndex(address);
            (*table).indexPosition = context->getIndexFile().write(index_handler);

            delete *data;
        };

        EvaluationNodeFactory::collector_type value_collector = [](std::string &s, long l, QueryData **data) {
            TableNameWithValues *insert_data = reinterpret_cast<TableNameWithValues *>(*data);

            insert_data->values.push_back(s.substr(0, l));
        };

        EvaluationTree::Node *kw_insert = factory.createKeywordNode("insert", init_collector<TableNameWithValues>);
        EvaluationTree::Node *kw_into = factory.createKeywordNode("into");

        EvaluationTree::Node *kw_lpar = factory.createKeywordNode("(");
        EvaluationTree::Node *kw_comma = factory.createKeywordNode(",");
        EvaluationTree::Node *kw_rpar = factory.createKeywordNode(")", end_collector);

        EvaluationTree::Node *nw_tname = factory.createWordNode(table_name_collector<TableNameWithValues>);
        EvaluationTree::Node *nw_value = factory.createWordNode(value_collector);

        root->addNext(kw_insert);
        kw_insert->addNext(kw_into);
        kw_into->addNext(nw_tname);
        nw_tname->addNext(kw_lpar);
        kw_lpar->addNext(nw_value);

        nw_value->addNext(kw_comma);
        kw_comma->addNext(nw_value);

        nw_value->addNext(kw_rpar);
    }
}

#endif //ABSTRACT_PROGRAMMING_EVALUATION_H
