#include "heights_generator.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
using namespace std;

const int VERTEX_COUNT = 512;

heights_generator::heights_generator()
{
	seed = time(NULL);
    srand(seed);
    this->heights = new float[VERTEX_COUNT * VERTEX_COUNT];
    for(int i = 0; i < VERTEX_COUNT * VERTEX_COUNT; ++i)
        this->heights[i] = -2.0;
}

heights_generator::~heights_generator()
{
    delete[] this->heights;
}

float heights_generator::getHeight(int x, int z)
{
    float total = 0;
    float d = pow(2, OCTAVES - 1);
    for(int i = 0; i < OCTAVES; i++)
    {
        float freq = (float) (pow(2, i) / d);
        float amp = (float) pow(ROUGHNESS, i) * AMPLITUDE;
        total += m_getInterpolatedNoise(x*freq, z*freq) * amp;
    }
    return total;
}

float heights_generator::m_getNoise(int x, int z)
{
    if(this->heights[z * VERTEX_COUNT + x] == -2.0)
    {
        float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        r *= 2.0;
        r -= 1.0;
        this->heights[z*VERTEX_COUNT + x] = r;
        return r;
    }
    else
        return this->heights[z*VERTEX_COUNT + x];
}

float heights_generator::m_getInterpolatedNoise(float x, float z)
{
    int intX = (int) x;
    int intZ = (int) z;
    float fracX = x - intX;
    float fracZ = z - intZ;
    float v1 = m_getSmoothNoise(intX, intZ);
    float v2 = m_getSmoothNoise(intX+1, intZ);
    float v3 = m_getSmoothNoise(intX, intZ+1);
    float v4 = m_getSmoothNoise(intX+1, intZ+1);
    float i1 = m_interpolate(v1, v2, fracX);
    float i2 = m_interpolate(v3, v4, fracX);
    return m_interpolate(i1, i2, fracZ);
}

float heights_generator::m_interpolate(float a, float b, float blend)
{
    double theta = blend * 3.14159;
    float f = (float) (1.0 - cos(theta)) * 0.5;
    return a * (1.0 - f) + b*f;
}

float heights_generator::m_getSmoothNoise(int x, int z)
{
    float corners = (m_getNoise(x-1, z-1) + m_getNoise(x+1, z-1) + m_getNoise(x-1,z+1) + m_getNoise(x+1,z+1))/16.0;
    float sides = (m_getNoise(x-1, z) + m_getNoise(x+1, z) + m_getNoise(x, z-1) + m_getNoise(x, z+1)) / 8.0;
    float center = m_getNoise(x,z)/4.0;
    return corners + sides + center;
}
