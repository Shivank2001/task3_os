#include <stdio.h>
#include "sdkconfig.h"
#include "esp_chip_info.h"
#include "esp_spi_flash.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


#define LED_PIN2 2

static const char *TAG = "Hello World";

void led_blink2(void *pvParams) {
    gpio_pad_select_gpio(LED_PIN2);
    gpio_set_direction (LED_PIN2,GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LED_PIN2,0);
        vTaskDelay(500/portTICK_RATE_MS);
        gpio_set_level(LED_PIN2,1);
        vTaskDelay(500/portTICK_RATE_MS);
	printf("Task2 is running on Core %d\n", xPortGetCoreID());
    }
}

void hello_world(void *pvParams) {
    printf("Hello world! on Core %d\n",xPortGetCoreID());


    for (int i = 10; i >= 0; i--) {
       // printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
 //   printf("Restarting now.\n");
 //   fflush(stdout);
 //   esp_restart();

    
}
