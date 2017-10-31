#include "Fish.h"

    Fish::Fish(double myX, double myY, string myT, bool l)
    {
        myFish.x = myX;
        myFish.y = myY;
        myFish.type = myT;
        myFish.left = l;
        myFish.currFrame = 0;
        myFish.frameCount = 0;
        myFish.maxFrame = 7;
        int height = 0;
        int width = 0;
        if(myFish.type == "smallFish.bmp")
        {
            height = 44;
            width = 84;
        }
        if(myFish.type == "medFish.bmp")
        {
            height = 49;
            width = 85;
        }
        if(myFish.type == "bigFish.bmp")
        {
            myFish.maxFrame = 5;
            height = 85;
            width = 111;
        }
        if(myFish.type == "smallPlayer.bmp")
        {
            height = 44;
            width = 84;
        }
        if(myFish.type == "medPlayer.bmp")
        {
            height = 50;
            width = 85;
        }
        if(myFish.type == "bigPlayer.bmp")
        {
            myFish.maxFrame = 5;
            height = 85;
            width = 111;
        }
        BITMAP *temp = load_bitmap(myFish.type.c_str(), NULL);
        for (int i = 0; i < myFish.maxFrame; i++)
        {
            myFish.imgRight[i] = grabframe(temp, width, height, 0, 0, myFish.maxFrame, i);
        }

        destroy_bitmap(temp);
    }

    void Fish::swimRight(BITMAP *bmp)
    {
        myFish.left = false;
        myFish.x += .2;
        draw_sprite(bmp, myFish.imgRight[myFish.currFrame / (myFish.maxFrame + 8) % (myFish.maxFrame)], myFish.x, myFish.y);
        myFish.currFrame++;
    }

    void Fish::swimLeft(BITMAP *bmp)
    {
        myFish.left = true;
        myFish.x -= .2;
        draw_sprite_h_flip(bmp, myFish.imgRight[myFish.currFrame / (myFish.maxFrame + 8) % (myFish.maxFrame)], myFish.x, myFish.y);
        myFish.currFrame++;
    }

    void Fish::floatDown(BITMAP *bmp)
    {
        myFish.y += .1;
        draw_sprite(bmp, myFish.imgRight[myFish.currFrame / (myFish.maxFrame + 8) % (myFish.maxFrame)], myFish.x, myFish.y);
    }

    void Fish::swimDown(BITMAP *bmp)
    {
        myFish.y += .2;
        draw_sprite(bmp, myFish.imgRight[myFish.currFrame / (myFish.maxFrame + 8) % (myFish.maxFrame)], myFish.x, myFish.y);
    }

    void Fish::swimUp(BITMAP *bmp)
    {
        myFish.y -= .2;
        draw_sprite(bmp, myFish.imgRight[myFish.currFrame / (myFish.maxFrame + 8) % (myFish.maxFrame)], myFish.x, myFish.y);
    }

    void Fish::getBig()
    {
        myFish.type = "bigPlayer.bmp";
        myFish.maxFrame = 5;
        BITMAP *temp = load_bitmap(myFish.type.c_str(), NULL);
        for (int i = 0; i < myFish.maxFrame; i++)
        {
            myFish.imgRight[i] = grabframe(temp, 111, 85, 0, 0, myFish.maxFrame, i);
        }
        destroy_bitmap(temp);
    }

    void Fish::getMed()
    {
        myFish.type = "medPlayer.bmp";
        myFish.maxFrame = 7;
        BITMAP *temp = load_bitmap(myFish.type.c_str(), NULL);
        for (int i = 0; i < myFish.maxFrame; i++)
        {
            myFish.imgRight[i] = grabframe(temp, 85, 50, 0, 0, myFish.maxFrame, i);
        }
        destroy_bitmap(temp);
    }

    int Fish::getX()
    {
        return myFish.x;
    }

    int Fish::getY()
    {
        return myFish.y;
    }

    bool Fish::isLeft()
    {
        return myFish.left;
    }

    BITMAP *Fish::grabframe(BITMAP *source, int width, int height, int startX, int startY, int columns, int frame)
    {
        BITMAP *temp = create_bitmap(width, height);
        int x = startX + (frame % columns) * width;
        int y = startY + (frame / columns) * height;
        blit(source, temp, x, y, 0, 0, width, height);
        return temp;
    }
