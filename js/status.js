const apiKey = "YOUR_API_KEY";
const endpoint = "https://app.pendless.com/api/enqueue/";

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
