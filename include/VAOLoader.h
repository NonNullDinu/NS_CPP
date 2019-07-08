#ifndef VAOLOADER_H_INCLUDED
#define VAOLOADER_H_INCLUDED
#include <GL/glew.h>
#include <GL/gl.h>
#include "VAO.h"
#include "VBO_DATA.h"
namespace GL
{
VAO* vao_make(int, VBO_DATA data[]);

}

#endif // VAOLOADER_H_INCLUDED
