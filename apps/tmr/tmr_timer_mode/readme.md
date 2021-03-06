---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: TMR periodic interrupt
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TMR periodic interrupt

This example demonstrates how to use the TMR module in timer mode to generate periodic interrupt.

## Description

The TMR module generates periodic interrupt on 1 second period match. The LED is toggled in the interrupt handler to indicate periodic callback. Two TMR modules are used to form a 32-bit timer.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/tmr/tmr_timer_mode/firmware** .

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

- Connect micro USB cable to the 'USB1' connector on the board to the computer

## Running the Application

1. Build and program the application project using its IDE
2. On successful execution, LED starts blinking

Following table provides the LED names:

| Board      | LED Name |
| ---------- |--------- |
| [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) | LED1 |
|||
