#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    std::cout << "dupa";

    std::ifstream stream("baza", std::ios_base::in);
    char x = 'a';
    stream >> x;
    std::cout << x;
    stream.seekg(0);
    stream >> x;
    std::cout << x;

}