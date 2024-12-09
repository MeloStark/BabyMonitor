#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; // OpenCVの名前空間を利用

int main() {
    // カメラデバイスをオープン (デバイスID 0)
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "カメラを開けませんでした。" << std::endl;
        return -1;
    }

    // カメラの解像度を設定
    cap.set(CAP_PROP_FRAME_WIDTH, 1280);  // 幅     // 1280 / 640
    cap.set(CAP_PROP_FRAME_HEIGHT, 720); // 高さ    // 720 / 480

    std::cout << "カメラを開きました。フレームをキャプチャしています..." << std::endl;

    // フレームを格納するMat型変数
    Mat frame;
    cap >> frame; // フレームをキャプチャ

    if (frame.empty()) {
        std::cerr << "フレームをキャプチャできませんでした。" << std::endl;
        return -1;
    }

    // 画像を保存
    std::string filename = "/home/RPizero2/repository/BabyMonitor/data/capture.jpg";
    if (!imwrite(filename, frame)) {
        std::cerr << "画像の保存に失敗しました。" << std::endl;
        return -1;
    }

    std::cout << "画像が " << filename << " に保存されました。" << std::endl;

    return 0;
}