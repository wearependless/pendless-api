#include "PendlessApi.h"
#include <curl/curl.h>
#include <string>
#include <sstream>

PendlessApi::PendlessApi(const std::string& key) {
    apiKey = key;
    endpoint = "https://pendless.atomian.com/api/enqueue/";
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string PendlessApi::postRequest(const std::string& data) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist* headers = NULL;
        std::string authHeader = "Authorization: Bearer " + apiKey;
        headers = curl_slist_append(headers, authHeader.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            readBuffer = std::string("Error: ") + curl_easy_strerror(res);
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return readBuffer;
}

std::string PendlessApi::enqueue(const std::string& url, const std::string& prompt, const std::string& title) {
    std::stringstream ss;
    ss << "{"
       << "\"procedure\":\"enqueue\","
       << "\"url\":\"" << url << "\","
       << "\"prompt\":\"" << prompt << "\"";
    if(!title.empty()) {
        ss << ",\"title\":\"" << title << "\"";
    }
    ss << "}";
    return postRequest(ss.str());
}

std::string PendlessApi::status(const std::string& uuid) {
    std::stringstream ss;
    ss << "{"
       << "\"procedure\":\"status\","
       << "\"uuid\":\"" << uuid << "\""
       << "}";
    return postRequest(ss.str());
}
