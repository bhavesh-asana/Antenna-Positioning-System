# Antenna Positioning System

# Table of Contents
1. [Overview](#abstract)
2. [Napkin Diagram](#block_diagram)
3. [Deployment](#deployment)
4. [Project Wiki](#wiki)
5. [Contributors](#contribution)

# Overview <a name="abstract"></a>
The idea is to develop an Internet of Things(IoT) based automated control system that is used to supervise the movement & an angle of a receiving antenna in all the possible directions. Here we use the NodeMCU and Arduino UNO micro-controllers to communicate across the sensors/actuators connected. It is a sensor-based system with a servo motor connected to a receving antenna to check its facing direction. Thus, the coordinates are sent to the end user over a secure communication channel.


 If the direction of a satellite or transmitting station changes over time, the antenna direction must also be changed accordingly. The receiving antennas may be placed far apart from each other across the globe. So our system allows for antenna positioning over very long distances. The antenna positions are visible over the internet to the controlling operator on the IoT GUI. We here use IOT Gecko to develop the antenna monitoring GUI system. Our system allows for monitoring antenna direction as well as transmitting new coordinates to position the antenna and the motor appropriately position the antenna accordingly.


# Napkin Diagram <a name="block_diagram"></a>
![Block Diagram](https://user-images.githubusercontent.com/62237873/172036256-357c8623-6599-4c1d-be56-0c23972c625e.png)


# Deployment <a name="deployment"></a>
1. Download and install <a href="https://www.arduino.cc/en/software">Arduino IDE</a>
2. Setup a workspace and clone the repository.
    ```bash
    $ git clone https://github.com/bhavesh-asana/Antenna-Positioning-System.git
    ```
3. Connect to NodeMCU and deploy the controller code.
    ```bash
    $ cd Codebase/Servo\ Motor
    $ open servo_motor.ino
    ```
    **Note:** Configure the WiFi SSID and Password before deploying the code into NodeMCU microcontroller.
4. Conenct to Arduino UNO-1 and deploy the RF reveiver code.
    ```bash
    $ cd Codebase/Receiver
    $ open receiver.ino
    ```
5. Connect to Arduino UNO-2 and deploy the RF transmitter code.
    ```bash
    $ cd Codebase/Transmitter
    $ open transmitter.ino
    ```
## Web Interface
1. On deploying the code into NodeMCU, open the serial monitor and set the baud rate to 15000.
2. Connect your desktop/laptop to the WiFi configured in the code. If ESP8266 is connected to the WiFi, it shows the successful connectionwith an IP address.
3. Copy the IP address and paste in a new window.
4. It shows a webpage with controlles.
## Mobile Interface

# Project Wiki <a name="wiki"></a>

# Contributors <a name="contribution"></a>
* Bhavesh Asanabada - Software Development
* Manoghnaa Reeddy Bobbala - Hardware Architecture
* Aravind Boyini - Resources & Maintenance

