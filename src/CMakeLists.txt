set(HEADER_LIST "${craft-project_SOURCE_DIR}/include/shader.h" "${craft-project_SOURCE_DIR}/include/glad/gl.h" )

add_library(craft-lib ../include gl.c shader.c ${HEADER_LIST})

target_include_directories(craft-lib PUBLIC ../include)
