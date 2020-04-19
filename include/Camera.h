#ifndef CAMERA_H
#define CAMERA_H

class Camera;

#include "Game.h"

class Camera
{
    public:
        Camera(int width, int height);
        virtual ~Camera();

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        void set(int x, int y)
        {
            this->x = x - width * 0.5;
            this->y = y - height * 0.5;
        }

        void update();
        void forceBorder(int minX, int minY, int maxX, int maxY);

    protected:

    private:
        int x;
        int y;
        int width;
        int height;
};

#endif // CAMERA_H
