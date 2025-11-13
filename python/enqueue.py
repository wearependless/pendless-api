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
