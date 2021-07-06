---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: RCON reset handler 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# RCON reset handler

This example shows how to use the RCON peripheral to indicate the cause of the device reset and clear the reset causes.

## Description

The Reset module combines all Reset sources and controls the device Master Reset signal, SYSRST. The Reset module allows the reset source to be identified and it clears the reset cause through software.

This example application uses the RCON peripheral to indicate the MCLR and the Watchdog reset. The WDT reset is emulated by not feeding the watchdog on switch press.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/rcon/reset_handler/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32mm_usb_curiosity.X | MPLABX project for [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32mm_usb_curiosity.X | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
|||

### Setting up [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)

- To run the demo, the following additional hardware are required:
  - [USB UART click board](https://www.mikroe.com/usb-uart-click)

- Connect micro USB cable to the 'USB1' connector on the board to the computer
- Install an [USB UART click board](https://www.mikroe.com/usb-uart-click) on to the mikroBUS socket J4
- Connect mini USB cable between PC and the [USB UART click board](https://www.mikroe.com/usb-uart-click)
  - *Note: Ensure that the series resistors on the mikroBUS headers are of value 0 Ohms*

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the "USB to UART" COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application project using its IDE
4. Following message is output on console:

    ![output_1](images/output_reset_handler_1.png)

5. Watch dog timer is fed periodically using Core Timer to prevent the WDT reset and the LED is toggled
    - Following table provides the switch and the LED name:

    | Board      | LED Name | Switch Name |
    | ---------- |--------- |--------- |
    | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) | LED1 | S3 |

6. Press the switch to put the system in deadlock
7. LED should stop blinking and the console should print the following message

    ![output_2](images/output_reset_handler_2.png)

8. The WDT will reset the device in four seconds and the demonstration should restart