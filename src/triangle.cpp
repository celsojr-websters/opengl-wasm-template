// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>

// #ifdef __EMSCRIPTEN__
// #include <emscripten/emscripten.h>
// #endif

// const char* vertexShaderSource = R"(
//     #version 300 es
//     layout(location = 0) in vec3 aPos;
//     void main() {
//         gl_Position = vec4(aPos, 1.0);
//     }
// )";

// const char* fragmentShaderSource = R"(
//     #version 300 es
//     precision mediump float;
//     out vec4 FragColor;
//     void main() {
//         FragColor = vec4(1.0, 0.5, 0.2, 1.0);
//     }
// )";

// GLuint shaderProgram;
// GLuint VAO;

// void initOpenGL() {
//     // Vertex Shader
//     GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);

//     // Check for vertex shader compile errors
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     // Fragment Shader
//     GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);

//     // Check for fragment shader compile errors
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     // Shader Program
//     shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);

//     // Check for linking errors
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//     }

//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     // Set up vertex data (and buffer(s)) and configure vertex attributes
//     float vertices[] = {
//          0.0f,  0.5f, 0.0f,  // top
//         -0.5f, -0.5f, 0.0f,  // bottom left
//          0.5f, -0.5f, 0.0f   // bottom right
//     };

//     GLuint VBO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     glBindBuffer(GL_ARRAY_BUFFER, 0); 
//     glBindVertexArray(0); 
// }

// void render() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     glUseProgram(shaderProgram);
//     glBindVertexArray(VAO);
//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     glBindVertexArray(0);
// }

// void mainLoop() {
//     render();
//     glfwSwapBuffers(glfwGetCurrentContext());
//     glfwPollEvents();
// }

// int main() {
//     if (!glfwInit()) {
//         std::cerr << "Failed to initialize GLFW" << std::endl;
//         return -1;
//     }

// #ifdef __EMSCRIPTEN__
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
// #else
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// #endif

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", NULL, NULL);
//     if (!window) {
//         std::cerr << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
    
// #ifndef __EMSCRIPTEN__
//     // Load OpenGL function pointers with GLAD
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         std::cerr << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
// #endif

//     initOpenGL();

// #ifdef __EMSCRIPTEN__
//     emscripten_set_main_loop(mainLoop, 0, 1);
// #else
//     while (!glfwWindowShouldClose(window)) {
//         mainLoop();
//     }
// #endif

//     glfwTerminate();
//     return 0;
// }
