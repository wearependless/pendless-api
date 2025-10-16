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
    endpoint := "https://pendless.atomian.com/api/enqueue/"

    data := map[string]string{
        "procedure": "status",
        "uuid":      "TASK_UUID_HERE",
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
