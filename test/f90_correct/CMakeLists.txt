enable_language(Fortran)

set(Fortran_MODULE_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_library(f90_check_mod
    ${CMAKE_CURRENT_SOURCE_DIR}/src/check_mod.f90
    ${CMAKE_CURRENT_SOURCE_DIR}/src/fs24336_module.f90
)

target_link_libraries(f90_check_mod
    ieee_arithmetic
)

file(GLOB F90_TESTS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f90"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.f"
)

foreach(F90_TEST ${F90_TESTS})
    get_filename_component(F90_TEST_NAME ${F90_TEST} NAME_WE)
    
    if(F90_TEST_NAME STREQUAL "check_mod")
        continue()
    endif()

    if(F90_TEST_NAME STREQUAL "fs24336_module")
        continue()
    endif()
    
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
        f90_check_mod
    )

    target_include_directories(${F90_TEST_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )

    target_link_libraries(${F90_TEST_NAME}
        flangrti_shared
        flang_shared
        ompstub_shared
        flangmain
        f90_check_mod
    )

    add_test("RUN_${MP_TEST_NAME}"
        ${CMAKE_BINARY_DIR}/bin/${F90_TEST_NAME}
    )
endforeach()
