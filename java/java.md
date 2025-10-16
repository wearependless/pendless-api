# Java Examples — Pendless API

This document shows how to call the Pendless API in Java using **HttpURLConnection**. All requests require an **API key** in the `Authorization` header:

```
Authorization: Bearer YOUR_API_KEY
```

---

## 📝 Enqueue a Task

Required POST parameters:

- `url` (string, must be a valid URL)  
- `prompt` (string) — instructions for the task  

Optional:

- `title` (string, default is timestamp + random number)  

**Example:** browser automation task to log in.

```java
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

public class EnqueueExample {
    public static void main(String[] args) throws IOException {
        String apiKey = "YOUR_API_KEY";
        String endpoint = "https://pendless.atomian.com/api/enqueue/";

        String jsonInput = "{\"procedure\":\"enqueue\",\"url\":\"https://example.com/login\",\"prompt\":\"Open the login page, enter username and password\",\"title\":\"Browser Automation: Login\"}";

        URL url = new URL(endpoint);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("POST");
        conn.setRequestProperty("Authorization", "Bearer " + apiKey);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);

        try (OutputStream os = conn.getOutputStream()) {
            byte[] input = jsonInput.getBytes("utf-8");
            os.write(input, 0, input.length);
        }

        try (BufferedReader br = new BufferedReader(
                new InputStreamReader(conn.getInputStream(), "utf-8"))) {
            StringBuilder response = new StringBuilder();
            String responseLine = null;
            while ((responseLine = br.readLine()) != null) {
                response.append(responseLine.trim());
            }
            System.out.println(response.toString());
        }
    }
}
```

**Sample Response:**

```json
{
    "status": "success",
    "data": {
        "uuid": "a1b2c3d4-5678-90ab-cdef-1234567890ab"
    },
    "message": "Task created successfully"
}
```

---

## 📝 Check Task Status

Required POST parameter:

- `uuid` (string, returned from `enqueue`)  

```java
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

public class StatusExample {
    public static void main(String[] args) throws IOException {
        String apiKey = "YOUR_API_KEY";
        String endpoint = "https://pendless.atomian.com/api/enqueue/";

        String jsonInput = "{\"procedure\":\"status\",\"uuid\":\"TASK_UUID_HERE\"}";

        URL url = new URL(endpoint);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("POST");
        conn.setRequestProperty("Authorization", "Bearer " + apiKey);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);

        try (OutputStream os = conn.getOutputStream()) {
            byte[] input = jsonInput.getBytes("utf-8");
            os.write(input, 0, input.length);
        }

        try (BufferedReader br = new BufferedReader(
                new InputStreamReader(conn.getInputStream(), "utf-8"))) {
            StringBuilder response = new StringBuilder();
            String responseLine = null;
            while ((responseLine = br.readLine()) != null) {
                response.append(responseLine.trim());
            }
            System.out.println(response.toString());
        }
    }
}
```

**Sample Response:**

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
