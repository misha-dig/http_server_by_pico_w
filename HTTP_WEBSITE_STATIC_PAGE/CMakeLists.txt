cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(http_server_by_pico_w C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(http_server_by_pico_w
    main.c
)

pico_enable_stdio_usb(http_server_by_pico_w 1)
pico_enable_stdio_uart(http_server_by_pico_w 1)

pico_add_extra_outputs(http_server_by_pico_w)

target_include_directories(http_server_by_pico_w PRIVATE ${CMAKE_CURRENT_LIST_DIR} )

target_compile_definitions(http_server_by_pico_w PRIVATE
        WIFI_SSID=\"${WIFI_SSID}\"
        WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
)

target_link_libraries(http_server_by_pico_w
        pico_cyw43_arch_lwip_threadsafe_background
        pico_lwip_http
        pico_stdlib
        hardware_adc
)
