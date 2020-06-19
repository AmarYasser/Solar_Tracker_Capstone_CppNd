#include "SunDetector.h"

// consturctors
sunDetector::sunDetector() {}
sunDetector::sunDetector(cv::Mat fr) : frame(fr) {}

sunDetector::sunDetector(std::string path)
{
    frame = cv::imread(path);
}

// setter
void sunDetector::setFrame(std::string path)
{
    frame = cv::imread(path);
}

void sunDetector::setFrame(cv::Mat fr)
{
    frame = fr;
}

void sunDetector::setSunCenter(cv::Point center)
{
    if (cv::Mat(center).isContinuous())
        cv::Mat(center).col(0).copyTo(sunCenter);
}

void sunDetector::setFrameCenter()
{
    frameCenter.push_back(frame.cols / 2);
    frameCenter.push_back(frame.rows / 2);
}

// getters
cv::Mat sunDetector::getFrame()
{
    return frame;
}
std::vector<int> sunDetector::getSunCenter()
{
    return sunCenter;
}
std::vector<int> sunDetector::getFrameCenter()
{
    return frameCenter;
}

int sunDetector::getFramewidth() { return frame.size().width; }
int sunDetector::getFrameHight() { return frame.size().height; };

// method find sun
void sunDetector::findSun()
{

    // resizing by 50 %
    //cv::resize(frame, frame, cv::Size(), 0.5, 0.5);
    std::cout << "frame size : " << frame.size() << std::endl;

    // set frame reference
    sunDetector::setFrameCenter();
    // convert image to grayscale
    cv::cvtColor(frame, gry_img, cv::COLOR_BGR2GRAY);
    //cv::imshow("Gray Image ", gry_img);

    // Apply Gaussian Smoothing filter
    cv::GaussianBlur(gry_img, blurredImage, cv::Size(51, 51), 0, 0);
    //cv::imshow("Blurred Image", blurredImage);

    // convert grayscale to binary image
    cv::threshold(gry_img, threshold_img, 252, 255, cv::THRESH_BINARY);
    //cv::imshow("tHRE Image ", threshold_img);

    // find moments of the image
    cv::Moments m = moments(threshold_img, true);
    cv::Point center(m.m10 / m.m00, m.m01 / m.m00);

    // coordinates of centroid
    sunDetector::setSunCenter(center);
    std::cout << " Sun Detected at: " << sunCenter[0] << " , " << sunCenter[1] << std::endl;
}

// Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
void sunDetector::startVideo(cv::Mat fr)
{
    video.open("Solar_Tracker_outVideo.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, cv::Size(fr.size().width, fr.size().height));
}

void sunDetector::endVideo()
{
    video.release();
}
void sunDetector::display(std::string action)
{
    if (video.isOpened())
    {
        // Print the command on the image
        cv::putText(frame, action, cv::Point(30, 30),
                    cv::FONT_HERSHEY_DUPLEX, 0.9, cv::Scalar(200, 50, 200), 1.5);

        // show the image with a point mark at the centroid
        // cenerts
        cv::Point center(sunDetector::getSunCenter()[0], sunDetector::getSunCenter()[1]);
        cv::Point centerframe(sunDetector::getFrameCenter()[0], sunDetector::getFrameCenter()[1]);
        // Draw centers
        cv::circle(frame, center, 30, cv::Scalar(0, 255, 0), 3);
        cv::circle(frame, centerframe, 5, cv::Scalar(0, 0, 130), 10);

        //write on video
        video.write(frame);
        //show frame
        cv::imshow("Image with center", frame);
        
        //wait for a 0.5 second
        usleep(1000);
        
        // pres any key to get next frame
        //cv::waitKey(0);
    }
}