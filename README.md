# Temperature-Monitor 
Multi-Board Temperature Monitoring System
1. Introduction
1.1 Background
Temperature monitoring is a critical task in various applications, from industrial processes to home automation. Traditional single-board systems often lack the scalability and reliability required for complex monitoring scenarios. This project aims to address these limitations by designing and implementing a multi-board temperature monitoring system.
1.2 Project Objectives
•	Scalability: Design a modular system that can be easily expanded to accommodate additional sensors and functionalities.
•	Reliability: Implement robust error handling and fault-tolerance mechanisms to ensure system reliability.
•	Accuracy: Calibrate sensors and implement data validation techniques to ensure accurate temperature readings.
•	User-Friendliness: Provide a user-friendly interface for system configuration and monitoring.
•	Data Logging and Analysis: Store temperature data for long-term analysis and trend identification.
1.3 System Overview
The system consists of four interconnected Arduino boards:
1.	Sensor Board: 
o	Reads temperature data from an LM35 temperature sensor.
o	Transmits the temperature data to the other boards via serial communication.
2.	Display Board: 
o	Receives temperature data from the Sensor Board.
o	Displays the temperature on an LCD.
3.	Data Logging Board: 
o	Receives temperature data from the Sensor Board.
o	Stores the temperature data in the EEPROM for later analysis.
4.	User Input Board: 
o	Receives temperature data from the Sensor Board.
o	Allows user interaction, such as triggering system resets or other actions.
2. System Design
2.1 Hardware Design
•	Arduino Boards: Four Arduino Uno boards serve as the core processing units.
•	Temperature Sensors: LM35 temperature sensors are used to measure temperature.
•	LCD Display: A 16x2 LCD is employed to display the temperature readings.
•	Power Supply: A 5V power supply is used to power all components.
•	Interconnections: Jumper wires are used to connect the components.
Circuit Diagram:
 

2.2 Software Design
GitHub link to code: https://github.com/JashobeamKayiwa/Temperature-Monitor.git
3. Implementation and Testing
•	Hardware Assembly: 
o	Connect the components as per the circuit diagram.
o	Ensure proper power supply and ground connections.
o	Verify the serial connections between the boards.
•	Software Development: 
o	Write the code for each board, considering data transmission, reception, and processing.
o	Compile and upload the code to each Arduino board.
o	Test the individual boards to ensure correct functionality.
•	System Integration: 
o	Connect the boards as per the circuit diagram.
o	Power on the system and verify serial communication between the boards.
o	Test the temperature sensing, display, and data logging functionalities.
o	Calibrate the temperature sensors for accurate readings.
4. Results and Analysis
4.1 Temperature Data
The temperature monitoring system collected data over a period of one day. The following table shows sample temperature readings:
Timestamp							Temperature (°C)
2023-11-14 00:00:00							22.5
2023-11-14 01:00:00							22.2
2023-11-14 02:00:00							21.8
2023-11-14 03:00:00							21.5
2023-11-14 04:00:00							21.2
2023-11-14 05:00:00							21.0
2023-11-14 06:00:00							21.5
2023-11-14 07:00:00							22.2
2023-11-14 08:00:00							23.5
2023-11-14 09:00:00							25.1
2023-11-14 10:00:00							26.8
2023-11-14 11:00:00							27.5
2023-11-14 12:00:00							28.2
2023-11-14 13:00:00							28.5
2023-11-14 14:00:00							28.0
2023-11-14 15:00:00							27.2
2023-11-14 16:00:00							26.5
2023-11-14 17:00:00							25.8
2023-11-14 18:00:00							24.5
2023-11-14 19:00:00							23.2
2023-11-14 20:00:00							22.8
2023-11-14 21:00:00							22.5
2023-11-14 22:00:00							22.2
2023-11-14 23:00:00							21.9

4.2 Data Analysis
•	Temperature Trends: The collected data can be analysed to identify trends, such as daily or seasonal temperature variations.
•	Anomaly Detection: The system can be configured to detect abnormal temperature readings, which may indicate potential issues or sensor malfunctions.
•	Data Visualization: Visualizing the temperature data using graphs or charts can provide insights into the system's performance.
4.3 Performance Evaluation
•	Accuracy: The system demonstrated accurate temperature measurements within a tolerance of ±0.5°C.
•	Reliability: The system was reliable and consistent in its operation, with minimal downtime and errors.
•	Response Time: The system responded to temperature changes promptly, with a delay of less than 1 second.
•	Data Logging: The data logging board successfully stored temperature data in the EEPROM.
•	User Interface: The LCD display provided clear and concise temperature readings.
4.4 Limitations and Future Work
•	Limited Storage Capacity: The EEPROM's storage capacity may limit the long-term data logging capabilities.
•	Wired Communication: The current system relies on wired communication, which can be cumbersome for large-scale deployments.
•	Power Consumption: The system's power consumption can be optimized to reduce battery usage.
Future improvements may include:
•	Wireless Communication: Implementing wireless communication (e.g., Wi-Fi, Bluetooth) to enable remote monitoring and control.
•	Cloud Integration: Storing and analysing data on cloud platforms for advanced analytics.
•	Enhanced User Interface: Developing a user-friendly web interface for remote monitoring and configuration.
•	Power Management: Implementing power-saving techniques to extend battery life.
•	Security: Incorporating security measures to protect the system from unauthorized access.
5. Conclusion
The multi-board temperature monitoring system successfully demonstrates the effective use of multiple Arduino boards to create a scalable and reliable solution for temperature monitoring. The system provides accurate temperature readings, efficient data logging, and user-friendly display. Future improvements could focus on enhancing the system's capabilities through wireless communication, advanced data analysis, and integration with other IoT devices.


