# Security System Application

This is a simple security system application implemented in C++. The application allows users to register, login, and manage their profiles. It also provides an admin interface to view and manage user data.

## Features

The application offers the following features:

- User Registration: Users can register by providing their name, age, email, phone number, username, and password.
- User Login: Registered users can log in using their username and password.
- View Profile: Users can view their profile information, including name, age, email, phone number, username, and password.
- Change Password: Users can change their password.
- Logout: Users can log out of their account.
- Delete Account: Users can delete their account from the system.
- Admin Access: An admin can log in using a secret password and view all registered user information.

## Usage

To use the application, follow these steps:

1. Clone or download the source code files.
2. Compile the code using a C++ compiler.
3. Run the compiled executable.
4. Follow the prompts to register or log in as a user or access the admin interface.

Note: The application requires the `<bits/stdc++.h>` and `<conio.h>` libraries, so make sure they are available in your development environment.

## File Structure

- `main.cpp`: Contains the main code of the application, including class definitions and function implementations.
- `security_file.txt`: A text file used to store user data.
- `temp_file.txt`: A temporary file used for data manipulation.

## Dependencies

The application relies on the following libraries:

- `<bits/stdc++.h>`: A standard C++ library that includes commonly used standard library headers.
- `<conio.h>`: A library used to provide console input/output functions.

## Disclaimer

This application is intended for educational purposes only. It may not provide robust security measures and should not be used in sensitive or production environments. Use at your own risk.

## License

The application is released under open source
