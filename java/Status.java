import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;

public class Status {
    public static void main(String[] args) throws IOException {
        String apiKey = "YOUR_API_KEY";
        String endpoint = "https://pendless.atomian.com/api/enqueue/";

        String jsonInput = "{\"procedure\":\"status\",\"uuid\":\"TASK_UUID_HERE\"}";

        URL url = new URL(endpoint);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("POST");
        conn.setRequestProperty("Authorization", "Bearer " + apiKey);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);

        try (OutputStream os = conn.getOutputStream()) {
            byte[] input = jsonInput.getBytes("utf-8");
            os.write(input, 0, input.length);
        }

        try (BufferedReader br = new BufferedReader(
                new InputStreamReader(conn.getInputStream(), "utf-8"))) {
            StringBuilder response = new StringBuilder();
            String responseLine = null;
            while ((responseLine = br.readLine()) != null) {
                response.append(responseLine.trim());
            }
            System.out.println(response.toString());
        }
    }
}
