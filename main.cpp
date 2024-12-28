#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main() {
    // Yüz tanıma için Haar Cascade yükleyin
    cv::CascadeClassifier faceCascade;
    if (!faceCascade.load("/home/muti/face_recognition_project/data/haarcascade_frontalface_default.xml")) {
        std::cerr << "Haar Cascade yüklenemedi!" << std::endl;
        return -1;
    }

    // Kamerayı açın
    cv::VideoCapture capture(0);
    if (!capture.isOpened()) {
        std::cerr << "Kamera açılamadı!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        capture >> frame;
        if (frame.empty()) {
            break;
        }

        // Görüntüyü gri tonlamaya çevir
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Yüzleri algıla
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(gray, faces);

        // Yüzleri işaretle ve üzerine "Muhammet Bozkurt" yaz
        for (const auto& face : faces) {
            // Yüz etrafına dikdörtgen çizin
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);

            // Yüzün üzerine "Muhammet Bozkurt" yaz
            cv::putText(frame, "Muhammet Bozkurt", 
                        cv::Point(face.x, face.y - 10), 
                        cv::FONT_HERSHEY_SIMPLEX, 
                        1.0, cv::Scalar(0, 255, 0), 2);
        }

        // Sonucu göster
        cv::imshow("Face Recognition", frame);

        // Çıkmak için 'q' tuşuna basın
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    capture.release();
    cv::destroyAllWindows();
    return 0;
}

