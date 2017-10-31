#ifndef FISH_H
#define FISH_H

#include "allegro.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct fishy
{
       double x;
       double y;
       bool left;
       BITMAP *imgRight[8];
       BITMAP *img;
       int currFrame;
       int maxFrame;
       int frameDelay;
       int frameCount;
       string type;
};

class Fish
{
      public:
        Fish(double myX, double myY, string myT, bool l);
        void swimRight(BITMAP *bmp);
        void swimLeft(BITMAP *bmp);
        void stand(BITMAP *bmp);
        void floating(BITMAP *bmp);
        void swimDown(BITMAP *bmp);
        void floatDown(BITMAP *bmp);
        void swimUp(BITMAP *bmp);
        void getMed();
        void getBig();
        int getX();
        int getY();
        bool isLeft();
        BITMAP *grabframe(BITMAP *source, int width, int height, int startx, int starty, int columns, int frame);
      private:
          fishy myFish;
};

#endif // FISH_H
