#ifndef Matrix32x32_h
#define Matrix32x32_h

#include <Arduino.h>

#define LEN 8

class Matrix32x32
{
  public:
    // initialise PINs
    void init();

    // Display line @ offset, update R,G,B
    bool write(int nl); //

    // Affiche un message
    void display(int nl, int color, String msg);

    void update(void);

  private:
    long R[32*LEN], G[32*LEN], B[32*LEN];
    // http://sunge.awardspace.com/glcd-sd/node4.html
    static const char* Font5x7[];

};

extern Matrix32x32 M;

#endif
