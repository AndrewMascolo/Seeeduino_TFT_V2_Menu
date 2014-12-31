/*
  SeeedTouchScreen.h - Library for 4-line resistance touch screen.
  Modified by loovee Aug 12, 2012.
  (c) ladyada / adafruit
  Code under MIT License.
*/
#ifndef SeeedTouchScreen_H
#define SeeedTouchScreen_H

#define TS_MINX 260
#define TS_MAXX 1760
#define TS_MINY 170
#define TS_MAXY 1810

#define __PRESURE 10
class Point {
    public:
    int x, y, z;

    Point(void);
    Point(int x, int y, int z);
    bool operator==(Point);
    bool operator!=(Point);

};

class TouchScreen {
    private:
    unsigned char _yp, _ym, _xm, _xp;

    public:
    TouchScreen(unsigned char xp, unsigned char yp, unsigned char xm, unsigned char ym);
    bool isTouching(void);
    Point getPoint();

};

#endif