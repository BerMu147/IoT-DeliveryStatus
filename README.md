# IoT-DeliveryStatus

Self learned and done an IoT project with Arduino board for presentation on University 

The Project consists of 4 main components:
- Web Application (Frontend Part) using plain JS, HTML & CSS
- CPP code (Arduino aka Controler Part) using PlatformIO extension on VS Code
- Firebase
- Hardware material (NodeMCU, arduino board, 3 cable pins,3 leds and 3 resistors)

Software Requirements:
- Working environment (VS CODE)
- PlatformIO extension for VS CODE (PlatformIO is used for arduino code. It's same as Arduino IDE)
- Libraries on PlatformIO (configured in platform.ini)
- Firebase account and project with realtime database

Directory description:

Arduino-Controller - Only responsible for communication between web application, firebase and arduino device

web-app  - Frontend web application interface linked with firebase via config and is deployed on firebase

# Goal of the project
User is able to see in which state the delivery is.

Web application is deployed on the firebase and can be accessed on following link: https://arduinotest-4702d.web.app/
