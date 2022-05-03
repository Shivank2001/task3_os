#include "core0.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"

void app_main(void *pvParams)
{
    
    xTaskCreatePinnedToCore(&led_blink2, "LED_BLINK2", 10000,NULL,1,NULL,0);
    xTaskCreatePinnedToCore(&hello_world,"hello_world",10000,NULL,1,NULL,1);

}