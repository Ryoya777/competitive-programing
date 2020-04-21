#include <cstdint>
template <uint_fast64_t mod> class modint{
    using u64 = uint_least64_t;

public:
    u64 a;

    constexpr modint(const u64 num = 0) noexcept :a(num % mod){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept {return a;}

};  