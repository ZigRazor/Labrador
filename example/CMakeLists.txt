add_executable(  ExampleBoundedQueue main.cpp
                )

target_include_directories( ExampleBoundedQueue PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(  ExampleBoundedQueue PUBLIC )
