#include "VM.h"

int VM::exec()
{
    bool notHalted;
    do
    {
        notHalted = (executionFlags >> 0) & 1U;

        // Load next instruction
        byte b = program[programPtr];

        // Get instruction mode
        byte mode = b >> 4;
        byte *args;

        switch (mode)
        {
        case 0:
        default:
            // Default behaviour: pass next byte and increment programPtr
            programPtr++;
            args = &program[programPtr];
            break;
        }

        // Execute instruction
        byte instruction = b & 0x0F;
        INSTRUCTION_SET[instruction](args);

        programPtr++;
    } while (notHalted);
    return 0;
}

void VM::HALT(byte *n)
{
    // Clears execution flag bit
    executionFlags &= ~(1UL << 0);
}

void VM::LOAD(byte *n)
{
    accumulator = *n;
}

void VM::STORE(byte *n)
{
    *n = accumulator;
}

void VM::ADD(byte *n)
{
    accumulator += *n;
}

void VM::SUB(byte *n)
{
    accumulator -= *n;
}

void VM::AND(byte *n)
{
    accumulator &= *n;
}

void VM::NOT(byte *n)
{
    accumulator = ~*n;
}

void VM::OR(byte *n)
{
    accumulator |= *n;
}

void VM::NAND(byte *n)
{
    ushort tmp = accumulator;
    tmp &= *n;
    accumulator = ~tmp;
}

void VM::XOR(byte *n)
{
    accumulator ^= *n;
}

void VM::JMP_LT(byte *n)
{
    if (accumulator < *n)
    {
        programPtr = program[programPtr + 1];
    }
}

void VM::JMP_GT(byte *n)
{
    if (accumulator > *n)
    {
        programPtr = program[programPtr + 1];
    }
}

void VM::JMP_E(byte *n)
{
    if (accumulator == *n)
    {
        programPtr = program[programPtr + 1];
    }
}

void VM::BRA_LT(byte *n)
{
    if (accumulator < *n)
    {
        stackPtr++;
        stack[stackPtr] = programPtr;
        programPtr = program[programPtr + 1];
    }
}

void VM::BRA_GT(byte *n)
{
    if (accumulator > *n)
    {
        stackPtr++;
        stack[stackPtr] = programPtr;
        programPtr = program[programPtr + 1];
    }
}

void VM::BRA_E(byte *n)
{
    if (accumulator == *n)
    {
        stackPtr++;
        stack[stackPtr] = programPtr;
        programPtr = program[programPtr + 1];
    }
}