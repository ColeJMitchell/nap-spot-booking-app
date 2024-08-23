# IMPORTANT READ FIRST
1. The Cedrien contributor is my github account tied to lafayette college.
2. To view our presentation without cloning watch the .mov video included in the repository.
3. My personal contributions include all of the front end (gtk) and back end (sqlite database). My partner assisted with the unit testing; otherwise, the entirety of the project was conceptualized and developed by me.
4. All user and nap spot information is stored in a sqlite database and the backend makes SQL queries that are reflected in the front end.

#How To Build Locally
1. Clone the repository to your local machine.
2. Open the project in an IDE such as CLion, and the cmake-build-debug directory will automatically be generated.
3. Navigate CLion's hammer and specify the target as frontend.
4. In a terminal cd to cmake-build-debug and run ./frontend.

# Nap Spot Booking Application
This project is a graphical user interface (GUI) application built using C++ and the GTK+ toolkit. 
It allows users to book, favorite, and request nap spots on a university campus or any other relevant location.

# Features

## User Authentication:

Users can sign up by creating a new account with a username and password. If the account is already in the database than the user is denied access, but if the information is new, the account is added to the database. The way the application checks if an account exists is with a select statement that uses the conditional, where password = inputted password and username = inputted username and returns -1 if it does not exist. When a new user is created it is given an id equal to the number of nap spots in the database using a count select SQL query, since the first id begins at 0. All new accounts are given a privledge of 0 which means they do not have administrator privledges. The one administrator account is preloaded into the database with a csv file when make build is entered into the command line while in the databaee directory. 
When logging in, the inverse of the signup logic is utilized, where the application checks that the user credentials in order to provide access. If the user information is not in the database yet then the user is denied access.

## Nap Spot Booking:

Authenticated users can view a list of available nap spots. Each Nap Spot is listed with a name, availibility status, custom attributes (brightness, noise level, location), and a photo of the location which are all stored as varchar strings in the database. Nap spots also have ids which function similarly to user ids. The photos stored in the database are paths that lead to the photos directory which store all of the photos as jpgs. The path begins with .. because the photos directory is one directory up from the application. The nap spots are displayed graphically using two offsets. The first offset is a constant which ensures that the nap spots are evenly space from one another. The second offset increases and decreases when the scroll up and scroll down buttons are pushed respectively. The screen is also reloaded each time either of these buttons are pressed so that the user can graphically view the change.  Users can book a nap spot by selecting the desired spot's id and specifying the duration (in minutes). When the nap spot is booked, the reserved string in the database changes from open to reserved for the corresponding nap spot. The page is also reloaded to instantaneously show the change. A new thread also splits off from the main thread and immediately goes to sleep for the specified number of minutes. Once it wakes up, it switches the nap spot's reserved string back to open. After the user makes a reservation, they are unable to make another one until the reservation finishes; however, other users are still able to reserve nap spots. Users are also able to favorite nap spots from the booking page by entering ids. There are five integer columns in the user database which are iniialized to -1, but when a new nap spot is favorited, the first column with a -1 changes to the id of the nap spot. 

## Favorite Nap Spots:

From the favorites page, users can reserve nap spots using the same mechanism used in the booking page. Since there are only five columns that hold ids in the user database, only a maximum of five nap spots can be displayed at a time. If a user wishes to favorite a new nap spot, but already has the maximum number of favorited nap spots, thery also have the ability to remove favorited nap spots. When a user wants to remove a nap spot, they enter the id and the application searches through the user's nap spot columns and switches the id back to -1.

## Nap Spot Request:

Regular users can submit requests for new nap spot locations. Users enter nap spot information which is then held in a seperate table for the admins to review. The information of the requested nap spot is not passed to other users until it is approved by the administrator and added to the nap spot database. Requests include details such as the nap spot name, attributes, and a photo.

## Administrator Privileges:

Administrators have the ability to approve or deny new nap spot requests submitted by users.
Approved nap spots are added to the list of available nap spots for booking and seen by all other users. 

