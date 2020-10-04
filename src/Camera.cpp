#include "Camera.h"

#include <cstdint>

#include "Game.h"

const int camera_speed = 5;

Camera::Camera(uint16_t width_, uint16_t height_)
{
    x = 0;
    y = 0;
    width = width_;
    height = height_;
}

Camera::~Camera()
{

}

void Camera::update()
{
    if (keys[SDL_SCANCODE_W])
    {
        y -= camera_speed;
    }
    else if (keys[SDL_SCANCODE_S])
    {
        y += camera_speed;
    }
    else if (keys[SDL_SCANCODE_A])
    {
        x -= camera_speed;
    }
    else if (keys[SDL_SCANCODE_D])
    {
        x += camera_speed;
    }
}

void Camera::clamp(int32_t minX, int32_t minY, int32_t maxX, int32_t maxY)
{
    if (x < minX) x = minX;
    if (y < minY) y = minY;
    if (x > maxX - width) x = maxX - width;
    if (y > maxY - height) y = maxY - height;
}
