add_executable(order_tests
    order_tests.cpp
)

target_link_libraries(order_tests PRIVATE
    mini_hft
)

add_test(NAME order_tests COMMAND  order_tests)