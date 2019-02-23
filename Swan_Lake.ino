#include <pitches.h>

#include <toneAC.h>

 float TCHAILEN[87]={
      2.0, 8.0, 8.0, 8.0, 8.0, 
      3.0, 8.0, 3.0, 8.0,
      3.0, 8.0, 8.0, 8.0, 8.0, 8.0,
      2.0, 8.0, 8.0, 8.0, 
      2.0, 8.0, 8.0, 8.0, 8.0, 
      3.0, 8.0, 3.0, 8.0, 
      3.0, 8.0, 8.0, 8.0, 8.0, 8.0, 
      1.3, 4.0,  
      4.0, 4.0, 4.0, 8.0, 8.0, 
      3.0, 8.0, 4.0, 8.0, 8.0,
      3.0, 8.0, 4.0, 8.0, 8.0, 
      3.0, 8.0, 8.0, 8.0, 8.0, 8.0, 
      4.0, 4.0, 4.0, 8.0, 8.0, 
      3.0, 8.0, 4.0, 8.0, 8.0, 
      3.0, 8.0, 4.0, 8.0, 8.0,   
      3.0, 8.0, 4.0, 8.0, 8.0,  
      3.0, 8.0, 4.0, 8.0, 8.0, 
      2.85, 7.75, 2.75, 7.5, 
      0.90 };
      
  int TCHAISCORE[87]={
    NOTE_E4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4, 
    NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, 
    NOTE_E4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_E3, NOTE_C4, 
    NOTE_A3, NOTE_D4, NOTE_C4, NOTE_B3,
    NOTE_E4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4, 
    NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, 
    NOTE_E4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_E3, NOTE_C4, 
    NOTE_A3, NOTE_A3, 
    NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
    NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F3, NOTE_G3, 
    NOTE_A3, NOTE_G3, NOTE_F3, NOTE_G3, NOTE_A3, 
    NOTE_B3, NOTE_A3, NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3, 
    NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
    NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F3, NOTE_G3,
    NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4, 
    NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,  
    NOTE_AS4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_AS4, 
    NOTE_B4, NOTE_FS4, NOTE_B4, NOTE_E4, 
    NOTE_E4 };


void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int NoteNOW = 0;
  int NoteTTL = 0;
  float NoteLEN = 0;
  int NoteN = 0;
  
               
  for(int NoteN = 0; NoteN < 87; NoteN++){
     NoteLEN = TCHAILEN[NoteN]; //Adantino tempo 600 mS per beat
     NoteTTL = 1700.0/NoteLEN; //Adantino tempo 100 bpm
     NoteNOW = TCHAISCORE[NoteN];
     toneAC(NoteNOW, 5, NoteTTL, true); //play NoteN in background
     delay (NoteTTL *(4/3)); //Wait play note + 33% internote gap
    
     Serial.println(NoteN);
     
   
  }
  }

