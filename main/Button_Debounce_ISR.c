#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <stdio.h>  // Include the standard I/O library for printf

#define DEBOUNCE_TIME_MS 50        // Debounce time in milliseconds
#define BUTTON1_GPIO GPIO_NUM_18   // GPIO for Button 1
#define BUTTON2_GPIO GPIO_NUM_19   // GPIO for Button 2

bool button1_pressed = false;
bool button2_pressed = false;

void IRAM_ATTR button_isr_handler(void* arg) {
    static uint32_t last_isr_time = 0;
    uint32_t current_time = xTaskGetTickCountFromISR() * portTICK_PERIOD_MS;

    if (current_time - last_isr_time > DEBOUNCE_TIME_MS) {
        if ((int)arg == BUTTON1_GPIO) {
            button1_pressed = true;
            printf("Button 1 flag set\n");  // Print statement for debugging
        } else if ((int)arg == BUTTON2_GPIO) {
            button2_pressed = true;
            printf("Button 2 flag set\n");  // Print statement for debugging
        }
        last_isr_time = current_time;
    }
}

void app_main() {
    // Configure button GPIOs
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_POSEDGE;             // Interrupt on rising edge (button press)
    io_conf.mode = GPIO_MODE_INPUT;                    // Set as input
    io_conf.pin_bit_mask = (1ULL << BUTTON1_GPIO) | (1ULL << BUTTON2_GPIO); // Select pins
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;           // Enable internal pull-up resistors
    gpio_config(&io_conf);

    // Install ISR service and attach handlers
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON1_GPIO, button_isr_handler, (void*)BUTTON1_GPIO);
    gpio_isr_handler_add(BUTTON2_GPIO, button_isr_handler, (void*)BUTTON2_GPIO);

    while (true) {
        if (button1_pressed) {
            ESP_LOGI("APP_MAIN", "Button 1 pressed!");
            button1_pressed = false;
        }
        if (button2_pressed) {
            ESP_LOGI("APP_MAIN", "Button 2 pressed!");
            button2_pressed = false;
        }
        vTaskDelay(pdMS_TO_TICKS(100));  // Delay to reduce CPU usage
    }
}

