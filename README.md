<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->


<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Arduino Sensor Network</h3>

  <p align="center">
    A comprehensive tutorial on developing Arduino network using RF 433MHz and GSM Module
    <br />
    <a href="https://github.com/Ammarsyaf3035/Arduino-Network"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Ammarsyaf3035/Arduino-Network">View Demo</a>
    ·
    <a href="https://github.com/Ammarsyaf3035/Arduino-Network/issues">Report Bug</a>
    ·
    <a href="https://github.com/Ammarsyaf3035/Arduino-Network/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
This project guide how to build an IoT system using Arduino wireless sensor network. This system made up of a gateway and single or multiple sensor nodes that are connected to a gateway to forming a sensor nodes network. There are a multitude number of sensor nodes that can be added to the system making it highly scalable. Different types of sensor can be used for numerous applications such as monitoring room temperature and humidity, gathering a house power meter reading, and etcetera. The sensor nodes are connected to a single gateway that is a function to collect and transport the data from nodes to the internet. It is connected wirelessly using an RF 433MHz module, thus eliminating the use of wire making installation easy without messy wire.

![Product Name Screen Shot][Framework-screenshot]

The diagram shows multiple sensor nodes connected to a gateway wirelessly using RF 433MHz communication module. The gateway collect the data from the nodes and transport it to online database via the Internet. The data is then visualize using ThingsSentral Application Web Dashboard.

Project difficulty:
**Grandmaster, it involves several skills:**
`Electronics`, `Advanced Arduino Programming Knowledge`, `Exceptional Soldering Skill`, `GSM Protocol`, `Radio Frequency`, `Basic Multimeter Knowledge`


### Built With

* [Arduino](https://www.arduino.cc/)
* [ThinsSentral Dashboard](http://thingssentral.io:443/)



<!-- GETTING STARTED -->
## Getting Started

There are three section 

### 1. Gateway

[![Gateway Screen Shot][Gateway-screenshot]](https://tinyurl.com/y7dxtdnn)
(Click this picture to simulate in falstad circuit simulator)

The gateway have three building block that is Arduino block, HC-12 RF 433 MHz block, and GSM SIM800L block. 

Material required
1. [Arduino Nano (UNO can be used)](https://my.cytron.io/p-uno-compatible-ch340-with-usb-cable?search=uno&description=1)
2. [Proto shield](https://my.cytron.io/p-cytron-prototyping-shield?search=proto&description=1)
3. [Logic shifter (5V and 3.3V)](https://shopee.com.my/Logic-Converter-4-Channel-Bi-Directional-5V-3.3V-Level-Shifter-Module-i.13050358.1897892238)
4. [HC-12 RF433MHz Module](https://my.cytron.io/c-wireless-devices/p-433mhz-rf-uart-transceiver-module-1km)
5. [GSM SIM800L Module](https://shopee.com.my/Arduino-SIM800L-GPRS-GSM-Tracking-Module-with-Antena-SIM-Slot-i.33287405.462065175)
6. [9V Power Supply](https://shopee.com.my/AC-DC-Adapter-9V-1A-Power-Supply-Arduino-PIC-i.13050358.1696099696)
7. [PNP MOSFET IRF4905](https://my.cytron.io/p-transistor-irf4905?search=IRF4905&description=1&sub_category=true)
8. [BJT NPN 2N2222](https://my.cytron.io/p-transistor-2n2222?search=2N2222&description=1)
9. [LDO 3.3V LM1117](https://my.cytron.io/p-voltage-regulator-plus-3.3v-1880?search=3.3&description=1)
10. [LDO Adjustable LM317](https://my.cytron.io/p-ic-lm317?search=lm317&description=1)
11. 100nF, 1µF, 10µF, 100µF,and 2200µF Capacitors
12. 2x 1kOhm, 240Ohm,and 560Ohm Resistors
13. 2x Switches

### 2. Sensor Node (I2C Sensor)

[![Sensor Node Screen Shot][sensorNode-screenshot]](https://tinyurl.com/ybxluhys)
(Click this picture to simulate in falstad circuit simulator)

The sensor node have two building block which are Arduino, and HC-12 with sensor.

Material required
1. [Arduino Nano (UNO can be used)](https://my.cytron.io/p-uno-compatible-ch340-with-usb-cable?search=uno&description=1)
2. [Proto shield](https://my.cytron.io/p-cytron-prototyping-shield?search=proto&description=1)
3. [Logic shifter (5V and 3.3V)](https://shopee.com.my/Logic-Converter-4-Channel-Bi-Directional-5V-3.3V-Level-Shifter-Module-i.13050358.1897892238)
4. [HC-12 RF433MHz Module](https://my.cytron.io/c-wireless-devices/p-433mhz-rf-uart-transceiver-module-1km)
5. [9V Power Supply](https://shopee.com.my/AC-DC-Adapter-9V-1A-Power-Supply-Arduino-PIC-i.13050358.1696099696)
6. [LDO 3.3V LM1117](https://my.cytron.io/p-voltage-regulator-plus-3.3v-1880?search=3.3&description=1)
7. 10µF, 100µF, and 2200µF Capacitors
8. 2x switches

### 3. Setup ThingsSentral Account

Before we were able to transport the nodes data to the Internet, we must first set up our account in the ThingsSentral Application to get the sensor ID. This ID is required as the address to which portfolio the data is going to be visualized. In this guide, we will create a project to monitor our room temperature and humidity.

1. Register account [here](http://thingssentral.io:443/).
   * Fill the information required and click `Sign Up`.
   
![TS Register Screen Shot][registerAccount-screenshot]

2. Create your first project.
   * First, click the setting symbol located at top right of the page as indicated by the orange arrow.
   * Click `Project Settings`
   * When the Project Settings page is shown as in the picture below, click `Add New` located at bottom left of the page.
   * At New Project Name field, We will name our project with `Room monitoring`.
   * Click `Save`.

![TS Project Screen Shot][projectSetting-screenshot]

3. Setting up project location.
   * Click `Location Settings` under setting menu.
   * Select `Room monitoring` from Project ID menu located near top left of the page.
   * Click `Add New` and fill `My room` at New Location Setting field.
   * Click `Save`.

![TS Location Screen Shot][locationSetting-screenshot]

### 4. Gateway Programming 

After successful account registration, we will get the sensor ID after we added a project as shown in the steps above, before proceeding with coding the gateway and the nodes. we first will look into how to program the Arduino gateway. First, we have to look into a flow chart on how the code sequence works as any complicated system is best to visualize by using a diagram.

[![Gateway Flowchart Screen Shot][gsmMain-screenshot]](https://lucid.app/lucidchart/invitations/accept/inv_973f9c34-742d-4b43-ab90-21d9fb602df3)


<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Ammarsyaf3035/Arduino-Network/issues) for a list of proposed features (and known issues).

## References
1. Github 
   * [Github Readme Guide](https://docs.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax)
2. GSM
   * [GSM Protocol Guide](https://www.tutorialspoint.com/gsm/gsm_protocol_stack.htm)
   * [Using SIM800L with Arduino Tutorial](https://lastminuteengineers.com/sim800l-gsm-module-arduino-tutorial/)
3. Electronics
   * [Isolated Driver](https://www.bristolwatch.com/ele/opto_isolated.htm)
   * [MOSFET BJT tured driver](https://www.youtube.com/watch?v=fex79DvbZvg&ab_channel=LewisLoflin)
   

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the Apache 2.0 License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Ammar Syafiq Sabaahul Ahmad - [@twitter_handle](https://twitter.com/twitter_handle) - a.sabahul@gmail.com

Project Link: [https://github.com/Ammarsyaf3035/Arduino-Network](https://github.com/Ammarsyaf3035/Arduino-Network)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* []()
* []()
* []()





<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Ammarsyaf3035/Arduino-Network.svg?style=for-the-badge
[contributors-url]: https://github.com/Ammarsyaf3035/Arduino-Network/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Ammarsyaf3035/Arduino-Network.svg?style=for-the-badge
[forks-url]: https://github.com/Ammarsyaf3035/Arduino-Network/network/members
[stars-shield]: https://img.shields.io/github/stars/Ammarsyaf3035/Arduino-Network.svg?style=for-the-badge
[stars-url]: https://github.com/Ammarsyaf3035/Arduino-Network/stargazers
[issues-shield]: https://img.shields.io/github/issues/Ammarsyaf3035/Arduino-Network.svg?style=for-the-badge
[issues-url]: https://github.com/Ammarsyaf3035/Arduino-Network/issues
[license-shield]: https://img.shields.io/github/license/Ammarsyaf3035/Arduino-Network.svg?style=for-the-badge
[license-url]: https://github.com/Ammarsyaf3035/Arduino-Network/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/ammar-syafiq-sabaahul-ahmad-042ba9156/
[Framework-screenshot]: images/Framework.PNG
[Gateway-screenshot]: images/Gateway.PNG
[sensorNode-screenshot]: images/sensorNode.PNG
[gsmMain-screenshot]: images/gsmMain.png
[registerAccount-screenshot]: images/ThingSentralAccount/registerAccount.PNG
[projectSetting-screenshot]: images/ThingSentralAccount/projectSetting.png
[locationSetting-screenshot]: images/ThingSentralAccount/locationSetting.png
