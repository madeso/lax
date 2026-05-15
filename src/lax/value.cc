#include "lax/value.h"

namespace lax
{

std::string string_from_value(Value v)
{
    return std::to_string(v);
}

void ValueArray::write(Value v)
{
    values.emplace_back(v);
}

}
