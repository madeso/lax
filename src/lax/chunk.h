#pragma once

#include <string>

#include "lax/opcode.h"
#include "lax/value.h"

namespace lax
{

struct SourceRange
{
    std::size_t start;
    std::size_t end;

    constexpr SourceRange(std::size_t s, std::size_t e) : start(s), end(e) {}
    explicit constexpr SourceRange(std::size_t where) : start(where), end(where) {}

    constexpr bool operator==(const SourceRange& other) const {
        return start == other.start && end == other.end;
    }
    constexpr bool operator!=(const SourceRange& other) const {
        return !(*this == other);
    }
};

struct SourceInfo
{
    std::vector<SourceRange> ranges;
};

struct Chunk
{
    std::vector<std::uint8_t> code;
    ValueArray constants;
    SourceInfo source;

    void write(std::uint8_t byte, SourceRange range);
    void write(OpCode byte, SourceRange range);

    std::size_t add_constant(Value v);
};

std::string disassemble_chunk(const Chunk& chunk, const char* name);

}
