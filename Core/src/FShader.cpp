#include "FShader.h"
#include "raylib.h"

FShader::FShader()
{
	m_shaderCount = 0;
}

FShader::~FShader()
{
	TraceLog(LOG_INFO, "Unloading all shaders");
	for (int i = 0; i < m_shaderCount; i++)
	{
		UnloadShader(m_shaders[i]);
	}
	TraceLog(LOG_INFO, "Shaders unloaded successfully");
}

int FShader::FLoadShader(const char *shaderName, ShaderType shaderType)
{
	if (shaderType == ShaderType::Vertex)
	{
		TraceLog(LOG_INFO, "Loading vertex shader: %s", shaderName);
		m_shaders.push_back(LoadShader(TextFormat("resources/shaders/%s", shaderName), 0));
	}
	else if (shaderType == ShaderType::Fragment)
	{
		TraceLog(LOG_INFO, "Loading fragment shader: %s", shaderName);
		m_shaders.push_back(LoadShader(0, TextFormat("resources/shaders/%s", shaderName)));
	}
	else
	{
		TraceLog(LOG_WARNING, "Invalid shader type");
		return -1;
	}
	m_shaderCount++;
	TraceLog(LOG_INFO, "Shader loaded successfully %d", m_shaderCount);
	return m_shaderCount;
}

void FShader::FSetValue(int shaderId, int uniformName, const void *value, int uniformType)
{
	SetShaderValue(m_shaders[shaderId], uniformName, value, uniformType);
}

void FShader::FUnloadShader(int shaderId)
{
	UnloadShader(m_shaders[shaderId]);
	m_shaders.erase(m_shaders.begin() + shaderId);
	m_shaderCount--;
	TraceLog(LOG_INFO, "Shader unloaded successfully");
}
