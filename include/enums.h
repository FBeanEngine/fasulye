#pragma once

enum SceneType
{
    SpaceStation,
    Planet
};

enum PerformedAction
{
    NoneAction,
    LeftHandUse,
    RightHandUse
};

enum ShaderType
{
    Vertex,
    Fragment
};

enum CameraEffect {
    None,
    Shake,
    SmoothFollow
};