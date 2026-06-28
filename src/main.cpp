#include <iostream>

#include "mini_hft/order.hpp"

int main() {
    mini_hft::Order order{
        .id = 1,
        .side = mini_hft::Side::Buy,
        .price = 100,
        .quantity = 10
    };

    std::cout << order << std::endl;

    if (mini_hft::is_valid(order)) {
        std::cout << "Order is valid" << std::endl;
    } else {
        std::cout << "Order is invalid" << std::endl;
    }

    std::cout << "Opposite side: " << mini_hft::to_string(mini_hft::opposite(order.side)) << std::endl;

    return 0;
}