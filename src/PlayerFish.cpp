#include "PlayerFish.h"

    PlayerFish::PlayerFish(double myX, double myY, string myT, bool l, bool u):Fish(myX, myY, myT, l)
    {
        myFish.up = u;
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


