cmake_minimum_required(VERSION 3.2)

set(LIB_SOURCE_FILES utils/utils.cpp
                     entity_graph/entity_graph.cpp
                     clone_entity/clone_entity.cpp
                )

add_library(clone_entity ${LIB_SOURCE_FILES})
target_include_directories(
        clone_entity
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
            ${CMAKE_CURRENT_LIST_DIR}/clone_entity/
            ${CMAKE_CURRENT_LIST_DIR}/entity_graph/
            ${CMAKE_CURRENT_LIST_DIR}/utils/
)

target_link_libraries(clone_entity PUBLIC nlohmann_json)

set(EXE_SOURCE_FILES main.cpp)

add_executable(dep_resolver ${EXE_SOURCE_FILES})
target_include_directories(
        dep_resolver
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(dep_resolver PRIVATE clone_entity)
