// Paint application - Demonstate both TFT and Touch Screen
#include <stdint.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <SPI.h>

int ColorPaletteHigh = 30;
int color = WHITE;  //Paint brush color
unsigned int colors[8] = {BLACK, RED, GREEN, BLUE, CYAN, YELLOW, WHITE, GRAY1};

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// The 2.8" TFT Touch shield has 300 ohms across the X plate

TouchScreen ts = TouchScreen(XP, YP, XM, YM); //init TouchScreen port pins

void setup()
{
    Tft.TFTinit();  //init TFT library
    Serial.begin(115200);
    //Draw the pallet
    for(int i = 0; i<8; i++)
    {
        Tft.fillRectangle(i*30, 0, 30, ColorPaletteHigh, colors[i]);
    }
}

void loop()
{
    // a point object holds x y and z coordinates.
    Point p = ts.getPoint();

    //map the ADC value read to into pixel co-ordinates

    //p.x = map<long>(p.x, 260, 1760, 0, 240);
    //p.y = map<long>(p.y, 170, 1810, 0, 320);
    Serial.print(p.x); Serial.print(" ");Serial.println(p.y);
    
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!

    if (p.z > __PRESURE) {
        // Detect  paint brush color change
        if(p.y < ColorPaletteHigh+2)
        {
            color = colors[p.x/30];
        }
        else
        {
            Tft.fillCircle(p.x,p.y,2,color);
        }
    }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
