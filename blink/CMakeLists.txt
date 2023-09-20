add_executable(blink
        blink.c
        ltr303.c
        )

# Add extra include directories
target_include_directories(blink PRIVATE .)

# Link required libraries
target_link_libraries(blink pico_stdlib hardware_i2c)

# Generate extra output files
pico_add_extra_outputs(blink)
