add_executable(craft-project main.c)

find_package(OpenGL REQUIRED)

target_link_libraries(craft-project cglm glfw craft-lib OpenGL::GL)
