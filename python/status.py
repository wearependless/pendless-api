import requests

api_key = "YOUR_API_KEY"
endpoint = "https://pendless.atomian.com/api/enqueue/"

data = {
    "procedure": "status",
    "uuid": "TASK_UUID_HERE"
}

headers = {
    "Authorization": f"Bearer {api_key}"
}

response = requests.post(endpoint, json=data, headers=headers)
print(response.json())
