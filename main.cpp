#define GL_SGIX_fragment_lighting 1
#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <chrono>
using namespace std;

#include "VAO.h"
#include "shader_program.h"
#include "master_renderer.h"
#include "VAOLoader.h"
#include "src/files.h"
#include "VBO_DATA.h"
#include "entity.h"
#include "camera.h"
#include "GU.h"
#include "water_tile.h"

GLFWwindow* window;

void fatalError(string message)
{
    cerr << "main:" << message << endl;
    exit(1);
}

void redraw(camera *c, master_renderer* renderer, terrain* t)
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer->process(t);
    renderer->render(c);
    glfwSwapBuffers(window);
}

int controls = 0;
int mouseControls = 0;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        if(key == GLFW_KEY_UP)
            controls |= 1;
        if(key == GLFW_KEY_DOWN)
            controls |= 2;
        if(key == GLFW_KEY_LEFT)
            controls |= 4;
        if(key == GLFW_KEY_RIGHT)
            controls |= 8;
        if(key == GLFW_KEY_W)
            controls |= 16;
        if(key == GLFW_KEY_A)
            controls |= 32;
        if(key == GLFW_KEY_S)
            controls |= 64;
        if(key == GLFW_KEY_D)
            controls |= 128;
    }
    else if(action == GLFW_RELEASE)
    {
        if(key == GLFW_KEY_UP)
            controls &= ~1;
        if(key == GLFW_KEY_DOWN)
            controls &= ~2;
        if(key == GLFW_KEY_LEFT)
            controls &= ~4;
        if(key == GLFW_KEY_RIGHT)
            controls &= ~8;
        if(key == GLFW_KEY_W)
            controls &= ~16;
        if(key == GLFW_KEY_A)
            controls &= ~32;
        if(key == GLFW_KEY_S)
            controls &= ~64;
        if(key == GLFW_KEY_D)
            controls &= ~128;
    }
}

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLenum id, GLenum severity, GLsizei length, const GLchar* message, const void* useParam)
{
    cout << "GL CALLBACK: " <<  ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ) << " type = 0x" << type << ", severity = 0x" << severity << ", message = " << (char *) message << endl;
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        mouseControls |= 1 << button;
    }else if(action == GLFW_RELEASE)
        mouseControls &= ~(1<<button);
}

int mxpos = 0;
int mypos = 0;

static void mouse_moved_callback(GLFWwindow* window, double xpos, double ypos){
    mxpos = (int) xpos;
    mypos = (int) ypos;
}
void update(camera *cam)
{
    if((controls & 1))
        cam->rotate(-80.0 * GameUtil::delta,0,0);
    if((controls & 2))
        cam->rotate(80.0 * GameUtil::delta,0,0);

    if((controls & 4))
        cam->rotate(0, -80.0 * GameUtil::delta, 0);
    if((controls & 8))
        cam->rotate(0, 80.0 * GameUtil::delta, 0);

    if((controls & 16))
        cam->move(0, 0, -50.0 * GameUtil::delta);

    if((controls & 32))
        cam->move(-50.0 * GameUtil::delta, 0, 0);

    if((controls & 64))
        cam->move(0, 0, 50.0 * GameUtil::delta);

    if((controls & 128))
        cam->move(50.0 * GameUtil::delta, 0, 0);

    cout << controls << "\n";
}

int main(int argc, char **argv)
{
    if(!glfwInit())
    {
        fatalError("Failed to initialize glfw");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(1200, 720, "Nature Simulator", NULL, NULL);
    if(!window)
        fatalError("OpenGL context/ window failed to initialize");

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, mouse_moved_callback);

    glfwSwapInterval(0);


    if(glewInit() != GLEW_OK)
        fatalError("GLEW failed to initialize");

    ///HERE BEGINS THE GAME INITIALIZATION

    //INITIALIZE
    terrain *t = new terrain();
    camera *c = new camera;
    vector<entity*>* entities = new vector<entity*>;
    master_renderer *renderer = new master_renderer();

    glViewport(0,0, 1200, 720);
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDebugMessageCallback(MessageCallback, nullptr);
    auto prev = chrono::high_resolution_clock::now();
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        c->update(controls, mxpos, mypos, GameUtil::delta);
        redraw(c, renderer, t);
        auto t = chrono::high_resolution_clock::now();
        auto passed = t - prev;
        prev = t;
        GameUtil::delta = chrono::duration_cast<std::chrono::nanoseconds>(passed).count() / 1000000000.0;
        cout << 1 / GameUtil::delta << '\n';
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    delete renderer;
    delete t;
    delete c;
    delete entities;
    return 0;
}
