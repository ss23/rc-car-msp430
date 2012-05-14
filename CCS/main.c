#include <stdbool.h>
#include <msp430.h>
#include <msp430_lib.h>

#define OPTO_SENSOR BIT4

int main(void) {
	watchdog_disable();

	digital_set_on(&P1DIR, LED_GREEN); // Set the green LED to be an output

	// Main loop. Will do this forever and ever
	unsigned int j, h;

	// Number of times that the status has changed from off/on -- volatile because the compiler would optimize it out otherwise
	// I should get a 7-segment display so that I can display the count :O
	volatile unsigned int count = 0;
	h = P1IN & OPTO_SENSOR;
	while (true) {
		j = P1IN & OPTO_SENSOR;

		// Check whether the status of j has changed since last time. We don't need to do anything if it hasn't
		if (h != j) {
			digital_set_toggle(&P1OUT, LED_GREEN);
			count++;
			h = j;
		}
	}
}
