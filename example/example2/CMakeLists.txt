add_executable(  LabradorExample2 main.cpp
                )

target_include_directories( LabradorExample2 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(  LabradorExample2 PUBLIC pthread)
