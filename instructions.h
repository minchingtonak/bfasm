#define HEAD "%r8"

class Instruction {
    public:
        virtual const char* to_assembly() = 0;
        virtual ~Instruction() {}
};

class Move : public Instruction {

};

class Right : public Move {
    public:
        const char* to_assembly() override {
            return "  inc " HEAD;
        }
};

class Left : public Move {
    public:
        const char* to_assembly() override {
            return "  dec " HEAD;
        }
};

class Increment : public Instruction {
    public:
        const char* to_assembly() override {
            return "  incb (" HEAD ")";
        }
};

class Decrement : public Instruction {
    public:
        const char* to_assembly() override {
            return "  decb (" HEAD ")";
        }
};

class Output : public Instruction {
    public:
        const char* to_assembly() override {
            return "  movl " HEAD "d,%ecx\n  movl $1, %ebx\n  movl $4,%eax\n  int $0x80";
        }
};

class Input : public Instruction {
    public:
        const char* to_assembly() override {
            return "";
        }
};

class Jump : public Instruction {
    
};

class JumpForwardIfZero : public Instruction {
    public:
        const char* to_assembly() override {
            return "";
        }
};

class JumpBackIfNotZero : public Instruction {
    public:
        const char* to_assembly() override {
            return "";
        }
};