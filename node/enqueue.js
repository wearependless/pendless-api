import fetch from "node-fetch";

const apiKey = "YOUR_API_KEY";
const endpoint = "https://app.pendless.com/api/enqueue/";

const data = {
    procedure: "enqueue",
    url: "https://example.com/login",
    prompt: "Open the login page, enter username and password",
    title: "Browser Automation: Login"
};

const main = async () => {
    const response = await fetch(endpoint, {
        method: "POST",
        headers: {
            "Authorization": `Bearer ${apiKey}`,
            "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    });

    const json = await response.json();
    console.log(json);
};

main();
