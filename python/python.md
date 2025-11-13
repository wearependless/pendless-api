# Python Examples — Pendless API

This document shows how to call the Pendless API in Python using the `enqueue` and `status` procedures.

All requests require an **API key** in the `Authorization` header:

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

```python
import requests

api_key = "YOUR_API_KEY"
endpoint = "https://app.pendless.com/api/enqueue/"

data = {
    "procedure": "enqueue",
    "url": "https://example.com/login",
    "prompt": "Open the login page, enter username and password",
    "title": "Browser Automation: Login"
}

headers = {
    "Authorization": f"Bearer {api_key}"
}

response = requests.post(endpoint, json=data, headers=headers)
print(response.json())
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

> See also: [`examples/python/enqueue.py`](../examples/python/enqueue.py)

---

## 📝 Check Task Status

Required POST parameter:

- `uuid` (string, returned from `enqueue`)  

```python
import requests

api_key = "YOUR_API_KEY"
endpoint = "https://app.pendless.com/api/enqueue/"

data = {
    "procedure": "status",
    "uuid": "TASK_UUID_HERE"
}

headers = {
    "Authorization": f"Bearer {api_key}"
}

response = requests.post(endpoint, json=data, headers=headers)
print(response.json())
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

> See also: [`examples/python/status.py`](../examples/python/status.py)
