#include <msp430.h>
#include <msp430_lib.h>

/**
 * Disable the watchdog entirely
 */
void watchdog_disable(void) {
	WDTCTL = WDTPW + WDTHOLD;
}

/**
 * Control some simple digital pin operations
 */
void digital_set_on(volatile unsigned char * pin, int bit) {
	*pin |= bit;
}

void digital_set_off(volatile unsigned char * pin, int bit) {
	*pin &= ~bit;
}

void digital_set_toggle(volatile unsigned char * pin, int bit) {
	*pin ^= bit;
}
