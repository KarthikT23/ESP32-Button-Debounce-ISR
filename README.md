# ESP32-Button-Debounce-ISR
This project demonstrates how to handle button inputs with debouncing using Interrupt Service Routines (ISR) on the ESP32 Microcontroller, using Espressif-IDE.
# Requirements
1) ESP32 Development Board (e.g., ESP32 DevKitC)

2) Two Push Buttons (normally open type)

3) Two Pull-Up Resistors (Optional, 10kΩ each if internal pull-up resistors are not used)

4) Breadboard
 
5) Jumper Wires

# Circuit Connections
a) Push Button 1:
One terminal of Button 1 to GPIO18 on the ESP32 (labeled as BUTTON1_GPIO in the code).
Other terminal of Button 1 to GND (Ground).

b) Push Button 2:
One terminal of Button 2 to GPIO19 on the ESP32 (labeled as BUTTON2_GPIO in the code).
Other terminal of Button 2 to GND.

c) Internal Pull-Up Resistors:
The code enables internal pull-up resistors for the GPIO pins (GPIO_PULLUP_ENABLE). Therefore, external pull-up resistors are not strictly necessary unless you prefer to use them.


![Circuit](https://github.com/user-attachments/assets/b4ca65f1-acdd-4334-bcd7-2512483aa6e1)



# Code explanation
A) The code configures GPIO18 and GPIO19 as input pins with internal pull-up resistors.

B) When a button is pressed, an interrupt is triggered on the rising edge (button press).

C) The interrupt service routine (ISR) checks if the button press is valid (debounced) and sets the corresponding flag (button1_pressed or button2_pressed).

D) In the app_main function, the code continuously checks if any button was pressed and logs the corresponding message.



# References
1) https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html
2) https://www.youtube.com/watch?v=fD7B9LI45Rk&t=155s
