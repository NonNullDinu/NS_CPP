#ifndef VAO_H_INCLUDED
#define VAO_H_INCLUDED
#include <GL/glew.h>
#include <GL/gl.h>
#include <utility>
#include <unordered_set>
using namespace std;

class VAO
{
private:
    GLuint id = 0;
    unordered_set<GLuint> *vbos;
    GLuint vertexCount;
    int boundSize;
    int *bound;
public:
    VAO(GLuint id, unordered_set<GLuint> *vbos, GLuint vertexCount);
    virtual ~VAO();
    void bind(int size, int attributes[]);
    void unbind();
    GLuint GetId();
    GLuint GetVertexCount();
};

struct VAOHash
{
    std::size_t operator()(VAO* k) const
    {
        return (std::size_t) k->GetId();
    }
};

struct VAOEqual
{
    bool operator()(VAO* lhs, VAO* rhs) const
    {
        return lhs->GetId() == rhs->GetId();
    }
};

#endif // VAO_H_INCLUDED
