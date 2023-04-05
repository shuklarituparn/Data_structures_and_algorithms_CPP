file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} main.cpp)

    set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)

    install(TARGETS ${testname} DESTINATION "bin/dynamic_array")

endforeach( testsourcefile ${APP_SOURCES} )