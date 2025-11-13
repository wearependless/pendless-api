<?php

$apiKey = "YOUR_API_KEY";
$endpoint = "https://app.pendless.com/api/enqueue/";

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
