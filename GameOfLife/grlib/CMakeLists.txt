set(GRAPH_LIB_SOURCES graph_lib.cpp)
add_library(graph-lib STATIC ${GRAPH_LIB_SOURCES})

target_link_libraries(graph-lib -lsfml-graphics -lsfml-window -lsfml-system)
