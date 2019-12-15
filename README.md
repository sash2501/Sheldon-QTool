# Sheldon-QTool
The Sheldon QTool is a user-friendly app that helps the user learn basic concepts of Mechanics through practice.

The app provides visual demonstration to user by plotting the user provided shape on a graph.The user can zoom in or out of the graph according to his convenience.

Also, the user can play around with different shapes, provided the correct coordinates are given, in the composite body part of the application.

Sheldon QTool is built upon the Qt framework that uses 
- C++ 
- XML language.

### Why "Sheldon"??
Sheldon Cooper is a very smart scientist in Big Bang Theory series who can solve tough science and maths problems without breaking sweat!

## Installation

### Prequisites
- Qt5
- Qt Creator

### Qt Creator
To install QtCreator and Qt5 in your laptop, there are certain terminal commands to be executed. They are:

- Update the system
```bash
sudo apt-get update
sudo apt-get install build-essential
```
- Install Qt Creator
```bash
sudo apt-get install qtcreator
```
```bash
sudo apt install qt5-default
sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html
```
For more reference about installing QtCreator, you can go through this helpful [blog](https://lucidar.me/en/dev-c-cpp/how-to-install-qt-creator-on-ubuntu-18-04/)

After setting up Qt, clone this repository in a local directory on your machine

```bash
git clone "https://github.com/sash2501/Sheldon-QTool.git"
```
## Using Sheldon QTool
- The application can find Centroid as well as Moment of Inertia  of a given shape provided by the user.

<img src = "/ui_ss/MainWindow.png">

- The user has to enter values of the coordinates of the shape and the result will be displayed on the adjoining graph.

The Centroid of following shapes can be calculated:

<img src = "/ui_ss/Centroid.png">

The Moment of Inertia of the following shapes can be calculated:

<img src = "/ui_ss/MOI.png">

### Centroid
![centroid](/ui_ss/centroidshow.gif)

### Moment of Inertia
![moment of inertia](/ui_ss/moishow.gif)

### Entering Coordinates
![enter](/ui_ss/centroid.gif)
