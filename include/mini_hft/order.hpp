#pragma once

#include <cstdint>
#include <string_view>

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

    constexpr std::string_view to_string(Side side) {
        switch (side) {
            case Side::Buy:
                return "Buy";
            case Side::Sell:
                return "Sell";
        }

        return "Unknown";
    }

} // namespace mini_hft