# Autonomous Mobile Robot 🤖

## Project Description

This project consists of the development of a mobile robot capable of autonomous navigation and remote control.

The project is also used as a practical platform to improve my knowledge of embedded systems, electronics, sensors, communication protocols, and microcontroller programming.

The robot currently supports two operating modes:

- **Automatic Mode** – Autonomous navigation and obstacle avoidance

- **Manual Mode** – Remote control through a Wi-Fi web interface


## Hardware Components

- Arduino Uno

- NodeMCU ESP8266

- L298N Motor Driver

- 2x HC-SR04 Ultrasonic Sensors

- 2x DC Motors

- Mini Robot Chassis

- 4x AA Battery Pack

- DC-DC Step-Up/Step-Down Converter


## Features

### 🤖 Automatic Mode

- Autonomous navigation

- Distance measurement using ultrasonic sensors

- Obstacle detection

- Automatic obstacle avoidance

- State-machine based control

The autonomous behavior is implemented using the following states:

- `FAHREN`

- `STOPPEN`

- `RUECKFAHREN`

- `DREHEN`


### 🎮 Manual Mode

The robot can also be controlled remotely from a smartphone or computer through a web interface hosted by the ESP8266.

Available commands:

- `F` – Forward

- `B` – Backward

- `L` – Turn left

- `R` – Turn right

- `S` – Stop

The user can switch between **MANUELL** and **AUTOMATIK** directly from the web interface.


## System Architecture

The project uses two microcontrollers with different responsibilities:

```text

Smartphone / Computer

        |

      Wi-Fi

        |

        v

NodeMCU ESP8266

   Web Server

        |

       UART

        |

        v

   Arduino Uno

        |

        v

      L298N

        |

        v

     DC Motors

Arduino Uno

     |

     +---- HC-SR04 Right

     |

     +---- HC-SR04 Left

```

The **ESP8266** handles the Wi-Fi connection and hosts the web interface.

The **Arduino Uno** handles the motors, ultrasonic sensors, autonomous navigation, and robot control logic.

Communication between both microcontrollers is performed using **UART / SoftwareSerial**.


## Project Structure

```text

MobileRobot/

│

├── MobileRobot/

│   └── MobileRobot.ino

│

├── WifiController/

│   ├── WifiController.ino

│   └── secrets.h        # Local file, ignored by Git

│

├── .gitignore

└── README.md

```


## Wi-Fi Configuration

Wi-Fi credentials are stored locally inside:

```text

WifiController/secrets.h

```

Example:

```cpp

#pragma once

const char* ssid = "YOUR_WIFI_SSID";

const char* password = "YOUR_WIFI_PASSWORD";

```

The `secrets.h` file is excluded from Git using `.gitignore` so that Wi-Fi credentials are not published in the repository. 


## Current Development Status

### Phase 1 – Autonomous Robot ✅

- Motor control

- PWM speed control

- Ultrasonic distance measurement

- Obstacle detection

- Obstacle avoidance

- State-machine based autonomous navigation


### Phase 2 – Wi-Fi Remote Control ✅

- ESP8266 Wi-Fi connection

- Embedded web server

- Web-based robot controller

- UART communication between ESP8266 and Arduino

- Manual driving commands

- Manual / Automatic mode switching


## Future Improvements

Possible future developments include:

- Improve ultrasonic sensor reliability

- Improve autonomous navigation

- Add additional sensors

- Improve the web interface

- Display telemetry and sensor information on the web interface

- Migrate parts of the project to an STM32 microcontroller


## Author

**Aryl Warren Djiengoue Tchuegoue**
 