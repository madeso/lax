#pragma once

#include <vector>

namespace lax
{

using Value = double;

std::string string_from_value(Value v);

struct ValueArray
{
    std::vector<Value> values;

    void write(double d);
};

}
