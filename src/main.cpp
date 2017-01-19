#include <iostream>
#include <fstream>
#include "file/DataWriter.h"

int main(int argc, char **argv) {
    std::cout << "hello\n";

    std::ifstream stream("baza", std::ios_base::in);
    char x = 'a';
    stream >> x;
    std::cout << x;
    stream.seekg(0);
    stream >> x;
    std::cout << x;

    DataWriter dw = DataWriter();
    const char data[9] = "lalalala";

    std::ofstream os;
    os.open("baza", std::ios_base::out);
    dw.write(0, 0, data, os);
}