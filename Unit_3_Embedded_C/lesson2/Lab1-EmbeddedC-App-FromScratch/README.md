## Embedded C App To Send String To UART (versatilepb board with arm962ej-s processor)

### [Google Drive](https://drive.google.com/drive/folders/1azA8ii2c4cIe-YZ39sjIvAcVl8w14RWz?usp=sharing)

### Commands That Are Used In This App

#### Compile C Code Within App.c

```
arm-none-eabi-gcc -C -mcpu=arm926ej-s -I app.c -o app.o
```

#### Compile C Code Within uart.c

```
arm-none-eabi-gcc -C -mcpu=arm926ej-s -I uart.c -o uart.o
```

#### Disassemble app.o Sections

```
arm-none-eabi-objdumb -h app.o
```

#### Disassemble app.o

```
arm-none-eabi-objdumb -D app.o
```

#### Assembling startup.s file

```
arm-none-eabi-as -mcpu=arm926ej-s startup.s -o startup.o
```

#### Linking linker_script.ld file with app file and get executable.elf file

```
arm-none-eabi-ld -T linker_script.ld app.o uart.o startup.o -o executable.elf
```

#### Disassemble executable.elf sections

```
arm-none-eabi-objdump -h executable.elf
```

#### Resolving executable.elf Symbols

```
arm-none-eabi-nm executable.elf
```

#### Getting the binary executable from executable.elf file

```
arm-none-eabi-objcopy -O binary executable.elf executable.bin
```

#### Running The Binary File On Board Versatilepb Using Qemu Emulator

```
qemu-system-arm -M versatilepb -m 128M -nographic -kernel executable.bin
```
