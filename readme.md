# MiniPlayer: A Mini video player

#### Build Status:

[![Build Status](https://travis-ci.org/eypidan/MiniPremiere.svg?branch=master)](https://travis-ci.org/eypidan/MiniPremiere)



### 项目介绍
- 我们的项目使用了MVVM软件架构来进行开发。

- 项目实现了一个简易的视频播放器，支持播放部分格式的媒体文件，例如MP4

- 项目的总体报告见****

- 项目的需求分析见****

- 项目的model部分单元测试代码见 [testmodel.cpp](https://github.com/eypidan/MiniPremiere/blob/master/model/testmodel.cpp)

  

  <br>
### introduction
- Our project uses MVVM(Model-view-viewmodel) softerware architectural pattern.
- This project implements a Mini Video Player to play some media files.
- Final report of this project refers to ****.
- The requirement analysis refers to ****.
- The test about model refers to  [testmodel.cpp](https://github.com/eypidan/MiniPremiere/blob/master/model/testmodel.cpp)

### Features

- GUI interface
- Convert cv:Mat to  QImage
- Play  video files silently
- Play video fast forward and rewind 

### Supported OSes and compilers

- Ubuntu: 16.04 or later: GCC 4.9 or later
- Windows: MinGW 7.30 or later

### Build Requirements

These are the base requirements to build out miniplayer from  a source package:

* CMake 3.12 versions above
* a C++17-standard-compliant compiler
* Qt5:Gui, Qt5:Multimedia, Qt5:Core, Qt5:Widgets 
* OpenCV:core, OpenCV:Core:highgui, OpenCV:Core:imgproc
* FFmpeg: avcodec avformat avutil avdevice swscale lib

Refer to .travis.yml in this project for more build details.





