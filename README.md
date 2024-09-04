# ESP32-Button-Debounce-ISR
This project demonstrates how to handle button inputs with debouncing using Interrupt Service Routines (ISR) on the ESP32 Microcontroller, using Espressif-IDE. 

# Requirements
1) ESP32 Development Board (e.g., ESP32 DevKitC)

2) Two Push Buttons (normally open type)

3) Two Pull-Up Resistors (Optional, 10kΩ each if internal pull-up resistors are not used)

4) Breadboard 

5) Jumper Wires


# Circuit connections
1) Push Button 1:
One terminal of Button 1 to GPIO18 on the ESP32 (labeled as BUTTON1_GPIO in the code).
Other terminal of Button 1 to GND (Ground).

2) Push Button 2:
One terminal of Button 2 to GPIO19 on the ESP32 (labeled as BUTTON2_GPIO in the code).
Other terminal of Button 2 to GND.

3) Internal Pull-Up Resistors:

The code enables internal pull-up resistors for the GPIO pins (GPIO_PULLUP_ENABLE). Therefore, external pull-up resistors are not strictly necessary unless you prefer to use them.

![Circuit](https://github.com/user-attachments/assets/365d8430-ace8-4b0a-8ce1-95a312a03c8d)


# Code Explanation
1) The code configures GPIO18 and GPIO19 as input pins with internal pull-up resistors.

2) When a button is pressed, an interrupt is triggered on the rising edge (button press).

3) The interrupt service routine (ISR) checks if the button press is valid (debounced) and sets the corresponding flag (button1_pressed or button2_pressed).

4) In the app_main function, the code continuously checks if any button was pressed and logs the corresponding message.

# Output 
![image](https://github.com/user-attachments/assets/dab6eaaa-793c-42fc-8244-772167bde598)


# References
1) https://www.youtube.com/watch?v=fD7B9LI45Rk&t=155s
2) https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html
3) 

