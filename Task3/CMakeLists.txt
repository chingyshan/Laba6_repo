project(Task3)
add_executable(Task_3 task3.cpp functions.cpp)

#[[
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
endif()]]
