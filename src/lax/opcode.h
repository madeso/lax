#pragma once

namespace lax
{

enum class OpCode : std::uint8_t
{
    Return
};

OpCode opcode_from_byte(std::uint8_t byte);
std::uint8_t byte_from_opcode(OpCode op);

std::optional<OpCode> find_asm_keyword_or_null(std::string_view str);
std::string string_from_opcode(OpCode op);

}
