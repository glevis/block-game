#include "../include/glad/gl.h"
#include "../extern/glfw/include/GLFW/glfw3.h"
//#include <GLFW/glfw3.h>
#include "../include/shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include "../extern/cglm/include/cglm/cglm.h"
#include "../include/block.h"
#include "../include/camera.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void process_input(GLFWwindow *window);

camera_t camera;

vec3 cameraPos = {0.0f, 0.0f, 3.0f};
vec3 cameraFront = {0.0f, 0.0f, -1.0f};
vec3 cameraUp = {0.0f, 1.0f, 0.0f};

bool firstMouse = true;
float lastX = 800.0 / 2.0;
float lastY = 600.0 / 2.0;
float fov = 90.0f;

float deltaTime= 0.0f;
float lastFrame = 0.0f;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    //glViewport(0, 0, 800, 600);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    camera_scalar_init(&camera, 0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f, -90.0f, 0.0f);

    struct Shader shader1;

    //shader_init("/home/glevis/personal/craft-project/shaders/shader.vs", "/home/glevis/personal/craft-project/shaders/shader.fs", &shader1);
    shader_init("/home/levis/personal/block-game/shaders/shader.vs", "/home/levis/personal/block-game/shaders/shader.fs", &shader1);

    struct block_t* grass_block;
    grass_block = malloc(sizeof(struct block_t));

    block_init(grass_block, grass);
    printf("%f\n", grass_block->vertices[0]);

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    vec3 origin = {0.0f, 0.0f, 0.0f};

    /*
     * Vertex Buffer Object (VBO):
     * Stores vertices on the GPU. Sends vertices in batch from CPU to GPU.
     */
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(grass_block->vertices), grass_block->vertices, GL_STATIC_DRAW);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load("assets/texture_atlas1.png", &width, &height, &nrChannels, 0);
    if(data) {

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        printf("Failed to load texture\n");
    }
    stbi_image_free(data);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shader_use(&shader1);
    shader_set_int("texture1", 0, &shader1);

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    while(!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        nbFrames++;

        if (currentTime - lastTime >= 1.0) {
            printf("%f ms/frame\n", 1000.0/(double)nbFrames);
            printf("%d fps\n", nbFrames);
            nbFrames = 0;
            lastTime += 1.0;
        }
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        process_input(window);

        glClearColor(0.431f, .694f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
  
        shader_use(&shader1);

        mat4 proj;
        glm_mat4_identity(proj);
        glm_perspective(45.0f, (float) 800 / (float) 600, 0.1f, 100.0f, proj);
        shader_set_mat4("projection", proj[0], &shader1);

        mat4 view;
        camera_get_view_matrix(&camera, &view);
        shader_set_mat4("view", view[0], &shader1);

        glBindVertexArray(VAO);
        float plane = 0.0f;
        for(unsigned int i = 0; i < 16; i++) {
            for(unsigned int j = 0; j < 16; j++) {
                for(unsigned int k = 0; k < 16; k++) {
                    mat4 model;
                    glm_mat4_identity(model);
                    vec3 pos = {j, i, k};
                    /*
                    vec3 offset = {1.0f, 0.0f, 0.0f};
                    vec3 z_scale = {0.0f, 0.0f, plane};
                    glm_vec3_scale(offset, 1.0f * (float) j, offset);
                    glm_vec3_add(offset, z_scale, offset);
                    glm_vec3_add(origin, offset, pos);
                    */
                    glm_translate(model, pos);
                    shader_set_mat4("model", model[0], &shader1);
                    glDrawArrays(GL_TRIANGLES, 0, 36);
                }
            }
            plane -= 1.0f;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, 1);
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        process_keyboard(&camera, FORWARD, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        process_keyboard(&camera, BACKWARD, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        process_keyboard(&camera, LEFT, deltaTime);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        process_keyboard(&camera, RIGHT, deltaTime);
    }
    /*
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        vec3 cameraW = { 0.0f, 0.02f, 0.0f};
        //glm_vec3_scale(cameraW, cameraSpeed, cameraW);
        glm_vec3_add(cameraPos, cameraW, cameraPos);
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        vec3 cameraW = { 0.0f, -0.02f, 0.0f};
        //glm_vec3_scale(cameraW, cameraSpeed, cameraW);
        glm_vec3_add(cameraPos, cameraW, cameraPos);
    }
    */
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = (float)xposIn;
    float ypos = (float)yposIn;

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;
    
    process_mouse_movement(&camera, xoffset, yoffset, true);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}
