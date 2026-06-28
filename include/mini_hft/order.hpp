#pragma once

#include <cstdint>

namespace mini_hft {

    enum class Side {
        Buy,
        Sell
    };

    struct Order {
        std::uint64_t id;
        Side side;
        std::uint64_t price;
        std::uint64_t quantity;
    };
} // namespace mini_hft