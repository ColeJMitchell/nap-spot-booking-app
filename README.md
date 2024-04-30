# Nap Spot Booking Application
This project is a graphical user interface (GUI) application built using C++ and the GTK+ toolkit. 
It allows users to book, favorite, and request nap spots on a university campus or any other relevant location.

# Features

## User Authentication:

Users can sign up by creating a new account with a username and password.
Existing users can log in with their credentials. The System checks if a user's information is stored within the database before entering.

## Nap Spot Booking:

Authenticated users can view a list of available nap spots.
Each Nap Spot is listed with availibility status, custom attributes (brightness, noise level, location), and a photo of the location.
Users can book a nap spot by selecting the desired spot and specifying the duration (in minutes).
The application handles the reservation and automatic release of the nap spot after the specified duration.
Reservations are multithreaded; When a user books a reservation, the nap spot branches out from the thread and sleeps, and is unavaliable for all other users for a certain amount of time determined by the countdown. 

## Favorite Nap Spots:

Users can mark their favorite nap spots for easy access.
The list of favorite nap spots is displayed separately for each user.
Users can remove a nap spot from their favorites list if needed. 

## Nap Spot Request:

Regular users can submit requests for new nap spot locations.
Users enter nap spot information which is then held in a seperate table for the admins to review. The information of the requested nap spot is not passed to other users until it is approved by the administrator. 
Requests include details such as the nap spot name, attributes, and a photo.

## Administrator Privileges:

Administrators have the ability to approve or deny new nap spot requests submitted by users.
Approved nap spots are added to the list of available nap spots for booking and seen by all other users. 

## User Interface:

The application provides a responsive and intuitive user interface built with GTK+.
Users can navigate through different pages and interact with the application using buttons, entries, and labels.