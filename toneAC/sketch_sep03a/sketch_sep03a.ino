#include <pitches.h>

#include <toneAC.h>

 float TCHAILEN[82]={
      2.0, 8.0, 8.0, 8.0, 
      0.375, 4, 0.375, 8.0,
      2.0, 8.0, 8.0, 8.0, 8.0, 8.0,
      2.0, 8.0, 8.0, 8.0, 
      2.0, 8.0, 8.0, 8.0, 8.0, 
      0.375, 8.0, 0.375, 8.0, 
      0.375, 8.0, 8.0, 8.0, 8.0, 8.0, 
      0.375, 4.0, 2.0, 
      4.0, 4.0, 4.0, 8.0, 8.0, 
      0.375, 8.0, 4.0, 8.0, 8.0,
      0.375, 8.0, 4.0, 8.0, 8.0, 
      0.375, 8.0, 8.0, 8.0, 8.0, 8.0, 
      4.0, 4.0, 4.0, 8.0, 8.0, 
      0.375, 8.0, 4.0, 8.0, 8.0, 
      8.0, 8.0, 0.375, 0.375, 
      6.0, 7.0, 7.0, 7.0,  
      7.0, 7.0, 0.429, 7.0, 3.0, 
      1.75, 1.5};
      
 
      
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int NoteNOW = 0;
  float NoteTTL = 0;
  int NoteLEN = 0;
  int NoteN = 0;
  int TCHAISCORE[18]={
      NOTE_E4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_E3, NOTE_C4, 
      NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4,
      NOTE_A3, NOTE_D4, NOTE_C4, NOTE_B3
      NOTE_A3, NOTE_D4, NOTE_C4, NOTE_B3 
      };
               
  for(int NoteN = 0; NoteN < 82; NoteN++){
     NoteLEN = TCHAILEN[NoteN]; //Adagio tempo 882 mS per beat
     NoteTTL = 882/NoteLEN; //Adagio tempo
     NoteNOW = TCHAISCORE[NoteN];
     Serial.println(NoteLEN);
     delay (500);
   
  }
  }

