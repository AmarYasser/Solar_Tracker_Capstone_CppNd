// This code is the initial one, tests on an image 


////// don't uncomment it  //////

/* 
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

int main()
{
    // declare img matrices
    cv::Mat img, gry_img, blurredImage, threshold_img;

    // image input
    img = cv::imread("../resources/sun.png");
    // resizing by 50 %
    cv::resize(img, img, cv::Size(), 0.5, 0.5);

    // convert image to grayscale
    cv::cvtColor(img, gry_img, cv::COLOR_BGR2GRAY);
    //cv::imshow("Gray Image ", gry_img);

    // Apply Gaussian Smoothing filter
    cv::GaussianBlur(gry_img, blurredImage, cv::Size(51, 51), 0, 0);
    //cv::imshow("Blurred Image", blurredImage);

    // convert grayscale to binary image
    cv::threshold(gry_img, threshold_img, 252, 255, cv::THRESH_BINARY);
    cv::imshow("tHRE Image ", threshold_img);

    // find moments of the image
    cv::Moments m = moments(threshold_img, true);
    cv::Point center(m.m10 / m.m00, m.m01 / m.m00);

    // coordinates of centroid
    std::cout << cv::Mat(center) << std::endl;

    // show the image with a point mark at the centroid
    int radius = 50; // radius of circle

    cv::circle(img, center, radius, cv::Scalar(0, 255, 0),5);
    cv::imshow("Image with center", img);
    // put some words
    // cv::putText(img, "#{}".format(), ( cv::Mat(center) - 15), cv::FONT_HERSHEY_SIMPLEX, 0.45, (0, 0, 255), 2);

    cv::waitKey(0);

    return 0;
} */