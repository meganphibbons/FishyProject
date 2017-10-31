#include <allegro.h>
#include <iostream>
#include <Fish.h>
#include <PlayerFish.h>
#include <vector>

using namespace std;

void init();
void deinit();

int main()
{
    init();
    BITMAP *ocean = load_bitmap("ocean.bmp", NULL);
    BITMAP *game = load_bitmap("ocean.bmp", NULL);
    Fish player(SCREEN_W / 2, SCREEN_H / 2, "smallPlayer.bmp", true);
    bool med = false;
    bool big = false;
    int fishEaten = 0;
    vector<Fish> fishies;

    while(!key[KEY_ESC])
    {
        draw_sprite(game, ocean, 0, 0);
        if(key[KEY_RIGHT])
            player.swimRight(game);
        else if(key[KEY_LEFT])
            player.swimLeft(game);
        else if(key[KEY_UP])
            player.swimUp(game);
        else if(key[KEY_UP])
            player.swimDown(game);
        else
            player.floatDown(game);
        if(med)
        {
            player.getMed();
            med = false;
        }
        if(big)
        {
            player.getBig();
            big = false;
        }
        if(fishEaten >= 10)
            big = true;
        else if(fishEaten >= 5 && !med)
            med = true;
        if(fishies.size() < 5)
        {
            int decision = rand() % 3;
            int side = rand() % 2;
            int x = SCREEN_W + 15;
            int y = rand() % SCREEN_H;
            Fish temp(SCREEN_W / 2, SCREEN_H / 2, "smallFish.bmp", true);
            if(side == 0)
                x = -15;
            if(decision == 0)
                temp = Fish(x, y, "smallFish.bmp", (x < 0));
            else if(decision == 1)
                temp = Fish(x, y, "medFish.bmp", (x < 0));
            else if(decision == 2)
                temp = Fish(x, y, "bigFish.bmp", (x < 0));
            fishies.push_back(temp);
        }
        for(int i = 0; i < fishies.size(); i++)
        {
            if(fishies[i].getX() <= -15 || fishies[i].getX() > SCREEN_W + 15)
                fishies.erase(fishies.begin() + i);
        }
        for(int i = 0; i < fishies.size(); i++)
        {
            if(fishies[i].isLeft())
                fishies[i].swimRight(game);
            else
                fishies[i].swimRight(game);
        }
        for(int i = 0; i < fishies.size(); i++)
        {
            if((fishies[i].getX() > player.getX() - 15 && fishies[i].getX() < player.getX() + 15)  && (fishies[i].getY() < player.getY() + 15 && fishies[i].getY() > player.getY() - 15))
            {
                fishEaten++;
                fishies.erase(fishies.begin() + i);
            }
        }
        blit(game, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        clear_bitmap(game);
    }
    deinit();
    return 0;
}
END_OF_MAIN()

void init()
{
    srand(time(0));
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if(depth == 0)
        depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    if(res != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
}

void deinit()
{
    clear_keybuf();
}
