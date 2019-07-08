#ifndef VBO_DATA_H
#define VBO_DATA_H

#include <GL/glew.h>
#include <GL/gl.h>

class INFO
{
public:
    INFO(int usage, int vbo_index, int dimensions, bool isIndices);
    int usage;
    int vbo_index;
    int dimensions;
    bool isIndices;
private:
    void a() {}
};

class VBO_DATA
{
public:
    VBO_DATA();

    VBO_DATA(int len, int* data);
    VBO_DATA(int len, char* data);
    VBO_DATA(int len, float* data);

    void init(int len, int* data);
    void init(int len, char* data);
    void init(int len, float* data);

    virtual ~VBO_DATA();
    void put_data_in_vbo(GLuint vbo);
    void addInfo(INFO* info);
    INFO* GetInfo();
    int GetLen();
protected:

private:
    int len,type;
    char* datab;
    float* dataf;
    int* datai;
    INFO* info;
};

#endif // VBO_DATA_H
