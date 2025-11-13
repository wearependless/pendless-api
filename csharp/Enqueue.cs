using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

class EnqueueExample
{
    static async Task Main()
    {
        string apiKey = "YOUR_API_KEY";
        string endpoint = "https://app.pendless.com/api/enqueue/";

        var data = new
        {
            procedure = "enqueue",
            url = "https://example.com/login",
            prompt = "Open the login page, enter username and password",
            title = "Browser Automation: Login"
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
