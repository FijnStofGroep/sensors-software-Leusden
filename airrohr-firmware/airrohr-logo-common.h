//const char LUFTDATEN_INFO_LOGO_SVG[] PROGMEM = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100\" height=\"89\" fill=\"#fff\"><path d=\"M90.28 66.57v.1h-6.95c-2.04 0-3.7-1.66-3.7-3.7a3.7 3.7 0 0 1 3.7-3.7h5.56a3.72 3.72 0 0 0 3.7-3.7c0-2.06-1.67-3.72-3.7-3.72a3.73 3.73 0 0 1-3.72-3.7 3.7 3.7 0 0 1 3.7-3.7 3.74 3.74 0 0 1 .75.07c5.8.4 10.37 5.15 10.37 11.04 0 5.66-4.24 10.32-9.72 11zm-19.9-22.13a3.7 3.7 0 0 1-3.7-3.7c0-2.04 1.66-3.7 3.7-3.7a3.74 3.74 0 0 1 .75.07c5.78.4 10.36 5.17 10.36 11.05 0 5.66-4.24 10.33-9.72 11v.1H29.63c-2.04 0-3.7 1.67-3.7 3.7 0 2.06 1.65 3.72 3.7 3.72h42.14v.1a11.09 11.09 0 0 1 9.7 11c0 5.9-4.57 10.65-10.35 11.05-.25.04-.5.07-.75.07-2.04 0-3.7-1.67-3.7-3.7a3.71 3.71 0 0 1 3.7-3.72c2.04 0 3.7-1.66 3.7-3.7a3.7 3.7 0 0 0-3.7-3.7H28.23v-.1c-5.47-.7-9.7-5.35-9.7-11.02 0-1.95.53-3.76 1.42-5.35C8.35 53.6 0 42.6 0 29.64 0 13.27 13.27 0 29.63 0c11.12 0 20.8 6.13 25.86 15.2 1.22-.22 2.47-.38 3.76-.38 10.92 0 19.98 7.88 21.85 18.26-2.57-1.84-5.64-3.05-8.97-3.36-2.55-4.48-7.35-7.5-12.87-7.5-2.96 0-5.7.9-8.03 2.4-2.28-9.85-11.06-17.2-21.6-17.2C17.36 7.4 7.4 17.35 7.4 29.6c0 12.28 9.96 22.23 22.23 22.23h40.74c2.04 0 3.7-1.66 3.7-3.7a3.69 3.69 0 0 0-3.7-3.7z\"/></svg>";

// SVG is rather large, we can save space by blending this to a PNG:
// convert -size 100x88 -background '#33BBAA' <logo.svg> -dither None -colors 8 -depth 4 -flatten <logo.png>
// optipng -o7 -zm1-9 -strip all <logo.png>
// reduces size from 1255 to 632 bytes.

// constexpr const unsigned int LUFTDATEN_INFO_LOGO_PNG_SIZE = 632;
constexpr const unsigned int LUFTDATEN_INFO_LOGO_PNG_SIZE = 853;

const char LUFTDATEN_INFO_LOGO_PNG[] PROGMEM = {
    0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
    0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x5A, 0x08, 0x03, 0x00, 0x00, 0x00, 0x96, 0x8E, 0x68,
    0x85, 0x00, 0x00, 0x00, 0x45, 0x50, 0x4C, 0x54, 0x45, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF,
    0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x99, 0xDD, 0xDD, 0xCC, 0xEE, 0xEE, 0x76, 0xAF, 0xAB, 0x64, 0xA2, 0x9D, 0x2E, 0x81, 0x79,
    0x35, 0x87, 0x7F, 0x66, 0xA4, 0x9E, 0xB1, 0xCC, 0xC9, 0x05, 0x5D, 0x52, 0x06, 0x5E, 0x53, 0x08,
    0x61, 0x56, 0x42, 0x8E, 0x84, 0xAB, 0xC9, 0xC5, 0xCE, 0xDF, 0xDD, 0xAF, 0xCB, 0xC7, 0xBB, 0xED,
    0x6D, 0xA7, 0x00, 0x00, 0x02, 0xCB, 0x49, 0x44, 0x41, 0x54, 0x68, 0xDE, 0xD5, 0x99, 0xDD, 0x96,
    0xAB, 0x20, 0x0C, 0x85, 0xF7, 0x65, 0xED, 0x71, 0x34, 0x4E, 0x68, 0xDE, 0xFF, 0x51, 0xE7, 0x42,
    0x10, 0x70, 0x22, 0x02, 0xC1, 0x59, 0xEB, 0xE4, 0xB6, 0xAD, 0x5F, 0xF3, 0xB3, 0x93, 0x80, 0x20,
    0xDD, 0xB6, 0xD7, 0x6B, 0x9A, 0x00, 0x60, 0x9A, 0x5E, 0xDF, 0x64, 0x35, 0x68, 0x84, 0xAF, 0xF7,
    0xE7, 0x83, 0x68, 0x8E, 0x79, 0x38, 0x65, 0x7B, 0xA7, 0x84, 0xDD, 0x44, 0x6C, 0x20, 0x54, 0x30,
    0x76, 0x90, 0xE3, 0x51, 0x94, 0x4B, 0x86, 0x91, 0x93, 0x51, 0xBE, 0x0A, 0x0C, 0x00, 0x10, 0x1E,
    0x40, 0xC9, 0x21, 0x72, 0x98, 0xDD, 0x9D, 0x84, 0x92, 0x44, 0x4B, 0x24, 0xA9, 0x2B, 0x66, 0x17,
    0x49, 0x7D, 0xEE, 0x40, 0x49, 0x89, 0xF2, 0x8F, 0xD9, 0x89, 0x05, 0x73, 0x50, 0xDE, 0x37, 0x51,
    0x39, 0x38, 0x3D, 0x18, 0x9C, 0xC3, 0x75, 0x1D, 0x79, 0xEE, 0xC7, 0x20, 0x4F, 0x7C, 0x51, 0x7D,
    0xC1, 0x9D, 0x76, 0x0C, 0x4E, 0x90, 0xF2, 0xB7, 0xB9, 0x13, 0x03, 0x22, 0xA2, 0xED, 0x53, 0x1B,
    0x0B, 0x8F, 0x71, 0x3D, 0x94, 0x77, 0x7D, 0xC0, 0x5D, 0x97, 0x33, 0x48, 0x5C, 0xA9, 0xF9, 0x29,
    0x47, 0x0C, 0x73, 0x75, 0x0B, 0x45, 0x74, 0xA5, 0x4E, 0xD7, 0x21, 0x35, 0x22, 0x02, 0x48, 0x26,
    0xDF, 0x22, 0xC5, 0xBB, 0x52, 0x1B, 0x05, 0x96, 0xF6, 0x2E, 0x8A, 0xE8, 0x4A, 0x6D, 0x90, 0x5D,
    0x7B, 0xB7, 0x46, 0xAB, 0x2B, 0x8A, 0x33, 0xF7, 0x1C, 0xD0, 0x17, 0x5A, 0x8B, 0x53, 0xB4, 0xA9,
    0x50, 0xC4, 0xC0, 0x07, 0xAC, 0xA5, 0x36, 0x39, 0x1D, 0x0C, 0x55, 0xC3, 0x07, 0xE4, 0x03, 0xD6,
    0x50, 0xFD, 0x9C, 0x54, 0x16, 0x57, 0x75, 0x6B, 0xF8, 0xB4, 0x34, 0xA9, 0x39, 0x2F, 0xDE, 0x8A,
    0x6E, 0x8D, 0x57, 0xBD, 0x22, 0xEF, 0xA4, 0x7A, 0x8D, 0xF1, 0x14, 0xB1, 0x6D, 0x5C, 0xC1, 0x9D,
    0xAB, 0x88, 0x60, 0x6A, 0x4E, 0x4B, 0x47, 0x7F, 0x1B, 0x45, 0xE1, 0x22, 0x26, 0xD4, 0x07, 0x99,
    0x31, 0x52, 0xC8, 0xEF, 0x30, 0x0A, 0xB1, 0x13, 0x91, 0x8B, 0x07, 0x8D, 0xA3, 0x78, 0x12, 0x3F,
    0x4F, 0x39, 0x4B, 0xE9, 0x29, 0xCA, 0xB3, 0x35, 0x56, 0x47, 0xE1, 0x67, 0x29, 0x23, 0x3A, 0xCC,
    0x3D, 0x65, 0x5B, 0xBB, 0x76, 0x9F, 0x46, 0x0A, 0xAD, 0x7F, 0x90, 0x18, 0xD0, 0x32, 0x20, 0x31,
    0xEC, 0xDC, 0xCD, 0xAC, 0x9C, 0x61, 0x0E, 0x19, 0xCB, 0xCD, 0x09, 0x17, 0xE4, 0x13, 0x63, 0x71,
    0xC6, 0xDD, 0x4D, 0x4B, 0x90, 0x0F, 0x99, 0xC5, 0x99, 0xDB, 0x93, 0x1A, 0x68, 0x80, 0x33, 0x7C,
    0x87, 0x01, 0x45, 0x67, 0x46, 0x60, 0xF4, 0x87, 0x80, 0x0E, 0x67, 0x2C, 0x31, 0xE3, 0x63, 0x97,
    0xB9, 0xA4, 0x04, 0x67, 0xAC, 0xC3, 0x3F, 0x17, 0x5E, 0x5A, 0x71, 0xA0, 0xC4, 0x19, 0xA3, 0x68,
    0x24, 0x79, 0x06, 0x3B, 0x91, 0xB8, 0xD6, 0x82, 0x88, 0x88, 0xE6, 0x21, 0x18, 0x97, 0x84, 0xCC,
    0x65, 0xEB, 0xF3, 0x4E, 0x89, 0x18, 0x67, 0x96, 0x8D, 0xCB, 0xCA, 0x61, 0xFF, 0xDF, 0x9E, 0x42,
    0xCB, 0x0A, 0x73, 0xA5, 0x25, 0x94, 0x93, 0x84, 0x02, 0x25, 0x62, 0xFA, 0xDD, 0x49, 0x23, 0x96,
    0x4B, 0xE8, 0xA0, 0x44, 0x4C, 0x2F, 0x27, 0xCB, 0x3E, 0xC5, 0xCB, 0x1B, 0xC9, 0x6E, 0x7B, 0x22,
    0x06, 0x95, 0xC7, 0x45, 0x4D, 0x99, 0x2E, 0x15, 0x51, 0xE0, 0x26, 0x94, 0xA3, 0x04, 0xCE, 0x37,
    0x57, 0x95, 0xA6, 0x54, 0xE9, 0x2E, 0x21, 0xF7, 0x9D, 0x52, 0x0E, 0xDD, 0x18, 0x8C, 0x35, 0xFF,
    0xA6, 0x8C, 0x42, 0xDB, 0x62, 0xE4, 0x9C, 0x33, 0x1A, 0x6A, 0xE0, 0x14, 0x5D, 0x13, 0xE7, 0x77,
    0xD9, 0x5C, 0x50, 0x2C, 0x1C, 0xA5, 0x73, 0xA8, 0x11, 0xF3, 0x9C, 0x2E, 0x84, 0x36, 0x90, 0xB9,
    0x40, 0x99, 0xE3, 0x9D, 0x78, 0x83, 0x69, 0xC5, 0xED, 0xB4, 0x1A, 0x0B, 0xC2, 0x31, 0xF6, 0x9A,
    0xC0, 0x8D, 0x97, 0x76, 0x1A, 0xC5, 0x38, 0xA1, 0xCF, 0x77, 0x1B, 0x4E, 0x7D, 0x9B, 0x60, 0xDC,
    0x36, 0x7F, 0x41, 0x58, 0xA7, 0xD8, 0xE6, 0xB3, 0x53, 0x14, 0xF4, 0x30, 0xC5, 0x2B, 0xE8, 0x81,
    0x88, 0xB9, 0xB4, 0xBA, 0xD3, 0x89, 0x3C, 0x36, 0xFB, 0x6E, 0xEF, 0x9E, 0xC9, 0xEA, 0x5C, 0xD0,
    0xCB, 0xC0, 0x93, 0x93, 0xAA, 0xFD, 0xB5, 0xA3, 0xF7, 0x17, 0x07, 0x92, 0x46, 0xA1, 0xBE, 0x4E,
    0x56, 0x18, 0xB1, 0x2A, 0x85, 0xD6, 0x61, 0xED, 0xB2, 0x44, 0xD9, 0x06, 0x63, 0x74, 0x4A, 0x77,
    0xFB, 0x2F, 0xEC, 0xFC, 0xAA, 0xCD, 0x6B, 0x17, 0xE7, 0x7A, 0xE7, 0xBF, 0xE2, 0x2C, 0x6B, 0x8B,
    0x01, 0x37, 0x3B, 0xFF, 0x08, 0x3B, 0xCA, 0xFF, 0x51, 0x4A, 0xF1, 0x48, 0x37, 0x8E, 0x12, 0x5A,
    0xC6, 0xC3, 0x94, 0x42, 0x2F, 0xFF, 0xEF, 0x28, 0xCB, 0x5F, 0x44, 0x6C, 0x7E, 0x3C, 0xFB, 0xDB,
    0x3C, 0x2F, 0xA5, 0x83, 0x36, 0x06, 0xBA, 0x71, 0xDD, 0x62, 0x46, 0x50, 0xD2, 0xDE, 0xDA, 0xD8,
    0xC7, 0xDA, 0x85, 0x52, 0xD8, 0x14, 0x87, 0x52, 0x2E, 0xE7, 0xD8, 0x10, 0xCA, 0xED, 0x6D, 0xC1,
    0x90, 0xEC, 0x2F, 0x2B, 0xCA, 0x2F, 0xBA, 0xC7, 0x54, 0xF2, 0x0C, 0x4C, 0xFF, 0x0A, 0x9F, 0xFF,
    0x00, 0x03, 0x91, 0xE1, 0x1B, 0x8A, 0xFA, 0xAE, 0xBE, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E,
    0x44, 0xAE, 0x42, 0x60, 0x82
    };
