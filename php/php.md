# PHP Examples — Pendless API

This document shows how to call the Pendless API in PHP using the `enqueue` and `status` procedures.

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

```php
<?php

$apiKey = "YOUR_API_KEY";
$endpoint = "https://pendless.atomian.com/api/enqueue/";

$data = [
    "procedure" => "enqueue",
    "url" => "https://example.com/login",
    "prompt" => "Open the login page, enter username and password",
    "title" => "Browser Automation: Login"
];

$options = [
    "http" => [
        "header"  => [
            "Authorization: Bearer $apiKey"
        ],
        "method"  => "POST",
        "content" => json_encode($data)
    ]
];

$context = stream_context_create($options);
$result = file_get_contents($endpoint, false, $context);

$response = json_decode($result, true);
print_r($response);
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

> See also: [`examples/php/enqueue.php`](../examples/php/enqueue.php)

---

## 📝 Check Task Status

Required POST parameter:

- `uuid` (string, returned from `enqueue`)  

```php
<?php

$apiKey = "YOUR_API_KEY";
$endpoint = "https://pendless.atomian.com/api/enqueue/";

$data = [
    "procedure" => "status",
    "uuid" => "TASK_UUID_HERE"
];

$options = [
    "http" => [
        "header"  => [
            "Authorization: Bearer $apiKey"
        ],
        "method"  => "POST",
        "content" => json_encode($data)
    ]
];

$context = stream_context_create($options);
$result = file_get_contents($endpoint, false, $context);

$response = json_decode($result, true);
print_r($response);
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

> See also: [`examples/php/status.php`](../examples/php/status.php)
