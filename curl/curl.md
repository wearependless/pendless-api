# cURL Examples — Pendless API

This document shows how to call the Pendless API using **cURL** commands.  

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

```bash
curl -X POST https://pendless.atomian.com/api/enqueue/ \
  -H "Authorization: Bearer YOUR_API_KEY" \
  -d '{"procedure":"enqueue","url":"https://example.com/login","prompt":"Open the login page, enter username and password","title":"Browser Automation: Login"}'
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

```bash
curl -X POST https://pendless.atomian.com/api/enqueue/ \
  -H "Authorization: Bearer YOUR_API_KEY" \
  -d '{"procedure":"status","uuid":"TASK_UUID_HERE"}'
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

---

✅ Notes:

- The `-d` option sends JSON data in the POST body.  
- Replace `YOUR_API_KEY` with your actual API key.  
- Replace `TASK_UUID_HERE` with the `uuid` returned from the `enqueue` call.
