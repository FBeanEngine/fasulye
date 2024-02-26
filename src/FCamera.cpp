#include "FCamera.h"
#include "FStruct.h"
#include "utils.h"

FCamera::FCamera()
{
    m_camera.target = { 0.0f, 0.0f };
}

FCamera::FCamera(Vector2 target)
{
    m_camera.target = target;
}

void FCamera::SetTarget(Vector2 target) {
    for (auto effect : m_effects) {
        if (effect == CameraEffect::SmoothFollow) {
            m_camera.target = LerpVector2(m_camera.target, target, 0.035f);
        }

        if (effect == CameraEffect::Shake) {
            m_camera.target.x = target.x + GetRandomValue(-1, 1);
            m_camera.target.y = target.y + GetRandomValue(-1, 1);
        }
        
        if (effect == CameraEffect::None) {
            m_camera.target = target;
        }
    }
}

void FCamera::SetZoom(float zoom) {
    m_camera.zoom = zoom;
}

void FCamera::SetRotation(float rotation) {
    m_camera.rotation = rotation;
}

FCameraViewport FCamera::GetCameraViewport() {
    Vector2 topLeft = m_camera.target;
    Vector2 bottomRight = { m_camera.target.x + GetScreenWidth(), m_camera.target.y + GetScreenHeight() };
    return { topLeft, bottomRight };
}

void FCamera::AddEffect(CameraEffect effect) {
    m_effects.push_back(effect);
}

void FCamera::RemoveEffect(CameraEffect effect) {
    for (auto it = m_effects.begin(); it != m_effects.end(); it++) {
        if (*it == effect) {
            m_effects.erase(it);
            break;
        }
    }
}

Camera2D FCamera::m_camera = {
    target = { 0.0f, 0.0f };
    offset = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    rotation = 0.0f;
    zoom = 1.0f;
}