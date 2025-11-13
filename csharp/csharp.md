# C# Examples — Pendless API

This document shows how to call the Pendless API in C# using `HttpClient`. All requests require an **API key** in the `Authorization` header:

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

```csharp
using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        string apiKey = "YOUR_API_KEY";
        string endpoint = "https://app.pendless.com/api/enqueue/";

        var data = new
        {
            procedure = "enqueue",
            url = "https://example.com/login",
            prompt = "Open the login page, enter username and password",
            title = "Browser Automation: Login"
        };

        using (var client = new HttpClient())
        {
            client.DefaultRequestHeaders.Add("Authorization", $"Bearer {apiKey}");
            var content = new StringContent(System.Text.Json.JsonSerializer.Serialize(data), Encoding.UTF8, "application/json");

            var response = await client.PostAsync(endpoint, content);
            string respBody = await response.Content.ReadAsStringAsync();
            Console.WriteLine(respBody);
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

```csharp
using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        string apiKey = "YOUR_API_KEY";
        string endpoint = "https://app.pendless.com/api/enqueue/";

        var data = new
        {
            procedure = "status",
            uuid = "TASK_UUID_HERE"
        };

        using (var client = new HttpClient())
        {
            client.DefaultRequestHeaders.Add("Authorization", $"Bearer {apiKey}");
            var content = new StringContent(System.Text.Json.JsonSerializer.Serialize(data), Encoding.UTF8, "application/json");

            var response = await client.PostAsync(endpoint, content);
            string respBody = await response.Content.ReadAsStringAsync();
            Console.WriteLine(respBody);
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
