#include <cassert>
#include <sstream>
#include <string>

#include "mini_hft/matching.hpp"
#include "mini_hft/order.hpp"

void test_side_to_string() {
    using namespace mini_hft;

    assert(to_string(Side::Buy) == "Buy");
    assert(to_string(Side::Sell) == "Sell");
}

void test_side_helpers() {
    using namespace mini_hft;

    assert(is_buy(Side::Buy));
    assert(!is_buy(Side::Sell));

    assert(is_sell(Side::Sell));
    assert(!is_sell(Side::Buy));
}

void test_opposite_side() {
    using namespace mini_hft;

    assert(opposite(Side::Buy) == Side::Sell);
    assert(opposite(Side::Sell) == Side::Buy);
}

void test_order_equality() {
    using namespace mini_hft;

    Order a{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order b{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order c{
        .id = 2,
        .side = Side::Sell,
        .price = 200,
        .quantity = 5
    };

    assert(a == b);
    assert(a != c);
}

void test_order_validation() {
    using namespace mini_hft;

    Order valid{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order zero_id{
        .id = 0,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    Order bad_price{
        .id = 1,
        .side = Side::Buy,
        .price = 0,
        .quantity = 10
    };

    Order bad_quantity{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 0
    };

    assert(has_valid_id(valid));
    assert(has_valid_price(valid));
    assert(has_valid_quantity(valid));
    assert(is_valid(valid));

    assert(!has_valid_id(zero_id));
    assert(!is_valid(zero_id));

    assert(!has_valid_price(bad_price));
    assert(!is_valid(bad_price));

    assert(!has_valid_quantity(bad_quantity));
    assert(!is_valid(bad_quantity));
}

void test_notional() {
    using namespace mini_hft;

    Order order{
        .id = 1,
        .side = Side::Buy,
        .price = 100,
        .quantity = 10
    };

    assert(notional(order) == 1000);
}

void test_order_output() {
    using namespace mini_hft;

    Order order{
        .id = 42,
        .side = Side::Sell,
        .price = 150,
        .quantity = 7
    };

    std::ostringstream out;
    out << order;

    assert(out.str() == "Order{id=42, side=Sell, price=150, quantity=7}");
}

void test_constexpr_helpers() {
    using namespace mini_hft;

    static_assert(to_string(Side::Buy) == "Buy");
    static_assert(to_string(Side::Sell) == "Sell");

    static_assert(is_buy(Side::Buy));
    static_assert(is_sell(Side::Sell));

    static_assert(opposite(Side::Buy) == Side::Sell);
    static_assert(opposite(Side::Sell) == Side::Buy);
}

int main() {
    test_side_to_string();
    test_side_helpers();
    test_opposite_side();
    test_order_equality();
    test_order_validation();
    test_notional();
    test_order_output();
    test_constexpr_helpers();

    return 0;
}