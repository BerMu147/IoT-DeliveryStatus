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
- Arduino-Controller - Responsible for communication between web application, firebase and arduino device
- web-app  - Frontend web application interface deployed on firebase. All custom files must be included in public folder in order to be deployed.

# Usage
On first page user is able to order the meal via application.
Second page is redirecting to admin panel and admin selects in which state the order is.
Then the input is sent over firebase to arduino and defined leds are turned on.

States:
- Accepted: First led turns on
- Completed: Second turns on and first turns off.
- Declined or Returned: All leds turned off

# Goal of the project
User is able to see in which state the delivery is.


# Related Links
- https://platformio.org/
- https://firebase.google.com/docs/hosting/quickstart
- https://senuravihanjayadeva.medium.com/turn-on-off-a-led-from-a-html-web-site-using-firebase-53aadb828fac
