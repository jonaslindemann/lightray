#pragma once

#include <random>
#include <vector>
#include <iostream>

namespace lightray {

class RandomState {
public:
    static RandomState *instance()
    {
        static RandomState m_instance;
        return &m_instance;
    }

    int random(int low, int high);
    float random(float low, float high);
    void randomSeed(int seed);
    float randomGaussian();

private:
    std::random_device m_rd;
    std::mt19937 m_gen;

    RandomState();
    RandomState(const RandomState &) = delete;            // Delete copy constructor
    RandomState &operator=(const RandomState &) = delete; // Delete assignment operator
};

class PerlinNoise {
public:
    static PerlinNoise *instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new PerlinNoise();
        }
        return m_instance;
    }
    void noiseSeed(int seed);
    void noiseDetail(int o, float d);
    float noise(float x, float y, float z);

private:
    static PerlinNoise *m_instance;
    PerlinNoise();
    std::vector<int> m_p; // The permutation vector
    int m_octaves;        // Number of octaves
    float m_decay;        // Decay rate
    std::mt19937 m_gen;

    float fade(float t);
    float lerp(float t, float a, float b);
    float grad(int hash, float x, float y, float z);
};

float random(float high);
float random(float low, float high);
void noiseDetail(int lod, float falloff);
void noiseSeed(int seed);
float noise(float x);
float noise(float x, float y);
float noise(float x, float y, float z);
float randomGaussian();
void randomSeed(int seed);

} // namespace lightray
