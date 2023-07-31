## Project based on STM32F103C6 board with Cortex-M3

![board](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/fe458987-fb75-4b9c-b3d0-aa1bf6b3eb66)

## Google Drive 
### [Drive](https://drive.google.com/drive/folders/1LREqTt6J65qApYwFduNNfKyRYkOskptk?usp=sharing)

## The main objective of this project is to start an alarm when the pressure value is over a specific limit for 60 seconds.
![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/3eaab796-1d03-420b-9bea-f8039e234261)

### This Project Was Completed by Writing The Following:

- My Own main.c file.
- States files for every stage (pressureSensor, pressureController, alarmMonitor and alarmActuator).
- startup.c and linker_script.ld
- makefile for automation.
- simulation using proteus.

### The Tools Which is used in developing this project:
1. TTool ( for System Architecture).
2. Visual Studio Code.
3. ARM Cross Toolchain.
4. Proteus.
5. Terminal.
6. Git & Github.

## Commands Used Developing The Project:
```
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  alarmActuator.c -o alarmActuator.o
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  alarmMonitor.c -o alarmMonitor.o
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  driver.c -o driver.o
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  main.c -o main.o
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  pressureController.c -o pressureController.o
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -gdwarf-2 -c -I .  pressureSensor.c -o pressureSensor.o
arm-none-eabi-as -mcpu=cortex-m3 -mthumb -gdwarf-2 startup.s -o startup.o
arm-none-eabi-ld -T linker_script.ld  alarmActuator.o alarmMonitor.o driver.o main.o pressureController.o pressureSensor.o startup.o -o pressureController.elf -Map=map_file
arm-none-eabi-objcopy -O binary pressureController.elf pressureController.bin
```

### Note:
#### To run this project you install the source code and the tools I have mentioned and open the directory of the project in terminal and just hit make.


**There is also map_file with all the project symbols and sections of memory.**

![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/473c219f-59a2-4e9a-955e-7098775ab279)

**I provided a folder for all the files symbols and also the executable symbols resolved.**

![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/bd8a8b3b-9211-4634-a125-a90771697494)

## System Design:
![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/6d924e71-0f3e-42cb-9eb2-06235aad8451)

### Simulation Tree:
![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/7534a4cc-8a66-4551-9900-975386bb58d6)


### Working Code With The Board Simulator:

https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/91e0e9ec-275a-4bd1-b16e-b99aaa7789c4







