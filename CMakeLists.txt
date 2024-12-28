cmake_minimum_required(VERSION 3.10)
project(FaceRecognition)

# OpenCV'yi bul
find_package(OpenCV REQUIRED)

# Kaynak dosyalarını belirle
set(SOURCE_FILES main.cpp)

# Yüklenen OpenCV'yi ekleyin
include_directories(${OpenCV_INCLUDE_DIRS})

# Projeyi derleyin
add_executable(FaceRecognition ${SOURCE_FILES})

# OpenCV kütüphanesini bağlayın
target_link_libraries(FaceRecognition ${OpenCV_LIBS})
