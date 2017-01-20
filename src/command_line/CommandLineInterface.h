//
// Created by kamil on 20.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_COMMANDLINEINTERFACE_H
#define ABSTRACT_PROGRAMMING_COMMANDLINEINTERFACE_H


#include "evaluation.h"

class CommandLineInterface {
    EvaluationNodeFactory evaluationNodeFactory;
    EvaluationTree evaluationTree;

public:
    CommandLineInterface() : evaluationTree(), evaluationNodeFactory() {
        EvaluationTree::Node *root = evaluationTree.getRootNode();

        et::branch_create(root, evaluationNodeFactory);
        et::branch_delete(root, evaluationNodeFactory);

//        std::string create = "create table dupa (string name, string surname, integer age)";
//        evaluationTree.evaluate(create);
//        std::cout << "-----" << std::endl;
//
//        std::string delete_table = "delete table dupa";
//        evaluationTree.evaluate(delete_table);
//        std::cout << "-----" << std::endl;
//
//        std::string delete_from_table = "delete from dupa";
//        evaluationTree.evaluate(delete_from_table);
//        std::cout << "-----" << std::endl;
//
//        std::string delete_records = "delete from dupa where (name = ahmed and surname = duda)";
//        evaluationTree.evaluate(delete_records);
//        std::cout << "-----" << std::endl;
    }

    ~CommandLineInterface() {

    }

    void loop() {
        print_greetings();

        while (true) {
            std::cout << "> ";

            std::string query;
            std::getline(std::cin, query, '\n');

            if (query.find("exit") == 0) {
                break;
            } else if (query.find("help") == 0) {
                print_help();
            } else {
                evaluationTree.evaluate(query);
            }
        }
    }

private:
    void print_horizontal_bar() {
        for (int i = 0; i < 80; ++i) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }

    void print_on_center(std::string s) {
        std::cout << "||";

        long spaces = (80 - 4 - s.length()) / 2;

        for (int i = 0; i < spaces; ++i) {
            std::cout << " ";
        }

        std::cout << s;

        for (int i = 0; i < spaces; ++i) {
            std::cout << " ";
        }

        std::cout << "||" << std::endl;
    }

    void print_greetings() {
        print_horizontal_bar();

        print_on_center("**** simpleDBMS v 1.0.0 ****");
        print_on_center("");
        print_on_center("Type 'help' for list of available commands or 'exit' to quit");

        print_horizontal_bar();
    }

    void print_help() {
        std::cout << "List of available commands:\n"
                  << "  Tables:\n"
                  << "    - Creating new table:\n"
                  << "      > create table [table_name] ([attr_type_1] [attr_name_1], ... , [attr_type_n] [attr_name_n])\n"
                  << "      available data types:\n"
                  << "        [integer] - 8 bit integer number\n"
                  << "        [real]    - 8 bit floating point number\n"
                  << "        [string]  - ASCII encoded string\n"
                  << "        [binary]  - binary data\n"
                  << "    - Deleting table:\n"
                  << "      > delete table [table_name]\n"
                  << "  Records:\n"
                  << "    - Insert new record:\n"
                  << "      > insert into [table_name] ([attr_value_1], ... , [attr_value_n])\n"
                  << "    - Delete records:\n"
                  << "      > delete from [table_name] where ([attr_name_1] [op_1] [attr_value_1] and ... and [attr_name_n] [op_n] [attr_value_n])\n"
                  << "      list of available operators:\n"
                  << "        [=] - attribute equals value\n"
                  << "    - Print records:\n"
                  << "      > select from [table_name] where ([attr_name_1] [op_1] [attr_value_1] and ... and [attr_name_n] [op_n] [attr_value_n])\n"
                  << "      list of available operators:\n"
                  << "        [=] - attribute equals value\n"
                  << "\n"
                  << "  General commands:\n"
                  << "    > help - prints this screen\n"
                  << "    > exit - quits the program\n";
        std::cout << std::endl;
    };
};


#endif //ABSTRACT_PROGRAMMING_COMMANDLINEINTERFACE_H
