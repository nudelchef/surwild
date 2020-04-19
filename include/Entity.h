#ifndef ENTITY_H
#define ENTITY_H

#include "TextureManager.h"
#include "Direction.h"

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        virtual void update()
        {
            if (isMoving)
            {
                updateMovement();

                animationTime++;
                while (animationTime >= animationDuration)
                {
                    animationTime-=animationDuration;

                    atFrame++;
                    if (atFrame >= maxFrames)
                        atFrame = 0;
                    src.y = frameOrder[atFrame] * src.h;
                }
            } else {
                src.y = 0;
            }
        }

        virtual void render()
        {
            SDL_Rect render_dest;
            render_dest.x = dest.x - camera->getX();
            render_dest.y = dest.y - camera->getY() - 2; // Every entity should be rendered to pixels up
            render_dest.w = dest.w;
            render_dest.h = dest.h;

            TextureManager::render(texture, src, render_dest);
        }

        int getX() { return dest.x; }

        int getY() { return dest.y; }

        int getCenterX() { return dest.x + (dest.w >> 1); }

        int getCenterY() { return dest.y + (dest.h >> 1); }

        void setTexture(SDL_Texture *texture)
        {
            Entity::texture = texture;
        }

        void setFrameOrder(int *frameOrder_, int size)
        {
            for (int i = 0 ; i < size ; i++)
            {
                frameOrder[i] = frameOrder_[i];
            }
            maxFrames = size;
        }

        void setTilePosition(int x, int y);

        void move(Direction direction);

        void look(Direction direction);

        bool canMove(Direction direction);

    protected:

    private:
        const int movementSpeed = 2;

        const int animationDuration = 8;
        int atFrame;
        int* frameOrder;
        int maxFrames;
        int animationTime;

        Direction movementDirection;
        bool isMoving;
        SDL_Point* tilePosition;
        int distanceLeft;

        SDL_Rect src, dest;
        SDL_Texture* texture;

        void updateMovement();
};

#endif // ENTITY_H
