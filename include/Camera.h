#ifndef CAMERA_H
#define CAMERA_H

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

        void set(int x_, int y_)
        {
            x = x_ - width * 0.5;
            y = y_ - height * 0.5;
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
