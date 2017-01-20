#include <iostream>
#include <fstream>
#include "command_line/EvaluationTree.h"
#include "command_line/evaluation.h"
#include "command_line/CommandLineInterface.h"

int main(int argc, char **argv) {

    CommandLineInterface cmd;

    cmd.loop();
}