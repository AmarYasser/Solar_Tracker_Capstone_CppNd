#include <solarPanel.h>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main()
{

    solarPanel sp;

    // Create a VideoCapture object and open the input file
    cv::VideoCapture cap("../resources/sun_no_clouds.mp4");
    cv::Mat frame;

    // Check if camera opened successfully
    if (!cap.isOpened())
    {
        std::cout << ">>>>> Error opening video <<<<" << std::endl;
        return -1;
    }
    cap >> frame;
    sp.sd.startVideo(frame);
    while (1)
    {
        // save every frame from source video to frame variable
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        sp.takeAction(frame);


        // Option :: If you don't want to track the results per frame 
        // comment the next line and re-compile 
        cv::waitKey(27);
    }
    std::cout << ">>>>> Video Ended <<<<<< \n "
              << ">>>>>> You Can find the Output video on ./build Called "
                 "Solar_Tracker_outVideo.avi"
                 " <<<<"
              << std::endl;
    //release
    cap.release();
    sp.sd.endVideo();
    // Closes all the windows
    destroyAllWindows();

    return 0;
}