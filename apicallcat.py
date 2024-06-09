import requests

# Define the endpoint
url = "https://fedloginqa.cat.com/as/token.oauth2"

# Define headers
headers = {
    "Content-Type": "application/x-www-form-urlencoded"
}

# Define the body data (client ID and secret)
client_id = "PartsVizOrderStatusService_P230_cc_client"
client_secret = "LAjzqKIOPQCweD8m6hljtpVrVhwiLnJk3Ysy3QbZQFcowcXzkgJdJLrE7qu4tMxR"
data = {
    "client_id": client_id,
    "client_secret": client_secret
}

# Make the POST request
response = requests.post(url, headers=headers, data=data)

# Check the response status
if response.status_code == 200:
    # Request was successful
    print("Success:", response.json())
else:
    # Request failed
    print("Error:", response.json())
