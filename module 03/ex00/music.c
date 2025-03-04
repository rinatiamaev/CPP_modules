#include <windows.h>
#include <stdio.h>

// Define musical notes in Hz
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494
#define C5  523

// Function to play a note
void playNote(int frequency, int duration) {
    Beep(frequency, duration);
    Sleep(50); // Short pause between notes
}

int main() {
    printf("Playing Twinkle Twinkle Little Star...\n");

    // Twinkle Twinkle Little Star melody
    int melody[] = {
        C4, C4, G4, G4, A4, A4, G4, 
        F4, F4, E4, E4, D4, D4, C4,
        G4, G4, F4, F4, E4, E4, D4,
        G4, G4, F4, F4, E4, E4, D4,
        C4, C4, G4, G4, A4, A4, G4, 
        F4, F4, E4, E4, D4, D4, C4
    };

    int noteDurations[] = {
        400, 400, 400, 400, 400, 400, 800,
        400, 400, 400, 400, 400, 400, 800,
        400, 400, 400, 400, 400, 400, 800,
        400, 400, 400, 400, 400, 400, 800,
        400, 400, 400, 400, 400, 400, 800,
        400, 400, 400, 400, 400, 400, 800
    };

    // Play melody
    int size = sizeof(melody) / sizeof(melody[0]);
    for (int i = 0; i < size; i++) {
        playNote(melody[i], noteDurations[i]);
    }

    printf("Done!\n");
    return 0;
}
