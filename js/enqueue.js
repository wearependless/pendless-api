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
