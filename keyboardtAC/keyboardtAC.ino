#include <toneAC.h>
#include <pitches.h>

int freq[]={NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5};


void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ButtonOhms = analogRead (0);
  Serial.println(ButtonOhms);
 
  if (ButtonOhms >= 970 && ButtonOhms <= 1023){
  toneAC (freq[3], 10, 250, true);  
  }
  else if (ButtonOhms >= 737 && ButtonOhms <= 797) {
    toneAC (freq[2], 10,250, true);
  }
  else if (ButtonOhms >=481 && ButtonOhms <= 541) {
    toneAC (freq[1], 10, 250, true);
  }
  else if (ButtonOhms >= 225 && ButtonOhms <= 285) {
  toneAC (freq[0], 10, 250, true);
  }
  else if (ButtonOhms >= 160 && ButtonOhms <= 180) {
    TCHAI(); // Play melody TCHAI
  }
  else if (ButtonOhms >= 181 && ButtonOhms <= 201) {
    SLASH(); //Play melody SLASH
  }
  else{
  toneAC(0);
      }
}

void TCHAI() {
  int TCHAISCORE[]={
      NOTE_E4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_E3, NOTE_C4, 
      NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4,
      NOTE_A3, NOTE_D4, NOTE_C4, NOTE_B3
      NOTE_A3, NOTE_D4, NOTE_C4, NOTE_B3, 
      NOTE_E4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4, 
      NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4
      NOTE_E4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_E3, NOTE_C4, 
      NOTE_A3, NOTE_E3, NOTE_A2, 
      NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
      NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F3, NOTE_G3, 
      NOTE_A3, NOTE_G3, NOTE_F3, NOTE_G3, NOTE_A3, 
      NOTE_B3, NOTE_A3, NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3, 
      NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
      NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F3, NOTE_G3, 
      NOTE_NULL, NOTE_C4, NOTE_F4, NOTE_C4, 
      NOTE_NULL, NOTE_D4, NOTE_F4, NOTE_D4, 
      NOTE_NULL, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_G4, 
      NOTE_E4, NOTE_A2,   
                       }

  int TCHAILEN[]={
      2, 8, 8, 8, 
      3/8, 4, 3/8, 8,
      2, 8, 8, 8, 8, 8,
      2, 8, 8, 8, 
      2, 8, 8, 8, 8, 
      3/8, 8, 3/8, 8, 
      3/8, 8, 8, 8, 8, 8, 
      3/8, 4, 2, 
      4, 4, 4, 8, 8, 
      3/8, 8, 4, 8, 8,
      3/8, 8, 4, 8, 8, 
      3/8, 8, 8, 8, 8, 8, 
      4, 4, 4, 8, 8, 
      3/8, 8, 4, 8, 8, 
      8, 8, 3/8, 3/8, 
      6, 7, 7, 7,  
      7, 7, 3/7, 7, 3, 
      7/4, 6/4,  
                }

  for (int NoteN = 0; NoteN < 81; NoteN++){
    int NoteTTL = 882/TCHAILEN[NoteN]; //Adagio tempo
    toneAC(TCHAISCORE[NoteN], 10, NoteTTL, true); //play NoteN in background
    delay1 (NoteTTL *4/3); //Wait play note + 33% internote gap
  }
  while(1); // Halt, don´t repeat.
  }
  
  void SLASH(){
    int SLASHSCORE[]={
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4, 
      NOTE_D4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_E4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
      NOTE_E4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_G5, NOTE_A4, NOTE_FS5, NOTE_A4,
                      }
      
     int SLASHLEN[]={
       8, 8, 8, 8, 8, 8, 8, 8, 
       8, 8, 8, 8, 8, 8, 8, 8,
       8, 8, 8, 8, 8, 8, 8, 8,
       8, 8, 8, 8, 8, 8, 8, 8,
                    }
     for (int NoteN = 0; NoteN < 31; NoteN++){
       int NoteTTL = 491/SLASHLEN[NoteN]; //Adagio tempo
       toneAC(SLASHSCORE[NoteN], 10, NoteTTL, true); //play NoteN in background
       delay1 (NoteTTL *4/3.6); //Wait play note + 11% internote gap
  }
  while(2); //  Repeat, then halt.
  }
}


