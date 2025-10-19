# JavaScript Examples — Pendless API

This document shows how to call the Pendless API in JavaScript using **fetch**. All requests require an **API key** in the `Authorization` header:

```
Authorization: Bearer YOUR_API_KEY
```

---

## 📝 Enqueue a Task

Required POST parameters:

- `url` (string, must be a valid URL or "continue" to continue on the previous task's page)  
- `prompt` (string) — instructions for the task  

Optional:

- `title` (string, default is timestamp + random number)  

**Example:** browser automation task to log in.

```javascript
const apiKey = "YOUR_API_KEY";
const endpoint = "https://pendless.atomian.com/api/enqueue/";

const data = {
    procedure: "enqueue",
    url: "https://example.com/login",
    prompt: "Open the login page, enter username and password",
    title: "Browser Automation: Login"
};

fetch(endpoint, {
    method: "POST",
    headers: {
        "Authorization": `Bearer ${apiKey}`,
        "Content-Type": "application/json"
    },
    body: JSON.stringify(data)
})
.then(response => response.json())
.then(json => console.log(json))
.catch(err => console.error(err));
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

```javascript
const apiKey = "YOUR_API_KEY";
const endpoint = "https://pendless.atomian.com/api/enqueue/";

const data = {
    procedure: "status",
    uuid: "TASK_UUID_HERE"
};

fetch(endpoint, {
    method: "POST",
    headers: {
        "Authorization": `Bearer ${apiKey}`,
        "Content-Type": "application/json"
    },
    body: JSON.stringify(data)
})
.then(response => response.json())
.then(json => console.log(json))
.catch(err => console.error(err));
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

