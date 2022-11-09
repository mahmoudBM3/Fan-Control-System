#include"dc_motor.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"adc.h"
#include<util/delay.h>
int main() {

	uint8 fanspeed;
	DCMOTOR_init();
	LCD_init();
	ADC_init(&g_adcconfig);
	uint8 temp;
	LCD_clearScreen();
	LCD_moveCursor(0, 5);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1, 5);
	LCD_displayString("TEMP IS ");
	while (1) {

		temp = LM35_getTemperature();
		if (temp < 30) {
			fanspeed = 0;
		} else if (temp < 60) {
			fanspeed = 25;
		} else if (temp < 90) {
			fanspeed = 50;
		} else if (temp < 120) {
			fanspeed = 75;
		} else {
			fanspeed = 100;
		}
		LCD_moveCursor(0, 12);
		LCD_integerToString(fanspeed);
		LCD_displayString("  ");
		LCD_moveCursor(1, 13);
		LCD_integerToString(temp);
		LCD_displayString("  ");
		LCD_moveCursor(0, 0);
		DCMOTOR_rotate(CLOCKWISE, fanspeed);

	}

}
