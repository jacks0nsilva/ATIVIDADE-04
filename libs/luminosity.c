#include "luminosity.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>

uint16_t verify_luminosity(){
    adc_select_input(1);
    uint16_t adc_value = adc_read();
    printf("ADC Value: %d\n", adc_value);
    return adc_value;
    sleep_ms(100);
}