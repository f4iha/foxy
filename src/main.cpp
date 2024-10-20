#include "si5351.h"
#include "Wire.h"
#include <int.h>

Si5351 si5351;

uint64_t freq = 14445000000ULL; // 10 MHz, in hundredths of hertz

// Transmit multiple pulse
void transmit(uint8_t number)
{
    Serial.print("transmit()...");
    digitalWrite(LED_BUILTIN, HIGH);
    si5351.set_clock_pwr(SI5351_CLK0, 1);
    // Reset the tone to 0 and turn on the output
    for (uint8_t i = 0; i < number; i++) {
        si5351.output_enable(SI5351_CLK0, 1);
        delay(500);  
        si5351.output_enable(SI5351_CLK0, 0);
    }
    si5351.set_clock_pwr(SI5351_CLK0, 0);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("end transmit()");
    // Turn off the output
    
}

void setup()
{
   Serial.begin(9600);
   Serial.println("setup");
   pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the Si5351
  si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  si5351.set_correction(68000, SI5351_PLL_INPUT_XO);
  si5351.set_pll(SI5351_PLL_FIXED, SI5351_PLLA);
  // Set CLK0 output
  si5351.set_freq(freq, SI5351_CLK0);
  si5351.drive_strength(SI5351_CLK0, SI5351_DRIVE_8MA); // Set for max power
  si5351.set_clock_pwr(SI5351_CLK0, 0); // Disable the clock initially
}


void loop()
{
    transmit(10);
    delay(5000);
}