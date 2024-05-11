#include <lightray/random.h>

#include <cstdlib>
#include <random>

using namespace lightray;

#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>
#include <algorithm>

float PerlinNoise::fade(float t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float PerlinNoise::lerp(float t, float a, float b)
{
    return a + t * (b - a);
}

float PerlinNoise::grad(int hash, float x, float y, float z)
{
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

PerlinNoise::PerlinNoise() : m_gen(std::random_device()()), m_octaves(4), m_decay(0.5f)
{
    m_p.resize(256);
    std::iota(m_p.begin(), m_p.end(), 0); // Fill p with values from 0 to 255
    std::shuffle(m_p.begin(), m_p.end(), m_gen);
    m_p.insert(m_p.end(), m_p.begin(), m_p.end()); // Duplicate the permutation vector
}

void lightray::PerlinNoise::noiseSeed(int seed)
{
    m_gen.seed(seed);
    m_p.resize(256);
    std::iota(m_p.begin(), m_p.end(), 0); // Fill p with values from 0 to 255
    std::shuffle(m_p.begin(), m_p.end(), m_gen);
    m_p.insert(m_p.end(), m_p.begin(), m_p.end()); // Duplicate the permutation vector
}

void PerlinNoise::noiseDetail(int o, float d)
{
    m_octaves = o;
    m_decay = d;
}

float PerlinNoise::noise(float x, float y, float z)
{
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;
    int Z = (int)floor(z) & 255;
    x -= floor(x);
    y -= floor(y);
    z -= floor(z);
    float u = fade(x);
    float v = fade(y);
    float w = fade(z);
    int A = m_p[X] + Y, AA = m_p[A] + Z, AB = m_p[A + 1] + Z;
    int B = m_p[X + 1] + Y, BA = m_p[B] + Z, BB = m_p[B + 1] + Z;

    float res = 0.0;
    float amp = 1.0;

    for (int i = 0; i < m_octaves; i++)
    {
        float val = lerp(w,
                         lerp(v, lerp(u, grad(m_p[AA], x, y, z), grad(m_p[BA], x - 1, y, z)),
                              lerp(u, grad(m_p[AB], x, y - 1, z), grad(m_p[BB], x - 1, y - 1, z))),
                         lerp(v, lerp(u, grad(m_p[AA + 1], x, y, z - 1), grad(m_p[BA + 1], x - 1, y, z - 1)),
                              lerp(u, grad(m_p[AB + 1], x, y - 1, z - 1), grad(m_p[BB + 1], x - 1, y - 1, z - 1))));
        res += val * amp;
        amp *= m_decay;
    }

    return res;
}

PerlinNoise *PerlinNoise::m_instance = nullptr;

RandomState::RandomState() : m_gen(std::random_device()())
{}

int RandomState::random(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high - 1);
    return dist(m_gen);
}

float RandomState::random(float low, float high)
{
    std::uniform_real_distribution<float> dist(low, high);
    return dist(m_gen);
}

void RandomState::randomSeed(int seed)
{
    m_gen.seed(seed);
}

float RandomState::randomGaussian()
{
    std::normal_distribution<float> dist(0.0, 1.0);
    return dist(m_gen);
}

float lightray::random(float high)
{
    return RandomState::instance()->random(0.0f, high);
}

float lightray::random(float low, float high)
{
    return RandomState::instance()->random(low, high);
}

void lightray::noiseDetail(int lod, float falloff)
{
    PerlinNoise::instance()->noiseDetail(lod, falloff);
}

void lightray::noiseSeed(int seed)
{
    PerlinNoise::instance()->noiseSeed(seed);
}

float lightray::noise(float x)
{
    return PerlinNoise::instance()->noise(x, 0.0f, 0.0f);
}

float lightray::noise(float x, float y)
{
    return PerlinNoise::instance()->noise(x, y, 0.0f);
}

float lightray::noise(float x, float y, float z)
{
    return PerlinNoise::instance()->noise(x, y, z);
}

float lightray::randomGaussian()
{
    return RandomState::instance()->randomGaussian();
}

void lightray::randomSeed(int seed)
{
    RandomState::instance()->randomSeed(seed);
}
