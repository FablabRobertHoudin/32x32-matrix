#include "Matrix32x32.h"
#include <ESP8266WiFi.h>

class Matrix32x32 M;

#define r0 15
#define g0 2
#define b0 0
#define r1 4
#define g1 5
// GPIO3: RX...
#define b1 3

#define STB 16
#define CLK 14
#define OE  12
#define ABCD 13



    // initialise PINs
    void Matrix32x32::init() {
      pinMode(STB, OUTPUT); digitalWrite(STB, LOW);
      pinMode(CLK, OUTPUT); digitalWrite(CLK, LOW);
      pinMode(OE, OUTPUT); digitalWrite(OE, HIGH); // disable out
      pinMode(ABCD, OUTPUT); digitalWrite(ABCD, LOW);
      pinMode(r0, OUTPUT); digitalWrite(r0, LOW);
      pinMode(g0, OUTPUT); digitalWrite(g0, LOW);
      pinMode(b0, OUTPUT); digitalWrite(b0, LOW);
      pinMode(r1, OUTPUT); digitalWrite(r1, LOW);
      pinMode(g1, OUTPUT); digitalWrite(g1, LOW);
      pinMode(b1, OUTPUT); digitalWrite(b1, LOW); 
    
      pinMode(A0, INPUT);

      memset(R, 0, sizeof(R));
      memset(G, 0, sizeof(R));
      memset(B, 0, sizeof(R));
    
        R[0] = 0xC0000000;
        G[0] = 0xA0000000;
        B[0] = 0x90000000;
    
     // reset col ?
     // My screen: 15
     #define nReset 15
     for(byte i=0; i<nReset; i++) {
      //Serial.print(i); Serial.print(", before "); Serial.print(analogRead(A0));
      digitalWrite(ABCD, HIGH);
      digitalWrite(ABCD, HIGH);
      digitalWrite(ABCD, HIGH);
      digitalWrite(ABCD, HIGH);
      //Serial.print(", middle "); Serial.print(analogRead(A0));
      digitalWrite(ABCD, LOW);
      digitalWrite(ABCD, LOW);
      digitalWrite(ABCD, LOW);
      digitalWrite(ABCD, LOW);
      //Serial.print(", after "); Serial.print(analogRead(A0));
      //Serial.println();
     }
      }; //

//long mult = 0x00000001;
#define N 4
unsigned long mask[N] = {0xFFFFFF00, 0xFFFF00FF, 0xFF00FFFF, 0x00FFFFFF};
#define SIZE 64
char line[N][SIZE];
int offset[N];
int colors[N];

    // Display line @ offset, update R,G,B, decale offset
    bool Matrix32x32::write(int nl)
    {
      int x = offset[nl];
      bool f = 0, z=0;
      int col = colors[nl];
      unsigned long m = mask[nl];
      //Serial.print("WRITE, "); Serial.print(offset); Serial.println();
      for(char* pc=line[nl]; *pc != '\0'; pc++) { // chars in string
        if (*pc < ' ' || *pc > '}') *pc = '_';
        const char* codes = Matrix32x32::Font5x7[*pc-0x20];
        for(byte i=0; i<=6; i++) { // font codes
          //byte c = (i==6) ? 0 : *codes++;
          long c = (i==6) ? 0 : *codes++;
          if (z && (c==0)) { // zero et aussi precedent
            // skip
          } else { // on le met
            c = c << (nl*8);
            if (x>=0 && x<32) {
              R[x] = (R[x] & m) + (col&0x01 ? c : 0);
              G[x] = (G[x] & m) + (col&0x02 ? c : 0);
              B[x] = (B[x] & m) + (col&0x04 ? c : 0);
              f = 1;
            }
            x++;
          }
          z = (c==0 && (*pc != ' '));
        }
        //x++; // TBC
      }
      if (f) {
        offset[nl]--;
      } else {
        line[nl][0] = '\0';
      }
    return f;
    }

    // Affiche un message (urlencoded)
    void Matrix32x32::display(int nl, int color, String msg)
    {
      //strcpy(line, msg);
      if (msg.length() > SIZE) {
        int l = msg.length();
        msg = "TOO LONG: ";
        msg = msg + l;
      }
      msg.toCharArray(line[nl], SIZE);
      line[nl][msg.length()] = '\0';
      colors[nl] = color;
    
      char *dst, *src;
      dst=line[nl];
      src=line[nl];
      char a, b, x;
      while((x = *src++)) {
        if (x == '+') {x = ' ';}
        else if (x=='%') {
          a = *src++;
          if (a >= 'A')
            a -= ('A' - 10);
          else 
            a -= '0';
          b = *src++;
          if (b >= 'A')
            b -= ('A' - 10);
          else 
            b -= '0';
          x = 16*a+b;
        }
        *dst++ = x;
      }
      *dst = '\0';
      
      offset[nl] = 30;
    }

byte col=0;
void Matrix32x32::update(void) {
  long vr0=R[col], vg0=G[col], vb0=B[col];
  long vr1=R[col+15], vg1=G[col+15], vb1=B[col+15];
  long mask = 0x00000001;

  digitalWrite(OE, HIGH); // disable out
  digitalWrite(STB, HIGH);
  for(byte i=0; i<32; i++) {
    //byte x = (i==i0 && col==col0) ? 1 : 0;
    digitalWrite(r0, vr0 & mask ? HIGH : LOW); 
    digitalWrite(g0, vg0 & mask ? HIGH : LOW); 
    digitalWrite(b0, vb0 & mask ? HIGH : LOW); 
    digitalWrite(r1, vr1 & mask ? HIGH : LOW); 
    digitalWrite(g1, vg1 & mask ? HIGH : LOW); 
    digitalWrite(b1, vb1 & mask ? HIGH : LOW); 
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
    mask *= 2;
  }
  digitalWrite(STB, LOW);
  digitalWrite(OE, LOW); // enable out

  noInterrupts();
  digitalWrite(ABCD, HIGH);
  digitalWrite(ABCD, LOW);
  if (++col > 15) col=0;
  interrupts();

}

// http://sunge.awardspace.com/glcd-sd/node4.html
const char* Matrix32x32::Font5x7[] = {
    "\x00\x00\x00\x00\x00", // 00 00 00 00 00 (space)
    "\x00\x00\xFA\x00\x00", // 00 00 5F 00 00
    "\x00\xE0\x00\xE0\x00", // 00 07 00 07 00
    "\x28\xFE\x28\xFE\x28", // 14 7F 14 7F 14
    "\x24\x54\xFE\x54\x48", // 24 2A 7F 2A 12
    "\xC4\xC8\x10\x26\x46", // 23 13 08 64 62
    "\x6C\x92\xAA\x44\x0A", // 36 49 55 22 50
    "\x00\xA0\xC0\x00\x00", // 00 05 03 00 00
    "\x00\x38\x44\x82\x00", // 00 1C 22 41 00
    "\x00\x82\x44\x38\x00", // 00 41 22 1C 00
    "\x10\x54\x38\x54\x10", // 08 2A 1C 2A 08
    "\x10\x10\x7C\x10\x10", // 08 08 3E 08 08
    "\x00\x0A\x0C\x00\x00", // 00 50 30 00 00
    "\x10\x10\x10\x10\x10", // 08 08 08 08 08
    "\x00\x06\x06\x00\x00", // 00 60 60 00 00
    "\x04\x08\x10\x20\x40", // 20 10 08 04 02
    "\x7C\x8A\x92\xA2\x7C", // 3E 51 49 45 3E
    "\x00\x42\xFE\x02\x00", // 00 42 7F 40 00
    "\x42\x86\x8A\x92\x62", // 42 61 51 49 46
    "\x84\x82\xA2\xD2\x8C", // 21 41 45 4B 31
    "\x18\x28\x48\xFE\x08", // 18 14 12 7F 10
    "\xE4\xA2\xA2\xA2\x9C", // 27 45 45 45 39
    "\x3C\x52\x92\x92\x0C", // 3C 4A 49 49 30
    "\x80\x8E\x90\xA0\xC0", // 01 71 09 05 03
    "\x6C\x92\x92\x92\x6C", // 36 49 49 49 36
    "\x60\x92\x92\x94\x78", // 06 49 49 29 1E
    "\x00\x6C\x6C\x00\x00", // 00 36 36 00 00
    "\x00\x6A\x6C\x00\x00", // 00 56 36 00 00
    "\x00\x10\x28\x44\x82", // 00 08 14 22 41
    "\x28\x28\x28\x28\x28", // 14 14 14 14 14
    "\x82\x44\x28\x10\x00", // 41 22 14 08 00
    "\x40\x80\x8A\x90\x60", // 02 01 51 09 06
    "\x4C\x92\x9E\x82\x7C", // 32 49 79 41 3E
    "\x7E\x88\x88\x88\x7E", // 7E 11 11 11 7E
    "\xFE\x92\x92\x92\x6C", // 7F 49 49 49 36
    "\x7C\x82\x82\x82\x44", // 3E 41 41 41 22
    "\xFE\x82\x82\x44\x38", // 7F 41 41 22 1C
    "\xFE\x92\x92\x92\x82", // 7F 49 49 49 41
    "\xFE\x90\x90\x80\x80", // 7F 09 09 01 01
    "\x7C\x82\x82\x8A\x4C", // 3E 41 41 51 32
    "\xFE\x10\x10\x10\xFE", // 7F 08 08 08 7F
    "\x00\x82\xFE\x82\x00", // 00 41 7F 41 00
    "\x04\x02\x82\xFC\x80", // 20 40 41 3F 01
    "\xFE\x10\x28\x44\x82", // 7F 08 14 22 41
    "\xFE\x02\x02\x02\x02", // 7F 40 40 40 40
    "\xFE\x40\x20\x40\xFE", // 7F 02 04 02 7F
    "\xFE\x20\x10\x08\xFE", // 7F 04 08 10 7F
    "\x7C\x82\x82\x82\x7C", // 3E 41 41 41 3E
    "\xFE\x90\x90\x90\x60", // 7F 09 09 09 06
    "\x7C\x82\x8A\x84\x7A", // 3E 41 51 21 5E
    "\xFE\x90\x98\x94\x62", // 7F 09 19 29 46
    "\x62\x92\x92\x92\x8C", // 46 49 49 49 31
    "\x80\x80\xFE\x80\x80", // 01 01 7F 01 01
    "\xFC\x02\x02\x02\xFC", // 3F 40 40 40 3F
    "\xF8\x04\x02\x04\xF8", // 1F 20 40 20 1F
    "\xFE\x04\x18\x04\xFE", // 7F 20 18 20 7F
    "\xC6\x28\x10\x28\xC6", // 63 14 08 14 63
    "\xC0\x20\x1E\x20\xC0", // 03 04 78 04 03
    "\x86\x8A\x92\xA2\xC2", // 61 51 49 45 43
    "\x00\x00\xFE\x82\x82", // 00 00 7F 41 41
    "\x40\x20\x10\x08\x04", // 02 04 08 10 20
    "\x82\x82\xFE\x00\x00", // 41 41 7F 00 00
    "\x20\x40\x80\x40\x20", // 04 02 01 02 04
    "\x02\x02\x02\x02\x02", // 40 40 40 40 40
    "\x00\x80\x40\x20\x00", // 00 01 02 04 00
    "\x04\x2A\x2A\x2A\x1E", // 20 54 54 54 78
    "\xFE\x12\x22\x22\x1C", // 7F 48 44 44 38
    "\x1C\x22\x22\x22\x04", // 38 44 44 44 20
    "\x1C\x22\x22\x12\xFE", // 38 44 44 48 7F
    "\x1C\x2A\x2A\x2A\x18", // 38 54 54 54 18
    "\x10\x7E\x90\x80\x40", // 08 7E 09 01 02
    "\x10\x28\x2A\x2A\x3C", // 08 14 54 54 3C
    "\xFE\x10\x20\x20\x1E", // 7F 08 04 04 78
    "\x00\x22\xBE\x02\x00", // 00 44 7D 40 00
    "\x04\x02\x22\xBC\x00", // 20 40 44 3D 00
    "\x00\xFE\x08\x14\x22", // 00 7F 10 28 44
    "\x00\x82\xFE\x02\x00", // 00 41 7F 40 00
    "\x3E\x20\x18\x20\x1E", // 7C 04 18 04 78
    "\x3E\x10\x20\x20\x1E", // 7C 08 04 04 78
    "\x1C\x22\x22\x22\x1C", // 38 44 44 44 38
    "\x3E\x28\x28\x28\x10", // 7C 14 14 14 08
    "\x10\x28\x28\x18\x3E", // 08 14 14 18 7C
    "\x3E\x10\x20\x20\x10", // 7C 08 04 04 08
    "\x12\x2A\x2A\x2A\x04", // 48 54 54 54 20
    "\x20\xFC\x22\x02\x04", // 04 3F 44 40 20
    "\x3C\x02\x02\x04\x3E", // 3C 40 40 20 7C
    "\x38\x04\x02\x04\x38", // 1C 20 40 20 1C
    "\x3C\x02\x0C\x02\x3C", // 3C 40 30 40 3C
    "\x22\x14\x08\x14\x22", // 44 28 10 28 44
    "\x30\x0A\x0A\x0A\x3C", // 0C 50 50 50 3C
    "\x22\x26\x2A\x32\x22", // 44 64 54 4C 44
    "\x00\x10\x6C\x82\x00", // 00 08 36 41 00
    "\x00\x00\xFE\x00\x00", // 00 00 7F 00 00
    "\x00\x82\x6C\x10\x00", // 00 41 36 08 00
    "\x10\x10\x54\x38\x10", // 08 08 2A 1C 08
    "\x10\x38\x54\x10\x10", // 08 1C 2A 08 08
/*
  "\x00\x00\x00\x00\x00", // (space)
  "\x00\x00\x5F\x00\x00", // !
  "\x00\x07\x00\x07\x00", // "
  "\x14\x7F\x14\x7F\x14", // #
  "\x24\x2A\x7F\x2A\x12", // $
  "\x23\x13\x08\x64\x62", // %
  "\x36\x49\x55\x22\x50", // &
  "\x00\x05\x03\x00\x00", // '
  "\x00\x1C\x22\x41\x00", // (
  "\x00\x41\x22\x1C\x00", // )
  "\x08\x2A\x1C\x2A\x08", // *
  "\x08\x08\x3E\x08\x08", // +
  "\x00\x50\x30\x00\x00", // ,
  "\x08\x08\x08\x08\x08", // -
  "\x00\x60\x60\x00\x00", // .
  "\x20\x10\x08\x04\x02", // /
  "\x3E\x51\x49\x45\x3E", // 0
  "\x00\x42\x7F\x40\x00", // 1
  "\x42\x61\x51\x49\x46", // 2
  "\x21\x41\x45\x4B\x31", // 3
  "\x18\x14\x12\x7F\x10", // 4
  "\x27\x45\x45\x45\x39", // 5
  "\x3C\x4A\x49\x49\x30", // 6
  "\x01\x71\x09\x05\x03", // 7
  "\x36\x49\x49\x49\x36", // 8
  "\x06\x49\x49\x29\x1E", // 9
  "\x00\x36\x36\x00\x00", // :
  "\x00\x56\x36\x00\x00", // ;
  "\x00\x08\x14\x22\x41", // <
  "\x14\x14\x14\x14\x14", // =
  "\x41\x22\x14\x08\x00", // >
  "\x02\x01\x51\x09\x06", // ?
  "\x32\x49\x79\x41\x3E", // @
  "\x7E\x11\x11\x11\x7E", // A
  "\x7F\x49\x49\x49\x36", // B
  "\x3E\x41\x41\x41\x22", // C
  "\x7F\x41\x41\x22\x1C", // D
  "\x7F\x49\x49\x49\x41", // E
  "\x7F\x09\x09\x01\x01", // F
  "\x3E\x41\x41\x51\x32", // G
  "\x7F\x08\x08\x08\x7F", // H
  "\x00\x41\x7F\x41\x00", // I
  "\x20\x40\x41\x3F\x01", // J
  "\x7F\x08\x14\x22\x41", // K
  "\x7F\x40\x40\x40\x40", // L
  "\x7F\x02\x04\x02\x7F", // M
  "\x7F\x04\x08\x10\x7F", // N
  "\x3E\x41\x41\x41\x3E", // O
  "\x7F\x09\x09\x09\x06", // P
  "\x3E\x41\x51\x21\x5E", // Q
  "\x7F\x09\x19\x29\x46", // R
  "\x46\x49\x49\x49\x31", // S
  "\x01\x01\x7F\x01\x01", // T
  "\x3F\x40\x40\x40\x3F", // U
  "\x1F\x20\x40\x20\x1F", // V
  "\x7F\x20\x18\x20\x7F", // W
  "\x63\x14\x08\x14\x63", // X
  "\x03\x04\x78\x04\x03", // Y
  "\x61\x51\x49\x45\x43", // Z
  "\x00\x00\x7F\x41\x41", // [
  "\x02\x04\x08\x10\x20", // "\"
  "\x41\x41\x7F\x00\x00", // ]
  "\x04\x02\x01\x02\x04", // ^
  "\x40\x40\x40\x40\x40", // _
  "\x00\x01\x02\x04\x00", // `
  "\x20\x54\x54\x54\x78", // a
  "\x7F\x48\x44\x44\x38", // b
  "\x38\x44\x44\x44\x20", // c
  "\x38\x44\x44\x48\x7F", // d
  "\x38\x54\x54\x54\x18", // e
  "\x08\x7E\x09\x01\x02", // f
  "\x08\x14\x54\x54\x3C", // g
  "\x7F\x08\x04\x04\x78", // h
  "\x00\x44\x7D\x40\x00", // i
  "\x20\x40\x44\x3D\x00", // j
  "\x00\x7F\x10\x28\x44", // k
  "\x00\x41\x7F\x40\x00", // l
  "\x7C\x04\x18\x04\x78", // m
  "\x7C\x08\x04\x04\x78", // n
  "\x38\x44\x44\x44\x38", // o
  "\x7C\x14\x14\x14\x08", // p
  "\x08\x14\x14\x18\x7C", // q
  "\x7C\x08\x04\x04\x08", // r
  "\x48\x54\x54\x54\x20", // s
  "\x04\x3F\x44\x40\x20", // t
  "\x3C\x40\x40\x20\x7C", // u
  "\x1C\x20\x40\x20\x1C", // v
  "\x3C\x40\x30\x40\x3C", // w
  "\x44\x28\x10\x28\x44", // x
  "\x0C\x50\x50\x50\x3C", // y
  "\x44\x64\x54\x4C\x44", // z
  "\x00\x08\x36\x41\x00", // {
  "\x00\x00\x7F\x00\x00", // |
  "\x00\x41\x36\x08\x00", // }
  "\x08\x08\x2A\x1C\x08", // ->
  "\x08\x1C\x2A\x08\x08"  // <-
*/
  };

