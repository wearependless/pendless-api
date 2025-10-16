# C++ Examples — Pendless API

This document shows how to call the Pendless API in C++ using a reusable class with **libcurl**. All requests require an **API key** in the `Authorization` header:

```
Authorization: Bearer YOUR_API_KEY
```

---

## 📝 PendlessApi Class Example

```cpp
#include "PendlessApi.h"
#include <iostream>

int main() {
    PendlessApi api("YOUR_API_KEY");

    // Enqueue a task
    std::string enqueueResponse = api.enqueue(
        "https://example.com/login",
        "Open the login page, enter username and password",
        "Browser Automation: Login"
    );
    std::cout << enqueueResponse << std::endl;

    // Use the UUID returned from enqueue
    std::string uuid = "TASK_UUID_HERE";
    std::string statusResponse = api.status(uuid);
    std::cout << statusResponse << std::endl;

    return 0;
}
```

**Sample `enqueue` Response:**

```json
{
    "status": "success",
    "data": {
        "uuid": "a1b2c3d4-5678-90ab-cdef-1234567890ab"
    },
    "message": "Task created successfully"
}
```

**Sample `status` Response:**

```json
{
    "status": "success",
    "data": {
        "uuid": "a1b2c3d4-5678-90ab-cdef-1234567890ab",
        "creation date": "2025-10-16 14:22:01",
        "execution date": "",
        "status": "pending",
        "feedback": "",
        "result": ""
    },
    "message": "Task status retrieved successfully"
}
```
