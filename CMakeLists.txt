cmake_minimum_required(VERSION 3.20)


project (cmarkdown VERSION 1.0.0)

set (DEPENDANCY "")

set(DEPS
    # add subdirectory here
    modules
)


foreach(dir ${DEPS})
    add_subdirectory("${dir}")
endforeach()


add_executable("${CMAKE_PROJECT_NAME}" main.c)
foreach(dependancy ${DEPENDANCY})
    message(STATUS "Linking ${dependancy} to ${CMAKE_PROJECT_NAME}")
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${dependancy})
endforeach()
