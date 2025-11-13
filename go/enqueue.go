package main

import (
    "bytes"
    "encoding/json"
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    apiKey := "YOUR_API_KEY"
    endpoint := "https://app.pendless.com/api/enqueue/"

    data := map[string]string{
        "procedure": "enqueue",
        "url":       "https://example.com/login",
        "prompt":    "Open the login page, enter username and password",
        "title":     "Browser Automation: Login",
    }

    jsonData, _ := json.Marshal(data)
    req, _ := http.NewRequest("POST", endpoint, bytes.NewBuffer(jsonData))
    req.Header.Set("Authorization", "Bearer "+apiKey)

    client := &http.Client{}
    resp, err := client.Do(req)
    if err != nil {
        panic(err)
    }
    defer resp.Body.Close()

    body, _ := ioutil.ReadAll(resp.Body)
    fmt.Println(string(body))
}
