#ifndef HEIGHTS_GENERATOR_H
#define HEIGHTS_GENERATOR_H

const float AMPLITUDE = 300.0;
const int OCTAVES = 5;
const float ROUGHNESS = 0.1;

class heights_generator
{
public:
    heights_generator();
    virtual ~heights_generator();
    float getHeight(int x, int z);
protected:

private:
    float m_getNoise(int x, int z);
    float m_getInterpolatedNoise(float x, float z);
    float m_interpolate(float a, float b, float blend);
    float m_getSmoothNoise(int x, int z);
    int seed;
    float *heights;
};

#endif // HEIGHTS_GENERATOR_H
