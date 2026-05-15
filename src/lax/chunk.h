#pragma once

#include <string>

#include "lax/opcode.h"
#include "lax/value.h"

namespace lax
{

struct Chunk
{
    std::vector<std::uint8_t> code;
    ValueArray constants;

    void write(std::uint8_t byte);
    void write(OpCode byte);

    std::size_t add_constant(Value v);
};

std::string disassemble_chunk(const Chunk& chunk, const char* name);

}
