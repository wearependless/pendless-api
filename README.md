# Pendless API

Pendless is a **browser automation platform** that lets you automate virtually any task in a web browser. You can either run tasks directly or enqueue them in a queue and execute them later. The Pendless API allows developers to **enqueue tasks programmatically** from their own code.

---

## 🌐 Getting Started

To use the API:

1. **Sign up** at [Pendless.com](https://pendless.com).  
2. Request an **API key** by contacting us at:  
   ```
   developers@pendless.com
   ```
3. Use your API key in the `Authorization` header for all requests:

```
Authorization: Bearer YOUR_API_KEY
```

> Requests without a valid API key will return **HTTP 401 – Authentication failed**.

---

## 🚀 API Endpoint

```
POST https://app.pendless.com/api/enqueue/
```

> Only POST requests are allowed. Other HTTP methods return **405 – Method not allowed**.

---

## 📝 Available Procedures

1. **enqueue** – Create a new browser automation task  
2. **status** – Retrieve the status of a previously enqueued task

---

## 📂 Language Examples

Pendless provides example scripts for multiple programming languages. Each folder contains runnable code and Markdown documentation:

| Language | Folder |
|----------|--------|
| PHP      | `php/` |
| Python   | `python/` |
| C        | `c/` |
| C++      | `cpp/` |
| C#       | `csharp/` |
| Go       | `go/` |
| Java     | `java/` |
| JavaScript | `js/` |
| Node.js  | `node/` |
| cURL     | Root (`curl.md`) |

---

## ⚡ Quick Start

1. Clone the repository:

```bash
git clone https://github.com/yourusername/pendless-api.git
cd pendless-api
```

2. Navigate to your preferred language folder:

```bash
cd php
# or
cd python
```

3. Replace `YOUR_API_KEY` in the example scripts with your actual API key.  
4. Run the example scripts to **enqueue tasks** or **check their status**.

---

## 📖 See Also

- [API Documentation](api-docs.md) – Detailed reference for all procedures, parameters, and response formats.
