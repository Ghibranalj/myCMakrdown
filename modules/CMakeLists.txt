
file(GLOB sub-dir RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

set(list_of_dirs "")
foreach(dir ${sub-dir})
    if ("${dir}" STREQUAL "CMakeFiles")
        message(STATUS "excluding CMakeFiles directory")
        continue()
    endif()

    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
        set(list_of_dirs ${list_of_dirs} ${dir})
    endif()
endforeach()

foreach(dir ${list_of_dirs})

    FILE(GLOB c ${dir}/*.c)
    FILE(GLOB h ${dir}/*.h)

    add_library(${dir} ${c} ${h})
    message(STATUS "Adding module ${dir}")

    target_include_directories( ${dir} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

set(
    DEPENDANCY
    ${LIBRARIES} ${list_of_dirs}
    PARENT_SCOPE
)

