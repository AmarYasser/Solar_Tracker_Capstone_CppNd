# Solar Tracker

Implementing a solar tracking for 2D solar panel system using a OpenCV with C++

based on and Inspired by : https://www.mdpi.com/1424-8220/16/12/1995

The project is accepting a video for the sun and track the sun,
according to sun's position relative to the camera center, a proper action is taken.
In the current version, the action is a basic a print on the terminal.


## Cloning

```
git clone https://github.com/AmarYasser/Solar_Tracker_Capstone_CppNd.git
```
or with SSH:
```
git clone git@github.com:AmarYasser/Solar_Tracker_Capstone_CppNd.git
```

## Dependencies for Running Locally
* cmake >= 2.6
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* openCV4 
    * [Linux:](https://docs.opencv.org/trunk/d7/d9f/tutorial_linux_install.html) 

## Compiling and Running

### Compiling
To compile the project, From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./solarTracker
```
## Testing
In the `./resources` folder, you can find some videos for different situations that can face the system:

- sun with clouds 
- sunset without clouds
- sun with clouds interfering

So, You should specify the location of the video in the `main.cpp.
by default :
```
    cv::VideoCapture cap("../resources/sun_no_clouds.mp4");
```

## Structure

The code is mainly about two classes:

- `sunDetector` it has multible methods, the main ones are:
    -  `void findSun ();` :  method for Image processing and finding the sun centers 
    -  `void startVideo(cv::Mat fr);` : to make an output video of the frames treated
    -  `void display(std::string action);` : to dispaly every frame treaded while running
    
- `solarPanel()` represents the solarpanel to take the proper action , 
    - It has a method: `takeAction(cv::Mat& fr);` : to assign the proper action according to sun position relative to panel center (camera center in our case)
    - It has an object of  `sunDetector` to advantaage with its methods.

## Results
check the following Video for 3 senarios comibined:
[![Sun Traking](https://github.com/AmarYasser/Solar_Tracker_Capstone_CppNd/blob/master/SolarTracker.png)](https://www.youtube.com/watch?v=QRLSILizAyQ "Sun Traking")

## Deploying 
Extending the project to an physical system requires the following:
- Integrate a camera Instead of an existing video.
- corelate the camera and panel centers 
- Adapt the action with motors style.
- (option) remove the outVideo functions. 

## Future Considerations

to acquire more clean code with robust performance, upgrade the code involving:

- Using Smart pointers anf move semantics to manage `frame` variable and passing it between functions
- Extend `dispaly()` and `video` methods to be more generic and not related to a specific class.
- modify to accept an active camera.
- add camera caliberation functions.
- 
## Rubric 
this project mainly tackles Loops, Functions, I/O and Object Oriented Programming sections
