#include "luminosity.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>

uint16_t verify_luminosity(){
    adc_select_input(1);
    uint16_t adc_value = adc_read();
    uint16_t luminosity = (adc_value * 100) / 4095; // Convertendo para porcentagem
    //printf("Luminosidade: %d%%\n", luminosity);
    return luminosity;
    sleep_ms(100);
}

void control_lights(uint16_t luminosity_value){
    if(luminosity_value < 30){
        gpio_put(12, 1);
    } else {
        gpio_put(12, 0);
    }
}