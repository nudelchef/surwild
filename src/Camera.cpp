#include "Camera.h"

const int camera_speed = 5;

Camera::Camera(int width, int height)
{
    this->x = 0;
    this->y = 0;
    this->width = width;
    this->height = height;
}

Camera::~Camera()
{

}

void Camera::update()
{
    if (keys[SDL_SCANCODE_W])
    {
        y -= camera_speed;
    } else if (keys[SDL_SCANCODE_S])
    {
        y += camera_speed;
    } else if (keys[SDL_SCANCODE_A])
    {
        x -= camera_speed;
    } else if (keys[SDL_SCANCODE_D])
    {
        x += camera_speed;
    }
}

void Camera::forceBorder(int minX, int minY, int maxX, int maxY)
{
    if (x < minX) x = minX;
    if (y < minY) y = minY;
    if (x > maxX - width) x = maxX - width;
    if (y > maxY - height) y = maxY - height;
}