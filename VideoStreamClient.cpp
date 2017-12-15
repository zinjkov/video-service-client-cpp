//
// Created by zinjkov on 15.12.17.
//

#include "VideoStreamClient.hpp"




VideoStreamClient::VideoStreamClient():
        m_context(1) {

    std::thread([this]() {
        this->update();
    }).detach();


}


void VideoStreamClient::update() {
    while(1) {
        for (int i = 0; i < m_subscriber_pool.size(); i++) {
            zmq::message_t msg;
            if (m_subscriber_pool[i].recv(&msg, ZMQ_NOBLOCK)) {
                std::vector<uint8_t> buff(msg.size());
                memcpy(buff.data(), msg.data(), msg.size());
                cv::Mat rawData(1, buff.size(), CV_8UC1, (void *) buff.data());
                m_frame_pool[i] = cv::imdecode(rawData, CV_LOAD_IMAGE_COLOR);
            }
        }
    }
}

void VideoStreamClient::subscribe(const std::string &ipaddress__) {
    m_frame_pool.emplace_back();
    m_subscriber_pool.emplace_back(m_context, ZMQ_SUB);
    std::cout <<" " <<std::endl;
    m_subscriber_pool[0].connect(ipaddress__.c_str());
    m_subscriber_pool[0].setsockopt(ZMQ_SUBSCRIBE, "", 0);
}
