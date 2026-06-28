#pragma once

#include <ostream>
#include <string_view>

#include "mini_hft/types.hpp"

namespace mini_hft {

    enum class Side {
        Buy,
        Sell
    };

    struct Order {
        OrderId id{};
        Side side{};
        Price price{};
        Quantity quantity{};

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

    constexpr bool has_valid_id(const Order& order) {
        return order.id > 0;
    }

    constexpr bool has_valid_price(const Order& order) {
        return order.price > 0;
    }

    constexpr bool has_valid_quantity(const Order& order) {
        return order.quantity > 0;
    }

    constexpr bool is_valid(const Order& order) {
        return has_valid_id(order)
            && has_valid_price(order)
            && has_valid_quantity(order);
    }

    constexpr std::uint64_t notional(const Order& order) {
        return order.price * order.quantity;
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