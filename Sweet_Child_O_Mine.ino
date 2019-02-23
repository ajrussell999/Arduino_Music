
#include <pitches.h>
#include <toneAC.h>

float SLASHLEN[64]={
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,   
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
       8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0 };
                      
  int SLASHSCORE[64]={
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4, 
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_E4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_E4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4, 
      NOTE_G4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4, 
      NOTE_G4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4 };
            

  void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  }
  
  void loop(){
  
    for(int NoteN = 0; NoteN < 64; NoteN++) {
    
    int NoteLEN = 0;
    int NoteNOW = 0;
    int NoteTTL = 0;
   
    
     NoteLEN = SLASHLEN[NoteN]; //Allegro tempo 490 mS per beat
     NoteTTL = 1700.0/NoteLEN; //Allegro tempo 122 bpm
     NoteNOW = SLASHSCORE[NoteN]; //Select next note of the arpegio
     toneAC(NoteNOW, 10, NoteTTL, true); //play NoteN in background
     delay (NoteTTL *(4/3.9)); //Wait play note + 2% internote gap
    
     Serial.println(NoteN);
                                          }
  
          }
          
