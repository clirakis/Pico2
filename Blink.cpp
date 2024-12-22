#include <cstdio>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
/*
 * 21-Dec-24 CBL
 * using this website for help: https://www.hackster.io/whitney-knitter/raspbery-pi-pico-development-on-m2-mac-103609
 *
 * Dragged and dropped Blink.ul2 to the device, but it did not start to run.
 *
 */

int main()
{
  /**
   * This is a pico 2. According to the documentaiton the on board
   * LED is connected to WL_GPIO0  Not sure where this is defined
   */
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  
  /*
   * documentation: https://www.raspberrypi.com/documentation/pico-sdk/hardware.html#group_hardware_gpio
   *
   * gpio_init - Initialize GPI for (enabled I/O and set function to
   *     GPIO_FUNC-SIO)
   * Clear the output enable (i.e. set to intput) Clear any output value.
   *
   */
  gpio_init(LED_PIN);
  /*
   * Format: gpio_set_dir(unit_32_t mask)
   */
  gpio_set_dir(LED_PIN, GPIO_OUT);

  // Initialize serial USB...
    stdio_init_all();

  printf("Starting program now\n");

  for (uint i=0;i<10;i++)
    {
      /*
       * Format: gpio_put( uint gpio, bool value)
       */
      gpio_put(LED_PIN, 1);
      sleep_ms(500);
      gpio_put(LED_PIN, 0);
      sleep_ms(500);
      printf("Blink\n");
    }
   return 0;
}
