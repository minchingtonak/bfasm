#include <getopt.h>
#include "assembler.h"

int main(int argc, char *argv[]) {
    opterr = true;
    int choice, option_index = 0;
    option long_options[] = {{"help", no_argument, nullptr, 'h'},
                             // {"sample", required_argument, nullptr, 's'},
                             {nullptr, 0, nullptr, '\0'}};
    while ((choice = getopt_long(argc, argv, "h", long_options, &option_index)) != -1) {
        switch(choice) {
            case 'h':
                printf("Usage message here");
            break;
            default:
            break;
        }
    }

    bf_assembler assembler(stdin);
    assembler.assemble();
}