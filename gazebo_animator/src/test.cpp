//----------------------------------------------------------------------------------------------------------------------
// GRVC Utils
//----------------------------------------------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2016 GRVC University of Seville
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//----------------------------------------------------------------------------------------------------------------------
#include <ros/ros.h>
#include <gazebo_animator/frame.h>
#include <gazebo_animator/key_frame.h>
#include <gazebo_animator/gazebo_animated_link.h>

using grvc::utils::Frame;
using grvc::utils::KeyFrame;
using grvc::utils::GazeboAnimatedLink;

int main(int _argc, char** _argv) {
    ros::init(_argc, _argv, "gazebo_move");
    ROS_INFO("Starting gazebo_move");
    // WATCHOUT: Yellow misspelled!
    GazeboAnimatedLink yellow("Yelow cylinder object::grab_here");
    // TODO: Trajectory from argument/file
    yellow.addKeyFrame(KeyFrame(Frame(0.0, 0.0, 0.0), ros::Time(0.0)));
    yellow.addKeyFrame(KeyFrame(Frame(9.0, 0.0, 0.0), ros::Time(10.0)));
    yellow.addKeyFrame(KeyFrame(Frame(0.0, 0.0, 0.0), ros::Time(20.0)));
    //yellow.playOnce();
    yellow.playLoop();
    char input = 'a';
    while (input != 'q') {
        std::cout << "Enter q to quit" << std::endl;
        std::cin >> input;
    }
    yellow.stop();
    return 0;
}
