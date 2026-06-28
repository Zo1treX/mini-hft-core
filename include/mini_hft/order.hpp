#pragma once

#include <cstdint>
#include <ostream>
#include <string_view>

namespace mini_hft {

    enum class Side {
        Buy,
        Sell
    };

    struct Order {
        std::uint64_t id{};
        Side side{};
        std::uint64_t price{};
        std::uint64_t quantity{};

        bool operator==(const Order& other) const = default;
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

    constexpr bool is_buy(Side side) {
        return side == Side::Buy;
    }

    constexpr bool is_sell(Side side) {
        return side == Side::Sell;
    }

    constexpr Side opposite(Side side) {
        switch (side) {
            case Side::Buy:
                return Side::Sell;
            case Side::Sell:
                return Side::Buy;
        }

        return Side::Buy;
    }

    constexpr bool has_valid_price(const Order& order) {
        return order.price > 0;
    }

    constexpr bool has_valid_quantity(const Order& order) {
        return order.quantity > 0;
    }

    constexpr bool is_valid(const Order& order) {
        return order.id > 0
            && has_valid_price(order)
            && has_valid_quantity(order);
    }

    inline std::ostream& operator<<(std::ostream& out, const Order& order) {
        out << "Order{"
            << "id=" << order.id
            << ", side=" << to_string(order.side)
            << ", price=" << order.price
            << ", quantity=" << order.quantity
            << "}";

        return out;
    }

} // namespace mini_hft