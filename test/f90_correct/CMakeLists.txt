enable_language(Fortran)

set(Fortran_MODULE_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

file(GLOB F90_TESTS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f90"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f"
)

foreach(F90_TEST ${F90_TESTS})
    get_filename_component(F90_TEST_NAME ${F90_TEST} NAME_WE)
    set(F90_TEST_NAME "TEST_F90_CORRECT_${F90_TEST_NAME}")

    add_executable(${F90_TEST_NAME}
        ${F90_TEST}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/check.c
    )

    add_dependencies(${F90_TEST_NAME}
        flang1
        flang2
        flang_static
        flang_shared
        flangrti_shared
        flangmain
    )

    target_include_directories(${F90_TEST_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )

    target_link_libraries(${F90_TEST_NAME}
        flangrti_shared
        flang_shared
        oF90stub_shared
        flangmain
    )

    # target_coF90ile_options(${F90_TEST_NAME}
    #    PRIVATE
    #    -module
    #    ${CMAKE_CURRENT_SOURCE_DIR}/src
    #)
    add_test("RUN_${F90_TEST_NAME}"
        ${F90_TEST_NAME}
    )
endforeach()
