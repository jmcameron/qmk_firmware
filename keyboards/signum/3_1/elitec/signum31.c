#include "signum31.h"

void matrix_init_kb(void) 
{
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();

// ???     setPinOutput(RED_LED);
// ???     setPinOutput(BLUE_LED);
// ???     setPinOutput(GREEN_LED);
// ???     setPinOutput(ORANGE_LED);
}



// ??? void turn_off_leds(void)
// ??? {
// ???     writePinLow(RED_LED);
// ???     writePinLow(BLUE_LED);
// ???     writePinLow(GREEN_LED);
// ???     writePinLow(ORANGE_LED);
// ??? }
// ??? 
// ??? void turn_on_led(pin_t pin)
// ??? {
// ???     writePinHigh(pin);
// ??? }
// ??? 
// ??? void led_set_user(uint8_t usb_led) {
// ???     if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
// ???         writePinHigh(ORANGE_LED);
// ???     } else {
// ???         writePinLow(ORANGE_LED);
// ???     }
// ??? }
