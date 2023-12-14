#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int xmov, x, y;

    for (xmov = 1; xmov < 200; xmov = xmov + 5) {
        line(0, 400, 639, 400);
        circle(30 + xmov, 280, 20);  // head
        line(30 + xmov, 300, 30 + xmov, 350);  // body
        line(30 + xmov, 330, 70 + xmov, 330);  // hand

        if (xmov % 2 == 0) {
            line(30 + xmov, 350, 25 + xmov, 400);  // left leg
            line(30 + xmov, 350, 10 + xmov, 400);  // right leg
        } else {
            line(30 + xmov, 350, 25 + xmov, 400);
            delay(25);
        }

        line(70 + xmov, 250, 70 + xmov, 330);  // umbrella
        pieslice(80 + xmov, 250, 180, 0, 80);

        srand(time(NULL));  // Seed for rand() based on current time

        for (int i = 0; i <= 300; i++) {
            x = rand() % 800;
            y = rand() % 800;
            outtextxy(x, y, "/");
        }

        delay(600);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}

