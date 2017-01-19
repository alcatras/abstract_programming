//
// Created by kamil on 17.01.17.
//

#ifndef ABSTRACT_PROGRAMMING_COMMANDLINE_H
#define ABSTRACT_PROGRAMMING_COMMANDLINE_H

#include <iostream>

class CommandLine {
public:

    void loop() {

        while (true) {
            std::cout << "> ";

            std::string s;
            std::cin >> s;

            std::cout << s << std::endl;
        }
    }

};


#endif //ABSTRACT_PROGRAMMING_COMMANDLINE_H
