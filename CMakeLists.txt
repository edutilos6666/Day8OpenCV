CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 PROJECT( "Day8" )
 
# set(CMAKE_PREFIX_PATH C:/Qt/5.3/msvc2013)
#32-bit because , my vs is 32 bit application 
 #set(CMAKE_PREFIX_PATH C:/Qt/5.3/msvc2013)
 #set(CMAKE_PREFIX_PATH C:/Qt/5.3/msvc2013)
 #set(OpenCV_DIR C:/opencv_3_2/build)
 FIND_PACKAGE( Qt5Core)
 FIND_PACKAGE(Qt5Widgets)
 FIND_PACKAGE(Qt5Gui)
 FIND_PACKAGE(Qt5Sql)
FIND_PACKAGE(Qt5Xml)
FIND_PACKAGE(Qt5XmlPatterns)
FIND_PACKAGE(Qt5Network )
FIND_PACKAGE(Qt5Multimedia)
FIND_PACKAGE(Qt5MultimediaWidgets)
FIND_PACKAGE(OpenCV)
 #FIND_PACKAGE( Qt5Sql)
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 SET( CMAKE_AUTOMOC ON)
 INCLUDE_DIRECTORIES(
 ${CMAKE_CURRENT_BINARY_DIR}
 ../include
 )
 
 INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
 
 
  
 
 
 SET( INCS
 displaywidget.h
 filterwidget.h
 mainwindow.h
 sourcewidget.h
 )
 



 SET( SRCS
displaywidget.cpp
filterwidget.cpp
 main.cpp
 mainwindow.cpp
  sourcewidget.cpp
 )
 SET( GUIS
 displaywidget.ui
 filterwidget.ui
 sourcewidget.ui
 )
 QT5_WRAP_UI( GUI_SRCS
 ${GUIS}
 )
 ADD_EXECUTABLE( ${PROJECT_NAME}
 ${INCS}
 ${SRCS}
 ${GUI_SRCS}
 )
 #QT5_USE_MODULES -> old cmake , TARGET_LINK_LIBRARIES -> new cmake 
 #QT5_USE_MODULES( ${PROJECT_NAME} Widgets Gui Sql Xml Xmlpatterns Network )
#  QT5_USE_MODULES( ${PROJECT_NAME} Sql)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Widgets)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Gui)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Sql)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Xml)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::XmlPatterns)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Network)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Multimedia)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::MultimediaWidgets)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})