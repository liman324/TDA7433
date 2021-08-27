// liman324@yandex.ru rcl-radio.ru


#ifndef TDA7433_H
#define TDA7433_H

#define TDA7433_address 0b1000101

#define INPUT      0b00000000
#define VOLUME     0b00000001
#define BASS_TREB  0b00000010
#define ATT_LF     0b00000011
#define ATT_LR     0b00000100
#define ATT_RF     0b00000101
#define ATT_RR     0b00000110


#include <Arduino.h>
class TDA7433
{
  public:
    TDA7433();
        void setInput(byte in, byte bass_cut, byte bass_range, int bass); 
// in >>> 0=in2, 1=in1, 2=mono, 3=mute
// bass_cut >>> 0=non-symmetrical bass cut, 1=symmetrical bass cut
// bass_range >>> 0=extended bass range, 1=standard bass range ±14dB
// bass >>> -18...+18 (-18...+18 dB)
        void setVolume(int vol);
// vol >>> -79...+32 (-79...+32 dB)
        void setBass_Treb(int bass, int treb);
// bass >>> -18...+18 (-18...+18 dB)
// treb >>> -14...+14 (-14...+14 dB)
        void setAtt_LF(int lf);
// lf >>> 0...31 (0...-31 dB), 32=mute
        void setAtt_LR(int lr);
// lr >>> 0...31 (0...-31 dB), 32=mute
        void setAtt_RF(int rf);
// rf >>> 0...31 (0...-31 dB), 32=mute
        void setAtt_RR(int rr);
// rr >>> 0...31 (0...-31 dB), 32=mute
		
 private:
	void writeWire(byte a, byte b);
};
	
#endif //TDA7433_H
