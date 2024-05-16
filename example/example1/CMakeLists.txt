add_executable(  LabradorExample1 main.cpp
                )

target_include_directories( LabradorExample1 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(  LabradorExample1 PUBLIC pthread)
