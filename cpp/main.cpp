#include "PendlessApi.h"
#include <iostream>

int main() {
    PendlessApi api("YOUR_API_KEY");

    // Enqueue task
    std::string enqueueResp = api.enqueue(
        "https://example.com/login",
        "Open the login page, enter username and password",
        "Browser Automation: Login"
    );
    std::cout << "Enqueue Response:\n" << enqueueResp << std::endl;

    // Check status (replace with actual UUID returned above)
    std::string uuid = "TASK_UUID_HERE";
    std::string statusResp = api.status(uuid);
    std::cout << "Status Response:\n" << statusResp << std::endl;

    return 0;
}
