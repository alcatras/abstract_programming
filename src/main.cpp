#include <iostream>
#include <fstream>
#include "file/DataWriter.h"
#include "file/BinaryReader.h"

int main(int argc, char **argv) {
    std::cout << "hello\n";

    DataWriter dw = DataWriter();
    const char data[9] = "lalalala";

    std::ofstream os;
    os.open("baza", std::ios_base::binary);
    dw.writeWithLength(0, 8, data, os);
    os.close();

    std::ifstream is;
    is.open("baza", std::ios_base::binary|std::ios_base::in);
    BinaryReader br = BinaryReader();
    std::cout << *(br.read(is, 0));
}