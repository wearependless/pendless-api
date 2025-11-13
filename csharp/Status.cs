using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

class StatusExample
{
    static async Task Main()
    {
        string apiKey = "YOUR_API_KEY";
        string endpoint = "https://app.pendless.com/api/enqueue/";

        var data = new
        {
            procedure = "status",
            uuid = "TASK_UUID_HERE"
        };

        using (var client = new HttpClient())
        {
            client.DefaultRequestHeaders.Add("Authorization", $"Bearer {apiKey}");
            var content = new StringContent(System.Text.Json.JsonSerializer.Serialize(data), Encoding.UTF8, "application/json");

            var response = await client.PostAsync(endpoint, content);
            string respBody = await response.Content.ReadAsStringAsync();
            Console.WriteLine(respBody);
        }
    }
}
