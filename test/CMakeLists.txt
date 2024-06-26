option(CODE_COVERAGE "Enable coverage reporting" OFF)

# Force dynamic linking since MSVC now links C runtimes dynamically by default
set(gtest_force_shared_crt on)

if(CODE_COVERAGE)
	message( "Code Coverage Enabled" )
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
		--coverage #set coverage flag
		-fprofile-arcs
		-ftest-coverage
		-fPIC
	)
	link_libraries(
		"gcov"
		"-fprofile-arcs"
		"--coverage"
	)

endif(CODE_COVERAGE)


include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG origin/main
    OPTIONS "gtest_forced_shared_crt ON CACHE BOOL FORCE"
)

file (GLOB TEST_FILES "*.cpp" "*.hpp" "*.h")
add_executable(labrador_test_exe ${TEST_FILES})

target_compile_definitions(labrador_test_exe
    PUBLIC WITH_COMPRESSION
)

target_include_directories(labrador_test_exe
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(labrador_test_exe
    PUBLIC GTest::gtest_main
    pthread
)

add_test(test_bounded_queue labrador_test_exe --gtest_filter=BoundedQueueTest*)
add_test(test_concurrent_queue labrador_test_exe --gtest_filter=ConcurrentQueueTest*)
   

