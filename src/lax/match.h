#pragma once

namespace lax
{


template<class... Ts>
struct overloads : Ts... { using Ts::operator()...; };
// Deduction guide for overloads
template<class... Ts> overloads(Ts...) -> overloads<Ts...>;

template <typename V>
[[nodiscard]] constexpr auto match(V&& v) {
  return [&v](auto... fs) -> decltype(auto) {
    return std::visit(overloads{std::move(fs)...}, std::forward<V>(v));
  };
}

}
