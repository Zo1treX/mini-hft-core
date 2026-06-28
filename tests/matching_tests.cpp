#include <cassert>

#include "mini_hft/matching.hpp"

void test_price_priority_for_buy() {
    using namespace mini_hft;

    assert(is_better_price(Side::Buy, 105, 100));
    assert(!is_better_price(Side::Buy, 95, 100));
    assert(!is_better_price(Side::Buy, 100, 100));
}

void test_price_priority_for_sell() {
    using namespace mini_hft;

    assert(is_better_price(Side::Sell, 95, 100));
    assert(!is_better_price(Side::Sell, 105, 100));
    assert(!is_better_price(Side::Sell, 100, 100));
}

void test_side_relation() {
    using namespace mini_hft;

    Order buy{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order sell{
        .id = 2,
        .side = Side::Sell,
        .price = 95,
        .quantity = 10
    };

    Order another_buy{
        .id = 3,
        .side = Side::Buy,
        .price = 101,
        .quantity = 5
    };

    assert(is_opposite_side(buy, sell));
    assert(!is_same_side(buy, sell));

    assert(is_same_side(buy, another_buy));
    assert(!is_opposite_side(buy, another_buy));
}

void test_buy_crosses_sell() {
    using namespace mini_hft;

    Order buy{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order cheap_sell{
        .id = 2,
        .side = Side::Sell,
        .price = 95,
        .quantity = 10
    };

    Order equal_sell{
        .id = 3,
        .side = Side::Sell,
        .price = 100,
        .quantity = 10
    };

    Order expensive_sell{
        .id = 4,
        .side = Side::Sell,
        .price = 105,
        .quantity = 10
    };

    assert(prices_cross(buy, cheap_sell));
    assert(prices_cross(buy, equal_sell));
    assert(!prices_cross(buy, expensive_sell));
}

void test_sell_crosses_buy() {
    using namespace mini_hft;

    Order sell{
        .id = 1,
        .side = Side::Sell,
        .price = 100,
        .quantity = 10
    };

    Order strong_buy{
        .id = 2,
        .side = Side::Buy,
        .price = 105,
        .quantity = 10
    };

    Order equal_buy{
        .id = 3,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order weak_buy{
        .id = 4,
        .side = Side::Buy,
        .price = 95,
        .quantity = 10
    };

    assert(prices_cross(sell, strong_buy));
    assert(prices_cross(sell, equal_buy));
    assert(!prices_cross(sell, weak_buy));
}

void test_same_side_does_not_cross() {
    using namespace mini_hft;

    Order buy_a{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order buy_b{
        .id = 2,
        .side = Side::Buy,
        .price = 90,
        .quantity = 10
    };

    Order sell_a{
        .id = 3,
        .side = Side::Sell,
        .price = 100,
        .quantity = 10
    };

    Order sell_b{
        .id = 4,
        .side = Side::Sell,
        .price = 90,
        .quantity = 10
    };

    assert(!prices_cross(buy_a, buy_b));
    assert(!prices_cross(sell_a, sell_b));
}

void test_can_match() {
    using namespace mini_hft;

    Order buy{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order matching_sell{
        .id = 2,
        .side = Side::Sell,
        .price = 95,
        .quantity = 7
    };

    Order non_matching_sell{
        .id = 3,
        .side = Side::Sell,
        .price = 105,
        .quantity = 7
    };

    Order invalid_sell{
        .id = 4,
        .side = Side::Sell,
        .price = 95,
        .quantity = 0
    };

    assert(can_match(buy, matching_sell));
    assert(!can_match(buy, non_matching_sell));
    assert(!can_match(buy, invalid_sell));
}

void test_executed_quantity() {
    using namespace mini_hft;

    Order buy{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order sell_smaller{
        .id = 2,
        .side = Side::Sell,
        .price = 95,
        .quantity = 7
    };

    Order sell_larger{
        .id = 3,
        .side = Side::Sell,
        .price = 95,
        .quantity = 20
    };

    Order sell_too_expensive{
        .id = 4,
        .side = Side::Sell,
        .price = 105,
        .quantity = 7
    };

    assert(executed_quantity(buy, sell_smaller) == 7);
    assert(executed_quantity(buy, sell_larger) == 10);
    assert(executed_quantity(buy, sell_too_expensive) == 0);
}

void test_constexpr_matching_helpers() {
    using namespace mini_hft;

    static_assert(is_better_price(Side::Buy, 105, 100));
    static_assert(!is_better_price(Side::Buy, 95, 100));

    static_assert(is_better_price(Side::Sell, 95, 100));
    static_assert(!is_better_price(Side::Sell, 105, 100));
}

int main() {
    test_price_priority_for_buy();
    test_price_priority_for_sell();
    test_side_relation();
    test_buy_crosses_sell();
    test_sell_crosses_buy();
    test_same_side_does_not_cross();
    test_can_match();
    test_executed_quantity();
    test_constexpr_matching_helpers();

    return 0;
}