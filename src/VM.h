typedef unsigned char byte;
typedef unsigned short ushort;
typedef void (VM::*INSTRUCTION)(byte *n);

class VM
{

    /**   INSTR ↴  // MODE →
     *            || 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
     * HALT   | 0 || ✔
     * LOAD   | 1 || ✔
     * STORE  | 2 || ✔
     * ADD    | 3 || ✔
     * SUB    | 4 || ✔
     * AND    | 5 || ✔
     * NOT    | 6 || ✔
     * OR     | 8 || ✔
     * NAND   | 8 || ✔
     * XOR    | 9 || ✔
     * JMP_LT | 10|| ✔
     * JMP_GT | 11|| ✔
     * JMP_E  | 12|| ✔
     * BRA_LT | 13|| ✔
     * BRA_GT | 14|| ✔
     * BRA_E  | 15|| ✔
     **/
private:
    void HALT(byte *n);
    void LOAD(byte *n);
    void STORE(byte *n);
    void ADD(byte *n);
    void SUB(byte *n);
    void AND(byte *n);
    void NOT(byte *n);
    void OR(byte *n);
    void NAND(byte *n);
    void XOR(byte *n);
    void JMP_LT(byte *n);
    void JMP_GT(byte *n);
    void JMP_E(byte *n);
    void BRA_LT(byte *n);
    void BRA_GT(byte *n);
    void BRA_E(byte *n);

public:
    int exec();
    byte executionFlags; // 0: Halt, 1?
    byte screen[65536];
    ushort screenPtr;
    byte system[65536];
    byte program[65536];
    ushort programPtr;
    ushort accumulator;
    ushort stack[256];
    byte stackPtr;
    INSTRUCTION INSTRUCTION_SET[16] = {
        HALT,
        LOAD,
        STORE,
        ADD,
        SUB,
        AND,
        NOT,
        OR,
        NAND,
        XOR,
        JMP_LT,
        JMP_GT,
        JMP_E,
        BRA_LT,
        BRA_GT,
        BRA_E,
    };
};
