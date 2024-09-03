# Metro Network Pathfinding and Fare Calculation System

## Overview

This project is a console-based application designed to simulate a metro distance counter. Developed by **Aman Chahar**, it uses Dijkstra's algorithm to compute the shortest path between metro stations, providing users with comprehensive travel information including total distance, number of intermediate stations, and fare. The application also includes a secure user authentication system for login and signup.

## Features

1. **Shortest Path Calculation:**
   - Implements Dijkstra's algorithm to find the shortest path between metro stations.
   - Calculates total distance, number of intermediate stations, and fare based on the distance traveled.

2. **User Authentication System:**
   - Secure login and signup system with credential verification and storage.
   - Ensures data integrity and security through robust file handling techniques.

3. **Interactive Console Application:**
   - User-friendly interface for selecting source and destination stations.
   - Provides clear instructions and prompts for ease of use.
   - Integrates voice prompts to guide users through the process.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- `espeak` library for voice prompts

### Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/AmanChahar/metro-pathfinding.git
   cd metro-pathfinding
2. **Compile the code:**
   ```sh
   g++ -o metro metro.cpp -lstdc++fs
3. **Run the application:**
   ```sh
   ./metro

   
   
## Usage

### Login or Signup:
- On running the application, choose to login or signup.
- Follow the prompts to enter your username and password.

### Select Source Station:
- Once logged in, you will be prompted to select a source station from the list.

### View Shortest Path Information:
- The application will compute and display the shortest path, total distance, number of intermediate stations, and fare.
- You can check the distance to any other station by entering its corresponding number.

### Continue or Exit:
- You can choose to continue finding paths for other stations or exit the application.

## Code Structure

- **main.cpp:** Contains the main function and handles the menu navigation.
- **dijkstra.cpp:** Implements Dijkstra's algorithm for shortest path calculation.
- **auth.cpp:** Contains functions for user login and signup.
- **utils.cpp:** Includes utility functions for file handling and user prompts.

## Acknowledgements

- Thanks to the creators of Dijkstra's algorithm for the foundational work.
- Special thanks to the contributors and open-source community for their support.

## Contact

For any questions or feedback, please contact **Aman Chahar**.

