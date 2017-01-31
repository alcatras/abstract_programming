#include "command_line/CommandLineInterface.h"
#include "DatabaseContext.h"

int main(int argc, char **argv) {
    DatabaseContext context;

    CommandLineInterface cmd(&context);
    cmd.loop();
}