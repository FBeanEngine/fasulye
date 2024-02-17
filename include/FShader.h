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
    void FUnloadShader(int shaderId);

public:
    std::vector<Shader> m_shaders;
    int m_shaderCount;
    const char *m_shaderName;
};