#define IMG_SIZE 636

bool altWalk    = false;
bool crouchWalk = false;
bool proneCheck      = false;

static void render_r6(void) {

    // 'Walking!', 128x32px
    static const char PROGMEM walking[][IMG_SIZE] = {{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xfe, 0x7f, 0x07, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xf7, 0xf8, 0xfe, 0xcf, 0x07, 0x01, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x07, 0x00, 0xf0, 0xff, 0xff, 0x3f, 0xff, 0xfc, 0x80, 0xfc, 0xff, 0x7f, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x81, 0x81, 0x81, 0x8f, 0x8f, 0x8f, 0x00, 0x00, 0xfe, 0xff, 0x7f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xe7, 0xff, 0xff, 0x7f, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x7f, 0x07, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x80, 0xf0, 0xfe, 0x3f, 0x1f, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0x83, 0x80, 0x80, 0x80, 0x80, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x00, 0xf8, 0xff, 0xff, 0x01, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xfe, 0xff, 0xff, 0xc0, 0x80, 0x81, 0xc1, 0xff, 0xff, 0x7f, 0x00, 0x00, 0xc8, 0xcf, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }};
    // 'Crouch!', 128x32px
    static const char PROGMEM crouch[][IMG_SIZE] = {{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x47, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x0f, 0x0f, 0x0f, 0x00, 0xf0, 0xff, 0xff, 0x87, 0x81, 0x81, 0xe1, 0xff, 0x7f, 0x1f, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0xfb, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x01, 0xfc, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x0f, 0x0f, 0x0f, 0x00, 0xf0, 0xff, 0xff, 0xe7, 0xe0, 0xe0, 0xe0, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00, 0xfe, 0xff, 0x7f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xdf, 0x1f, 0xbf, 0xfe, 0xfc, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc0, 0xf8, 0x78, 0x38, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x01, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x7e, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xff, 0x3f, 0x01, 0x7c, 0xff, 0xff, 0xc1, 0x80, 0x80, 0xc0, 0xfe, 0xff, 0x3f, 0x00, 0x7e, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc0, 0xf8, 0x78, 0x38, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x01, 0x00, 0x00, 0xc8, 0xcf, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x03, 0x01, 0x00, 0x03, 0x00, 0x00, 0x0f, 0x1f, 0x1b, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }};
    // 'Prone!', 128x32px
    static const char PROGMEM prone[][IMG_SIZE] = {{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x87, 0x81, 0x81, 0xc1, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0xff, 0x87, 0x81, 0x81, 0xe1, 0xff, 0x7f, 0x1f, 0x00, 0xfc, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0xfb, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0x3f, 0xff, 0xfc, 0x80, 0xfc, 0xff, 0x7f, 0x00, 0xf0, 0xff, 0xff, 0xe7, 0xe1, 0xe1, 0xe1, 0x01, 0x01, 0x00, 0x00, 0xfe, 0xff, 0x7f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x30, 0x30, 0x70, 0x70, 0x73, 0x7b, 0x73, 0x73, 0x77, 0x77, 0x77, 0x7f, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x3e, 0x0e, 0x0e, 0x06, 0x1e, 0x1e, 0x0f, 0x07, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0xf8, 0xff, 0xff, 0x03, 0x01, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x7e, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xff, 0x3f, 0x01, 0xf8, 0xff, 0xff, 0x01, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xf8, 0xff, 0xff, 0x83, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xc8, 0xcf, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }};
    // 'Logo', 128x32px
    static const char PROGMEM logo[][IMG_SIZE] = {{
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xef, 0xef, 0xef, 0xce, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x1c, 0x7f, 0xff, 0xff, 0xe3, 0xc3, 0x8f, 0x0f, 0x0f, 0x06, 0xf8, 0xff, 0xff, 0x3f, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xc7, 0xc3, 0xc3, 0x03, 0x83, 0xfe, 0xff, 0xff, 0x0f, 0x07, 0x03, 0x07, 0x1f, 0x1f, 0x1f, 0x1e, 0x18, 0x1f, 0x9f, 0x9f, 0x87, 0x87, 0xc7, 0xc7, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x81, 0x80, 0xf4, 0xf8, 0xfc, 0xff, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x00, 0x70, 0xf0, 0xf0, 0xe0, 0xc1, 0xe7, 0xff, 0xff, 0x7e, 0x18, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe3, 0xe1, 0x00, 0x7f, 0xff, 0xff, 0xe3, 0xe0, 0xe0, 0xe6, 0xfe, 0xfe, 0x7f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe3, 0xe3, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }};

    void R6_func(void) {

        if (altWalk) {
            oled_scroll_off();
            oled_write_raw_P(walking[0], IMG_SIZE);

        } else if (crouchWalk) {
            oled_scroll_off();
            oled_write_raw_P(crouch[0], IMG_SIZE);

        } else if (proneCheck) {
            oled_scroll_off();
            oled_write_raw_P(prone[0], IMG_SIZE);

        } else {
            oled_scroll_set_speed(3);
            oled_write_raw_P(logo[0], IMG_SIZE);
            oled_scroll_left();     
        }
    }

    R6_func();
}
