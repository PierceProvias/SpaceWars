add_library(${SPACE_WARS_ENGINE_TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/core.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/include/entry_point.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/entry_point.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/world.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/world.cpp


)

target_include_directories(${SPACE_WARS_ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${SPACE_WARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${SPACE_WARS_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${SPACE_WARS_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${SPACE_WARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    
add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
)
endfunction()

CopyLibToTarget(sfml-graphics   ${SPACE_WARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window     ${SPACE_WARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system     ${SPACE_WARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio      ${SPACE_WARS_ENGINE_TARGET_NAME})