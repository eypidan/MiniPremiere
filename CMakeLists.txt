cmake_minimum_required(VERSION 3.14)
project(MiniPremiere)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH E:\\Qt\\5.13.0\\mingw73_64\\lib\\cmake E:\\OpenCV\\opencv-3.4.6\\mingw-build\\install)

include_directories(E:\\ffmpeg\\dev\\include)
link_directories(E:\\ffmpeg\\dev\\lib)

include_directories(E:\\OpenCV\\opencv-3.4.6\\mingw-build\\install\\include)
link_directories(E:\\OpenCV\\opencv-3.4.6\\mingw-build\\install\\x64\\)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(OpenCV)


set(SOURCE_FILES App/main.cpp
                 App/app.h App/app.cpp View/MainWindow.cpp View/MainWindow.h View/Notification/UpdateViewNotification.cpp View/Notification/UpdateViewNotification.h
                 model/EditableVideo.cpp model/EditableVideo.h model/Model.cpp model/Model.h
                 common/command.h common/notification.h
                 ViewModel/commands/FetchQimageCommand.cpp ViewModel/commands/FetchQimageCommand.h
                 ViewModel/commands/OpenFileCommand.cpp ViewModel/commands/openFileCommand.h
                 ViewModel/ViewModel.cpp ViewModel/ViewModel.h App/main.cpp)
add_executable(MiniPremiere ${SOURCE_FILES})

#target_link_libraries(MiniPremiere Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia)
#target_link_libraries(QtTest Qt5::Widgets ${OpenCV_LIBS} E:\\ffmpeg\\dev\\lib)
target_link_libraries(MiniPremiere ${OpenCV_LIBS} avcodec avdevice avfilter avformat swresample avutil postproc swresample swscale Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia)
