import requests
import base64

url = "https://fedloginqa.cat.com/as/token.oauth2"

headers = {
    "Content-Type": "application/x-www-form-urlencoded"
}

client_id = "PartsVizOrderStatusService_P230_cc_client"
client_secret = "LAjzqKlOPQCweD8m6hljtpVrVhwiLnJk3Ysy3QbZQFcowcXzkgJdJLrE7qu4tMxR"
grant_type = "client_credentials"
scope = "manage:all"

credentials = f"{client_id}:{client_secret}"
credentials_b64 = base64.b64encode(credentials.encode()).decode()

data = {
    "grant_type": grant_type,
    "scope": scope
}

response = requests.post(url, headers={**headers, "Authorization": f"Basic {credentials_b64}"}, data=data)

if response.status_code == 200:
    print("Success:", response.json())
else:
    print("Error:", response.json())
