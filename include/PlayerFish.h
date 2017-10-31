#ifndef PLAYERFISH_H
#define PLAYERFISH_H

#include <Fish.h>


class PlayerFish : public Fish
{
    public:
        PlayerFish(double myX, double myY, string myT, bool l, bool u);
        void swimDown(BITMAP *bmp);
        void floatDown(BITMAP *bmp);
        void swimUp(BITMAP *bmp);

    private:
};

#endif // PLAYERFISH_H
