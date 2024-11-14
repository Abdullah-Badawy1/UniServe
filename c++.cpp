#include <iostream>
#include <math.h>
#include <conio.h>
#include <graphics.h>

using namespace std;

void EllipseMidPoint() {
    int xc, yc, a, b;
    cout << "Enter The center of The ellipse ( Xc , Yc ) : ";
    cin >> xc >> yc;
    cout << "Enter The horizontal radius ( a ) and Vertical radius ( b ) : ";
    cin >> a >> b;
    int x = 0;
    int y = b;

    // Region 1
    int dx = 2 * pow(b, 2) * x;
    int dy = 2 * pow(a, 2) * y;
    int pk1 = pow(b, 2) - pow(a, 2) * b + 0.25 * pow(a, 2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout << "Pk\tX\tY\tdX\tdY\n";

    while (dx < dy) {
        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);

        if (pk1 < 0) {
            x++;
            dx += 2 * pow(b, 2);
            pk1 += dx + pow(b, 2);
        } else {
            x++;
            y--;
            dx += 2 * pow(b, 2);
            dy -= 2 * pow(a, 2);
            pk1 += dx - dy + pow(b, 2);
        }

        cout << pk1 << "\t" << x << "\t" << y << "\t" << dx << "\t" << dy << "\n";
    }

    // Region 2
    int pk2 = pow(b, 2) * pow(x + 0.5, 2) + pow(a, 2) * pow(y - 1, 2) - pow(b, 2) * pow(a, 2);

    while (y != 0) {
        if (pk2 > 0) {
            y--;
            dy -= 2 * pow(a, 2);
            pk2 += pow(a, 2) - dy;
        } else {
            x++;
            y--;
            dx += 2 * pow(b, 2);
            dy -= 2 * pow(a, 2);
            pk2 += dx - dy + pow(a, 2);
        }

        putpixel(x + xc, y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);

        cout << pk2 << "\t" << x << "\t" << y << "\t" << dx << "\t" << dy << "\n";
    }

    getch();
    closegraph();
}

int main() {
    EllipseMidPoint();
    return 0;
}

