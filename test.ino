#include <TDA7433.h>

TDA7433 tda;

void setup(){
  audio();
  }

void loop(){
  
  }
void audio(){
        tda.setInput(1, 0, 0, 0); 
// in >>> 0=in2, 1=in1, 2=mono, 3=mute
// bass_cut >>> 0=non-symmetrical bass cut, 1=symmetrical bass cut
// bass_range >>> 0=extended bass range, 1=standard bass range ±14dB
// bass >>> -18...+18 (-18...+18 dB) step 2
        tda.setVolume(0);
// vol >>> -79...+32 (-79...+32 dB)
        tda.setBass_Treb(0, 0);
// bass >>> -18...+18 (-18...+18 dB) step 2
// treb >>> -14...+14 (-14...+14 dB) step 2
        tda.setAtt_LF(0);
// lf >>> 0...31 (0...-31 dB), 32=mute 
        tda.setAtt_LR(0);
// lr >>> 0...31 (0...-31 dB), 32=mute
        tda.setAtt_RF(0);
// rf >>> 0...31 (0...-31 dB), 32=mute
        tda.setAtt_RR(0);
// rr >>> 0...31 (0...-31 dB), 32=mute
  }
  
