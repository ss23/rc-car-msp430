#ifndef MSP430_LIB_H_
#define MSP430_LIB_H_

	#define LED_GREEN BIT6
	#define LED_RED   BIT0

	void watchdog_disable(void);

	void digital_set_on(volatile unsigned char *, int);
	void digital_set_off(volatile unsigned char *, int);
	void digital_set_toggle(volatile unsigned char *, int);

#endif /* MSP430_LIB_H_ */
