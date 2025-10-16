#ifndef PENDLESSAPI_H
#define PENDLESSAPI_H

#include <string>

class PendlessApi {
private:
    std::string apiKey;
    std::string endpoint;

public:
    PendlessApi(const std::string& key);

    std::string enqueue(const std::string& url, const std::string& prompt, const std::string& title = "");
    std::string status(const std::string& uuid);

private:
    std::string postRequest(const std::string& data);
};

#endif
