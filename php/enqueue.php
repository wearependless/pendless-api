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
