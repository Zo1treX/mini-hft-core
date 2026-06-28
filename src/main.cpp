#include <iostream>

#include "mini_hft/matching.hpp"
#include "mini_hft/order.hpp"

int main() {
    mini_hft::Order buy_order{
        .id = 1,
        .side = mini_hft::Side::Buy,
        .price = 100,
        .quantity = 10
    };

    mini_hft::Order sell_order{
        .id = 2,
        .side = mini_hft::Side::Sell,
        .price = 95,
        .quantity = 7
    };

    std::cout << buy_order << std::endl;
    std::cout << sell_order << std::endl;

    std::cout << "Can match: " << std::boolalpha << mini_hft::can_match(buy_order, sell_order) << std::endl;
    std::cout << "Executed quantity: "  << mini_hft::executed_quantity(buy_order, sell_order) << std::endl;

    return 0;
}