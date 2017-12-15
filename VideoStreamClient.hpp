//
// Created by zinjkov on 15.12.17.
//

#ifndef ZMQCLIENT_VIDEOSTREAMCLIENT_HPP
#define ZMQCLIENT_VIDEOSTREAMCLIENT_HPP

#include <vector>
#include <zmq.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <iostream>
class VideoStreamClient {
public:
    static VideoStreamClient &instance() {
        static VideoStreamClient inst;
        return inst;
    }

    inline cv::Mat getFrame(int stream_idx = 0) {
        return (!m_frame_pool[stream_idx].empty()) ? m_frame_pool[stream_idx] : cv::Mat(1, 1, 0);
    }


    void subscribe(const std::string &ipaddress);

private:
    VideoStreamClient();

    void update();

    zmq::context_t m_context;
    std::vector<zmq::socket_t> m_subscriber_pool;
    std::vector<cv::Mat> m_frame_pool;
};


#endif //ZMQCLIENT_VIDEOSTREAMCLIENT_HPP
