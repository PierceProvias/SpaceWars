add_executable(${SPACE_WARS_GAME_TARGET_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/game_framework/game_application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game_framework/game_application.cpp
)

target_include_directories(${SPACE_WARS_GAME_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${SPACE_WARS_GAME_TARGET_NAME} PUBLIC ${SPACE_WARS_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(
        TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:${LIB_NAME}>
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirToTarget(${SPACE_WARS_ENGINE_TARGET_NAME} ${SPACE_WARS_GAME_TARGET_NAME})
