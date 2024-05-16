add_executable(  Example1 main.cpp
                )

target_include_directories( Example1 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(  Example1 PUBLIC pthread)
