#pragma once

#include <string>

#include "lax/opcode.h"

namespace lax
{

struct Chunk
{
    std::vector<std::uint8_t> code;

    void write(std::uint8_t byte);
    void write(OpCode byte);
};

std::string disassemble_chunk(const Chunk& chunk, const char* name);

}
