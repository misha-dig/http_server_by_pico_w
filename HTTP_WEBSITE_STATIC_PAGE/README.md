# HTTP Server with static page

A web server that retrieve web static page by using html and other media files. 
Each web page won't change and update datas in realtime.

# Prerequisite
* **Raspberry Pico W**
* **Wireless router with support 2.4GHz 802.11n WIFI**
* **Installed PICO C SDK, cmake and visual studio code** (In PICO SDK will install automatically visual studio code IDE, cmake and other essential softwares)
* **Micro USB cable (which we can connect into laptop)**

# Where I tested this code
I used Linux Mint 21.1 x86_64 in virtual machine, so you can use any linux OS debian based.

# Our home page website screenshot
Go to our Raspberry Pico W server IP address. Router will assign IP address automatically. You can look this device IP address by receiving data UART port. 

![image](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/5d922448-3d6c-4720-a683-c99c905a43e0)

Screen of our home page from my personal website

# Gallery

![photo_2023-05-10_04-15-18](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/635d8341-140d-4c6e-9e0b-02e3dd1fab79)

My homepage of website opened in my laptop and my Raspberry Pi Pico W

![image](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/12fb2d21-ffbd-49e2-b617-5d0eac786374)

My TP-Link TL-WR840N 300 Mbps Wireless router, which we used as DHCP server for this project 

# List essential file

```CMakeLists.txt``` - a file that able build via cmake tool

```build.sh``` - a file build source of code

```makefs.sh``` - a file generating own_fsdata.c code file with array of http request

```makefsdata``` - a tool perl script from lwIP library tool (which I download this file form lwIP official repository plus I corrected mistake makefsdata that missing supporting file shtml for http requesting server)

```own_fsdata.c``` - a generated file of array of http request code by script makefs.sh

```fs``` - directory that html and other media files will retrieve in website (Make fsdata.c via makefsdata perl script)

Note: All scripts you can read my comments to explain need to do that the project can work properly (Don't care in makefsdata , own_fsdata.c unless you have experience work with tools and software)

# How to build my source code
## Installation and configuration of my website server (Without change file in fs directory)

1. Open ```build.sh``` bash script in any text editor. Please read this script carefully (the comment will aid to you)

2. Change enviroment into your directory pico-sdk path in PICO_SDK_PATH enviroment

from section ```export PICO_SDK_PATH=/home/linuxpc/pico/pico-sdk``` into ```export PICO_SDK_PATH=/example/pico-sdk``` (This change directory path is showed example in enviroment command)

3. Change your WIFI setting connect. 

from section ```cmake -DPICO_BOARD=pico_w -DWIFI_SSID="WIFI_EXAMPLE" -DWIFI_PASSWORD="PASSWORD_EXAMPLE" ..``` into cmake ```-DPICO_BOARD=pico_w -DWIFI_SSID="TP-LINK" -DWIFI_PASSWORD="1234567890_EA" ..``` (This change WIFI password is illustrative example)

4. Set file premission of build.sh by invoking command in linux ternimal with specific path ```sudo chmod -R 777 build.sh``` (Your root password will ask)

5. Invoke our script by ```./build.sh``` 

6. Check your code error in terminal

7. Flash into Raspberry Pico W via USB inferface

8. Open any serial port terminal  (I prefer to use Putty software for beginners or read documentation and getting started Raspberry Pi Pico W / without W)

9. Connect your PICO W into 5V power via USB port

10. Open website with specific IP adress, which IP adress receive in serial port terminal.

11. Enjoy my website!!! :)


## Installation and configuration of my website server (WITH change file in fs directory)

1. Save your html and other media files in ```fs``` directory

2. Run a script ```./makefs.sh```, but you need to grant file premission in first time usage after downloaded this repository by invoking command ```sudo chmod -R 777 makefs.sh``` 

3. Open ```build.sh``` bash script in any text editor. Please read this script carefully (the comment will aid to you)

4. Change enviroment into your directory pico-sdk path in PICO_SDK_PATH enviroment

from section ```export PICO_SDK_PATH=/home/linuxpc/pico/pico-sdk``` into ```export PICO_SDK_PATH=/example/pico-sdk``` (This change directory path is showed example in enviroment command)

5. Change your WIFI setting connect. 

from section ```cmake -DPICO_BOARD=pico_w -DWIFI_SSID="WIFI_EXAMPLE" -DWIFI_PASSWORD="PASSWORD_EXAMPLE" ..``` into cmake ```-DPICO_BOARD=pico_w -DWIFI_SSID="TP-LINK" -DWIFI_PASSWORD="1234567890_EA" ..``` (This change WIFI password is illustrative example)

6. Set file premission of build.sh by invoking command in linux ternimal with specific path ```sudo chmod -R 777 build.sh``` (Your root password will ask)

7. Invoke our script by ```./build.sh``` 

8. Check your code error in terminal

9. Flash into Raspberry Pico W via USB inferface

10. Open any serial port terminal  (I prefer to use Putty software for beginners or read documentation and getting started Raspberry Pi Pico W / without W)

11. Connect your PICO W into 5V power via USB port

12. Open website with specific IP adress, which IP adress receive in serial port terminal.

13. Enjoy your customized website!!! :)

# Credit and authors which I used code for this projects

LearnEmbeddedSystems. (2023, April). pico-w-webserver-template. LearnEmbeddedSystems. Github. https://github.com/LearnEmbeddedSystems/pico-w-webserver-template (Tutorial + using portion of code example)

Krzysiek. (2022, August 15th). Creating a web server on Raspberry Pi Pico W using Pico SDK and lwIP. krzmaz's blog. https://krzmaz.com/2022-08-15-creating-a-web-server-on-raspberry-pi-pico-w-using-pico-sdk-and-lwip/ (Tutorial + using portion of code example)

Savannah. Lightweight IP stack. nongnu.org. https://www.nongnu.org/lwip/2_1_x/index.html (Documentation and instruction lwIP library)

Raspberry Pi Ltd. Connecting to the Internet with Raspberry Pi Pico W. Raspberry Pi. https://datasheets.raspberrypi.com/picow/connecting-to-the-internet-with-pico-w.pdf (Documentation and instruction how install PICO-SDK tools for Raspberry PI Pico board coding development, including show how to use template for each new project)

Raspberry Pi Ltd. Raspberry Pi Pico SDK Examples. GitHub. https://github.com/raspberrypi/pico-examples (We used some built-in example in own code for understanding how works GPIO, ADC, Timer for RP2040 MCU).

lwIP Developers. lwip. GitHub. https://github.com/lwip-tcpip/lwip (A repository lwIP code. I can download only makefsdata perl script for this project)

Any sources code you can look copyright of holder by clicking links above. 

Many thanks of all authors of opensource coding. :)

# Useful resource

https://datasheets.raspberrypi.com/picow/connecting-to-the-internet-with-pico-w.pdf (Installation PICO C SDK for development with Raspberry PI Pico W)

https://datasheets.raspberrypi.com/picow/pico-w-datasheet.pdf (Datasheet of Raspberry PI Pico W Board)

https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf (Documentation of PICO C SDK)

https://www.nongnu.org/lwip/2_1_x/index.html (Documentation and instruction lwIP library)

https://github.com/lwip-tcpip/lwip (For downloading only makefsdata perl script for this project)

https://www.raspberrypi.com/documentation/microcontrollers/ (Finding any important information about Raspberry Pico W)

# Errata makefsdata script (Important information)

 When I download makefsdata perl script for generating fsdata.c file-code in lwIP HTTP requesting from lwIP repository. (Links: https://github.com/lwip-tcpip/lwip)
 
 When I run this code with SSI feature (which need file extension .shtml) and I open our SSI web page as result show plain text in browsers instead shtml rendering. 
 
 I found solution of this errat by forum website: https://stackoverflow.com/questions/70468042/stm32-lwip-shtml-page-not-rendering-source-code-displayed-instead 
 
 I added parts string of perl script makefsdata, which makefsdata script was missed generating for .shtml extension when http request receiving
 
 ```elsif($file =~ /\.shtml$/) {```
 
 ```print(HEADER "Content-type: text/html shtml\r\n");```
 
 ```}```
    
 You can look orignal script by links: https://github.com/lwip-tcpip/lwip/blob/master/src/apps/http/makefsdata/makefsdata
 
 So, you don't panic that SSI doesn't work in your website and use own makefsdata to generate fsdata.c 
 
 But this part of project (static http server), you don't need to use .shtml file extension unless enabling SSI feature. 
 
 # Thanks
 Thanks you for projecting!!! Enjoy to use this project
