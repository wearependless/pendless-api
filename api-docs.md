# Pendless API Documentation

This document describes the **Pendless API** endpoints, parameters, authentication, and response formats.

---

## 🔑 Authentication

All requests require a **valid API key** sent in the `Authorization` header:

```
Authorization: Bearer YOUR_API_KEY
```

Requests without a valid key return:

- **HTTP 401** – Authentication failed

---

## 🚀 Endpoint

```
POST https://pendless.atomian.com/api/enqueue/
```

> Only `POST` requests are allowed. Other methods return **HTTP 405** – Method not allowed.

---

## 📝 Procedures

### 1. `enqueue` – Create a new task

**POST Parameters:**

| Parameter | Type   | Required | Description |
|-----------|--------|----------|-------------|
| procedure | string | Yes      | Must be `"enqueue"` |
| url       | string | Yes      | Target URL (must be valid or "continue" to continue on the previous task's page) |
| prompt    | string | Yes      | Instructions for the task |
| title     | string | No       | Task title; defaults to timestamp+random |

**Sample Request:**

```json
{
    "procedure": "enqueue",
    "url": "https://example.com/login",
    "prompt": "Open the login page, enter username and password",
    "title": "Browser Automation: Login"
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

**Errors:**

- Missing `url` or invalid URL → HTTP 400
- Missing `prompt` → HTTP 400
- Server error → HTTP 500

---

### 2. `status` – Check task status

**POST Parameters:**

| Parameter | Type   | Required | Description |
|-----------|--------|----------|-------------|
| procedure | string | Yes      | Must be `"status"` |
| uuid      | string | Yes      | Task UUID returned from `enqueue` |

**Sample Request:**

```json
{
    "procedure": "status",
    "uuid": "a1b2c3d4-5678-90ab-cdef-1234567890ab"
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

**Errors:**

- Missing `uuid` → HTTP 400
- Task not found → HTTP 500

---

## 📦 Response Format

All responses follow the **`ApiResponse` JSON structure**:

**Success:**

```json
{
    "status": "success",
    "data": {...},
    "message": "Descriptive message"
}
```

**Error:**

```json
{
    "status": "error",
    "data": null,
    "message": "Error message",
    "errors": [
        { "code": 400 }
    ]
}
```

---

## ⚠ Error Codes

| Code | Meaning |
|------|---------|
| 400  | Bad request / Missing parameters |
| 401  | Unauthorized / Invalid API key |
| 405  | Method not allowed |
| 500  | Internal server error |

---

This documentation, combined with the examples in each language folder, provides everything a developer needs to integrate with Pendless API quickly and safely.

