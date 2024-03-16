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
    NoneEffect,
    Shake,
    SmoothFollow
};

enum UIComponentState {
    NoneEvent,
    MouseHover,
    MouseClicked
};