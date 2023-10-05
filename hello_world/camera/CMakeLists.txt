add_executable(ArduCAM
        ArduCAM.cpp
)

# pull in common dependencies
target_link_libraries(ArduCAM pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(ArduCAM)

# add url via pico_set_program_url
example_auto_set_url(ArduCAM)
