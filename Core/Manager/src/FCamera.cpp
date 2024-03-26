#include "FCamera.h"
#include "FStruct.h"
#include "FUtils.h"

Camera2D FCamera::m_camera;

FCamera::FCamera()
{
    m_camera.target = {0.0f, 0.0f};
    m_camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    m_camera.rotation = 0.0f;
    m_camera.zoom = 1.0f;
}

FCamera::FCamera(Vector2 target)
{
    m_camera.target = target;
}

void FCamera::SetTarget(Vector2 target)
{
    for (auto effect : m_effects)
    {
        if (effect == CameraEffect::SmoothFollow)
        {
            m_camera.target = LerpVector2(m_camera.target, target, 0.035f);
        }

        if (effect == CameraEffect::Shake)
        {
            m_camera.target.x = target.x + GetRandomValue(-1, 1);
            m_camera.target.y = target.y + GetRandomValue(-1, 1);
        }

        if (effect == CameraEffect::NoneEffect)
        {
            m_camera.target = target;
        }
    }
}

void FCamera::SetZoom(float zoom)
{
    m_camera.zoom = zoom;
}

void FCamera::SetRotation(float rotation)
{
    m_camera.rotation = rotation;
}

FCameraViewport FCamera::GetCameraViewport()
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    Vector2 topLeft = {m_camera.target.x - width / 2, m_camera.target.y - height / 2};
    Vector2 bottomRight = {m_camera.target.x + width / 2, m_camera.target.y + height / 2};
    return {topLeft, bottomRight};
}

void FCamera::AddEffect(CameraEffect effect)
{
    m_effects.push_back(effect);
}

void FCamera::RemoveEffect(CameraEffect effect)
{
    for (auto it = m_effects.begin(); it != m_effects.end(); it++)
    {
        if (*it == effect)
        {
            m_effects.erase(it);
            break;
        }
    }
}

Rectangle FCamera::GetCameraViewportAsRectangle()
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    Vector2 topLeft = {m_camera.target.x - width / 2, m_camera.target.y - height / 2};
    return {topLeft.x, topLeft.y, (float)width, (float)height};
}
