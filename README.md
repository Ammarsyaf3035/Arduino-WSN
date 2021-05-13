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

[![Gateway Screen Shot][Gateway-screenshot]](https://tinyurl.com/yhq6l9zb)
(Click this picture to simulate in falstad circuit simulator)

The gateway is has three block that is Arduino block, HC-12 RF 433 MHz block, and GSM SIM800L block. 

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

### 2. Sensor Node (I2C Sensor)

[![Sensor Node Screen Shot][sensorNode-screenshot]](https://tinyurl.com/yze45sqd)
(Click this picture to simulate in falstad circuit simulator)


### 3. Gateway Programming 

This is an example of how to list things you need to use the software and how to install them.
* npm
  ```sh
  npm install npm@latest -g
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/github_username/repo_name.git
   ```
2. Install NPM packages
   ```sh
   npm install
   ```



<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Ammarsyaf3035/Arduino-Network/issues) for a list of proposed features (and known issues).



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

Distributed under the MIT License. See `LICENSE` for more information.



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
