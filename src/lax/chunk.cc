#include "lax/chunk.h"

#include <iomanip>
#include <sstream>

namespace lax
{

    void Chunk::write(std::uint8_t byte)
    {
        code.push_back(byte);
    }

    OpCode opcode_from_byte(std::uint8_t byte)
    {
        return static_cast<OpCode>(byte);
    }

    // printing

    std::size_t simple_instruction(std::ostream& s, const char* name, std::size_t offset) {
        s << name << "\n";
        return offset + 1;
    }

    std::size_t disassemble_instruction(std::ostream& s, const Chunk& chunk, std::size_t offset) {
        s << std::setw(4) << std::setfill('0') << offset;

        const auto instruction = chunk.code[offset];
        switch (instruction) {
        case OpCode::Return:
            return simple_instruction(s, "Return", offset);
        default:
            s << "Unknown opcode "<< instruction << "\n";
            return offset + 1;
        }
    }

    std::string disassemble_chunk(const Chunk& chunk, const char* name)
    {
        std::ostringstream ss;

        ss << "== " << name << " ==\n";

        for (std::size_t offset = 0; offset < chunk.code.size();) {
            offset = disassemble_instruction(ss, chunk, offset);
        }

        return ss.str();
    }
}
