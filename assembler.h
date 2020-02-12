#include "instructions.h"
#include <cstdio>
#include <unordered_map>

using std::unordered_map;

class bf_assembler {
  public:
    bf_assembler(FILE *input)
        : instructions({{'>', new Right()},
                        {'<', new Left()},
                        {'+', new Increment()},
                        {'-', new Decrement()},
                        {'.', new Output()},
                        {',', new Input()},
                        {'[', new JumpForwardIfZero()},
                        {']', new JumpBackIfNotZero()}}),
          source(input) {}

    ~bf_assembler() {
        for (const auto p : instructions)
            delete p.second;
    }

    void assemble() {
        puts(".data\n  memory: .fill 0xffff");
        puts(".text\n  .global _start\n\n_start:");
        puts("  movq $memory,%r8");
        puts("  movl $1,%edx");
        puts("  movl $1,%ebx");
        puts("  movl $4,%eax");

        char ch;
        while ((ch = getc(source)) != EOF)
            if (instructions.find(ch) != instructions.end())
                printf("%s\n", instructions[ch]->to_assembly());

        puts("  movl $0,%ebx");
        puts("  movl $1,%eax");
        puts("  int $0x80");
    }

  private:
    unordered_map<char, Instruction *> instructions;
    FILE *source;
};