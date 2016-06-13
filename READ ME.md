#Overview -
Is a tradicional game called snake.  We control our snake by an accelerometer from STM32 Discovery board. 
#STM SNAKE CONSOLE
~~~~~~~~~~~~~~~~~~

#Description - 
This project consists of two main parts: STM32 project and Nokia 3310/5110 LCD For for displaying game.

#Tools - 
CooCox CoIDE 1.7.8.

#How to run -
1. Connection to Discovery board.

Connect LCD board with Discovery
LCD board	Discovery	Description
RST	PC15	Reset pin for LCD
CE	PC13	Chip enable for SPI2
DC	PC14	Data/Command pin
DIN	PC3	MOSI pin for SPI2
CLK	PB10	CLOCK pin for SPI2
VCC	3.3V	VCC Power
LIGHT	GND	If you connect this to GND, backlight is turned on
GND	GND	Ground

2. Download and open relase file in CoCox, compile program and send to STM. 

3. Yours game is ready to play.

#How to compile -
 Just download file from out github Project, compile this code with Coocox CoIDE and send it to STM.

#Attributions -
http://stm32f4-discovery.net/pcd8544-nokia-33105110-lcd-stm32f429discovery-library/

#License - 
MIT License

#Credits - 
Paulina Kurpisz, Michał Suchorzyński 

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.

Supervisor: Michał Fularz/Tomasz Mańkowski