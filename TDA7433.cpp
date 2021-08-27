#include <Arduino.h>
#include <Wire.h>
#include "TDA7433.h"

TDA7433::TDA7433(){
	Wire.begin();
}

void TDA7433::setInput(byte in, byte bass_cut, byte bass_range, int bass){
  if(bass>-16&&bass<16){bass_range = 1;}else{bass_range = 0;}
  writeWire(INPUT, in + (bass_cut << 3) + (bass_range << 4));	
} 

void TDA7433::setVolume(int vol){
  byte vol_digit;
  if(vol<=0){vol_digit = abs(vol)+32;}
  if(vol>0){vol_digit = 32-vol;}
  writeWire(VOLUME, vol_digit);
}

void TDA7433::setBass_Treb(int bass, int treb){
  switch(treb){
   case -14: treb = 0b00000000;break;
   case -12: treb = 0b00000001;break;
   case -10: treb = 0b00000010;break;
   case -8 : treb = 0b00000011;break;
   case -6 : treb = 0b00000100;break;
   case -4 : treb = 0b00000101;break;
   case -2 : treb = 0b00000110;break;
   case  0 : treb = 0b00000111;break;
   case  2 : treb = 0b00001110;break;
   case  4 : treb = 0b00001101;break;
   case  6 : treb = 0b00001100;break;
   case  8 : treb = 0b00001011;break;
   case  10: treb = 0b00001010;break;
   case  12: treb = 0b00001001;break;
   case  14: treb = 0b00001000;break;
}
  switch(bass){
   case -18: bass = 0b00000001;break;
   case -16: bass = 0b00000000;break;
   case -14: bass = 0b00000000;break;
   case -12: bass = 0b00000001;break;
   case -10: bass = 0b00000010;break;
   case -8 : bass = 0b00000011;break;
   case -6 : bass = 0b00000100;break;
   case -4 : bass = 0b00000101;break;
   case -2 : bass = 0b00000110;break;
   case  0 : bass = 0b00000111;break;
   case  2 : bass = 0b00001110;break;
   case  4 : bass = 0b00001101;break;
   case  6 : bass = 0b00001100;break;
   case  8 : bass = 0b00001011;break;
   case 10 : bass = 0b00001010;break;
   case 12 : bass = 0b00001001;break;
   case 14 : bass = 0b00001000;break;
   case 16 : bass = 0b00001000;break;
   case 18 : bass = 0b00001001;break;
}
  writeWire(BASS_TREB, treb + (bass << 4));
}

void TDA7433::setAtt_LF(int lf){
  writeWire(ATT_LF, lf);
}
void TDA7433::setAtt_LR(int lr){
  writeWire(ATT_LR, lr);
}
void TDA7433::setAtt_RF(int rf){
  writeWire(ATT_RF, rf);
}
void TDA7433::setAtt_RR(int rr){
  writeWire(ATT_RR, rr);
}

void TDA7433::writeWire(byte a, byte b){
  Wire.beginTransmission(TDA7433_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
