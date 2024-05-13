add_executable(  Example2 main.cpp
                )

target_include_directories( Example2 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

#target_link_libraries(  Example2 PUBLIC Labrador)
