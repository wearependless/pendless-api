# Go Examples — Pendless API

This document shows how to call the Pendless API in Go using `net/http`. All requests require an **API key** in the `Authorization` header:

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

```go
package main

import (
    "bytes"
    "encoding/json"
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    apiKey := "YOUR_API_KEY"
    endpoint := "https://app.pendless.com/api/enqueue/"

    data := map[string]string{
        "procedure": "enqueue",
        "url":       "https://example.com/login",
        "prompt":    "Open the login page, enter username and password",
        "title":     "Browser Automation: Login",
    }

    jsonData, _ := json.Marshal(data)
    req, _ := http.NewRequest("POST", endpoint, bytes.NewBuffer(jsonData))
    req.Header.Set("Authorization", "Bearer "+apiKey)

    client := &http.Client{}
    resp, err := client.Do(req)
    if err != nil {
        panic(err)
    }
    defer resp.Body.Close()

    body, _ := ioutil.ReadAll(resp.Body)
    fmt.Println(string(body))
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

```go
package main

import (
    "bytes"
    "encoding/json"
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    apiKey := "YOUR_API_KEY"
    endpoint := "https://app.pendless.com/api/enqueue/"

    data := map[string]string{
        "procedure": "status",
        "uuid":      "TASK_UUID_HERE",
    }

    jsonData, _ := json.Marshal(data)
    req, _ := http.NewRequest("POST", endpoint, bytes.NewBuffer(jsonData))
    req.Header.Set("Authorization", "Bearer "+apiKey)

    client := &http.Client{}
    resp, err := client.Do(req)
    if err != nil {
        panic(err)
    }
    defer resp.Body.Close()

    body, _ := ioutil.ReadAll(resp.Body)
    fmt.Println(string(body))
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
