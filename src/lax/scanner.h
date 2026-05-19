#pragma once

#include "lax/token.h"

namespace lax
{

struct ErrorHandler;

struct ScriptTokens
{
    int errors = 0;
    std::vector<Token> tokens;
};

struct AsmTokens
{
    int errors = 0;
    std::vector<AsmToken> tokens;
};

ScriptTokens
script_tokens_from_source(const std::string_view source, ErrorHandler* error_handler);

AsmTokens
asm_tokens_from_source(std::string_view source, ErrorHandler* error_handler);

std::vector<std::string>
parse_package_path(const std::string& path);

}
