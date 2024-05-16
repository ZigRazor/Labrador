add_executable(  JackRussellExample1 main.cpp
                )

target_include_directories( JackRussellExample1 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(  JackRussellExample1 PUBLIC pthread)
