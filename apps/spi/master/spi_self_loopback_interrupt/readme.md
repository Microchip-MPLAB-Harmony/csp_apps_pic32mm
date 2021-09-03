---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: SPI interrupt
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SPI interrupt

This example application demonstrates how to use the SPI peripheral to transmit and receive a block of data using interrupt.

## Description

This example shows the transmit and receive operation over a SPI interface in a non-blocking manner. The peripheral interrupt is used to manage the transfer.The example application transmits known values from an array and verifies the data received through the loop back by comparing the transmitted data and the received data. The example application performs the loop back test only once after a power on reset. After the loop back is complete, the status of the loop back is indicated and the application remains idle. The loop back test requires the MOSI output pin to be connected to the MISO input pin so that anything transmitted will also be received.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/spi/master/spi_self_loopback_interrupt/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32mm_usb_curiosity.X | MPLABX project for [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
| pic32mm_curiosity.X | MPLABX project for [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32mm_usb_curiosity.X | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
| pic32mm_curiosity.X | [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) |
|||

### Setting up [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)

- Use a jumper wire to short pin RD0 (SDO1) and pin RD4 (SDI1) of the J2 connector
- Connect micro USB cable to the 'USB1' connector on the board to the computer

### Setting up [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101)

- Use a jumper wire to short pin RB9 (SDO1) and pin RB14 (SDI1) of the J4 connector
- Connect micro USB cable to the 'USB1' connector on the board to the computer

## Running the Application

- Build and program the application using its IDE
- LED indicates the success or failure:
  - LED is turned ON when the when the value received matched with the transmitted value
  - LED is turned OFF when the when the value received did not match with the transmitted value

Following table provides LED names:

| Board      | LED Name |
| ---------- |--------- |
| [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) | LED1 |
| [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) | LED1 |
|||
