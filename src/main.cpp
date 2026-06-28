#include <iostream>

#include "mini_hft/order.hpp"

int main() {
    mini_hft::Order order{
        .id = 1,
        .side = mini_hft::Side::Buy,
        .price = 100,
        .quantity = 10
    };

    std::cout << "Order id: " << order.id << std::endl;
    std::cout << "Price: " << order.price << std::endl;
    std::cout << "Quantity: " << order.quantity << std::endl;

    return 0;
}