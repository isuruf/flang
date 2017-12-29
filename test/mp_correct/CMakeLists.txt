enable_language(Fortran)

set(Fortran_MODULE_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

file(GLOB MP_TESTS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f90"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f"
)

foreach(MP_TEST ${MP_TESTS})
    get_filename_component(MP_TEST_NAME ${MP_TEST} NAME_WE)
    set(MP_TEST_NAME "TEST_MP_CORRECT_${MP_TEST_NAME}")

    add_executable(${MP_TEST_NAME}
        ${MP_TEST}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/check.c
    )

    add_dependencies(${MP_TEST_NAME}
        flang1
        flang2
        flang_static
        flang_shared
        flangrti_shared
        flangmain
    )

    target_include_directories(${MP_TEST_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )

    target_link_libraries(${MP_TEST_NAME}
        flangrti_shared
        flang_shared
        ompstub_shared
        flangmain
    )

    # target_compile_options(${MP_TEST_NAME}
    #    PRIVATE
    #    -module
    #    ${CMAKE_CURRENT_SOURCE_DIR}/src
    #)
    add_test("RUN_${MP_TEST_NAME}"
        ${MP_TEST_NAME}
    )
endforeach()
