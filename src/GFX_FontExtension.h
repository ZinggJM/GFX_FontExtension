// Display Library for parallel interface e-paper panels from Dalian Good Display Co., Ltd.: www.e-paper-display.com
//
// based on Demo Examples from Good Display, available here: http://www.e-paper-display.com/download_list/downloadcategoryid=34&isMode=false.html
//
// class GFX_FontExtension : Subclass for Adafruit_GFX to add multiple UTF-8 fonts
//
// based on code extracted from https://github.com/adafruit/Adafruit-GFX-Library and https://github.com/Bodmer/Adafruit-GFX-Library#enhanced-fork
//
// Author : J-M Zingg
//
// Version : see library.properties
//
// License: GNU GENERAL PUBLIC LICENSE V3, see LICENSE
//
// Library: https://github.com/ZinggJM/GxEPD_HD
//
// Font files can be created using the fontconverter from https://github.com/Bodmer/GFX_Font_Converter
// see tutorial https://www.youtube.com/watch?v=L8MmTISmwZ8


#ifndef _GFX_FontExtension_H_
#define _GFX_FontExtension_H_

// comment out to revert to Adafruit_GFX
//#include <Fruitless_GFX.h>

#ifndef _Fruitless_GFX_H
#include <Adafruit_GFX.h>
class GFX_FontExtension : public Adafruit_GFX
#else
class GFX_FontExtension : public Fruitless_GFX
#endif
{
  public:
#ifndef _Fruitless_GFX_H
    GFX_FontExtension(int16_t w, int16_t h) : Adafruit_GFX(w, h) {};
#else
    GFX_FontExtension(int16_t w, int16_t h) : Fruitless_GFX(w, h) {};
#endif
    void drawChar(int16_t x, int16_t y, uint16_t c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y, const GFXfont* gfxFont);
    virtual size_t write(uint8_t);
    void setFont(const GFXfont* f = NULL); // use this to set a font (to its page)
    void setFont(const GFXfont* f, uint8_t page); // use setFont(0, page); to remove a font, e.g. setFont(0, FreeMonoBold12pt7b.first / 256);
  private:
    uint16_t decodeUTF8(uint8_t c);
  private:
    const GFXfont* gfxFonts[256];
    uint8_t  decoderState = 0;   // UTF-8 decoder state
    uint16_t decoderBuffer;      // Unicode code-point buffer
};

#endif
