if (TARGET tinyusb_device)
    add_executable(hello_usb
<<<<<<< Updated upstream
            ../../../pico-examples-a7fc6cc3561a88b668104baf0e8acc7baaf4f5f0/hello_world/usb/hello_usb9_28.c
            ../../../pico-examples-a7fc6cc3561a88b668104baf0e8acc7baaf4f5f0/hello_world/usb/ltr303.c
            )
=======
            hello_usb.c
            ltr303.c
            ArduCAM.h
            ArduCAM.h
            ArduCAM.cpp
            ArduCAM.cpp
            ov2640_regs.h
            ov5642_regs.h
    )
>>>>>>> Stashed changes

    # pull in common dependencies
    target_link_libraries(hello_usb9_28 pico_stdlib hardware_i2c)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_usb9_28 1)
    pico_enable_stdio_uart(hello_usb9_28 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello_usb9_28)

    # add url via pico_set_program_url
#    example_auto_set_url(hello_usb)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
