#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x, y, prev_x = -1, prev_y = -1;
    int drawing = 0;

    // Hide mouse cursor
    setmousequeuestatus(WM_LBUTTONDOWN | WM_LBUTTONUP | WM_MOUSEMOVE);

    while(!kbhit()) {
        // Check for mouse events
        if (ismouseclick(WM_LBUTTONDOWN)) {
            // Get mouse click coordinates
            getmouseclick(WM_LBUTTONDOWN, x, y);
            prev_x = x;
            prev_y = y;
            drawing = 1;
        } else if (ismouseclick(WM_MOUSEMOVE) && drawing) {
            // Get mouse movement coordinates
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (prev_x != -1 && prev_y != -1) {
                line(prev_x, prev_y, x, y);
            }
            prev_x = x;
            prev_y = y;
        } else if (ismouseclick(WM_LBUTTONUP)) {
            drawing = 0;
            prev_x = -1;
            prev_y = -1;
        }

        delay(10); // Small delay to reduce CPU usage
    }

    closegraph();
    return 0;
}