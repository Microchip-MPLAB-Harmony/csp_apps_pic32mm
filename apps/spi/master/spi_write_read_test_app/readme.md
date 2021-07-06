---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: SPI Master read write test application 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# SPI Master read write test application

This is a SPI Master test application which is provided to demonstrate communication between SPI master and the corresponding SPI slave application available under -  apps/spi/slave/spi_write_read/firmware

## Description

This example uses the SPI peripheral library in master mode and serves as a test application to demonstrate communication between SPI master and corresponding SPI slave application available at apps/spi/slave/spi_write_read/firmware.

The SPI master writes data by sending a write command followed by two bytes of memory address followed by the data to be written.

< WR_CMD > < ADDR_MSB > < ADDR_LSB > < DATA0 > ... < DATA n >

The SPI slave asserts the Busy line to indicate to the SPI master that it is busy. Once ready, the SPI slave de-asserts the Busy line. Once the SPI slave is ready, the SPI master reads the data by sending read command followed by two bytes of memory address and the number of bytes to read.

< RD_CMD > < ADDR_MSB > < ADDR_LSB > < NUM_BYTES >

The SPI slave responds by sending the data at the requested memory address. The SPI master compares the sent data with the received data and repeats the test if it matches.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/spi/master/spi_write_read_test_app/firmware** .

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

- To run this demo two [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) are required. One will be progammed as SPI master and other will be programmed as SPI slave.
- Connect Pin 3, 4, 5, 6 of mikroBus header J12 on SPI master to Pin 3, 4, 6, 5 respectively of mikroBus header J12 on SPI slave
    - Pin 3 - SPI Chip Select
    - Pin 4 - SCK
    - Pin 5 - SDI
    - Pin 6 - SDO
- Connect Pin 16 of mikroBus header J12 on SPI master to Pin 16 of mikroBus header J12 on SPI slave. Pin 16 (RB0) is configured as GPIO and serves as the slave busy pin.
- Connect mini USB cable to the 'USB1' connector on the board to the computer
- *Note: Ensure that the series resistors on the mikroBUS headers are of value 0 Ohms*

### Setting up [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101)

- To run this demo two [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) are required. One will be progammed as SPI master and other will be programmed as SPI slave.
- Connect Pin 3, 4, 5, 6 of mikroBus header J4 on SPI master to Pin 3, 4, 6, 5 respectively of mikroBus header J4 on SPI slave
    - Pin 3 - SPI Chip Select
    - Pin 4 - SCK
    - Pin 5 - SDI
    - Pin 6 - SDO
- Connect Pin 16 of mikroBus header J4 on SPI master to Pin 16 of mikroBus header J4 on SPI slave. Pin 16 (RB15) is configured as GPIO and serves as the slave busy pin.
- Connect mini USB cable to the 'USB1' connector on the board to the computer
- *Note: Ensure that the series resistors on the mikroBUS headers are of value 0 Ohms*

## Running the Application

1. Build and Program the SPI master application project using its IDE
2. Build and Program the SPI slave application project using its IDE. Path of the SPI Slave application within the repository is **apps/spi/slave/spi_write_read/firmware** 
3. On the SPI master board, press switch to start reading and writing data
2. LED on SPI master board indicates the success or failure:
    - LED is turned ON when the data read from the SPI slave matches with the data written
    - LED is turned OFF when the data read from the SPI slave does not match with the data written

Following table provides the Switch and LED name:

| Board      | Switch Name | LED Name |
| ---------- |--------- |--------- |
| [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) | S3 | LED1 |
| [PIC32MM Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) | S2 | LED1 |
|||
