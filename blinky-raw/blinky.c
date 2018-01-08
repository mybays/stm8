#include "stm8l.h"

int main() {
	int d;
	// Configure pins
	PD_DDR = 0x08;
	PD_CR1 = 0x08;
	// Loop
	do {
		PD_ODR ^= 0x08;
		for(d = 0; d < 29000; d++) { }
	} while(1);
}
