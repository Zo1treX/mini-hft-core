#pragma once

#include "mini_hft/order.hpp"

namespace mini_hft {

    constexpr bool is_better_price(Side side, Price lhs, Price rhs) {
        switch (side) {
            case Side::Buy:
                return lhs > rhs;
            case Side::Sell:
                return lhs < rhs;
        }

        return false;
    };

    constexpr bool is_same_side(const Order& lhs, const Order& rhs) {
        return lhs.side == rhs.side;
    }

    constexpr bool is_opposite_side(const Order& lhs, const Order& rhs) {
        return lhs.side != rhs.side;
    }

    constexpr bool prices_cross(const Order& incoming, const Order& resting) {
        if (incoming.side == Side::Buy && resting.side == Side::Sell) {
            return incoming.price >= resting.price;
        }

        if (incoming.side == Side::Sell && resting.side == Side::Buy) {
            return incoming.price <= resting.price;
        }

        return false;
    }

    constexpr bool can_match(const Order& incoming, const Order& resting) {
        return is_valid(incoming) && is_valid(resting) && is_opposite_side(incoming, resting) && prices_cross(incoming, resting);
    }

    constexpr Quantity executed_quantity(const Order& incoming, const Order& resting) {
        if (!can_match(incoming, resting)) {
            return 0;
        }

        return incoming.quantity < resting.quantity ? incoming.quantity : resting.quantity;
    }

} // namespace mini_hft