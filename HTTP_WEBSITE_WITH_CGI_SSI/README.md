# HTTP Server with SSI and CGI feature
We can create dynamic website by using Raspberry Pi Pico W Microcontroller with using official PICO SDK API with lwIP library.
Server Side Include is a feature of web server which can impertate with own programming language code into website, manipluating by server device side. 
For example, server can send data into client's device if SSI feature is enabled. 

Common gateway inferface is a feature of web server which client can maniplulate server/external programm by using website.
For example, client can control coloer of LEDs by webiste, changing client's favorite color of LED which he/she decides to change what color. 

# Prerequisite
* **Raspberry Pico W**
* **Wireless router with support 2.4GHz 802.11n WIFI**
* **Installed PICO C SDK, cmake and visual studio code** (In PICO SDK will install automatically visual studio code IDE, cmake and other essential softwares)
* **Micro USB cable (which we can connect into laptop)**

# Our home page website screenshot
Go to our Raspberry Pico W server IP address. Router will assign IP address automatically. You can look this device IP address by receiving data UART port. 

![image](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/da620cae-e234-46ee-b71e-5feace4dce72)

Screen of our home page from my personal website

# Gallery

![20230506_172646](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/5c0690d8-b0ac-41da-bd28-9b78375bac52)

My circuit built in breadboard. 

![20230506_172618](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/b6871456-f0e4-4a8f-b1bf-9b6f51f4118d)

My TP-Link TL-WR840N 300 Mbps Wireless router, which we used as DHCP server for this project 

![20230506_172734](https://github.com/misha-dig/http_server_by_pico_w/assets/55639759/5bc4c58b-79ae-4505-8927-8c0f3fb46d35)

My laptop for checking network status of our web server and wireless router. 
