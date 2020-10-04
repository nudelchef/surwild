#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>

class Camera
{
public:
    Camera(uint16_t width, uint16_t height);
    virtual ~Camera();

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void set(int x_, int y_)
    {
        x = x_ - (width >> 1);
        y = y_ - (height >> 1);
    }

    void update();
    void clamp(int32_t minX, int32_t minY, int32_t maxX, int32_t maxY);

protected:

private:
    int32_t x;
    int32_t y;
    uint16_t width;
    uint16_t height;
};

#endif // CAMERA_H
