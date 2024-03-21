#pragma once
#include <vector>
#include "enums.h"
#include "raylib.h"

class FShader
{
public:
    FShader();
    ~FShader();
    int FLoadShader(const char *shaderName, ShaderType shaderType);
    void FSetValue(int shaderId, int uniformName, const void *value, int uniformType);
    void FUnloadShader(int shaderId);

public:
    std::vector<Shader> m_shaders;
    int m_shaderCount;
    const char *m_shaderName;
    std::vector<float> m_shaderFloatValues;
};