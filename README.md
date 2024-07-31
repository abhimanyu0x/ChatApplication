# ChatApplication Project in C++

## Introduction

This project implements a simple chat application using C++. The chat application consists of a server and multiple clients that can connect to the server to send and receive messages in real-time. The project demonstrates the use of sockets for network communication, threading for handling multiple clients, and synchronization mechanisms to ensure thread-safe operations. The chat application uses a blocking concept to manage communication between the server and clients.

## Features

- Multiple clients can connect to the server simultaneously.
- Clients can send and receive messages in real-time.
- Each client is identified by a unique name.
- Handles client disconnections gracefully.

## Requirements

- Visual Studio 2022
- Windows operating system

## Files

- `main.cpp`: Contains the server-side code in server folder.
- `main.cpp`: Contains the client-side code in client folder.

## How to Compile and Run

### Visual Studio 2022

#### Server

1. Open Visual Studio 2022.
2. Open the project containing `main.cpp`.
3. Set `main.cpp` as the startup file.
4. Build the project by selecting `Build > Build Solution` or pressing `Ctrl+Shift+B`.
5. Run the server by selecting `Debug > Start Without Debugging` or pressing `Ctrl+F5`.

#### Client

1. Open Visual Studio 2022.
2. Open the project containing `main.cpp`.
3. Set `main.cpp` as the startup file.
4. Build the project by selecting `Build > Build Solution` or pressing `Ctrl+Shift+B`.
5. Run the client by selecting `Debug > Start Without Debugging` or pressing `Ctrl+F5`.
6. Enter your name when prompted and start chatting!

## Usage

1. Start the server first.
2. Start one or more clients and connect to the server.
3. Enter your name when prompted.
4. Start sending and receiving messages.

## Contributing

Contributions to improve the project are welcome. Please feel free to submit issues or pull requests.
