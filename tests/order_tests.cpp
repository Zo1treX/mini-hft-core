#include <cassert>
#include <sstream>
#include <string>

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

    assert(is_valid(valid));

    assert(!is_valid(zero_id));
    assert(!is_valid(bad_price));
    assert(!is_valid(bad_quantity));
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

int main() {
    test_side_to_string();
    test_side_helpers();
    test_opposite_side();
    test_order_equality();
    test_order_validation();
    test_order_output();

    return 0;
}